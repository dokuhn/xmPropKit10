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

#include <RB_NVM.h>
#include <RB_SCU.h>
#include <DrvNVM.h>

#define WORD_SIZE     (0x4u)    /// 4 Bytes

// --------------   Private Macro Definitions  ----------------------------- //



// ROM function Table
// Start address of ROM function table,  s. Reference Manual Table XX-YY
#define ROM_FUNCTION_TABLE_START             (0x00000100u)
// Pointer to Erase Flash Page routine
#define NvmErase                             (ROM_FUNCTION_TABLE_START + 0x00u)
// Pointer to Erase, Program & Verify Flash Page routine
#define NvmProgVerify                        (ROM_FUNCTION_TABLE_START + 0x04u)
// Macro for Erase Flash Page routine
#define NvmErasePage         (*((NVM_STATUS (**) (WORD * scr_add)) NvmErase))
// Macro for ProgVerifyPage Flash Page routine
#define NvmProgVerifyPage    (*((NVM_STATUS (**) (WORD * scr_add, WORD * dst_add)) NvmProgVerify))


NVMErrCodeType  initNVM( void ){

  rbNVM.PROG  = 0x3000u;                          ///< Enabling flash Idle State

  rbNVM.PROG |= MASK_NVM_NVMPROG_RSTECC;          ///< reset ECC2READ, ECC1READ in NVMSTATUS

  rbNVM.PROG |= MASK_NVM_NVMPROG_RSTVERR;         ///< reset Write protocol error in NVMSTATUS

  return NVMNoError;
}


void clearStatusNVM( void ){




}


NVMErrCodeType writeNVM( WORD address, WORD pBuf[] ){
  NVMErrCodeType status;

  WORD rd1;
  WORD rd2;
  WORD rd3;

  WORD lWordCnt;

  rd1 = (rbNVM.PROG   & MASK_NVM_NVMPROG_ACTION)  >> INDX_NVM_NVMPROG_ACTION;
  rd2 = (rbNVM.STATUS & MASK_NVM_NVMSTATUS_BUSY)  >> INDX_NVM_NVMSTATUS_BUSY;
  rd3 = (rbNVM.STATUS & MASK_NVM_NVMSTATUS_SLEEP) >> INDX_NVM_NVMSTATUS_SLEEP;

  if( (address < NVM_START_ADDRESS) || (address > NVM_END_ADDRESS) ){

    status = NVMInvalidAddress;

  }else if( (rd1 == 0x0u) && (rd2 == 0x0u) && (rd3 == 0x0u) ){
    /* updating the ACTION with Oneshot Write and Auto Verify */
    NVM_NVMPROG =  (NVM_NVMPROG & ~MASK_NVM_NVMPROG_ACTION) | ( MASK_NVM_NVMPROG_ACTION & (0x51u << INDX_NVM_NVMPROG_ACTION) );

    /* Writing a Block of Data */
    for( lWordCnt = 0u; lWordCnt < WORD_SIZE; lWordCnt++ ){
      *((WORD *)(  address + (WORD_SIZE * lWordCnt) )) = pBuf[lWordCnt] ;
    }

    /* Polling Busy Flag until Idle State */
    while( ((NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_BUSY) >> INDX_NVM_NVMSTATUS_BUSY) != 0u);

    /* Wait for 10us to complete thw verification (need to check) */
    SCU_CLKCR = (SCU_CLKCR & ~MASK_SCU_CLKCR_CNTADJ) | (MASK_SCU_CLKCR_CNTADJ & (0x2AA << INDX_SCU_CLKCR_CNTADJ));
    while( SCU_CLKCR & MASK_SCU_CLKCR_VDDC2LOW );

    /* Checking for verification flag for any writing errors */
    if( ((NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_VERR) >> INDX_NVM_NVMSTATUS_VERR) != 0u ){
      status = NVMComplete;
    }else{
      status = NVMNoError;
    }
  }else{

    status = NVMError;
  }
  return status;
}


