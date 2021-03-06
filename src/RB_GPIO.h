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
///  RB_GPIO.h
///
/// \file RB_GPIO.h


#ifndef __RB_GPIO_H__
#define __RB_GPIO_H__

#include "Compiler.h"


/// Datentyp für GPIO-Registerbank, s. Reference Manual Table 18-3.
typedef struct __regbank_GPIO
{

  WORD OUT;                     ///< Port n Output Register
  WORD OMR;                     ///< Port n Output Modification Register

  WORD reserved00;
  WORD reserved01;

  WORD IOCR0;                  ///< Port n Input / Output Control Register 0
  WORD IOCR4;                  ///< Port n Input / Output Control Register 4
  WORD IOCR8;                  ///< Port n Input / Output Control Register 8
  WORD IOCR12;                 ///< Port n Input / Output Control Register 12

  WORD reserved02;
  WORD IN;                     ///< Port n Input Register

  WORD reserved03;
  WORD reserved04;
  WORD reserved05;
  WORD reserved06;
  WORD reserved07;
  WORD reserved08;

  WORD PHCR0;                  ///< Port n Pad Hysteresis Control Register 0
  WORD PHCR1;                  ///< Port n Pad Hysteresis Control Register 1

  WORD reserved09;
  WORD reserved10;
  WORD reserved11;
  WORD reserved12;
  WORD reserved13;
  WORD reserved14;

  WORD PDISC;                  ///< Port n Pin Function Decision Control Register (ADC ports)

  WORD reserved15;
  WORD reserved16;
  WORD reserved17;

  WORD PPS;                   ///< Port n Pin Power Save Register

  WORD reserved18;

  WORD HWSEL;                 ///< Port n Hardware Select Register

}RegbankTypeGPIO;

extern RegbankTypeGPIO volatile rbGPIOp0;               ///< GPIO_P0-Registerbank.
extern RegbankTypeGPIO volatile rbGPIOp1;               ///< GPIO_P1-Registerbank.
extern RegbankTypeGPIO volatile rbGPIOp2;               ///< GPIO_P2-Registerbank.


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
