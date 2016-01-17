///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// xmPropKit10
//
// Author:  Dominik Kuhn
// Updated: 01/17/2016
// Designed For: XMC1100
// Version: 1.0
//
// Copyright (c) 2016 Dominik Kuhn
// See end of file for terms of use.
//
// Update History:
//
// v1.0 - Original release - 01/17/2016.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Compiler.h>

#include <xmc1100.h>
#include <RB_I2C.h>
#include <RB_USIC.h>

#include <DrvUSIC.h>
#include <DrvI2C.h>
#include <DrvNVM.h>
#include <DrvEEPROM.h>

#define MASK_I2C_10BIT_ADDR      (0xF800u)      ///< Address Mask for 10-bit Mode
#define INDX_I2C_7BIT_ADDR       (8u)           ///< 7-bit address position
#define XMC_I2C_10BIT_ADDR       (0xF000U)      ///< Value to verify the address is 10-bit or not


void setSlaveAddress( const HWRD address ){
  if ((address & MASK_I2C_10BIT_ADDR) == XMC_I2C_10BIT_ADDR){
    USIC0_CH1_PCR = (WORD)( USIC0_CH1_PCR & (~MASK_I2C_PCR_SLAD)) | (WORD)(address);
  }else{
    USIC0_CH1_PCR = (WORD)( USIC0_CH1_PCR & (~MASK_I2C_PCR_SLAD)) | (((WORD)address) << INDX_I2C_7BIT_ADDR);
  }
}


I2CErrCodeType  initI2C( I2CInstanceType const I2CInstance , const HWRD address ){
  if( I2CInstance == I2CInst1 ){
    // disable bit protection
    SCU_PASSWD = 0xC0u;

    // USIC Enable
    SCU_CGATCLR0 |= (WORD)(0x1u << 3);

    // enable bit protection
    SCU_PASSWD = 0xC3u;

    // USIC channel switched on
    USIC0_CH1_KSCFG |= (MASK_USIC_CH_KSCFG_MODEN | MASK_USIC_CH_KSCFG_BPMODEN) ;

    while( (USIC0_CH1_KSCFG & MASK_USIC_CH_KSCFG_MODEN) == 0u  ){
      // wait till the channel is enabled
    }

    // set the USIC channel in IDLE mode
    USIC0_CH1_CCR &= (WORD)(~MASK_USIC_CH_CCR_MODE);

    if( USIC0_CH1_KSCFG == rbUSIC0_CH1.KSCFG ){
      // P2_OMR = (0x1u << 11u) | (0x1u << 27u);                 ///< Red LED toggled
    }
    
    // Data format configuration
    USIC0_CH1_SCTR  = MASK_I2C_SCTR_TRM  | MASK_I2C_SCTR_PDL              |
                      (MASK_I2C_SCTR_FLE & (0x3Fu << INDX_I2C_SCTR_FLE))  |
		      (MASK_I2C_SCTR_WLE & (0x7u  << INDX_I2C_SCTR_WLE))  |
                      MASK_I2C_SCTR_SDIR ;

    // set slave address
    setSlaveAddress( address );

    //  f_PERIPH = 32 MHz  ==> f_FD = f_PIN = 4 MHz , ( Reference Manual 14-26 )
    //
    //  Normal divider mode FDR.DM = 1
    //  FDR.STEP = 1016
    //
    USIC0_CH1_FDR |=  (0x3F8u << INDX_USIC_CH_FDR_STEP) | MASK_USIC_CH_FDR_DM_NORMAL ; 
    
    // 100 kBaud by f_PIN = f_IN = 4MHz :
    //
    // CTQSEL = 00u ; DCTQ   =  9u ; PCTQ = 1u ; PDIV = 1u 
    //
    USIC0_CH1_BRG = (9u << INDX_USIC_CH_BRG_DCTQ) | (1u << INDX_USIC_CH_BRG_PCTQ) | (1u << INDX_USIC_CH_BRG_PDIV) ;

    // Enable transfer buffer
    USIC0_CH1_TCSR = ((WORD)SET_TDV << (WORD)USIC_CH_TCSR_TDEN_POS) | USIC_CH_TCSR_TDSSM_MASK ;

    // Clear Status flags 
    USIC0_CH1_PSCR = 0xFFFFFFFFu;

    // Disable parity generation 
    USIC0_CH1_CCR = 0x0u;

    // ************************   Interrupt Enable    ****************************
    // ***************************************************************************
    USIC0_CH1_CCR  |= MASK_USIC_CH_CCR_RIEN  |      // Receive Interrupt Enable
                      MASK_USIC_CH_CCR_DLIEN |      // Data Lost Interrupt Enable
                      MASK_USIC_CH_CCR_AIEN  |      // Alternative Receive Interrupt Enable
                      MASK_USIC_CH_CCR_TBIEN ;
     
    USIC0_CH1_PCR  |= MASK_I2C_PCR_SCRIEN  |       // Start Condition Received Interrupt Enable
                      MASK_I2C_PCR_RSCRIEN |       // Repeated Condition 
                      MASK_I2C_PCR_PCRIEN  |       // Stop Condition Received Interrupt Enable 
                      MASK_I2C_PCR_ERRIEN  |       // Error Interrupt Enable
                      MASK_I2C_PCR_SRRIEN  |       // Slave Read Request Interrupt Enable
                      MASK_I2C_PCR_MCLK    ;
    
                          
    NVIC_ISER      |=  0xE00u;                     // Enable Interrupt IRQ 9 - 11

    // Set node pointer
    USIC0_CH1_INPR |=  (( 0x1u <<  8 ) & MASK_USIC_CH_INPR_RINP) ;
    USIC0_CH1_INPR |=  (( 0x1u << 12 ) & MASK_USIC_CH_INPR_AINP) ;
    USIC0_CH1_INPR |=  (( 0x1u << 16 ) & MASK_USIC_CH_INPR_PINP) ;
    USIC0_CH1_INPR |=  (( 0x1u <<  4 ) & MASK_USIC_CH_INPR_TBINP);
    // *****************************************************************************
    // *****************************************************************************

    // Set Input Source
    USIC0_CH1_DX0CR  |= ( MASK_USIC_CH_DX0CR_DSEL &  0x3u ) ;
    USIC0_CH1_DX1CR  |=  0x1 ;

    P0_IOCR4  |=  0xF8000000u  ;    // P0.7 as open-drain AL7 --> SDA
    P0_IOCR8  |=  0xF8;             // P0.8 as open-drain AL7 --> SCL
    
    // the IIC protcoll is selected
    USIC0_CH1_CCR = (WORD)( USIC0_CH1_CCR & (~(MASK_USIC_CH_CCR_MODE))) | (WORD)( 0x4u) ;
    
    return I2CNoError;
  }else
    return I2CInvalidParameter;
}


