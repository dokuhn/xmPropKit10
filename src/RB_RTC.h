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
///  RB_RTC.h
///
/// \file RB_RTC.h

#ifndef __RB_RTC_H__
#define __RB_RTC_H__

#include "Compiler.h"


/// Datentyp fuer RTC-Registerbank, s. Reference Manual Table 11-3 ( Page 11-7 ).
typedef struct __regbank_RTC
{

  WORD ID;                ///< RTC Module ID Register

  WORD CTR;               ///< RTC Control Register

  WORD RAWSTAT;           ///< RTC Raw Service Request Register

  WORD STSSR;             ///< RTC Service Request Status Register

  WORD MSKSR;             ///< Service Request Mask Register

  WORD CLRSR;             ///< Clear Service Request Register

  WORD ATIM0;             ///< Alarm Time Register 0

  WORD ATIM1;             ///< Alarm Time Register 1

  WORD TIM0;              ///< Time Register 0

  WORD TIM1;              ///< Time Register 1

}RegbankTypeRTC;

extern RegbankTypeRTC volatile rbRTC;               ///< RTC - Registerbank.


// --------------------------------  ID ------------------------------- //
#define INDX_RTC_ID_MOD_REV           0
#define MASK_RTC_ID_MOD_REV           (WORD)( 0xFFu << INDX_RTC_ID_MOD_REV )      ///< Module Revision Number, Bits[7:0]

#define INDX_RTC_ID_MOD_TYPE          8
#define MASK_RTC_ID_MOD_TYPE          (WORD)( 0xFFu << INDX_RTC_ID_MOD_TYPE )     ///< Module Type, Bits[15:8]

#define INDX_RTC_ID_MOD_NUMBER        16
#define MASK_RTC_ID_MOD_NUMBER        (WORD)( 0xFFFFu << INDX_RTC_ID_MOD_NUMBER)  ///< Module Number Value, Bits[31:16]


// ------------------------------  CTR  --------------------------------- //
#define INDX_RTC_CTR_ENB              0
#define MASK_RTC_CTR_ENB              (WORD)( 0x1u << INDX_RTC_CTR_ENB )          ///< RTC Module Enable

#define INDX_RTC_CTR_SUS              1
#define MASK_RTC_CTR_SUS              (WORD)( 0x1u << INDX_RTC_CTR_SUS )          ///< Debug Suspend Control

#define INDX_RTC_CTR_DIV              16
#define MASK_RTC_CTR_DIV              (WORD)( 0xFFFFu << INDX_RTC_CTR_DIV )       ///< Divider Value


// -----------------------------  RAWSTAT  ----------------------------- //
#define INDX_RTC_RAWSTAT_RPSE         0
#define MASK_RTC_RAWSTAT_RPSE         (WORD)( 0x1u << INDX_RTC_RAWSTAT_RPSE )     ///< Raw Periodic Seconds Service Request

#define INDX_RTC_RAWSTAT_RPMI         1
#define MASK_RTC_RAWSTAT_RPMI         (WORD)( 0x1u << INDX_RTC_RAWSTAT_RPMI )     ///< Raw Periodic Minutes Service Request

#define INDX_RTC_RAWSTAT_RPHO         2
#define MASK_RTC_RAWSTAT_RPHO         (WORD)( 0x1u << INDX_RTC_RAWSTAT_RPHO )     ///< Raw  Periodic Hours Service Request

#define INDX_RTC_RAWSTAT_RPDA         3
#define MASK_RTC_RAWSTAT_RPDA         (WORD)( 0x1u << MASK_RTC_RAWSTAT_RPDA )     ///< Raw  Periodic Days Service Request

#define INDX_RTC_RAWSTAT_RPMO         5
#define MASK_RTC_RAWSTAT_RPMO         (WORD)( 0x1u << MASK_RTC_RAWSTAT_RPMO )     ///< Raw Periodic Months Service Request

#define INDX_RTC_RAWSTAT_RPYE         6
#define MASK_RTC_RAWSTAT_RPYE         (WORD)( 0x1u << MASK_RTC_RAWSTAT_RPYE )    ///< Raw Periodic Years Service Request

#define INDX_RTC_RAWSTAT_RAI          8
#define MASK_RTC_RAWSTAT_RAI          (WORD)( 0x1u << MASK_RTC_RAWSTAT_RAI )     ///< Alarm Service Request

