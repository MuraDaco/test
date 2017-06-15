/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: mdau $																										
   *	REVISION NUMBER:        $Revision: 373 $																											
   *	LAST DATE REVISION:     $Date: 2017-02-02 16:55:34 +0100 (Thu, 02 Feb 2017) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/krProcessTbl.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define _PROCESS_TABLE_C

// Piattaforma e Tool di sviluppo
#include "../Include/Driver/msPlatform.h"

// driver
#include "../Include/Driver/hw_msMicro.h"
#include "../Include/Driver/hw_krInterrupt.h"

#include "ConfigEasyPicV7.h"

// Per definizione strutte dati dei Processi
#include "krProcessGlo.h"

// Per le strutture dati
#include "krTimerGlo.h"   // necessario per TMR_NUMBER

// Per la tabella dei processi di init
#include "krTimer.h"
#include "rs2Touch.h"
#include "rs2Buttons.h"

#include "rs2Glcd.h" 
#include "rs2Lcd.h"
#include "uiBase.h"
#include "msTest.h"

// Per la matrice dei processi: funzioni di controllo
#include "krTimer.h"

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE

// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

// direct dependecies:

//	reverse dependecies:

// SECTION END
// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - ARRAY DEFINITION

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	****************************************************************************
// SECTION - CONTROL FUNCTION DEFINITION

// SECTION END
//	****************************************************************************

//	****************************************************************************
// SECTION - EVENT FUNCTION DEFINITION

// SECTION END
//	****************************************************************************


//	****************************************************************************
// SECTION - LIBRTARY FUNCTION DEFINITION

// SECTION END
//	****************************************************************************


#ifdef _COMPILER_MICROCHIP_OLD_C18
#pragma code
#endif

_ROM ProcessStruct ProcessTable[NUMBER_PROCESS] = {
   {ControlloTimer0     ,EventTimerMatrix       ,TMR_NUMBER},     // PROCESS_TIMER        0
   {ControlloButtons    ,ButtonsEventMatrix     ,1}               // PROCESS_BUTTONS      1
};                                                                // NUMBER_PROCESS       2


_ROM EventTableDef ProcessInitTable[NUMERO_EVENTI_INIT] = {
   
   InitTimer,                 // init System Timer
   InitButtons,               // init Buttons pin ports
   InitMicro,                 // init Hardware Micro
#ifdef _CONFIG_EASY_PIC_V7_GRAPHIC_LCD
   glcdInitPorts,             // init port about Graphic LCD
#ifdef _CONFIG_EASY_PIC_V7_TOUCH
   touchInit,                 // init port about touch
#endif   // _CONFIG_TOUCH   
#endif   // _CONFIG_GRAPHIC_LCD
   InitInterruptTimer,        // init Interrupt Timer
#ifdef _CONFIG_EASY_PIC_V7_LCD
   LcdInit,                   // init LCD
#endif
   uiBaseInitCold,
   TestInit                  // visualizza la versione firmware
   
};

