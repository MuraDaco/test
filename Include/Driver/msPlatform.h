/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 310 $																											
   *	LAST DATE REVISION:     $Date: 2015-12-08 17:39:10 +0100 (mar, 08 dic 2015) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/Administrator/Documents/SVN/Repository/fw2/15101-emphil/work/Def.c $			
   *																																						
   ****************************************************************************************************************************************************

 */


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
