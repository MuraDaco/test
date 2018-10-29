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

