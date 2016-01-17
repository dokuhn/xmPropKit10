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
// RB_USIC.h
//

/// \file RB_USIC.h


#ifndef __RB_USIC_H__
# define __RB_USIC_H__

#include "Compiler.h"


// Datentyp für USIC-Registerbank, s. Manual.

typedef struct __regbank_USIC
{
  WORD reserved00;
  
  WORD CCFG;

  WORD ID;

  WORD KSCFG;

  WORD FDR;

  WORD BRG;

  WORD INPR;

  WORD DX0CR;
  WORD DX1CR;
  WORD DX2CR;
  WORD DX3CR;
  WORD DX4CR;
  WORD DX5CR;

  WORD SCTR;

  WORD TCSR;

  WORD PCR;

  WORD CCR;

  WORD CMTR;

  WORD PSR;

  WORD PSCR;

  WORD RBUFSR;
  WORD RBUF;

  WORD RBUFD;
  WORD RBUF0;
  WORD RBUF1;
  WORD RBUF01SR;

  WORD FMR;

  /*
  #define USIC0_CH0_FMR		REGISTER_32(USIC0_CH0_BASE + 0x068)
  // USIC0_CH0_TBUF IS AN ARRAY OF 32 WORDS (INDEX 0 TO 31)
  #define USIC0_CH0_TBUF		PTR_32(USIC0_CH0_BASE + 0x080)
  #define USIC0_CH0_BYP		REGISTER_32(USIC0_CH0_BASE + 0x100)
  #define USIC0_CH0_BYPCR		REGISTER_32(USIC0_CH0_BASE + 0x104)
  #define USIC0_CH0_TBCTR		REGISTER_32(USIC0_CH0_BASE + 0x108)
  #define USIC0_CH0_RBCTR		REGISTER_32(USIC0_CH0_BASE + 0x10c)
  #define USIC0_CH0_TRBPTR	REGISTER_32(USIC0_CH0_BASE + 0x110)
  #define USIC0_CH0_TRBSR		REGISTER_32(USIC0_CH0_BASE + 0x114)
  #define USIC0_CH0_TRBSCR	REGISTER_32(USIC0_CH0_BASE + 0x118)
  #define USIC0_CH0_OUTR		REGISTER_32(USIC0_CH0_BASE + 0x11c)
  #define USIC0_CH0_OUTDR		REGISTER_32(USIC0_CH0_BASE + 0x120)
  #define USIC0_CH0_IN		PTR_32(USIC0_CH0_BASE + 0x180)
  */

} RegbankTypeUSIC;


extern RegbankTypeUSIC volatile rbUSIC0_CH0;            ///< USIC0-Channel0-Registerbank.
extern RegbankTypeUSIC volatile rbUSIC0_CH1;


/* --------------------------------  USIC_CCR  ------------------------------- */
#define INDX_USIC_CH_CCR_MODE         0
#define MASK_USIC_CH_CCR_MODE         (WORD)( 0xFu << INDX_USIC_CH_CCR_MODE )     ///< Operating Mode Bit[3:0]

#define INDX_USIC_CH_CCR_HPCEN        6
#define MASK_USIC_CH_CCR_HPCEN        (WORD)( 0x3u << INDX_USIC_CH_CCR_HPCEN )    ///< Hardware Port Control Enable Bit[7:6]

#define INDX_USIC_CH_CCR_PM           8
#define MASK_USIC_CH_CCR_PM           (WORD)( 0x3u << INDX_USIC_CH_CCR_PM )       ///< Parity Mode Bit[9:8]

#define INDX_USIC_CH_CCR_RSIEN        10
#define MASK_USIC_CH_CCR_RSIEN        (WORD)( 0x1u << INDX_USIC_CH_CCR_RSIEN )    ///< Receiver Start Interrupt Enable

#define INDX_USIC_CH_CCR_DLIEN        11
#define MASK_USIC_CH_CCR_DLIEN        (WORD)( 0x1u << INDX_USIC_CH_CCR_DLIEN )    ///< Data Lost Interrupt Enable

#define INDX_USIC_CH_CCR_TSIEN        12
#define MASK_USIC_CH_CCR_TSIEN        (WORD)( 0x1u << INDX_USIC_CH_CCR_TSIEN )    ///< Transmit Shift Interrupt Enable