// ########################## Lokale Funktionen #######################################
// ####################################################################################

static void RecvInterrupt( volatile BYTE * const ptr2Data ){
  *ptr2Data = USIC0_CH1_RBUF;
}


static void SendInterrupt( BYTE const anyData ){
  *USIC0_CH1_TBUF = (0x1u << 8) | anyData ;
}


static void Interrupt( void ){
  
  const WORD I2C_PSR = USIC0_CH1_PSR;
  
  static I2C_StateType I2C_State = start;
  
  static BYTE AddrBuf[ NUM_OF_ADDR_BYTES ];
  static HWRD tAddress;
  
  static bool AddrFlag;
  static bool recvFlag;
  
  static WORD i; 
  
  static BYTE index ;
  
  // ********************   Protocol Status Interrupt   ************************
  // ***************************************************************************
  if( (I2C_PSR & MASK_I2C_PSR_SCR ) != 0u  ){
    ///<    Start
    USIC0_CH1_PSCR |= MASK_I2C_PSR_SCR;
    
    tAddress++;
    tAddress = tAddress & 0x7FFFu;
    
    P0_OMR = (0x1u << 0u) | ( 0x1u << 16u);                 ///< Green LED toggled
    
   
  }else if( ((I2C_PSR & MASK_I2C_PSR_RSCR) != 0u) || ((I2C_PSR & MASK_I2C_PSR_PCR) != 0u)  ){

    if( (I2C_PSR & MASK_I2C_PSR_RSCR) != 0u ){
      USIC0_CH1_PSCR |= MASK_I2C_PSR_RSCR;
    }else{
      USIC0_CH1_PSCR |= MASK_I2C_PSR_PCR;
    }

    
       
    // !!!!!!! HACK !!!!!! HACK !!!!!!!!! HACK !!!!!!!!!!!
    // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
 
  
    if( (I2C_State == recv) && recvFlag ){

      I2C_State = idle;

      setSlaveAddress( 0u );

      P2_OMR = (0x1u << 10 ) | ( 0x1u <<  26u );             ///< Yellow LED toogled 
      
      for( i = 0u; i < NUM_OF_RECV_BYTES ; i++ ){
	writeByte( I2C_Descr.regAddr + i , I2C_Descr.IO_Buffer[i] );
      }

      P2_OMR = (0x1u << 10 ) | ( 0x1u <<  26u );             ///< Yellow LED toogled

      setSlaveAddress( 0xA0u );
   
      
    }
        

    I2C_State = start;
    recvFlag = false;

    // I2C_Descr.writeCnt ++;
    // I2C_Descr.writeCnt = I2C_Descr.writeCnt & ( 0x4u - 1u );
    // I2C_Descr.writeBuf = I2C_Descr.IO_Buffer + ( I2C_Descr.writeCnt * NUM_OF_RECV_BYTES );
      
  }else if( (I2C_PSR & MASK_I2C_PSR_SLSEL) != 0u ){
    USIC0_CH1_PSCR |= MASK_I2C_PSR_SLSEL;

    
  }else if( (I2C_PSR & MASK_I2C_PSR_ERR) != 0u){
    USIC0_CH1_PSCR |= MASK_I2C_PSR_ERR;
    
    P2_OMR = (0x1u << 11u) | (0x1u << 27u);                 ///< Red LED toggled
  }
  
  
  switch( I2C_State ){
  case start:
    if( (I2C_PSR & MASK_I2C_PSR_AIF) != 0u ){
      USIC0_CH1_PSCR |= MASK_I2C_PSR_AIF;
   
      AddrFlag = true;
      RecvInterrupt( AddrBuf );
      
      I2C_State = recv;
    }else if( (I2C_PSR & MASK_I2C_PSR_SRR) != 0u  ){
      USIC0_CH1_PSCR |= MASK_I2C_PSR_SRR;
      
      SendInterrupt( getByte( tAddress ) );
      I2C_State = transmit;
    }
    break;
  case  recv:
    if( (I2C_PSR & MASK_I2C_PSR_RIF) != 0u ){
      USIC0_CH1_PSCR |= MASK_I2C_PSR_RIF;
      if( AddrFlag ){
	RecvInterrupt( AddrBuf + 1 );
	tAddress = ( (HWRD)(AddrBuf[0]) << 8u) | (HWRD)(AddrBuf[1]) ;
	I2C_Descr.regAddr = tAddress;
	AddrFlag = false;
      }else{
	RecvInterrupt( I2C_Descr.IO_Buffer + index );
        index++;
	I2C_Descr.recvCnt++;
	
	index = index & (NUM_OF_RECV_BYTES - 1u);
	I2C_Descr.recvCnt = I2C_Descr.recvCnt & (NUM_OF_RECV_BYTES -1u);

	recvFlag = true;
	// I2C_Descr.recvCnt =  I2C_Descr.recvCnt & ( (NUM_OF_RECV_BYTES * 4u)  - 1u) ;
      }
    }else if( (I2C_PSR & MASK_I2C_PSR_DLIF) != 0u){
      USIC0_CH1_PSCR |= MASK_I2C_PSR_DLIF;
    }
    break;
  case transmit:
    if( (I2C_PSR & MASK_I2C_PSR_TBIF) != 0u ){
      USIC0_CH1_PSCR |= MASK_I2C_PSR_TBIF;
      tAddress++;
      tAddress = tAddress & 0x7FFFu;
      SendInterrupt( getByte( tAddress ) );
    }
    break;
  case idle:    
    break;
  }
       

 

}


void IRQ_I2C_EV(void){
  Interrupt();   
}


void IRQ_I2C_ER(void){


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                  TERMS OF USE: MIT License
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
