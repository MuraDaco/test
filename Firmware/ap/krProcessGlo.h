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

#ifndef _PROCESS_GLO_H
#define _PROCESS_GLO_H

#include "../cf/cfInclude.h"

#include INCLUDE_MS_PLATFORM

#include INCLUDE_KR_EVENT_GLO       // "krEventGlo.h"

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
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

		
#define	PROCESS_TIMER						0
#define	PROCESS_BUTTONS					1
#define	NUMBER_PROCESS						2


#define PROCESS_INIT_MICRO                  0       // InitMicro,                 // init Hardware Micro
#define PROCESS_INIT_TIMER                  1       // InitTimer,                 // init System Timer
#define PROCESS_INIT_BUTTONS                2       // InitButtons,               // init Buttons pin ports
#define PROCESS_INIT_INTERRUPT_TIMER        3       // InitInterruptTimer,        // init Interrupt Timer
#define PROCESS_INIT_LCD                    4       // LcdInit,                   // init LCD
#define PROCESS_INIT_UI_BASE                5       // uiBaseInitCold,
#define PROCESS_INIT_TEST                   6       // TestInit                  // visualizza la versione firmware
#define NUMERO_EVENTI_INIT                  7

typedef struct
{
//   unsigned char (*Controllo)(char);			
//   _INTERFACE_EVENT_SUPPLY(Controllo); // Funziona!!!
   EventSupply Controllo;   // Funziona!!!
   EventPtrTableDef *EventMatrix;				
   char NumeroRipetizioniControllo;
} ProcessStruct;


extern _ROM ProcessStruct ProcessTable[];
extern _ROM EventTableDef ProcessInitTable[];


#endif	// _PROCESS_GLO_H