#define INDX_USIC_CH_CCR_TBIEN        13
#define MASK_USIC_CH_CCR_TBIEN        (WORD)( 0x1u << INDX_USIC_CH_CCR_TBIEN )    ///< Transmit Buffer Interrupt Enable

#define INDX_USIC_CH_CCR_RIEN         14
#define MASK_USIC_CH_CCR_RIEN         (WORD)( 0x1u << INDX_USIC_CH_CCR_RIEN )     ///< Receive Interrupt Enable

#define INDX_USIC_CH_CCR_AIEN         15
#define MASK_USIC_CH_CCR_AIEN         (WORD)( 0x1u << INDX_USIC_CH_CCR_AIEN )     ///< Alternative Receive Interrupt Enable

#define INDX_USIC_CH_CCR_BRGIEN       16
#define MASK_USIC_CH_CCR_BRGIEN       (WORD)( 0x1u << INDX_USIC_CH_CCR_BRGIEN )   ///< Baud Rate Generator Interrupt Enable

/* --------------------------------  USIC_CCFG  ------------------------------- */
#define INDX_USIC_CH_CCFG_SSC         0
#define MASK_USIC_CH_CCFG_SSC         (WORD)( 0x1u << INDX_USIC_CH_CCFG_SSC )     ///< SSC Protocol Available

#define INDX_USIC_CH_CCFG_ASC         1
#define MASK_USIC_CH_CCFG_ASC         (WORD)( 0x1u << INDX_USIC_CH_CCFG_ASC )     ///< ASC Protocol Available

#define INDX_USIC_CH_CCFG_IIC         2
#define MASK_USIC_CH_CCFG_IIC         (WORD)( 0x1u << INDX_USIC_CH_CCFG_IIC )     ///< IIC Protocol Available

#define INDX_USIC_CH_CCFG_IIS         3
#define MASK_USIC_CH_CCFG_IIS         (WORD)( 0x1u << INDX_USIC_CH_CCFG_IIS )     ///< IIS Protocol Available

#define INDX_USIC_CH_CCFG_RB          6
#define MASK_USIC_CH_CCFG_RB          (WORD)( 0x1u << INDX_USIC_CH_CCFG_RB )      ///< Receive FIFO Buffer Available

#define INDX_USIC_CH_CCFG_TB          7
#define MASK_USIC_CH_CCFG_TB          (WORD)( 0x1u << INDX_USIC_CH_CCFG_TB )      ///< Transmit FIFO Buffer Available

/* --------------------------------  USIC_KSCFG  ------------------------------- */
#define INDX_USIC_CH_KSCFG_MODEN      0
#define MASK_USIC_CH_KSCFG_MODEN      (WORD)( 0x1u << INDX_USIC_CH_KSCFG_MODEN )    ///< Module Enable

#define INDX_USIC_CH_KSCFG_BPMODEN    1
#define MASK_USIC_CH_KSCFG_BPMODEN    (WORD)( 0x1u << INDX_USIC_CH_KSCFG_BPMODEN )  ///< Bit Protection for MODEN 

#define INDX_USIC_CH_KSCFG_NOMCFG     4
#define MASK_USIC_CH_KSCFG_NOMCFG     (WORD)( 0x3u << INDX_USIC_CH_KSCFG_NOMCFG )   ///< Normal Operation Mode Config. Bit[5:4]

#define INDX_USIC_CH_KSCFG_BPNOM      7
#define MASK_USIC_CH_KSCFG_BPNOM      (WORD)( 0x1u << INDX_USIC_CH_KSCFG_BPNOM )    ///< Bit Protection for NOMCFG

#define INDX_USIC_CH_KSCFG_SUMCFG     8
#define MASK_USIC_CH_KSCFG_SUMCFG     (WORD)( 0x3u << INDX_USIC_CH_KSCFG_SUMCFG )   ///< Suspend Mode Configuration

#define INDX_USIC_CH_KSCFG_BPSUM      11
#define MASK_USIC_CH_KSCFG_BPSUM      (WORD)( 0x1u << INDX_USIC_CH_KSCFG_BPSUM )    ///< Bit Protection for SUMCFG


