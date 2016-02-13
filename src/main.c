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

#include <RB_SCU.h>
#include <RB_GPIO.h>

#include <DrvI2C.h>
#include <DrvSCU.h>
#include <DrvGPIO.h>
#include <DrvNVM.h>
#include <DrvEEPROM.h>

const HWRD address = 0xA0u;

int main()
{

  // Clock configuration
  SCU_PASSWD = 0x000000C0UL;      // disable bit protection
  SCU_CLKCR = 0x3FF00100UL;       //MCLK = 32 MHz, PCLK = 32 MHz
  while((SCU_CLKCR & MASK_SCU_CLKCR_VDDC2LOW));
  SCU_PASSWD = 0x000000C3UL;      // enable bit protection
  // SystemCoreClockUpdate();



  // setup Debug LEDs
  InitGpioOutput( gpioPort0 , 0u );
  // P0_IOCR0 |= BIT7;                         ///< P0.0

  InitGpioOutput( gpioPort1 , 0u );
  InitGpioOutput( gpioPort1 , 1u );
  // P1_IOCR0 |= BIT7 + BIT15;                 ///< P1.0 + P1.1

  rbGPIOp2.IOCR8 |= BIT23 + BIT31;
  // P2_IOCR8 |= BIT23 + BIT31;
                ///< P2.10 + P2.11
  rbGPIOp2.PDISC = rbGPIOp2.PDISC & ~BIT10;
  // P2_PDISC  = P2_PDISC & ~BIT10;

 P2_PDISC  = P2_PDISC & ~BIT11;




  if( (initNVM() ==  NVMNoError) && (initI2C(I2CInst1,address) == I2CNoError) ){

    I2C_Descr.writeBuf = I2C_Descr.IO_Buffer ;
    I2C_Descr.recvCnt  = 0u;
    I2C_Descr.writeCnt = 0u;

    enable_interrupts();

  }



  while(1){


  };

  return 0;

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
