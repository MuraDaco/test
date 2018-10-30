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

#define _HW_LCD_C


#include "../../../../../Include/Driver/msPlatform.h"


// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
#include "qtlcdglo.h"



// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

#include "../../../../../Firmware/ap/krTimerGlo.h"


// SECTION END
// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION

// attendi altri 39us circa (39000ns / 125ns) = 312 cicli di clock // esegui 312 cicli
#define     DELAY_37us        20
#define     DELAY_39us        40 // OK 200

#define     LCD_COLUMN     20 // le colonne vanno da 0 a 19
#define     LCD_ROW        4  // le righe vanno da 1 a 4

// #define		LCD_DELAY_NOP_50ns		asm("nop");
// #define		LCD_DELAY_NOP_150ns		asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");

#define		LCD_DELAY_NOP_50ns	_ASM_01_NOP_50ns
#define		LCD_DELAY_NOP_150ns	_ASM_11_NOP_150ns

// RAM e DISPLAY
// entry mode agisce quando si scrive nella ram
// il cursor_display_shift agisce al momento che viene dato il comando
// RAM  rimane ferma si sposta il display

#define  LCD_INSTRUCTION_CLEAR_DISPLAY             0x01
#define  LCD_INSTRUCTION_RETURN_HOME               0x02
#define  LI_CLEAR_DISPLAY                                         LCD_INSTRUCTION_CLEAR_DISPLAY
#define  LI_RETURN_HOME                                           LCD_INSTRUCTION_RETURN_HOME

#define  LCD_INSTRUCTION_ENTRY_MODE                0x04
#define  _SHIFT_RIGHT                              0x02
#define  _SHIFT_LEFT                               0x00
#define  _DISPLAY_MOVED_AND_CURSOR_FIXED           0x01
#define  _DISPLAY_FIXED_AND_CURSOR_MOVED           0x00
#define  LI_DISPLAY_MOVED_RIGHT_AND_CURSOR_FIXED                  LCD_INSTRUCTION_ENTRY_MODE | _DISPLAY_MOVED_AND_CURSOR_FIXED | _SHIFT_RIGHT
#define  LI_DISPLAY_MOVED_LEFT_AND_CURSOR_FIXED                   LCD_INSTRUCTION_ENTRY_MODE | _DISPLAY_MOVED_AND_CURSOR_FIXED | _SHIFT_LEFT
#define  LI_DISPLAY_FIXED_AND_CURSOR_MOVED_RIGHT                  LCD_INSTRUCTION_ENTRY_MODE | _DISPLAY_FIXED_AND_CURSOR_MOVED | _SHIFT_RIGHT
#define  LI_DISPLAY_FIXED_AND_CURSOR_SHIFT_LEFT                   LCD_INSTRUCTION_ENTRY_MODE | _DISPLAY_FIXED_AND_CURSOR_MOVED | _SHIFT_LEFT
#define  LI_DEFAULT_ENTRY_MODE                     LI_DISPLAY_FIXED_AND_CURSOR_MOVED_RIGHT

#define  LCD_INSTRUCTION_ON_OFF_CONTROL            0x08
#define  _DISPLAY_ON                               0x04
#define  _DISPLAY_OFF                              ~_DISPLAY_ON
#define  _CURSOR_ON                                0x02
#define  _CURSOR_OFF                               ~_CURSOR_ON
#define  _BLINKING_ON                              0x01
#define  _BLINKING_OFF                             ~_BLINKING_ON
#define  LI_DISPLAY_ON_CURSOR_ON_BLINKING_ON                      LCD_INSTRUCTION_ON_OFF_CONTROL | _DISPLAY_ON | _CURSOR_ON | _BLINKING_ON
#define  LI_DISPLAY_ON_CURSOR_ON                                  LCD_INSTRUCTION_ON_OFF_CONTROL | _DISPLAY_ON | _CURSOR_ON
#define  LI_DISPLAY_ON_BLINKING_ON                                LCD_INSTRUCTION_ON_OFF_CONTROL | _DISPLAY_ON | _BLINKING_ON
#define  LI_DISPLAY_ON                                            LCD_INSTRUCTION_ON_OFF_CONTROL | _DISPLAY_ON
#define  LI_DEFAULT_ON_OFF_CONTROL                 LI_DISPLAY_ON

#define  LCD_INSTRUCTION_DISPLAY_CURSOR_SHIFT      0x10
#define  _DISPLAY_SHIFT                            0x08
#define  _CURSOR_SHIFT                             0x00
#define  _DIRECTION_RIGHT                          0x04
#define  _DIRECTION_LEFT                           0x00
#define  LI_DISPLAY_SHIFT_DIRECTION_RIGHT                         LCD_INSTRUCTION_DISPLAY_CURSOR_SHIFT | _DISPLAY_SHIFT | _DIRECTION_RIGHT
#define  LI_DISPLAY_SHIFT_DIRECTION_LEFT                          LCD_INSTRUCTION_DISPLAY_CURSOR_SHIFT | _DISPLAY_SHIFT | _DIRECTION_LEFT
#define  LI_CURSOR_SHIFT_DIRECTION_RIGHT                          LCD_INSTRUCTION_DISPLAY_CURSOR_SHIFT | _CURSOR_SHIFT  | _DIRECTION_RIGHT
#define  LI_CURSOR_SHIFT_DIRECTION_LEFT                           LCD_INSTRUCTION_DISPLAY_CURSOR_SHIFT | _CURSOR_SHIFT  | _DIRECTION_LEFT
#define  LI_DEFAULT_DISPLAY_CURSOR_SHIFT           LI_CURSOR_SHIFT_DIRECTION_RIGHT