/* --------------------------------  USIC_INPR  ------------------------------- */
/* --------------    INPR - Interrupt Node Pointer Register    ---------------- */
#define INDX_USIC_CH_INPR_TSINP       0
#define MASK_USIC_CH_INPR_TSINP       (WORD)( 0x7u << INDX_USIC_CH_INPR_TSINP )    ///< Transmit Shift Interrupt Node Pointer, Bit[2:0]

#define INDX_USIC_CH_INPR_TBINP       4
#define MASK_USIC_CH_INPR_TBINP       (WORD)( 0x7u << INDX_USIC_CH_INPR_TBINP )    ///< Transmit Buffer Interrupt Node Pointer, Bit[6:4]

#define INDX_USIC_CH_INPR_RINP        8
#define MASK_USIC_CH_INPR_RINP        (WORD)( 0x7u << INDX_USIC_CH_INPR_RINP )     ///< Receive Interrupt Node Pointer, Bit[10:8]

#define INDX_USIC_CH_INPR_AINP        12
#define MASK_USIC_CH_INPR_AINP        (WORD)( 0x7u << INDX_USIC_CH_INPR_AINP )     ///< Alternative Receive Interrupt Node Pointer, Bit[14:12]

#define INDX_USIC_CH_INPR_PINP        16
#define MASK_USIC_CH_INPR_PINP        (WORD)( 0x7u << INDX_USIC_CH_INPR_PINP )     ///< Protocol Interrupt Node Pointer, Bit[18:16]

/* --------------------------------  USIC_DX0CR  ------------------------------- */
#define INDX_USIC_CH_DX0CR_DSEL       0
#define MASK_USIC_CH_DX0CR_DSEL       (WORD)( 0x7u << INDX_USIC_CH_DX0CR_DSEL )    ///< Data Selection for Input Signal, Bit[2:0]

#define INDX_USIC_CH_DX0CR_INSW       4
#define MASK_USIC_CH_DX0CR_INSW       (WORD)( 0x1u << INDX_USIC_CH_DX0CR_INSW )    ///< Input Switch

#define INDX_USIC_CH_DX0CR_DFEN       5
#define MASK_USIC_CH_DX0CR_DFEN       (WORD)( 0x1u << INDX_USIC_CH_DX0CR_DFEN )    ///< Digital Filter Enable


/* --------------------------------  USIC_FDR  ------------------------------- */
#define INDX_USIC_CH_FDR_STEP         0
#define MASK_USIC_CH_FDR_STEP         (WORD)( 0x3FFu << INDX_USIC_CH_FDR_STEP )   ///< Step Value

#define INDX_USIC_CH_FDR_DM           14
#define MASK_USIC_CH_FDR_DM           (WORD)( 0x3u << INDX_USIC_CH_FDR_DM )       ///< Divider Mode

#define MASK_USIC_CH_FDR_DM_OFF       (WORD)( 0x3u << INDX_USIC_CH_FDR_DM )       ///< Divider is switched off
#define MASK_USIC_CH_FDR_DM_NORMAL    (WORD)( 0x1u << INDX_USIC_CH_FDR_DM )       ///< Normal divider mode selected
#define MASK_USIC_CH_FDR_DM_FRAC      (WORD)( 0x2u << INDX_USIC_CH_FDR_DM )       ///< Fractional divider mode selected

/* --------------------------------  USIC_BRG  ------------------------------- */
#define INDX_USIC_CH_BRG_CLKSEL       0

#define INDX_USIC_CH_BRG_TMEN         3

#define INDX_USIC_CH_BRG_PPPEN        4

#define INDX_USIC_CH_BRG_CTQSEL       6

#define INDX_USIC_CH_BRG_PCTQ         8

#define INDX_USIC_CH_BRG_DCTQ         10

#define INDX_USIC_CH_BRG_PDIV         16


/* ---------------------------------------------------------------------------- */


#define USIC_CH_TCSR_TDEN_POS         (WORD)(10u)       
#define USIC_CH_TCSR_TDSSM_MASK       (WORD)(0x100)      
#define SET_TDV                       (WORD)(1u)        // Transmisson data valid 
#define USIC0_CH1_DX0CR_DSEN_MASK     (WORD)(0x1u << 6)


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
