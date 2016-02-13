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
// RB_NVM.h
//

/// \file RB_NVM.h


#ifndef __RB_NVM_H__
# define __RB_NVM_H__

#include "Compiler.h"


/// Datentyp fuer NVM-Registerbank (Non Volatile Memory) , s. Reference Manual Table 8-3 ( Page 8-9),
typedef struct __regbank_NVM{

  HWRD STATUS;
  HWRD reserved01;

  HWRD PROG;
  HWRD reserved02;

  HWRD CONF;

}RegbankTypeNVM;

extern RegbankTypeNVM volatile rbNVM;               ///< Non Volatile Memory - Registers.


// --------------------------------  NVM_NVMSTATUS  ------------------------------- //
#define INDX_NVM_NVMSTATUS_BUSY                0
#define MASK_NVM_NVMSTATUS_BUSY                (HWRD)(0x01u << INDX_NVM_NVMSTATUS_BUSY)     ///< NVMSTATUS BUSY Mask

#define INDX_NVM_NVMSTATUS_SLEEP               1
#define MASK_NVM_NVMSTATUS_SLEEP               (HWRD)(0x01u << INDX_NVM_NVMSTATUS_SLEEP)    ///< NVMSTATUS: SLEEP Mask

#define INDX_NVM_NVMSTATUS_VERR                2
#define MASK_NVM_NVMSTATUS_VERR                (HWRD)(0x03u << INDX_NVM_NVMSTATUS_VERR)     ///< NVMSTATUS: VERR Mask

#define INDX_NVM_NVMSTATUS_ECC1READ            4
#define MASK_NVM_NVMSTATUS_ECC1READ            (HWRD)(0x01u << INDX_NVM_NVMSTATUS_ECC1READ)

#define INDX_NVM_NVMSTATUS_ECC2READ            5
#define MASK_NVM_NVMSTATUS_ECC2READ            (HWRD)(0x01u << INDX_NVM_NVMSTATUS_ECC2READ)

#define INDX_NVM_NVMSTATUS_WRPERR              6
#define MASK_NVM_NVMSTATUS_WRPERR              (HWRD)(0x01u << INDX_NVM_NVMSTATUS_WRPERR)

// ---------------------------------  NVM_NVMPROG  -------------------------------- //
#define INDX_NVM_NVMPROG_ACTION                0
#define MASK_NVM_NVMPROG_ACTION                (HWRD)(0xFFu << INDX_NVM_NVMPROG_ACTION)

#define INDX_NVM_NVMPROG_RSTVERR               12
#define MASK_NVM_NVMPROG_RSTVERR               (HWRD)(0x01u << INDX_NVM_NVMPROG_RSTVERR)

#define INDX_NVM_NVMPROG_RSTECC                13
#define MASK_NVM_NVMPROG_RSTECC                (HWRD)(0x01u << INDX_NVM_NVMPROG_RSTECC)

// ---------------------------------  NVM_NVMCONF  -------------------------------- //
#define INDX_NVM_NVMCONF_HRLEV                 1
#define MASK_NVM_NVMCONF_HRLEV                 (HWRD)(0x03u << INDX_NVM_NVMCONF_HRLEV)

#define INDX_NVM_NVMCONF_SECPROT               4
#define MASK_NVM_NVMCONF_SECPROT               (HWRD)(0xFFu << INDX_NVM_NVMCONF_SECPROT)

#define INDX_NVM_NVMCONF_INT_ON                14
#define MASK_NVM_NVMCONF_INT_ON                (HWRD)(0x01u << INDX_NVM_NVMCONF_INT_ON)

#define INDX_NVM_NVMCONF_NVM_ON                15
#define MASK_NVM_NVMCONF_NVM_ON                (HWRD)(0x01u << INDX_NVM_NVMCONF_NVM_ON)


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
