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


#define	_TIMER_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM



// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE
#include INCLUDE_KR_TIMER_GLO       // "krTimerGlo.h"


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

//	****************************************************************************
//	****************************************************************************
void InitTimer (void)
{
   unsigned char i;
   
   for(i=0;i<TMR_NUMBER;i++)
   {
      Timer[i] = 0;
   }
   // TmrSecond init
   TmrSecond    = 1000;
   
  
}

//	****************************************************************************
//	****************************************************************************
void UpdateTimer (void)
{
   unsigned char i;

   for(i=0;i<TMR_NUMBER;i++)
   {
      if(Timer[i] > (_TICK_DEC_TIMER-1))
      {
         Timer[i] -= _TICK_DEC_TIMER;  
      }
   }

   // check TmrSecond variable
   if (TmrSecond == 0)
   {
      // update TmrError
      TmrError++;
   }
   else
   {
      // update TmrSecond
      TmrSecond -= _TICK_DEC_TIMER;
   }

   
}

//	****************************************************************************
//	****************************************************************************
_INTERFACE_EVENT_SUPPLY_(ControlloTimer0,i)
//unsigned char ControlloTimer0 (char i)
{
   if (Timer[i] == 0)
   {
      return i;
   }
   else
   {
      return 0xFF;
   }

}
