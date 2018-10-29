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
#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM


// driver
#include "../../Include/Driver/hw_msMicro.h"
#include "../../Include/Driver/hw_krInterrupt.h"

//#include "../cf/ConfigEasyPicV7.h"

// Per definizione strutte dati dei Processi
#include INCLUDE_KR_PROCESS_GLO     // "krProcessGlo.h"

// Per le strutture dati
#include INCLUDE_KR_TIMER_GLO       // "krTimerGlo.h"   // necessario per TMR_NUMBER

// Per la tabella dei processi di init
#include INCLUDE_KR_TIMER           // "krTimer.h"
#include INCLUDE_RS2_TOUCH          // "rs2Touch.h"
#include INCLUDE_RS2_BUTTONS        // "rs2Buttons.h"
#include INCLUDE_RS2_GLCD           // "rs2Glcd.h"
#include INCLUDE_RS2_LCD            // "rs2Lcd.h"
#include INCLUDE_UI_BASE            // "uiBase.h"
#include INCLUDE_MS_TEST            // "msTest.h"

// Per la matrice dei processi: funzioni di controllo
#include INCLUDE_KR_TIMER           // "krTimer.h"

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
   
   InitMicro,                 // init Hardware Micro
   InitTimer,                 // init System Timer
   InitButtons,               // init Buttons pin ports
   InitInterruptTimer,        // init Interrupt Timer
   LcdInit,                   // init LCD
   uiBaseInitCold,
   TestInit                  // visualizza la versione firmware
   
};

