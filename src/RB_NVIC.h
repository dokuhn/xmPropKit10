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
///  RB_NVIC.h
///
/// \file RB_NVIC.h

#ifndef __RB_NVIC_H__
#define __RB_NVIC_H__

#include "Compiler.h"

/// The IPR0 - IPR7 registers provide a 8-bit priority field for each interrupt node. Each registers holds four priority fields.
/// Each priority field holds a priority value, 0 - 192. The lower the value, the greater the priority of the corresponding node.
/// The processor implements only bits [7:6] of each field, bits[5:0] reads as 0 and ignores writes. This means writing 255 to
/// a priority register saves value 192 to the register.

// --------------------------------  IPRx  ------------------------------- //

#define INDX_NVIC_IPRx_PRI_0           0
#define MASK_NVIC_IPRx_PRI_0           (WORD)( 0xFFu << INDX_NVIC_IPRx_PRI_0 )     ///< priority, Byte Offset 0

#define INDX_NVIC_IPRx_PRI_1           8
#define MASK_NVIC_IPRx_PRI_1           (WORD)( 0xFFu << INDX_NVIC_IPRx_PRI_1 )    ///< priority, Byte Offset 1

#define INDX_NVIC_IPRx_PRI_2           16
#define MASK_NVIC_IPRx_PRI_2           (WORD)( 0xFFu << INDX_NVIC_IPRx_PRI_2 )    ///< priority, Byte Offset 2

#define INDX_NVIC_IPRx_PRI_3           24
#define MASK_NVIC_IPRx_PRI_3           (WORD)( 0xFFu << INDX_NVIC_IPRx_PRI_3 )    ///< priority, Byte Offset 3





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
