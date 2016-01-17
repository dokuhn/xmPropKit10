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


/// Datentyp für GPIO-Registerbank, s. Reference Manual,
typedef struct __regbank_GPIO
{

  WORD OUT;
  WORD OMR;

  WORD reserved00;
  WORD reserved01;

  WORD IOCR0;
  WORD IOCR4;
  WORD IOCR8;
  WORD IOCR12;

  WORD reserved02;
  WORD IN;

  WORD reserved03;
  WORD reserved04;
  WORD reserved05;
  WORD reserved06;
  WORD reserved07;
  WORD reserved08;

  WORD PHCR0;
  WORD PHCR1;

  WORD reserved09;
  WORD reserved10;
  WORD reserved11;
  WORD reserved12;
  WORD reserved13;
  WORD reserved14;

  WORD PDISC;

  WORD reserved15;
  WORD reserved16;
  WORD reserved17;

  WORD PPS;

  WORD reserved18;

  WORD HWSEL;

}RegbankTypeGPIO;

extern RegbankTypeGPIO volatile rbGPIOp0;               ///< GPIO_P0-Registerbank.
extern RegbankTypeGPIO volatile rbGPIOp1;               ///< GPIO_P1-Registerbank.
extern RegbankTypeGPIO volatile rbGPIOp2;               ///< GPIO_P2-Registerbank.


/* --------------------------------  USIC_PCR  ------------------------------- */
/*

#define INDX_I2C_PCR_SLAD             0 
#define MASK_I2C_PCR_SLAD             (WORD)( 0xFFFFu << INDX_I2C_PCR_SLAD )    ///< Slave Address Bit[15:0]

#define INDX_I2C_PCR_ACK00            16 
#define MASK_I2C_PCR_ACK00            (WORD)( 0x1u << INDX_I2C_PCR_ACK00 )   ///< Acknowledge 00H

#define INDX_I2C_PCR_STIM             17
#define MASK_I2C_PCR_STIM             (WORD)( 0x1u << INDX_I2C_PCR_STIM  )   ///< Symbol Timing

#define INDX_I2C_PCR_SCRIEN           18
#define MASK_I2C_PCR_SCRIEN           (WORD)( 0x1u << INDX_I2C_PCR_SCRIEN )  ///< Start Condition Received Interrupt Enable

#define INDX_I2C_PCR_RSCRIEN          19
#define MASK_I2C_PCR_RSCRIEN          (WORD)( 0x1u << INDX_I2C_PCR_RSCRIEN ) ///< Repeated Start Condition Received Interrupt Enable

#define INDX_I2C_PCR_PCRIEN           20
#define MASK_I2C_PCR_PCRIEN           (WORD)( 0x1u << INDX_I2C_PCR_PCRIEN )  ///< Stop Condition Received Interrupt Enable

#define INDX_I2C_PCR_NACKIEN          21
#define MASK_I2C_PCR_NACKIEN          (WORD)( 0x1u << INDX_I2C_PCR_NACKIEN ) ///< Non-Acknowledge Interrupt Enable

#define INDX_I2C_PCR_ARLIEN           22
#define MASK_I2C_PCR_ARLIEN           (WORD)( 0x1u << INDX_I2C_PCR_ARLIEN )   ///< Arbitration Lost Interrupt Enable

#define INDX_I2C_PCR_SRRIEN           23
#define MASK_I2C_PCR_SRRIEN           (WORD)( 0x1u << INDX_I2C_PCR_SRRIEN )   ///< Slave Read Request Interrupt Enable

#define INDX_I2C_PCR_ERRIEN           24
#define MASK_I2C_PCR_ERRIEN           (WORD)( 0x1u << INDX_I2C_PCR_ERRIEN )   ///< Error Interrupt Enable

#define INDX_I2C_PCR_SACKDIS          25
#define MASK_I2C_PCR_SACKDIS          (WORD)( 0x1u << INDX_I2C_PCR_SACKDIS )  ///< Slave Acknowledge Disable

#define INDX_I2C_PCR_HDEL             26
#define MASK_I2C_PCR_HDEL             (WORD)( 0xFu << INDX_I2C_PCR_HDEL )     ///< Hardware Delay Bit[29:26]

#define INDX_I2C_PCR_ACKIEN           30
#define MASK_I2C_PCR_ACKIEN           (WORD)( 0x1u << INDX_I2C_PCR_ACKIEN )   ///< Acknowledge Interrupt Enable

#define INDX_I2C_PCR_MCLK             31
#define MASK_I2C_PCR_MCLK             (WORD)( 0x1u << INDX_I2C_PCR_MCLK )     ///< Master Clock Enable

*/


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
