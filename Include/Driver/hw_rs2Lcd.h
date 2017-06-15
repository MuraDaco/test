/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: mdau $																										
   *	REVISION NUMBER:        $Revision: 377 $																											
   *	LAST DATE REVISION:     $Date: 2017-02-10 16:06:23 +0100 (Fri, 10 Feb 2017) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/hw_rs2Lcd.h $			
   *																																						
   ****************************************************************************************************************************************************

 */

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

void hw_LcdInit                  (void);

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

