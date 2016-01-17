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
// RB_SCU.h
//

/// \file RB_SCU.h


#ifndef __RB_SCU_H__
# define __RB_SCU_H__

#include "Compiler.h"


/* --------------------------------  SCU_CLKCR  ------------------------------- */
#define INDX_SCU_CLKCR_FDIV          0
#define MASK_SCU_CLKCR_FDIV          (WORD)( 0xFFu << INDX_SCU_CLKCR_FDIV )      ///< Fractional Divider Selection Bit[7:0]

#define INDX_SCU_CLKCR_IDIV          8
#define MASK_SCU_CLKCR_IDIV          (WORD)( 0xFFu << INDX_SCU_CLKCR_IDIV )      ///< Divider Selection Bit[15:8]

#define INDX_SCU_CLKCR_PCLKSEL       16
#define MASK_SCU_CLKCR_PCLKSEL       (WORD)( 0x1u << INDX_SCU_CLKCR_PCLKSEL )    ///< PCLK Clock Select 

#define INDX_SCU_CLKCR_RTCCLKSEL     17
#define MASK_SCU_CLKCR_RTCCLKSEL     (WORD)( 0x7u << INDX_SCU_CLKCR_RTCCLKSEL )  ///< RTC Clock Select Bit[19:17]

#define INDX_SCU_CLKCR_CNTADJ        20
#define MASK_SCU_CLKCR_CNTADJ        (WORD)( 0x3FFu << INDX_SCU_CLKCR_CNTADJ )   ///< Counter Adjustment Bit[29:20]

#define INDX_SCU_CLKCR_VDDC2LOW      30
#define MASK_SCU_CLKCR_VDDC2LOW      (WORD)( 0x1u << INDX_SCU_CLKCR_VDDC2LOW )   ///< VDDC too low

#define INDX_SCU_CLKCR_VDDC2HIGH     31
#define MASK_SCU_CLKCR_VDDC2HIGH     (WORD)( 0x1u << INDX_SCU_CLKCR_VDDC2HIGH )  ///< VDDC too high


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

