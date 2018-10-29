/******************************************************************************
 *
 *   emphiOS - RTOS, User Interface & Business Logic libriaries
 *   Copyright (C) (2003-2018) Marco Dau
 *
 *   'emphiOS' is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   'emphiOS' is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   You can contact me by the following email address
 *   marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
 *
 *****************************************************************************/


#ifndef _PLATFORM_H
#define _PLATFORM_H

#undef _COMPILER_MICROCHIP_OLD_C18
#undef _COMPILER_MICROCHIP_GNU_XC8
#undef _COMPILER_MICROSOFT_VISUAL_STUDIO_2010
#undef _COMPILER_GCC_QT_ON_LINUX
#define _COMPILER_ATMEL_GNU_AVR32


#if defined(_COMPILER_MICROCHIP_OLD_C18) && defined(_COMPILER_MICROCHIP_GNU_XC8) && defined(_COMPILER_MICROSOFT_VISUAL_STUDIO_2010) && defined(_COMPILER_ATMEL_GNU_AVR32)
#error DEFINITI TROPPI COMPILATORI, DEFINIRNE UNO SOLO!!!!
#endif

#if !defined(_COMPILER_MICROCHIP_OLD_C18) && !defined(_COMPILER_MICROCHIP_GNU_XC8) && !defined(_COMPILER_MICROSOFT_VISUAL_STUDIO_2010) && \
    !defined(_COMPILER_GCC_QT_ON_LINUX) && !defined(_COMPILER_ATMEL_GNU_AVR32)
#error NESSUN COMPILATORE DEFINITO, DEFINIRNE UNO!!!!
#endif


#if defined   _COMPILER_MICROCHIP_OLD_C18
// ---------------------1234567
#define _COMPILER_INFO "PW7_CO_" // Parallels Windows 7 Compiler Old
#define _ROM rom

#define		_ASM_01_NOP_50ns		{_asm nop _endasm}
#define		_ASM_11_NOP_150ns		{_asm nop nop nop nop nop nop nop nop nop nop nop _endasm}

#define _REENTRANT
#define _TICK_DEC_TIMER		2

#elif defined _COMPILER_MICROCHIP_GNU_XC8
// ---------------------1234567
#define _COMPILER_INFO "PW7_CG_" // Parallels Windows 7 Compiler GNU

#define _ROM const

#define _ASM_01_NOP_50ns  asm("nop");
#define _ASM_11_NOP_150ns asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); 

#define _REENTRANT reentrant
#define _TICK_DEC_TIMER		2


#elif defined _COMPILER_MICROSOFT_VISUAL_STUDIO_2010
// ---------------------1234567
#define _COMPILER_INFO "W7__VS_" // Simulazione su Windows 7 Compiler Microsoft VisualStudio 2010

#define _ROM

#define _REENTRANT
#undef  _EOS_REENTRANT
#define _EOS_REENTRANT

#define _TICK_DEC_TIMER		100


#elif defined _COMPILER_GCC_QT_ON_LINUX
// ---------------------1234567
#define _COMPILER_INFO "LQT_GC_" // Simulazione su Linux-ArchLinux - Compilatore GCC con librerie Qt


#define _ROM

#define _REENTRANT
#undef  _EOS_REENTRANT
#define _EOS_REENTRANT

// #warning Attenzione! Ridefinito _REENTRANT

#define _TICK_DEC_TIMER		2

#include <QDebug>

#elif defined _COMPILER_ATMEL_GNU_AVR32
// ---------------------1234567
#define _COMPILER_INFO "GNU_AVR" // Scheda sviluppo EVK1105

#define _ROM

#define _REENTRANT
#undef  _EOS_REENTRANT
#define _EOS_REENTRANT

#define _TICK_DEC_TIMER		2

#include <stdbool.h>

#endif


#define _CONST const

#endif		// _PLATFORM_H
