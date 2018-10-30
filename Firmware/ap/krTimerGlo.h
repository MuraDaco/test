/******************************************************************************
 *
 *   emphiOS - RTOS, User Interface & Business Logic libriaries
 *   Copyright (C) (2016-2018) Marco Dau
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


#ifdef _DEF_C
#define _EXTERN_DEF
#else
#define _EXTERN_DEF extern
#endif


#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

// definizione della funzione evento
#include INCLUDE_KR_EVENT_GLO       // "krEventGlo.h"



// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)


// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION

#define	TMR_SECOND		0  //  modulo Test  
#define	TMR_TEST_GLCD	1  //  modulo Test 
#define	TMR_TOUCH		2  //  modulo Touch
#define	TMR_LCD_INIT	3  //  non fare niente
#define	TMR_BUTTONS		4  //  modulo Buttons
#define	TMR_UI_PAR		5  //  modulo Parameter
#define	TMR_UI_LBOX		6  //  modulo ListBox
#define	TMR_UI_VAR		7  //  modulo Variable
#define	TMR_UI_BUTTON	8  //  modulo Parameter
#define TMR_NUMBER		9


// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

#if defined(_DEF_C) || defined(_TIMER_C) || defined(_TEST_C) || defined(_TOUCH_C) || defined(_HW_LCD_C) || defined(_BUTTONS_C) || \
    defined(_UI_PAR_C) || defined(_UI_VAR_C) || defined(_UI_LBOX_C) || defined(_UI_BUTTON_C) || defined(FW_TEST_H)
_EXTERN_DEF	int TmrSecond;
_EXTERN_DEF	int TmrError;
_EXTERN_DEF	int TmrTouch;
_EXTERN_DEF	int Timer[TMR_NUMBER];
#endif


extern _ROM EventTableDef EventTimer[];

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

