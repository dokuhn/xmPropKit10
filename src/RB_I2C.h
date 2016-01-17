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
// RB_I2C.h
//

/// \file RB_I2C.h


#ifndef __RB_I2C_H__
# define __RB_I2C_H__

#include "Compiler.h"

/* --------------------------------  USIC_PCR  ------------------------------- */
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

/* --------------------------------  USIC_PSR  ------------------------------- */
#define INDX_I2C_PSR_SLSEL            0
#define MASK_I2C_PSR_SLSEL            (WORD)( 0x1u << INDX_I2C_PSR_SLSEL )    ///< Slave Select

#define INDX_I2C_PSR_WTDF             1
#define MASK_I2C_PSR_WTDF             (WORD)( 0x1u << INDX_I2C_PSR_WTDF )     ///< Wrong TDF Code Found

#define INDX_I2C_PSR_SCR              2
#define MASK_I2C_PSR_SCR              (WORD)( 0x1u << INDX_I2C_PSR_SCR )      ///< Start Condition Received

#define INDX_I2C_PSR_RSCR             3
#define MASK_I2C_PSR_RSCR             (WORD)( 0x1u << INDX_I2C_PSR_RSCR )     ///< Repeated Start Condition Received

#define INDX_I2C_PSR_PCR              4
#define MASK_I2C_PSR_PCR              (WORD)( 0x1u << INDX_I2C_PSR_PCR )      ///< Stop Condition Received

#define INDX_I2C_PSR_NACK             5
#define MASK_I2C_PSR_NACK             (WORD)( 0x1u << INDX_I2C_PSR_NACK )     ///< Non-Acknowledge Received

#define INDX_I2C_PSR_ARL              6
#define MASK_I2C_PSR_ARL              (WORD)( 0x1u << INDX_I2C_PSR_NACK )     ///< Arbitration Lost

#define INDX_I2C_PSR_SRR              7
#define MASK_I2C_PSR_SRR              (WORD)( 0x1u << INDX_I2C_PSR_SRR )      ///< Slave Read Request

#define INDX_I2C_PSR_ERR              8
#define MASK_I2C_PSR_ERR              (WORD)( 0x1u << INDX_I2C_PSR_ERR )      ///< Error

#define INDX_I2C_PSR_ACK              9
#define MASK_I2C_PSR_ACK              (WORD)( 0x1u << INDX_I2C_PSR_ACK )      ///< Acknowledge Received

#define INDX_I2C_PSR_RSIF             10
#define MASK_I2C_PSR_RSIF             (WORD)( 0x1u << INDX_I2C_PSR_RSIF )     ///< Receiver Start Indication Flag

#define INDX_I2C_PSR_DLIF             11
#define MASK_I2C_PSR_DLIF             (WORD)( 0x1u << INDX_I2C_PSR_DLIF )     ///< Data Lost Indication Flag

#define INDX_I2C_PSR_TSIF             12
#define MASK_I2C_PSR_TSIF             (WORD)( 0x1u << INDX_I2C_PSR_TSIF )     ///< Transmit Shift Indication Flag

#define INDX_I2C_PSR_TBIF             13
#define MASK_I2C_PSR_TBIF             (WORD)( 0x1u << INDX_I2C_PSR_TBIF )     ///< Transmit Buffer Indication Flag

#define INDX_I2C_PSR_RIF              14
#define MASK_I2C_PSR_RIF              (WORD)( 0x1u << INDX_I2C_PSR_RIF )      ///< Receive Indication Flag

#define INDX_I2C_PSR_AIF              15
#define MASK_I2C_PSR_AIF              (WORD)( 0x1u << INDX_I2C_PSR_AIF )      ///< Alternative Receive Indication Flag

#define INDX_I2C_PSR_BRGIF            16
#define MASK_I2C_PSR_BRGIF            (WORD)( 0x1u << INDX_I2C_PSR_BRGIF )    ///< Baud Rate Generator Indication Flag

/* --------------------------------  USIC_SCTR  ------------------------------- */
#define INDX_I2C_SCTR_SDIR            0
#define MASK_I2C_SCTR_SDIR            (WORD)( 0x1u << INDX_I2C_SCTR_SDIR )    ///< Shift Direction ( 0 = LSB fisrt ; 1 = MSB first )

#define INDX_I2C_SCTR_PDL             1
#define MASK_I2C_SCTR_PDL             (WORD)( 0x1u << INDX_I2C_SCTR_PDL )     ///< Passive Data Level  (not needed)

#define INDX_I2C_SCTR_DSM             2
#define MASK_I2C_SCTR_DSM             (WORD)( 0x3u << INDX_I2C_SCTR_DSM )     ///< Data Shift Mode Bit[3:2] (not needed)

#define INDX_I2C_SCTR_HPCDIR          4
#define MASK_I2C_SCTR_HPCDIR          (WORD)( 0x1u << INDX_I2C_SCTR_HPCDIR )  ///< Port Control Direction (not needed)

#define INDX_I2C_SCTR_DOCFG           6
#define MASK_I2C_SCTR_DOCFG           (WORD)( 0x3u << INDX_I2C_SCTR_DOCFG )   ///< Data Output Configuration (not needed)

#define INDX_I2C_SCTR_TRM             8
#define MASK_I2C_SCTR_TRM             (WORD)( 0x3u << INDX_I2C_SCTR_TRM )     ///< Transmission Mode

#define INDX_I2C_SCTR_FLE             16
#define MASK_I2C_SCTR_FLE             (WORD)( 0x3Fu << INDX_I2C_SCTR_FLE )    ///< Frame Length

#define INDX_I2C_SCTR_WLE             24
#define MASK_I2C_SCTR_WLE             (WORD)( 0xFu << INDX_I2C_SCTR_WLE )     ///< Word Length


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
