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

#include <DrvEEPROM.h>
#include <DrvUSIC.h>
#include <DrvI2C.h>
#include <DrvNVM.h>

#define  Word_Size             (4u)
#define  Block_Size            (4u)
#define  Page_Size             (16u)

static WORD readWriteBuffer[ (Page_Size * Block_Size) ];           ///< Read-Write-Buffer for One Page
static HWRD bufferAddr = 0xFFFFu ;                                 ///< Address of current Page

void writeCache( void ){
  BYTE i = 0;
  
  eraseNVM( (WORD)(NVM_START_ADDRESS) + bufferAddr );
  P1_OMR = (0x1u << 0u) | (0x1u << 16u);
  
  for( i = 0u; i < Page_Size; i++ ){
    writeNVM( (WORD)(NVM_START_ADDRESS) + bufferAddr + (16u * i) , &(readWriteBuffer[ 4u * i ]) );    
  }
  
}


void writeByte( HWRD tAddress , BYTE wByte ){
  
  WORD readBuf;
  BYTE i = 0;
  
  if( ((tAddress >> 8u) << 8u) != bufferAddr ){

    writeCache();    
    
    // read new Page into Read-Write-Buffer
    for( i = 0u; i < (Block_Size * Page_Size); i++ ){
      readNVM( (WORD)(NVM_START_ADDRESS) + (((WORD)(tAddress >> 8u) << 8u) + (4u * i))  , readWriteBuffer + i  );
    }
    bufferAddr = ((tAddress >> 8u) << 8u);
  }

  P1_OMR = (0x1u << 1u) | (0x1u << 17u);
  
  // find WORD in Page-Buffer
  readBuf = readWriteBuffer[ (0x3Fu & (tAddress >> 2u)) ];

  // modify BYTE in WORD-Buffer
  readBuf = ( readBuf & ~(0xFFu << (8u * (tAddress & 0x3u))) ) |  (wByte << (8u * (tAddress & 0x3u))) ;

  // wirtes WORD-Buffer back in Page-Buffer
  readWriteBuffer[ (0x3Fu & (tAddress >> 2u)) ] = readBuf;
  
}


void writeBuffer( HWRD tAddress, BYTE *wByte, BYTE bufSize ){

  BYTE i = 0;

  for( i = 0u; i < bufSize; i++ ){
    writeByte( tAddress + i , wByte[i] );
  }

}


BYTE getByte( HWRD tAddress ){
  
  WORD readBuf;
  BYTE byteBuf;

  if( ((tAddress >> 8u) << 8u) == bufferAddr ){

    // find WORD in Page-Buffer
    readBuf = readWriteBuffer[ (0x3Fu & (tAddress >> 2u)) ];

  }else{
    
    readNVM( (WORD)(NVM_START_ADDRESS) + (((WORD)(tAddress) >> 2u) << 2u) , &readBuf );
  }

  byteBuf = (BYTE)( readBuf >> (8u * (tAddress & 0x3u)) );    

  return byteBuf ;
}




/*
void writeByte( HWRD address , BYTE wByte ){
  static bool firstInit = true;
  WORD readBuf;
  BYTE i = 0;

  if( (((WORD)(address)  >> 8u) << 8u) == addrHandler ){

    // find WORD in Page-Buffer
    readBuf = readWriteBuffer[ (0xFu & (address >> 2u)) ];

    // modify BYTE in WORD-Buffer
    readBuf = ( readBuf & ~(0xFFu << (8u * (address & 0x3u))) ) |  (wByte << (8u * (address & 0x3u))) ;

    // wirtes WORD-Buffer back in Page-Buffer
    readWriteBuffer[ (0xFu & (address >> 2u)) ] = readBuf;

  }else{

    // erase old Page if not first Init
    if( firstInit == false ){

      for( i = 0u; i < Page_Size; i++ ){

	
      }
      
    }

    // read new Page in the Read-Write-Buffer
    for( i = 0u; i < (Block_Size * Page_Size); i++ ){
      readNVM( (WORD)(NVM_START_ADDRESS)  + (((WORD)(address >> 8u) << 8u) + (4u * i))  , &readBuf  );
      readWriteBuffer[i] = readBuf;
    }
   
    addrHandler = (((WORD)(address) >> 8u) << 8u);
    firstInit = false;

    // find WORD in Page-Buffer
    readBuf = readWriteBuffer[ (0xFu & (address >> 2u)) ];

    // modify BYTE in WORD-Buffer
    readBuf = ( readBuf & ~(0xFFu << (8u * (address & 0x3u))) ) |  (wByte << (8u * (address & 0x3u))) ;

    // wirtes WORD-Buffer back in Page-Buffer
    readWriteBuffer[ (0xFu & (address >> 2u)) ] = readBuf;   
  }

}


BYTE getByte( HWRD address ){
  
  WORD readBuf;
  BYTE byteBuf;

  if( (((WORD)(address) >> 8u) << 8u) == addrHandler ){

    P1_OMR = (0x1u << 0u) | (0x1u << 16u);

    // find WORD in Page-Buffer
    readBuf = readWriteBuffer[ (0xFu & (address >> 2u)) ];
    byteBuf = (BYTE)( readBuf >> (8u * (address & 0x3u)) );    

  }else{
    
    P1_OMR = (0x1u << 1u) | (0x1u << 17u);
    readNVM( (WORD)(NVM_START_ADDRESS) + (((WORD)(address) >> 2u) << 2u) , &readBuf );
    byteBuf =  (BYTE)( readBuf >> (8u * (address & 0x3u)));
    
  }

  return byteBuf ;
}

*/ 
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
