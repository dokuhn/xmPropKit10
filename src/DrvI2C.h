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
// DrvI2C.h
//

#ifndef __DRV_I2C_H__
#define __DRV_I2C_H__

#include <Compiler.h>


#define  NUM_OF_RECV_BYTES        (0x40u)
#define  NUM_OF_ADDR_BYTES        (0x2u)

/// Aufzählungen der einzelnen I2C-Instanzen.
typedef enum {
  I2CInst1  = 0u,
  I2CInst2  = 1u,
  I2CInst3  = 2u,
} I2CInstanceType;

/// Aufzählungen der Fehler-Codes in den I2C-Funktionen.
/// Die Funktionen zum Ansteuern der I2C-Periphery können nicht immer erfolgreich ausgeführt werden. 
/// Deshalb ist es notwendig, nicht nur anzuzeigen, dass ein Fehler aufgetreten ist, sondern es muss auch angezeigt werden,
/// welcher Art der Fehler war. Dies ermöglicht der aufrufenden Routine ggf. besondere Maßnahmen zu ergreifen (z.B. 
/// Signalisierung an den Anwender).
typedef enum {
  I2CNoError,                        ///< Kein Fehler.
  I2CInvalidParameter,	             ///< Beim Aufruf der Funktion war mindestend ein Parameter ungültig.
  I2CcantSend,
  I2CcantRecv
} I2CErrCodeType;


typedef enum {
  start,
  transmit,
  recv,
  idle,
} I2C_StateType;



typedef struct {
  HWRD regAddr;
  BYTE IO_Buffer[ NUM_OF_RECV_BYTES ];
  BYTE recvCnt;
  BYTE writeCnt;  
  volatile BYTE *writeBuf;
}I2C_IODescrType;


volatile I2C_IODescrType I2C_Descr;



/// Initialisierung des I2Cx .
/// Diese Funktion schaltet zunächst die notwendigen Peripherie-Komponenten (I2Cx, AFIO, GPIOx) ein und
/// Aktiviert den Scl-Pin des I2C (alternate output, open-drain) und den Sda-Pin (alternate output, open-drain).
/// \param ptr2Handle zeigt nach Return auf den zug. I2C-Deskriptor.
/// \param I2CInstance gibt an, welcher der I2Cs initialisiert werden soll.
/// \return I2CNoError, wenn die Funktion erfolgreich ausgeführt wurde, sonst ein entrsprechender Fehler-Code.
/// \sa I2CErrCodeType
I2CErrCodeType  initI2C( I2CInstanceType const I2CInstance , const HWRD address );

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
