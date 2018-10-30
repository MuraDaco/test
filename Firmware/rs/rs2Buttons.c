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

#define _BUTTONS_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM


// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE

// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

#include "../../Include/Driver/hw_rs2Buttons.h"


#include INCLUDE_KR_EVENT_GLO              // "krEventGlo.h"
#include INCLUDE_KR_TIMER_GLO              // "krTimerGlo.h"
#include INCLUDE_RS2_BUTTONS_GLO        // "rs2ButtonsGlo.h"
#include INCLUDE_UI_RS2_BUTTONS_DSP   // "ui_rs2ButtonsDsp.h"



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


extern _ROM unsigned char ButtonsAction[BUTTONS_STATE_NUMBER][BUTTONS_EVENT_NUMBER];
_ROM unsigned char ButtonsAction[BUTTONS_STATE_NUMBER][BUTTONS_EVENT_NUMBER] =
{
   // NOTHING                          ,PRESS                              ,RELEASE
   // ----------------------------------------------------------------------------------------------------------------------------------------------
	  {BUTTONS_STATE_NO_PRESSED         ,BUTTONS_STATE_WAIT                 ,BUTTONS_STATE_NO_PRESSED}     // BUTTONS_STATE_NO_PRESSED					0
     ,{BUTTONS_STATE_PRESSED            ,BUTTONS_STATE_WAIT                 ,BUTTONS_STATE_NO_PRESSED}     // BUTTONS_STATE_WAIT							1
     ,{BUTTONS_STATE_PRESSED            ,BUTTONS_STATE_WAIT                 ,BUTTONS_STATE_NO_PRESSED}     // BUTTONS_STATE_PRESSED						2
     ,{BUTTONS_STATE_PRESSED_EXECUTED   ,BUTTONS_STATE_PRESSED_EXECUTED     ,BUTTONS_STATE_NO_PRESSED}     // BUTTONS_STATE_PRESSED_EXECUTED			3
};

//_ROM char ConversioneCodiceEvento[NUMBER_EVENT_BUTTONS] = {
//          EVENT_BUTTONS_RIGHT        //   0
//         ,EVENT_BUTTONS_UP           //   1
//         ,EVENT_BUTTONS_ENTER        //   2
//         ,EVENT_BUTTONS_DOWN         //   3
//         ,EVENT_BUTTONS_LEFT         //   4
//};  //    NUMBER_EVENT_BUTTONS            5

void InitButtons  (void)
{
	hw_InitButtons();
	Buttons.Codice = Buttons.CodiceOld = Buttons.Stato = Buttons.Modalita = 0;
	rs2ButtonsTimesPressed = 0;
   
}


unsigned char ControlloButtons   (char i)
{
   char evento;
//   _ROM char *ptr_conversion;     // solo questa definizione occupa 16 byte di codice!!!!
   
   
   // se TastoPremuto allora
   // in base al tasto premuto ritorna l'evento associato
   if(Buttons.Stato == BUTTONS_STATE_PRESSED)
   {
      Buttons.Stato = BUTTONS_STATE_PRESSED_EXECUTED;

      // imposta evento
//      for(evento=0;evento<NUMBER_EVENT_BUTTONS;evento++)
//      {
//         if(ConversioneCodiceEvento[evento] == Buttons.Codice)
//         {
//            return evento;
//         }
//      }
      
//      ptr_conversion = ConversioneCodiceEvento;
//      do
//      {
//         if(*ptr_conversion == Buttons.Codice)
//         {
//            return evento;
//         }
//         ptr_conversion++;
//         
//      } while(*ptr_conversion == 0xFF);
      
      // imposta evento
      switch (Buttons.Codice)
      {
         case CODE_BUTTONS_RIGHT:
            evento = EVENT_BUTTONS_RIGHT;
            break;
         case CODE_BUTTONS_UP:
            evento = EVENT_BUTTONS_UP;
            break;
         case CODE_BUTTONS_ENTER:
            evento = EVENT_BUTTONS_ENTER;
            break;
         case CODE_BUTTONS_DOWN:
            evento = EVENT_BUTTONS_DOWN;
            break;
         case CODE_BUTTONS_LEFT:
            evento = EVENT_BUTTONS_LEFT;
            break;   
         default:
            return 0xFF;
      }

      return evento;
      
   }
   
   return 0xFF;
}

