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

#ifndef _RS2_BUTTONS_GLO_H
#define _RS2_BUTTONS_GLO_H

#ifdef _DEF_C
#define _EXTERN_DEF
#else
#define _EXTERN_DEF extern
#endif


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

#define	BUTTONS_STATE_NO_PRESSED					0
#define	BUTTONS_STATE_WAIT							1
#define	BUTTONS_STATE_PRESSED						2
#define	BUTTONS_STATE_PRESSED_EXECUTED			3
#define	BUTTONS_STATE_NUMBER							4

#define	BUTTONS_EVENT_NOTHING						0
#define	BUTTONS_EVENT_PRESS							1
#define	BUTTONS_EVENT_RELEASE						2
#define	BUTTONS_EVENT_NUMBER							3

#define	BUTTONS_MODALITA_RIPETUTA_OFF		0
#define	BUTTONS_MODALITA_RIPETUTA_ON		1

#define  CODE_BUTTONS_RIGHT     0x01
#define  CODE_BUTTONS_UP        0x02
#define  CODE_BUTTONS_ENTER     0x04
#define  CODE_BUTTONS_LEFT      0x08
#define  CODE_BUTTONS_DOWN      0x10



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

typedef struct
//struct ButtonsStruct
{
   unsigned char Stato;
   char Codice;
   char CodiceOld;
   char Modalita;
} ButtonsStruct;
//};

_EXTERN_DEF ButtonsStruct Buttons;


#endif // endif of _RS2_BUTTONS_GLO_H