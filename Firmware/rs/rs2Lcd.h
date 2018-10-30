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

#ifndef _LCD_H
#define _LCD_H

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

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

#ifdef _MAIN_C
void LcdInit (void);
#endif
#ifdef _PROCESS_TABLE_C
void LcdInit (void);
#endif

void LcdClear                   (void);
void LcdSetPosition				(unsigned char row, unsigned char column);
void LcdCh							(char carattere);
void LcdSetDisplayShiftLeft	(void);
void LcdSetDisplayShiftRight  (void);
void LcdSetCursorShiftLeft		(void);
void LcdSetCursorShiftRigh		(void);
void LcdStrRC  					(unsigned char row,unsigned char column,char *str);
void LcdRomStrRC  				(unsigned char row,unsigned char column,const _ROM char *str);
void LcdNumberRC					(unsigned char row,unsigned char column,unsigned char par);
void LcdDisplayReset 			(void);

void LcdDisplayOff 				(void);
void LcdDisplayOn 				(void);
void LcdCursorOff 				(void);
void LcdCursorOn 					(void);
void LcdBlinkingOff 				(void);
void LcdBlinkingOn 				(void);

void LcdDisplayShift 			(void);
void LcdCursorShift 				(void);
void LcdRightShift 				(void);
void LcdLeftShift 				(void);

void LcdEntryModeRightShift	(void);
void LcdEntryModeLeftShift		(void);
void LcdEntryModeDisplay		(void);
void LcdEntryModeCursor			(void);



#endif	// _LCD_H

