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

///
///  RB_WDT.h
///
/// \file RB_WDT.h

#ifndef __RB_WDT_H__
#define __RB_WDT_H__

#include "Compiler.h"


/// Datentyp fuer WDT-Registerbank (Window Watchdog Timer) , s. Reference Manual,
typedef struct __regbank_WDT
{

  WORD ID;     ///< Module ID Register

  WORD CTR;    ///< Control Register

  WORD SRV;    ///< Service Register

  WORD TIM;    ///< Timer Register

  WORD WLB;    ///< Window Lower Bound Register

  WORD WUB;    ///< Window Upper Bound Register

  WORD WDTSTS; ///< Status Register

  WORD WDTCLR; ///< Clear Register

}RegbankTypeWDT;


extern RegbankTypeWDT volatile rbWDT;               ///< Window Watchdog Timer - Registers.


// --------------------------------   ID   ------------------------------- //

#define INDX_WDT_ID_MOD_REV           0
#define MASK_WDT_ID_MOD_REV           (WORD)( 0xFFu << INDX_WDT_ID_MOD_REV )  ///< Module Revision Number Bit[7:0]

#define INDX_WDT_ID_MOD_TYPE          8
#define MASK_WDT_ID_MOD_TYPE          (WORD)( 0xFFu << INDX_WDT_ID_MOD_TYPE ) ///< Module Type Bit[15:8]

#define INDX_WDT_ID_MOD_NUMBER        16
#define MASK_WDT_ID_MOD_NUMBER        (WORD)( 0xFFFFu << INDX_WDT_ID_MOD_NUMBER ) ///< Module Number Value


// --------------------------------  CTR  ------------------------------- //


#define INDX_WDT_CTR_ENB              0
#define MASK_WDT_CTR_ENB              (WORD)( 0x1u << INDX_WDT_CTR_ENB )

#define INDX_WDT_CTR_PRE              1
#define MASK_WDT_CTR_PRE              (WORD)( 0x1u << INDX_WDT_CTR_PRE )

#define INDX_WDT_CTR_DSP              4
#define MASK_WDT_CTR_DSP              (WORD)( 0x1u << INDX_WDT_CTR_DSP )

#define INDX_WDT_CTR_SPW              8
#define MASK_WDT_CTR_SPW              (WORD)( 0xFFu << INDX_WDT_CTR_SPW )

// --------------------------------  WDSTS  ------------------------------ //

#define INDX_WDT_WDSTS_ALMS           0
#define MASK_WDT_WDSTS_ALMS           (WORD)( 0x1u << INDX_WDT_WDSTS_ALMS )   ///< Pre-warning Alarm

// --------------------------------  WDTCLR  ----------------------------- //

#define INDX_WDT_WDTCLR_ALMC          0
#define MASK_WDT_WDTCLR_ALMC          (WORD)( 0x1u << INDX_WDT_WDTCLR_ALMC )  ///> clear Pre-warning Alarm



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
