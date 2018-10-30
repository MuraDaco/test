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

/*
   touch.c
   
   Description / Descrizione:
   Driver to handle the resistive touch screen with 4 wire
   Driver per gestire il touch ecreen resistivo a 4 fili
	
   Documentation / Documentazione
	

   Gestione Personale
   - RC0->1 e RC1->0 ---> Read RA0
   - RC0->0 e RC1->1 ---> Read RA1
   
   Gestione MicroElektronika
   - RC0 e RC1 sempre a 0 e quindi RA0 -> 1 e RA1 -> 0
   - Periodo di 3 ms e con RC a 1 per 1ms
   
   
   Author:
   Marco Dau

   Creation Date:
   Tuesday, 17 March 2015
   
   Update:
   
   
*/


#define	_TOUCH_C

#include "msPlatform.h"

#include <p18f45k22.h>

#include "rs2ADC.h"
#include "rs2ADCGlo.h"
#include "rs2TouchGlo.h"
#include "krTimerGlo.h"



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

#define TOUCH_PHASE_0	0
#define TOUCH_PHASE_1	1
#define TOUCH_PHASE_2	2


char TouchState;
char TouchXold;
char TouchYold;



void touchInit (void)
{
   // configure the port on adc for the reading

   // 01 - Disable pin output driver
   TRISA |= 0x03;

   // 02 - Configure pin as analog
   ANSELA |= 0x03;
   

   // configure the drive port
   
   // configure as digital the following ports -> It doesn,'t need for RC0 and RC1
   // di default portx ?mpostato come ingresso analogico
//   ANSELC &= 0xFC;

   // configure as OUT the following ports
   // PORT C <0..1>
   TRISC &= 0xFC;
	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
 
   // inizializza le porte
   LATCbits.LATC0 = 0;
   LATCbits.LATC1 = 0;
   
   adcInit();
   
   TouchState = 0;
   Timer[TMR_TOUCH] = 0;
}

void TouchTimer (void)
{

/*
   . Legend:
   ... Pin 4 -> Bootom
   ... Pin 3 -> Left
   ... Pin 2 -> Top
   ... Pin 1 -> Right

   . reading X
   .. set pin 1   (Right)                       to High  -> automatically from Drive A
   .. set pin 3   (Left -> Drive A -> RC0)      to Low   -> set Drive A / RC0 to 1 -> Right go to High // Top go to free -> it's all OK
   .. read pin 4  (Bottom -> Read X -> RA0)     IN       -> set Drive B / RC1 to 0         
   .. free pin 2  (Top)                         Free     -> automatically from Drive A

   . reading Y
   .. set pin 2   (Top)                         to High  -> set Drive A / RC0 to 0 -> Left go to High and IN state // Right go to free -> it's all OK
   .. set pin 4   (Bottom -> Drive B -> RC1)    to Low   -> set Drive B / RC1 to 1
   .. read pin 3  (Left -> Read Y -> RA1)       IN       -> automatically from Drive B 
   .. free pin 1  (Right)                       Free     -> automatically from Drive B

*/

   char touch_y, touch_x;

//   if(Timer[TMR_TOUCH] == 0)
   {
      switch (TouchState)
      {
         case TOUCH_PHASE_0:
            touch_x = adcReadChannel(ADC_CH_TOUCH_BOTTOM_READ_X);  // X is long side
            touch_y = adcReadChannel(ADC_CH_TOUCH_LEFT_READ_Y);    // Y is short side
//            if(TmrTouch == 0)
            {
               if(touch_y > 0xF0)
               {
                  // touch-pannel is pressed, then ...
                  
                  // set touch-pannel state to phase1
                  TouchState = TOUCH_PHASE_1;
                  // set Timer[TMR_TOUCH] to 4ms
                  Timer[TMR_TOUCH] = 4;
                  // set RC0
                  LATCbits.LATC0 = 1;
               }
               else
               {
                  TouchX = TouchXold;
                  TouchY = TouchYold;
               }
            }
         break;
         case TOUCH_PHASE_1:
//            if(TmrTouch == 0)
            {
               // read X-channel
               TouchXold = TouchX;
               TouchX = adcReadChannel(ADC_CH_TOUCH_BOTTOM_READ_X); // X is long side
               // set RC1
               LATCbits.LATC0 = 0;
               LATCbits.LATC1 = 1;
               // set Timer[TMR_TOUCH] to 4ms
               Timer[TMR_TOUCH] = 4;
               // set TouchState to TOUCH_PHASE_2
               TouchState = TOUCH_PHASE_2;
            }
         break;
         case TOUCH_PHASE_2:
//            if(TmrTouch == 0)
            {
               // read Y-channel
               TouchYold = TouchY;
               TouchY = adcReadChannel(ADC_CH_TOUCH_LEFT_READ_Y); // Y is short side
               // set RC1
               LATCbits.LATC1 = 0;
               // set TouchState to TOUCH_PHASE_0
               TouchState = TOUCH_PHASE_0;
               // set Timer[TMR_TOUCH] to 4ms
               Timer[TMR_TOUCH] = 4;
            }
         break;
      }
   }
   
/*   
   
	//	....a) set drive A
	LATCbits.LATC0 = 0;
	LATCbits.LATC1 = 0;
//   // PORTC &= 0xFD;
//	
//	// ....a.1) wait
	for(i=0;i<1500;i++){}
	
	// ....b) select adc channel
	// ....b.1) start adc
	// ....c) wait for adc
	touchX = adcAppReadChannel(ADC_CH_TOUCH_BOTTOM_READ_X); // X is long side
//
//
//	////////////////////////////////////////////
	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
	LATCbits.LATC0 = 0;
	LATCbits.LATC1 = 0;
	for(i=0;i<500;i++){}
//	////////////////////////////////////////////
//	
//	//	....a) set drive B
	LATCbits.LATC0 = 0;
	LATCbits.LATC1 = 0;
//   // PORTC &= 0xFE;
//	
	// ....a.1) wait
	for(i=0;i<1500;i++){}
	
	// ....b) select adc channel
	// ....b.1) start adc
	// ....c) wait for adc
	touchY = adcAppReadChannel(ADC_CH_TOUCH_LEFT_READ_Y); // Y is short side

*/
   
}

char ControlloTouch0 (char i)
{
}

void touchCheckLoopParallel (void)
{
}
