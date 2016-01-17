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
///  DrvGPIO.h
///
/// \file GPIO.h
/// Routinen zum Ansteuern von I/O-Pins.

#ifndef __DRV_GPIO_H__
#define __DRV_GPIO_H__

#include <Compiler.h>

/// Aufzaehlungsdatentyp zur Definition der GPIO-Fehler.
typedef enum {
	noGpioError,
	outOfGpioDescr,
	invalidGpioArgs 		///< Ungueltige Aufrufparameter.
} GpioErrorType;


typedef enum {
	gpioPort0 = 0u,
	gpioPort1 = 1u,
	gpioPort2 = 2u,
} GpioPortType;


typedef enum {
  OpenDrain,
  PushPull
} GpioOutputType;


GpioErrorType InitGpioOutput( GpioPortType gpioPort, BYTE pinNum);


GpioErrorType InitGpioAF( GpioPortType gpioPort, BYTE pinNum , GpioOutputType OutputType, unsigned AFRbitMASK );




/*

typedef struct __GpioIDescr GpioIDescrType;
typedef GpioIDescrType const * GpioIHandleType;

GpioErrorType InitGpioInput(GpioIHandleType * ptr2Handle, GpioPortType gpioPort, unsigned pinNum);



bool GpioInputState(GpioIHandleType theHandle);

typedef struct __GpioODescr GpioODescrType;
typedef GpioODescrType const * GpioOHandleType;


void GpioOutputToggle(GpioOHandleType theHandle);
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
