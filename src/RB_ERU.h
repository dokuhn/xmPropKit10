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
///  RB_ERU.h
///
/// \file RB_ERU.h

#ifndef __RB_ERU_H__
#define __RB_ERU_H__

#include <Compiler.h>


/// Datentyp fuer ERU-Registerbank (Event Request Unit) , s. Reference Manual Table 6-2,
typedef struct __regbank_ERU
{

  WORD EXISEL;           ///< ERU Event Input Select

  WORD reserved00;
  WORD reserved01;
  WORD reserved02;

  WORD EXICON0;         ///< ERU Event Input Control 0

  WORD EXICON1;         ///< ERU Event Input Control 1

  WORD EXICON2;         ///< ERU Event Input Control 2

  WORD EXICON3;         ///< ERU Event Input Control 3

  WORD EXOCON0;         ///< ERU Event Output Trigger Control 0

  WORD EXOCON1;         ///< ERU Event Output Trigger Control 1

  WORD EXOCON2;         ///< ERU Event Output Trigger Control 2

  WORD EXOCON3;         ///< ERU Event Output Trigger Control 3

}RegbankTypeERU;


extern RegbankTypeERU volatile rbERU;               ///< Event Request Unit - Registers.


// --------------------------------  EXISEL   ------------------------------- //

#define INDX_ERU_EXISEL_EXS0A         0
#define MASK_ERU_EXISEL_EXS0A         (WORD)( 0x3u << INDX_ERU_EXISEL_EXS0A )  ///< Event Source Select for A0, Bit[1:0]

#define INDX_ERU_EXISEL_EXS0B         2
#define MASK_ERU_EXISEL_EXS0B         (WORD)( 0x3u << INDX_ERU_EXISEL_EXS0B )  ///< Event Source Select for B0, Bit[3:2]

#define INDX_ERU_EXISEL_EXS1A         4
#define MASK_ERU_EXISEL_EXS1A         (WORD)( 0x3u << INDX_ERU_EXISEL_EXS1A )  ///< Event Source Select for A1, Bit[5:4]

#define INDX_ERU_EXISEL_EXS1B         6
#define MASK_ERU_EXISEL_EXS1B         (WORD)( 0x3u << INDX_ERU_EXISEL_EXS1B )  ///< Event Source Select for B1, Bit[7:6]

#define INDX_ERU_EXISEL_EXS2A         8
#define MASK_ERU_EXISEL_EXS2A         (WORD)( 0x3u << INDX_ERU_EXISEL_EXS2A )  ///< Event Source Select for A2, Bit[9:8]

#define INDX_ERU_EXISEL_EXS2B         10
#define MASK_ERU_EXISEL_EXS2B         (WORD)( 0x3u << INDX_ERU_EXISEL_EXS2B )  ///< Event Source Select for B2, Bit[11:10]

#define INDX_ERU_EXISEL_EXS3A         12
#define MASK_ERU_EXISEL_EXS3A         (WORD)( 0x3u << INDX_ERU_EXISEL_EXS3A )  ///< Event Source Select for A3, Bit[13:12]

#define INDX_ERU_EXISEL_EXS3B         14
#define MASK_ERU_EXISEL_EXS3B         (WORD)( 0x3u << INDX_ERU_EXISEL_EXS3B )  ///< Event Source Select for B3, Bit[15:14]

// --------------------------------  EXICONx  ------------------------------- //

#define INDX_ERU_EXICONx_PE           0
#define MASK_ERU_EXICONx_PE           (WORD)( 0x1u << INDX_ERU_EXICONx_PE )    ///< Output Trigger Pulse Enable for ETLx

#define INDX_ERU_EXICONx_LD           1
#define MASK_ERU_EXICONx_LD           (WORD)( 0x1u << INDX_ERU_EXICONx_LD )    ///< Rebuild Level Detection for Status Flag for ETLx

#define INDX_ERU_EXICONx_RE           2
#define MASK_ERU_EXICONx_RE           (WORD)( 0x1u << INDX_ERU_EXICONx_RE )    ///< Rising Edge Detection Enable ETLx

#define INDX_ERU_EXICONx_FE           3
#define MASK_ERU_EXICONx_FE           (WORD)( 0x1u << INDX_ERU_EXICONx_FE )    ///< Falling Edge Detection Enable ETLx

#define INDX_ERU_EXICONx_OCS          4
#define MASK_ERU_EXICONx_OCS          (WORD)( 0x7u << INDX_ERU_EXICONx_OCS )   ///< Output Channel Select for ETLx Output Trig. Pulse, Bit[6:4]

#define INDX_ERU_EXICONx_FL           7
#define MASK_ERU_EXICONx_FL           (WORD)( 0x1u << INDX_ERU_EXICONx_FL )    ///< Status Flag for ETLx

#define INDX_ERU_EXICONx_SS           8
#define MASK_ERU_EXICONx_SS           (WORD)( 0x3u << INDX_ERU_EXICONx_SS )    ///< Input Source Select for ERSx, Bit[9:8]

#define INDX_ERU_EXICONx_NA           10
#define MASK_ERU_EXICONx_NA           (WORD)( 0x1u << INDX_ERU_EXICONx_NA )    ///< Input A Negation Select for ERSx

#define INDX_ERU_EXICONx_NB           11
#define MASK_ERU_EXICONx_NB           (WORD)( 0x1u << INDX_ERU_EXICONx_NB )    ///< Input B Negation Select for ERSx

// ---------------------------------  EXOCONx  ------------------------------ //

#define INDX_ERU_EXOCONx_ISS          0
#define MASK_ERU_EXOCONx_ISS          (WORD)( 0x3u << INDX_ERU_EXOCONx_ISS )   ///< Internal Trigger Source Selection

#define INDX_ERU_EXOCONx_GEEN         2
#define MASK_ERU_EXOCONx_GEEN         (WORD)( 0x1u << INDX_ERU_EXOCONx_GEEN )  ///< Gating Event Enable

#define INDX_ERU_EXOCONx_PDR          3
#define MASK_ERU_EXOCONx_PDR          (WORD)( 0x1u << INDX_ERU_EXOCONx_PDR )   ///< Pattern Detection Result Flag

#define INDX_ERU_EXOCONx_GP           4
#define MASK_ERU_EXOCONx_GP           (WORD)( 0x3u << INDX_ERU_EXOCONx_GP )    ///< Gating Selection for Pattern Detection Result

#define INDX_ERU_EXOCONx_IPEN0        12
#define MASK_ERU_EXOCONx_IPEN0        (WORD)( 0x1u << INDX_ERU_EXOCONx_IPEN0 ) ///< Pattern Detection Enable for ETL0

#define INDX_ERU_EXOCONx_IPEN1        13
#define MASK_ERU_EXOCONx_IPEN1        (WORD)( 0x1u << INDX_ERU_EXOCONx_IPEN1 ) ///< Pattern Detection Enable for ETL1

#define INDX_ERU_EXOCONx_IPEN2        14
#define MASK_ERU_EXOCONx_IPEN2        (WORD)( 0x1u << INDX_ERU_EXOCONx_IPEN2 ) ///< Pattern Detection Enable for ETL2

#define INDX_ERU_EXOCONx_IPEN3        15
#define MASK_ERU_EXOCONx_IPEN3        (WORD)( 0x1u << INDX_ERU_EXOCONx_IPEN3 ) ///< Pattern Detection Enable for ETL3



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