void ButtonsTimer    (void)
{
   unsigned char evento;
//   // leggi il digital input
//   // se ancora premuto allora imposta tasto premuto

   if(Buttons.Stato != BUTTONS_STATE_PRESSED)
   {
      Buttons.CodiceOld = Buttons.Codice;
      Buttons.Codice = hw_ButtonsRead();
		
//      unsigned char cod ice;
//		
//      codice = PORTC&0xE0;
//      codice >>=3;
//		
//      Buttons.Codice = codice;
//
//      codice = PORTB&0xC0;
//      codice >>=6;
//		
//      Buttons.Codice += codice;
   }

	evento = BUTTONS_EVENT_NOTHING;
   if(Buttons.Codice != Buttons.CodiceOld)
   {
		evento = BUTTONS_EVENT_RELEASE;
      if(Buttons.Codice != 0)
      {
			evento = BUTTONS_EVENT_PRESS;
		}
	}
   
   // imposta il nuovo stato
	Buttons.Stato = ButtonsAction[Buttons.Stato][evento];
   
   // Completa le azioni da eseguire associate allo stato appena impostato
   if(Buttons.Stato == BUTTONS_STATE_NO_PRESSED)
   {
      Buttons.Modalita = BUTTONS_MODALITA_RIPETUTA_OFF;
   }

   if(Buttons.Stato == BUTTONS_STATE_WAIT)
   {
      Timer[TMR_BUTTONS] = _TICK_DEC_TIMER;
   }
      
   if(Buttons.Stato == BUTTONS_STATE_PRESSED)
   {
      Timer[TMR_BUTTONS] = _TICK_DEC_TIMER;
      rs2ButtonsTimesPressed++;
   }

   if(Buttons.Stato == BUTTONS_STATE_PRESSED_EXECUTED)
   {
      hw_ButtonsReset();
   }

   
//   switch (Buttons.Stato)
//   {
//      case BUTTONS_NO_PRESSED:
//         if(Buttons.Codice != 0)
//         {
//            // nessun tasto premuto
//            Buttons.Stato = BUTTONS_WAIT;
//            Timer[TMR_BUTTONS] = 20;
//         }
//         break;
//      case BUTTONS_WAIT:
//         if(Buttons.Codice == Buttons.CodiceOld)
//         {
//            // nessun tasto premuto
//            if(Buttons.Codice != 0)
//            {
//               Buttons.Stato = BUTTONS_PRESSED;
//            }
//            else
//            {
//               Buttons.Stato = BUTTONS_NO_PRESSED;
//            }
//               
//         }
//         break;
//      case BUTTONS_PRESSED_EXECUTED:
//         if(Buttons.Codice == Buttons.CodiceOld)
//         {
//            if(Buttons.Modalita == BUTTONS_MODALITA_RIPETUTA_ON)
//            {
//               // nessun tasto premuto
//               Buttons.Stato = BUTTONS_PRESSED;
//            }
//         }
//         else
//         {
//            if(Buttons.Codice != 0)
//            {
//               Buttons.Stato = BUTTONS_WAIT;
//               Timer[TMR_BUTTONS] = 20;
//            }
//            else
//            {
//               Buttons.Stato = BUTTONS_NO_PRESSED;
//               Buttons.Modalita = BUTTONS_MODALITA_RIPETUTA_OFF;
//            }
//         }
//         break;
//   }
   
//**++**   if(Buttons.Stato == BUTTONS_STATE_NO_PRESSED)
//**++**   {
//**++**
//**++**      if(Buttons.Codice != 0)
//**++**      {
//**++**         // nessun tasto premuto
//**++**         Buttons.Stato = BUTTONS_STATE_WAIT;
//**++**         Timer[TMR_BUTTONS] = 20;
//**++**      }
//**++**   }
//**++**   else if(Buttons.Stato == BUTTONS_STATE_WAIT)
//**++**   {
//**++**      if(Buttons.Codice == Buttons.CodiceOld)
//**++**      {
//**++**         // nessun tasto premuto
//**++**         if(Buttons.Codice != 0)
//**++**         {
//**++**            Buttons.Stato = BUTTONS_STATE_PRESSED;
//**++**            Timer[TMR_BUTTONS] = 100;
//**++**         }
//**++**         else
//**++**         {
//**++**            Buttons.Stato = BUTTONS_STATE_NO_PRESSED;
//**++**         }
//**++**            
//**++**      }
//**++**   }
//**++**   else if(Buttons.Stato == BUTTONS_STATE_PRESSED_EXECUTED)
//**++**   {
//**++**      if(Buttons.Codice == Buttons.CodiceOld)
//**++**      {
//**++**         if(Buttons.Modalita == BUTTONS_MODALITA_RIPETUTA_ON)
//**++**         {
//**++**            // nessun tasto premuto
//**++**            Buttons.Stato = BUTTONS_STATE_PRESSED;
//**++**         }
//**++**      }
//**++**      else
//**++**      {
//**++**         if(Buttons.Codice != 0)
//**++**         {
//**++**            Buttons.Stato = BUTTONS_STATE_WAIT;
//**++**            Timer[TMR_BUTTONS] = 20;
//**++**         }
//**++**         else
//**++**         {
//**++**            Buttons.Stato = BUTTONS_STATE_NO_PRESSED;
//**++**            Buttons.Modalita = BUTTONS_MODALITA_RIPETUTA_OFF;
//**++**         }
//**++**      }
//**++**   }
   
}
