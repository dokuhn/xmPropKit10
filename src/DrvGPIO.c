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

//
// DrvGPIO.c
//

#include <Compiler.h>

#include <xmc1100.h>

#include <RB_GPIO.h>
#include <DrvGPIO.h>


typedef struct{ 
    RegbankTypeGPIO volatile * ptr2RegBank;
    WORD dummyNum;
} GpioConstantsType;

static GpioConstantsType const gpioConstantsArr[] = {
    { &rbGPIOp0, 0u },
    { &rbGPIOp1, 0u },
    { &rbGPIOp2, 0u }
};


GpioErrorType InitGpioOutput( GpioPortType const gpioPort, BYTE const pinNum){

   unsigned const gpioIndx = (unsigned)gpioPort;

   GpioConstantsType const * const gpioConstants = gpioConstantsArr + gpioIndx;

   RegbankTypeGPIO volatile * const ptr2RegBank = gpioConstants->ptr2RegBank;

   if( gpioPort != gpioPort1 ){
     
     if( pinNum <= 3u ){
       
       ptr2RegBank->IOCR0 |= ( 0x80u << (8u * pinNum));
     
     }


   }else{

     if( pinNum <= 3u ){
       
       ptr2RegBank->IOCR0 |= ( 0x80u << (8u * pinNum));
     
     }


   }

   ptr2RegBank->IOCR0 |= 0u;


  return noGpioError;

}


GpioErrorType InitGpioAF( GpioPortType const gpioPort, BYTE const pinNum, GpioOutputType OutputType, unsigned const AFRbitMASK ){

   unsigned const gpioIndx = (unsigned)gpioPort;

   GpioConstantsType const * const gpioConstants = gpioConstantsArr + gpioIndx;

   RegbankTypeGPIO volatile * const ptr2RegBank = gpioConstants->ptr2RegBank;

   ptr2RegBank->IOCR0 |= 0u;


   return noGpioError;

}




/*

GpioErrorType InitGpioInput(GpioIHandleType * const ptr2Handle, GpioPortType const gpioPort, unsigned const pinNum)
{
	unsigned const gpioIndx = (unsigned)gpioPort;

	if ( pinNum < 16U && gpioIndx < ARRAY_DIM(gpioConstantsArr) )
	{
	  static GpioIDescrType allDescrs[MAX_NUM_OF_IDESCR];		
		static UINT08 descrCntr = 0;
		UINT08 const descrIndx = IncrUINT08(&descrCntr);
		
		if ( descrIndx < ARRAY_DIM(allDescrs) )
		{
			GpioConstantsType const * const gpioConstants = gpioConstantsArr + gpioIndx;
			RegbankTypeGPIO volatile * const ptr2RegBank = gpioConstants->ptr2RegBank;
			GpioIDescrType * const theHandle = allDescrs + descrIndx;		
			WORD const bitMask = 1U << pinNum;
			
			theHandle->ptr2RegBank = ptr2RegBank;
			theHandle->bitMask = bitMask;

			AHBClockEnable(gpioConstants->peripheryNum);
			WrGpioMode(ptr2RegBank, pinNum, MASK_GPIO_MODER_INPUT);
			
			*ptr2Handle = theHandle;
			
			return noGpioError;
		} else
			return outOfGpioDescr;
	} else
		return invalidGpioArgs;
}

bool GpioInputState(GpioIHandleType const theHandle)
{
	RegbankTypeGPIO volatile * const ptr2RegBank = VERIFY_PTR(theHandle)->ptr2RegBank;
	WORD const bitMask = theHandle->bitMask;
	
	return (ptr2RegBank->IDR & bitMask) != 0U;
}


GpioErrorType InitGpioAF( GpioPortType const gpioPort, unsigned const pinNum , GpioOutputType OutputType, unsigned const AFRbitMASK )
{
  unsigned const gpioIndx = (unsigned)gpioPort;

	if ( pinNum < 16U && gpioIndx < ARRAY_DIM(gpioConstantsArr) )
	{    
			GpioConstantsType const * const gpioConstants = gpioConstantsArr + gpioIndx;
			RegbankTypeGPIO volatile * const ptr2RegBank = gpioConstants->ptr2RegBank;
			
      WORD const typeMask = MASK_GPIO_OTYPER_OD << pinNum;
			WORD volatile * const ptr2Afr = ptr2RegBank->AFR + (pinNum / 8U);
      unsigned const afrPosition = 4U * (pinNum % 8U);
      			
 			AHBClockEnable(gpioConstants->peripheryNum);
            
      if ( OutputType == OpenDrain ) 
        ptr2RegBank->OTYPER |=  typeMask;
      else
        ptr2RegBank->OTYPER &= ~typeMask;
      
      *ptr2Afr = (*ptr2Afr & ~(MASK_GPIO_AFR << afrPosition)) | (AFRbitMASK << afrPosition);
      
      WrGpioMode( ptr2RegBank , pinNum , MASK_GPIO_MODER_ALTFNC);
      
      return noGpioError; 
  }else
      return invalidGpioArgs;
}


GpioErrorType InitGpioOutput(GpioOHandleType * const ptr2Handle, GpioPortType const gpioPort, unsigned const pinNum)
{
	unsigned const gpioIndx = (unsigned)gpioPort;

	if ( pinNum < 16U && gpioIndx < ARRAY_DIM(gpioConstantsArr) )
	{
	  static GpioODescrType allDescrs[MAX_NUM_OF_ODESCR];		
		static UINT08 descrCntr = 0;
		UINT08 const descrIndx = IncrUINT08(&descrCntr);
		
		if ( descrIndx < ARRAY_DIM(allDescrs) )
		{
			GpioConstantsType const * const gpioConstants = gpioConstantsArr + gpioIndx;
			RegbankTypeGPIO volatile * const ptr2RegBank = gpioConstants->ptr2RegBank;
			GpioODescrType * const theHandle = allDescrs + descrIndx;		
			WORD const bitMask = 1U << pinNum;
			
			theHandle->ptr2RegBank = ptr2RegBank;
			theHandle->bitMask = bitMask;

			AHBClockEnable(gpioConstants->peripheryNum);
      
			WrGpioMode(ptr2RegBank, pinNum, MASK_GPIO_MODER_GPOUT);
			
			*ptr2Handle = theHandle;
			
			return noGpioError;
		} else
			return outOfGpioDescr;
	} else
		return invalidGpioArgs;
}


void GpioOutputToggle(GpioOHandleType const theHandle)
{
	RegbankTypeGPIO volatile * const ptr2RegBank = VERIFY_PTR(theHandle)->ptr2RegBank;
	WORD const bitMask = theHandle->bitMask;
			
	if ( (ptr2RegBank->ODR & bitMask) != 0U )
	{
		ptr2RegBank->BRR = bitMask;
	} else
	{
		ptr2RegBank->BSR = bitMask;
	}
}

*/
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
