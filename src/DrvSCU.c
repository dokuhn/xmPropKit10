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
#include <DrvSCU.h>

/*--------------------------------------------------------
  Clock Global defines
 *--------------------------------------------------------*/
#define DC0_DCLK         (WORD)(64000000u)
#define MCLK_MHZ         (WORD)(32000000u)

/*-------------------------------------------------------
  Clock Variables definitions
 *-------------------------------------------------------*/
WORD SystemCoreClock;


void SystemCoreClockUpdate(void){
  WORD IDIV, FDIV;

  IDIV = ( (SCU_CLKCR & MASK_SCU_CLKCR_IDIV) >> INDX_SCU_CLKCR_IDIV );
  FDIV = ( (SCU_CLKCR & MASK_SCU_CLKCR_FDIV) >> INDX_SCU_CLKCR_FDIV );

  if(IDIV){
    /* Fractional divider is enabled and used */
    SystemCoreClock = (  (MCLK_MHZ << 7) / ( (IDIV << 8) + FDIV )  ) << 1;
  }else{
    /* Fractional divider bypassed. Simply divide DC0_DCLK by 2 */
    SystemCoreClock = MCLK_MHZ;
  }
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