NVMErrCodeType readNVM( WORD address, WORD * buf ){
  NVMErrCodeType status;

  WORD rd1;
  WORD rd2;
  WORD rd3;

  rd1 = (NVM_NVMPROG   & MASK_NVM_NVMPROG_ACTION)  >> INDX_NVM_NVMPROG_ACTION;
  rd2 = (NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_BUSY)  >> INDX_NVM_NVMSTATUS_BUSY;
  rd3 = (NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_SLEEP) >> INDX_NVM_NVMSTATUS_SLEEP;

  /* validate the address for range */
  if( (address < NVM_START_ADDRESS) || (address > NVM_END_ADDRESS) ){

    status = NVMInvalidAddress;

  /* checking for status of Flash for Idle and Sleep Mode */
  }else if( (rd1 == 0x0u) && (rd2 == 0x0u) && (rd3 == 0x0u) ){
    /* reads one word */
    *buf = *((WORD*)address);

    status = NVMComplete;

    rd1 = (NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_ECC1READ) >> INDX_NVM_NVMSTATUS_ECC1READ;
    rd2 = (NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_ECC2READ) >> INDX_NVM_NVMSTATUS_ECC2READ;

    /* Checking for ECC error flags */
    if( (rd1 != 0x0u) || (rd2 != 0x0u) ){
      status = NVMError;
    }
  }else{
    status = NVMError;
  }
  return status;
}


/*
 * The function uses the ROM api to Erase
 * the one page of data
 */

NVMErrCodeType eraseNVM( WORD address ){
  NVMErrCodeType status;
  NVM_STATUS     NvmStatus;

  /* validate the Address Range */
  if( (address < NVM_START_ADDRESS) || (address > NVM_END_ADDRESS) ){
    status = NVMInvalidAddress;
  }else{
    /* Calling ROM API to Erase a Page */
    NvmStatus = NvmErasePage((WORD *) address);
    /* ---> Mapping different status returned by ROM Api to standard Return */
    if( NvmStatus == NVM_PASS){
      status = NVMComplete;
    }else if( (NvmStatus == NVM_E_FAIL) || (NvmStatus == NVM_E_NVM_FAIL) || (NvmStatus == NVM_E_VERIFY) ){
      status = NVMError;
    }else{
      status = NVMInvalidAddress;
    }
  }

  return status;

}


NVMErrCodeType readByteNVM( WORD address, BYTE buf[], WORD NoOfBytes){
  NVMErrCodeType status;
  WORD lByteCnt;
  WORD rd1;
  WORD rd2;
  WORD rd3;

  WORD finalAddlocation;

  finalAddlocation = ( address + NoOfBytes ) - 1u;

  rd1 = (NVM_NVMPROG   & MASK_NVM_NVMPROG_ACTION)  >> INDX_NVM_NVMPROG_ACTION;
  rd2 = (NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_BUSY)  >> INDX_NVM_NVMSTATUS_BUSY;
  rd3 = (NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_SLEEP) >> INDX_NVM_NVMSTATUS_SLEEP;

  /* validate the address for range  and Block Alignment*/
  if( (address < NVM_START_ADDRESS) || (address > NVM_END_ADDRESS) || (finalAddlocation > NVM_END_ADDRESS) ){
    status = NVMInvalidAddress;
  }else if( (rd1 == 0x0u) && (rd2 == 0x0u) && (rd3 == 0x0u) ){
    /* reads no of bytes specified */
    for( lByteCnt = 0u; lByteCnt < NoOfBytes; lByteCnt++ ){
      *(buf + lByteCnt) = *((BYTE*)address + lByteCnt);
      status = NVMComplete;

    }
    rd1 = (NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_ECC1READ)  >> INDX_NVM_NVMSTATUS_ECC1READ;
    rd2 = (NVM_NVMSTATUS & MASK_NVM_NVMSTATUS_ECC2READ)  >> INDX_NVM_NVMSTATUS_ECC2READ;

    /* checking for ECC error flags */
    if( (rd1 != 0x0u) || (rd2 != 0x0u) ){
      status = NVMError;
    }
  }else{
    status = NVMError;
  }

  return status;
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
