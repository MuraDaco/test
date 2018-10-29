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


#ifndef _EVENT_GLO_H
#define _EVENT_GLO_H

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

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

#define  EVENT_BUTTONS_RIGHT     		0
#define  EVENT_BUTTONS_UP        		1
#define  EVENT_BUTTONS_ENTER     		2
#define  EVENT_BUTTONS_DOWN      		3
#define  EVENT_BUTTONS_LEFT      		4
#define  NUMBER_EVENT_BUTTONS    		5


#define _INTERFACE_EVENT(a) void (*a) (void) 
#define _INTERFACE_EVENT_(a) void a (void) 
#define _INTERFACE_EVENT_SUPPLY(a)  unsigned char (*a)(char)			
#define _INTERFACE_EVENT_SUPPLY_(a,b)  unsigned char a (char b)
//#define _INTERFACE_EVENT_SUPPLY_(a,b)  unsigned char a (unsigned char b)


//typedef void (*EventTableDef)(void);
typedef _INTERFACE_EVENT(EventTableDef);
typedef _INTERFACE_EVENT(EventAction);
typedef _INTERFACE_EVENT_SUPPLY(EventSupply);

typedef struct
{
   _ROM EventTableDef *EventTable;
} EventPtrTableDef;		// EventStructX;                     	// EventPtrTableDef

// extern EventStructX	EventTimerMatrix[];   
// extern EventStructX	ButtonsEventMatrix[];  

extern EventPtrTableDef		EventTimerMatrix[];   
extern EventPtrTableDef		ButtonsEventMatrix[];  


#endif	// _EVENT_GLO_H

