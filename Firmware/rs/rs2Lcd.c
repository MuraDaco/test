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

#define _LCD_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM


// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE



// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

#include "../../Include/Driver/hw_rs2Lcd.h"
#include INCLUDE_KR_TIMER_GLO       // "krTimerGlo.h"


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


void LcdInit (void)
{
	hw_LcdInit();
}

void LcdClear (void)
{
	hw_LcdClear();
}


void LcdStrRC  (unsigned char row,unsigned char column,char *str)
{
   hw_LcdSetPosition(row,column);
   
   // write string
   while (*str>0)
   {
      hw_LcdCh(*str);
      str++;
   }   
   
}

void LcdRomStrRC  (unsigned char row,unsigned char column,const _ROM char *str)
{
   hw_LcdSetPosition(row,column);
   
   // write string
   while (*str>0)
   {
      hw_LcdCh(*str);
      str++;
   }   
   
}

void LcdNumberRC  (unsigned char row,unsigned char column,unsigned char par)
{
//   char par;
   unsigned char num[4];
   unsigned char i;
   
   hw_LcdSetPosition(row,column);
   
//   par = *ptr_par;
   num[3] = 0;
   num[2] = par%10;
   num[1] = (par/10)%10;
   num[0] = par/100;
   
   
   // write string
   for(i=0;i<3;i++)
   {
      hw_LcdCh('0'+num[i]);
   }   
   
}

