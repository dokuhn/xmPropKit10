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
// DrvNVM.h
//

#ifndef __DRV_NVM_H__
#define __DRV_NVM_H__


#include <Compiler.h>


#define NVM_START_ADDRESS            (0x10001000u + 0x8000u)      
#define NVM_END_ADDRESS              (0x10010FFFu)


/*
 * This enumeration defines error codes for NVM functions
 */
typedef enum {
  /** No Error */
  NVMNoError,
  /** completion of operation*/
  NVMComplete,
  /** Invalid Parameter */
  NVMInvalidAddress,
  /** Error */
  NVMError,
  /** Operation in Progress*/
  NVMInProgress,
  /** Function is IDLE*/
  NVMIdle
}NVMErrCodeType;



/*
 * This enumeration defines NVM Rom APIs return values
 */
typedef enum NVMStatus{
    /*the function succeeded*/
    NVM_PASS               = (int32_t) 0x00010000,
    /*generic error code*/
    NVM_E_FAIL             = (int32_t) 0x80010001, 
    /*source data not in RAM*/
    NVM_E_SRC_AREA_EXCCEED = (int32_t) 0x80010003,  
    /*source data is not 4 byte aligned*/
    NVM_E_SRC_ALIGNMENT    = (int32_t) 0x80010004,   
    /*NVM module cannot be physically accessed*/
    NVM_E_NVM_FAIL         = (int32_t) 0x80010005,  
    /*verification of written page not successful*/
    NVM_E_VERIFY           = (int32_t) 0x80010006,  
    /*destination data is not (completely) located in NVM*/
    NVM_E_DST_AREA_EXCEED  = (int32_t) 0x80010009,  
    /*destination data is not properly aligned*/
    NVM_E_DST_ALIGNMENT    = (int32_t) 0x80010010,   
  } NVM_STATUS;



NVMErrCodeType  initNVM( void );

NVMErrCodeType  writeNVM( WORD address ,WORD pBuf[] );
NVMErrCodeType  readNVM( WORD address , WORD * buf );

NVMErrCodeType  eraseNVM( WORD address );


#endif



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