#define  LCD_INSTRUCTION_FUNCTION_SET              0x20
#define  _DATA_8BIT                                0x10
#define  _DATA_4BIT                                0x00
#define  _2_LINE                                   0x08
#define  _1_LINE                                   0x00
#define  _5X11_FONT                                0x04
#define  _5X08_FONT                                0x00
#define  LI_DATA_8BIT_2_LINE_5X11_FONT                            LCD_INSTRUCTION_FUNCTION_SET | _DATA_8BIT | _2_LINE | _5X11_FONT
#define  LI_DATA_8BIT_2_LINE_5X08_FONT                            LCD_INSTRUCTION_FUNCTION_SET | _DATA_8BIT | _2_LINE | _5X08_FONT
#define  LI_DATA_8BIT_1_LINE_5X11_FONT                            LCD_INSTRUCTION_FUNCTION_SET | _DATA_8BIT | _1_LINE | _5X11_FONT
#define  LI_DATA_8BIT_1_LINE_5X08_FONT                            LCD_INSTRUCTION_FUNCTION_SET | _DATA_8BIT | _1_LINE | _5X08_FONT
#define  LI_DATA_4BIT_2_LINE_5X11_FONT                            LCD_INSTRUCTION_FUNCTION_SET | _DATA_4BIT | _2_LINE | _5X11_FONT
#define  LI_DATA_4BIT_2_LINE_5X08_FONT                            LCD_INSTRUCTION_FUNCTION_SET | _DATA_4BIT | _2_LINE | _5X08_FONT
#define  LI_DATA_4BIT_1_LINE_5X11_FONT                            LCD_INSTRUCTION_FUNCTION_SET | _DATA_4BIT | _1_LINE | _5X11_FONT
#define  LI_DATA_4BIT_1_LINE_5X08_FONT                            LCD_INSTRUCTION_FUNCTION_SET | _DATA_4BIT | _1_LINE | _5X08_FONT
#define  LI_DEFAULT_FUNCTION_SET                   LI_DATA_4BIT_2_LINE_5X11_FONT

#define _PROVA_DEF  (unsigned char) (0xFF | 0xAA)


// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

extern unsigned char hw_lcdStato;
extern unsigned char hw_lcdDisplayCursorShift;
extern unsigned char hw_lcdEntryMode;

unsigned char hw_lcdStato;
unsigned char hw_lcdDisplayCursorShift;
unsigned char hw_lcdEntryMode;

extern unsigned char Row;
extern unsigned char Col;

unsigned char Row;
unsigned char Col;

extern bool hw_lcdChanged;
bool hw_lcdChanged;


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



void hw_LcdInit (void)
{
    unsigned char i, j;

    Row = 0;
    Col = 0;

    for(i=0;i<LCD_ROW;i++)
    {
        for(j=0;j<LCD_COLUMN;j++)
        {
            lcd_string[i][j] = '-';
        }
    }

    lcd_string[0][LCD_COLUMN] = 0;
    lcd_string[1][LCD_COLUMN] = 0;
    lcd_string[2][LCD_COLUMN] = 0;
    lcd_string[3][LCD_COLUMN] = 0;
    lcd_string[4][LCD_COLUMN] = 0;

    hw_lcdChanged = true;

}


void hw_LcdRefresh (void) {

    // unsigned char i;
    // for (i=0; i<LCD_ROW; i++)
    // {
    // 	et024006_PrintString(lcd_string[i],
    // 	//(const unsigned char*) &FONT6x8,
    // 	(const unsigned char*) &FONT8x16,
    // 	20, 70 + 20*i,
    // 	WHITE, BLACK);
    // }

    hw_lcdChanged = false;


}



void hw_LcdClear (void)

{
    unsigned char i, j;

    for(i=0;i<LCD_ROW;i++)
    {
        for(j=0;j<LCD_COLUMN;j++)
        {
            lcd_string[i][j] = ' ';
        }
    }
    hw_lcdChanged = true;
}





void hw_LcdIncCoord (void)
{
    unsigned char ch_box;

    ch_box = LCD_COLUMN*(Row) + Col;

    ch_box++;

    if(ch_box < LCD_COLUMN*LCD_ROW)
    {
        Row = ch_box / LCD_COLUMN;
        Col = ch_box % LCD_COLUMN;
    }
    else
    {
        Row = Col = 0;
    }
}

void hw_LcdSetPosition(unsigned char row, unsigned char column)
{
    Row = row-1;
    Col = column;
}

void hw_LcdCh(char carattere)
{
    if(Col < LCD_COLUMN) {
        lcd_string[Row][Col] = carattere;
        hw_LcdIncCoord();
    }
    lcd_string[Row][LCD_COLUMN] = 0;

}

void hw_LcdDisplayReset (void)
{
}

void hw_LcdDisplayOff (void)
{
}

void hw_LcdDisplayOn (void)
{
}

void hw_LcdCursorOff (void)
{
}

void hw_LcdCursorOn (void)
{
}

void hw_LcdBlinkingOff (void)
{
}

void hw_LcdBlinkingOn (void)
{
}

void hw_LcdDisplayShift (void)
{
}

void hw_LcdCursorShift (void)
{
}

void hw_LcdRightShift (void)
{
}

void hw_LcdLeftShift (void)
{
}

void hw_LcdEntryModeRightShift (void)
{
}

void hw_LcdEntryModeLeftShift (void)
{
}

void hw_LcdEntryModeDisplay (void)
{
}

void hw_LcdEntryModeCursor (void)
{
}
