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

#ifndef _HW_LCD_H
#define _HW_LCD_H


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

// #ifdef _MAIN_C
// void hw_LcdInit (void);
// #endif
// #ifdef _PROCESS_TABLE_C
// void hw_LcdInit (void);
// #endif

void hw_LcdIntToHex					(unsigned int num, char* num_hex);

void hw_LcdInit                  (void);
void hw_LcdClear				 (void);
void hw_LcdSetPosition				(unsigned char row, unsigned char column);
void hw_LcdCh							(char carattere);
void hw_LcdSetDisplayShiftLeft	(void);
void hw_LcdSetDisplayShiftRight  (void);
void hw_LcdSetCursorShiftLeft		(void);
void hw_LcdSetCursorShiftRigh		(void);

void hw_LcdDisplayReset 			(void);

void hw_LcdDisplayOff 				(void);
void hw_LcdDisplayOn 				(void);
void hw_LcdCursorOff 				(void);
void hw_LcdCursorOn 					(void);
void hw_LcdBlinkingOff 				(void);
void hw_LcdBlinkingOn 				(void);

void hw_LcdDisplayShift 			(void);
void hw_LcdCursorShift 				(void);
void hw_LcdRightShift 				(void);
void hw_LcdLeftShift 				(void);

void hw_LcdEntryModeRightShift	(void);
void hw_LcdEntryModeLeftShift		(void);
void hw_LcdEntryModeDisplay		(void);
void hw_LcdEntryModeCursor			(void);


#endif	// _LCD_H

