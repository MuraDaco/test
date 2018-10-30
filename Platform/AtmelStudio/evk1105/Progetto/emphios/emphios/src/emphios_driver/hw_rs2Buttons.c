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

#define _HW_BUTTONS_C

#include "qt1081.h"
#include "et024006dhu.h"

#include "msPlatform.h"

//#include "emphios/firmware/rs2ButtonsGlo.h"
#include "rs/rs2ButtonsGlo.h"
#include "hw_rs2Lcd.h"
#include "hw_msMicro.h"



// #include "dntButtonsGlo.h"

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
char atmelKeyPress;


void			hw_InitButtons				(void);
void			hw_driver_ButtonRefresh		(void);
unsigned char	hw_ButtonsRead				(void);
void			hw_ButtonsReset				(void);



void hw_InitButtons  (void)
{
      
}

void hw_driver_ButtonRefresh (void) {
	
	char num_hex[9];
	bool key_pressed=false;
	
	// UP
	if(is_touch_sensor_0()) {
		atmelKeyPress |= CODE_BUTTONS_UP;
		
		key_pressed=true;

		et024006_PrintString("UP",
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*1, 160,
			WHITE, BLACK);

		hw_LcdIntToHex(0x59FC6E37,num_hex);
		et024006_PrintString(num_hex,
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*1, 180,
			WHITE, BLACK);
	}
	
	// DOWN
	if(is_touch_sensor_1()) {
		atmelKeyPress |= CODE_BUTTONS_DOWN;

		key_pressed=true;

		et024006_PrintString("DW",
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*2, 160,
			WHITE, BLACK);
			
		hw_LcdIntToHex(registro_usbb,num_hex);
			et024006_PrintString(num_hex,
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*4, 180,
			WHITE, BLACK);
	}
	
	// RIGHT
	if(is_touch_sensor_2()) {
		atmelKeyPress |= CODE_BUTTONS_RIGHT;

		key_pressed=true;

		et024006_PrintString("RG",
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*3, 160,
			WHITE, BLACK);

		hw_LcdIntToHex(registro_usbb1,num_hex);
		et024006_PrintString(num_hex,
		//(const unsigned char*) &FONT6x8,
		(const unsigned char*) &FONT8x16,
		30*4, 180,
		WHITE, BLACK);

		et024006_PrintString("--",
		//(const unsigned char*) &FONT6x8,
		(const unsigned char*) &FONT8x16,
		30*1, 180,
		WHITE, BLACK);
		
		et024006_PrintString("--",
		//(const unsigned char*) &FONT6x8,
		(const unsigned char*) &FONT8x16,
		30*3, 180,
		WHITE, BLACK);

	}
	
	// LEFT
	if(is_touch_sensor_3()) {
		atmelKeyPress |= CODE_BUTTONS_LEFT;
		
		key_pressed=true;

		et024006_PrintString("LF",
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*4, 160,
			WHITE, BLACK);

		hw_LcdIntToHex(registro_usbb2,num_hex);
		et024006_PrintString(num_hex,
		//(const unsigned char*) &FONT6x8,
		(const unsigned char*) &FONT8x16,
		30*4, 180,
		WHITE, BLACK);


	} 
	
	// C-ENTER
	if(is_touch_sensor_4()) {
		atmelKeyPress |= CODE_BUTTONS_ENTER;
		
		key_pressed=true;

		et024006_PrintString("EN",
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*5, 160,
			WHITE, BLACK);
	} 
	
	if(!key_pressed) {
		//                    0123456789012345678901234
		et024006_PrintString("                         ",
		//(const unsigned char*) &FONT6x8,
		(const unsigned char*) &FONT8x16,
		30, 160,
		WHITE, BLACK);
		
	}
	
}

unsigned char hw_ButtonsRead		(void)
{
	return atmelKeyPress;
}

void hw_ButtonsReset				(void)
{
	atmelKeyPress = 0;
}

// void hw_ButtonTest (char key_code) {
// 
// 	unsigned char key:
// 	char str[3]:
// 	
// 	et024006_PrintString(str,
// 	(const unsigned char*) &FONT6x8,
// 	30*key, 160 + 10*i,
// 	WHITE, BLACK);
// 	
// }