// ----------------------------  STSSR ---------------------------------- //
#define INDX_RTC_STSSR_SPSE           0
#define MASK_RTC_STSSR_SPSE           (WORD)( 0x1u << INDX_RTC_STSSR_SPSE )      ///< Periodic Seconds Service Request Status after masking

#define INDX_RTC_STSSR_SPMI           1
#define MASK_RTC_STSSR_SPMI           (WORD)( 0x1u << INDX_RTC_STSSR_SPMI )      ///< Periodic Minutes Service Request Status after masking

#define INDX_RTC_STSSR_SPHO           2
#define MASK_RTC_STSSR_SPHO           (WORD)( 0x1u << INDX_RTC_STSSR_SPHO )      ///< Periodic Hours Service Request Status after masking

#define INDX_RTC_STSSR_SPDA           3
#define MASK_RTC_STSSR_SPDA           (WORD)( 0x1u << INDX_RTC_STSSR_SPDA )      ///< Periodic Days Service Request Status after masking

#define INDX_RTC_STSSR_SPMO           5
#define MASK_RTC_STSSR_SPMO           (WORD)( 0x1u << INDX_RTC_STSSR_SPMO )      ///< Periodic Months Service Request Status after masking

#define INDX_RTC_STSSR_SPYE           6
#define MASK_RTC_STSSR_SPYE           (WORD)( 0x1u << INDX_RTC_STSSR_SPYE )      ///< Periodic Years Service Request Status after masking

#define INDX_RTC_STSSR_SAI            8
#define MASK_RTC_STSSR_SAI            (WORD)( 0x1u << INDX_RTC_STSSR_SAI )       ///< Alarm Service Request Status after masking

// ----------------------------- MSKSR ----------------------------------- //
#define INDX_RTC_MSKSR_MPSE           0
#define MASK_RTC_MSKSR_MPSE           (WORD)( 0x1u << INDX_RTC_MSKSR_MPSE )      ///< Periodic Seconds Interrupt enable

#define INDX_RTC_MSKSR_MPMI           1
#define MASK_RTC_MSKSR_MPMI           (WORD)( 0x1u << INDX_RTC_MSKSR_MPMI )      ///< Periodic Minutes Interrupt enable

#define INDX_RTC_MSKSR_MPHO           2
#define MASK_RTC_MSKSR_MPHO           (WORD)( 0x1u << INDX_RTC_MSKSR_MPHO )      ///< Periodic Hours Interrupt enable

#define INDX_RTC_MSKSR_MPDA           3
#define MASK_RTC_MSKSR_MPDA           (WORD)( 0x1u << INDX_RTC_MSKSR_MPDA )      ///< Periodic Days Interrupt enable

#define INDX_RTC_MSKSR_MPMO           5
#define MASK_RTC_MSKSR_MPMO           (WORD)( 0x1u << INDX_RTC_MSKSR_MPMO )      ///< Periodic Months Interrupt enable

#define INDX_RTC_MSKSR_MPYE           6
#define MASK_RTC_MSKSR_MPYE           (WORD)( 0x1u << INDX_RTC_MSKSR_MPYE )      ///< Periodic Years Interrupt enable

#define INDX_RTC_MSKSR_MAI            8
#define MASK_RTC_MSKSR_MAI            (WORD)( 0x1u << INDX_RTC_MSKSR_MAI )       ///< Alarm Interrupt enable

// ----------------------------- CLRSR ------------------------------------ //
#define INDX_RTC_CLRSR_RPSE           0
#define MASK_RTC_CLRSR_RPSE           (WORD)( 0x1u << INDX_RTC_CLRSR_RPSE )      ///< Raw Periodic Seconds Interrupt Clear

#define INDX_RTC_CLRSR_RPMI           1
#define MASK_RTC_CLRSR_RPMI           (WORD)( 0x1u << INDX_RTC_CLRSR_RPMI )      ///< Raw Periodic Minutes Interrupt Clear

#define INDX_RTC_CLRSR_RPHO           2
#define MASK_RTC_CLRSR_RPHO           (WORD)( 0x1u << INDX_RTC_CLRSR_RPHO )      ///< Raw Periodic Hours Interrupt Clear

