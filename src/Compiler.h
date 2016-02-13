//
// Compiler.h
//

/// \file Compiler.h
/// Compiler-spezifische Definitions, Macros und Funktionen.
/// Um die Quellen auch zu Testzwecken auch mit anderen
/// Compilern (z.B. MSC) übersetzen zu können, werden in dieser Datei
/// mittels bedingter Kompilierung verschiedene Makros für die unterschiedlichen Compiler definiert.

#if ! defined(__COMPILER_H__)
# define __COMPILER_H__

// # if defined(__arm__)

#  include <stddef.h>
#  include <stdint.h>
#  include <stdbool.h>

#  define INLINE                __forceinline

#  define BYTE                  uint8_t               ///< Byte-Datentyp (8 Bits).
#  define WORD                  uint32_t              ///< Wort-Datentyp (nach ARM-Konvention 32 Bits, d.h. 4 Bytes).
#  define HWRD                  uint16_t              ///< Halbwort-Datentyp (nach ARM-Konvention 16 Bits, d.h. 2 Bytes).
#  define DWRD                  uint64_t              ///< Doppelwort-Datentyp (nach ARM-Konvention 8 Bytes).

// Nomenklatur <s>INT<nn>:
// <s> = U bzw. S für unsigned bzw. signed
// <nn> = 08, 12, 32, 64 für 8 bis 64 Bits

#  define UINT64                uint64_t              ///< 8 byte unsigned int.
#  define SINT64                int64_t               ///< 8 byte signed int.

#  define UINT32                uint32_t              ///< 4 byte unsigned int.
#  define SINT32                int32_t               ///< 4 byte signed int.

#  define UINT16                uint16_t              ///< 2 byte unsigned int.
#  define SINT16                int16_t               ///< 2 byte signed int.

#  define UINT08                uint8_t               ///< Single byte unsigned int.
#  define SINT08                int8_t                ///< Single byte signed int.



/*
#
#  define ATTRIBUTE(...)        __attribute__((__VA_ARGS__))
#  define FILE                  __MODULE__            ///< Name der aktuellen Datei.
#  define FUNC                  __PRETTY_FUNCTION__   ///< Name der aktuellen Funktion.
#  define LINE                  __LINE__              ///< Aktuelle Zeilennummer.
#  define INLINE                inline
#
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
