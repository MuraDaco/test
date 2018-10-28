/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 366 $																											
   *	LAST DATE REVISION:     $Date: 2016-07-27 18:13:43 +0200 (Wed, 27 Jul 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/krTimerTbl.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define _TIMER_TABLE_C


#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM



// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE


// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

// definizione della tabella evento
#include INCLUDE_KR_EVENT_GLO       // "krEventGlo.h"

// definizione Evento Nullo
#include INCLUDE_KR_EVENT           // "krEvent.h"

// si apprende il numero dei timers
#include INCLUDE_KR_TIMER_GLO       // "krTimerGlo.h"

// Moduli che usano timer (dipendenze indirette)
#include INCLUDE_KR_TIMER    // "krTimer.h"
//#include INCLUDE_RS2_TOUCH    // "rs2Touch.h"
#include INCLUDE_RS2_BUTTONS    // "rs2Buttons.h"
#include INCLUDE_UI_PAR    // "uiPar.h"
#include INCLUDE_UI_BUTTON    // "uiButton.h"
#include INCLUDE_UI_VAR    // "uiVar.h"
#include INCLUDE_UI_LBOX    // "uiLbox.h"
#include INCLUDE_MS_TEST    // "msTest.h"


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


_ROM EventTableDef EventTimer[TMR_NUMBER] = {
                                 TestTmrSecond,    // TMR_SECOND		0  //  modulo Test      
                                 TestTmrGLCD,      // TMR_TEST_GLCD	1  //  modulo Test      
                                 EventNull,        // TMR_TOUCH		2  //  modulo Touch     
                                 EventNull,        // TMR_LCD_INIT	3  //  non fare niente   
                                 ButtonsTimer,     // TMR_BUTTONS		4  //  modulo Buttons   
                                 uiParTimer,       // TMR_UI_PAR		5  //  modulo Parameter 
                                 uiLboxTimer,      // TMR_UI_LBOX		6  //  modulo ListBox   
                                 uiVarTimer,        // TMR_UI_VAR     7  //  modulo Variable
                                 uiButtonTimer     // TMR_UI_BUTTON     8  //  modulo Variable
};                                                 // TMR_NUMBER		9