#define INDX_RTC_CLRSR_RPDA           3
#define MASK_RTC_CLRSR_RPDA           (WORD)( 0x1u << INDX_RTC_CLRSR_RPDA )      ///< Raw Periodic Days Interrupt Clear

#define INDX_RTC_CLRSR_RPMO           5
#define MASK_RTC_CLRSR_RPMO           (WORD)( 0x1u << INDX_RTC_CLRSR_RPMO )      ///< Raw Periodic Months Interrupt Clear

#define INDX_RTC_CLRSR_RPYE           6
#define MASK_RTC_CLRSR_RPYE           (WORD)( 0x1u << INDX_RTC_CLRSR_RPYE )      ///< Raw Periodic Years Interrupt Clear

#define INDX_RTC_CLRSR_RAI            8
#define MASK_RTC_CLRSR_RAI            (WORD)( 0x1u << INDX_RTC_CLRSR_RAI )       ///< Raw Alarm Interrupt Clear

// -----------------------------  ATIM0 ----------------------------------- //
#define INDX_RTC_ATIM0_ASE            0
#define MASK_RTC_ATIM0_ASE            (WORD)( 0x3Fu << INDX_RTC_ATIM0_ASE )       ///< Alarm Seconds Compare Value, Bits[5:0]

#define INDX_RTC_ATIM0_AMI            8
#define MASK_RTC_ATIM0_AMI            (WORD)( 0x3Fu << INDX_RTC_ATIM0_AMI )       ///< Alarm Minutes Compare Value, Bits[13:8]

#define INDX_RTC_ATIM0_AHO            16
#define MASK_RTC_ATIM0_AHO            (WORD)( 0x1Fu << INDX_RTC_ATIM0_AHO )       ///< Alarm Hours Compare Value, Bits[20:16]

#define INDX_RTC_ATIM0_ADA            24
#define MASK_RTC_ATIM0_ADA            (WORD)( 0x1Fu << INDX_RTC_ATIM0_ADA )       ///< Alarm Days Compare Value, Bits[28:24]

// -----------------------------  ATIM1  ---------------------------------- //
#define INDX_RTC_ATIM1_AMO            8
#define MASK_RTC_ATIM1_AMO            (WORD)( 0xFu << INDX_RTC_ATIM1_AMO )        ///< Alarm Month Compare Value, Bits[11:8]

#define INDX_RTC_ATIM1_AYE            16
#define MASK_RTC_ATIM1_AYE            (WORD)( 0xFFFFu << INDX_RTC_ATIM1_AYE )     ///< Alarm Year Compare Value, Bits[31:16]

// -----------------------------  TIM0  ----------------------------------- //
#define INDX_RTC_TIM0_SE               0
#define MASK_RTC_TIM0_SE               (WORD)( 0x3Fu << INDX_RTC_TIM0_SE )        ///< Seconds Time Value, Bits[5:0]

#define INDX_RTC_TIM0_MI               8
#define MASK_RTC_TIM0_MI               (WORD)( 0x3Fu << INDX_RTC_TIM0_MI )        ///< Minutes Time Value, Bits[13:8]

#define INDX_RTC_TIM0_HO               16
#define MASK_RTC_TIM0_HO               (WORD)( 0x1Fu << INDX_RTC_TIM0_HO )        ///< Hours Time Value, Bits[20:16]

#define INDX_RTC_TIM0_DA               24
#define MASK_RTC_TIM0_DA               (WORD)( 0x1Fu << INDX_RTC_TIM0_DA )        ///< Days Time Value, Bits[28:24]

// ------------------------------  TIM1  ---------------------------------- //
#define INDX_RTC_TIM1_DAWE             0
#define MASK_RTC_TIM1_DAWE             (WORD)( 0x7u << INDX_RTC_TIM1_DAWE )       ///< Days of Week Time Value, Bits[2:0]

#define INDX_RTC_TIM1_MO               8
#define MASK_RTC_TIM1_MO               (WORD)( 0xFu << INDX_RTC_TIM1_MO )         ///< Month Time Value, Bits[11:8]

#define INDX_RTC_TIM1_YE               16
#define MASK_RTC_TIM1_YE               (WORD)( 0xFFFFu << INDX_RTC_TIM1_YE )     ///< Year Time Value, Bits[31:16]


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
