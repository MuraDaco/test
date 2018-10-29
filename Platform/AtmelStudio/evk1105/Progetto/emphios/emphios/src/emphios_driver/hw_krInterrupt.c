/******************************************************************************
 *
 *   emphiOS - RTOS, User Interface & Business Logic libriaries
 *   Copyright (C) (2003-2018) Marco Dau
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

 
#define	_HW_INTERRUPT_C 

#include <asf.h>
#include <avr32/io.h>
//#include "conf_board.h"
//#include "cycle_counter.h"
#include "tc.h"

//#include "emphios/firmware/krTimer.h"
#include "kr/krTimer.h"
#include "msPlatform.h"
#include "hw_driver_glo.h"


void InitTC (void);
void InitInterruptTimer (void);


ISR(tc_test_int_handler,14,0) {
	//__attribute__((__interrupt__)) static void tc_test_int_handler(void) {

	if(AVR32_TC.channel[0].SR.cpcs) {
		
		UpdateTimer();
		if(n < 1000) {
			n++;
		} else
		{
			n = 0;
			// toggle
			if (tcIntpTest3) {
				tcIntpTest3 = 0;
				} else {
				tcIntpTest3 = 1;
			}
		}
	}
}


void InitTC (void) {
	tc_interrupt_t bitfield;
	
	bitfield.covfs  = 0;
	bitfield.cpas   = 0;
	bitfield.cpbs   = 0;
	bitfield.cpcs   = 0;
	bitfield.etrgs  = 0;
	bitfield.ldras  = 0;
	bitfield.ldrbs  = 0;
	bitfield.lovrs  = 0;
	
	tc_configure_interrupts(	&AVR32_TC,
	1,
	&bitfield);
	tc_configure_interrupts(	&AVR32_TC,
	2,
	&bitfield);
	bitfield.covfs  = 0;
	bitfield.cpas   = 0;
	bitfield.cpbs   = 0;
	bitfield.cpcs   = 1;
	bitfield.etrgs  = 0;
	bitfield.ldras  = 0;
	bitfield.ldrbs  = 0;
	bitfield.lovrs  = 0;
	
	tc_configure_interrupts(	&AVR32_TC,
	0,
	&bitfield);
}




//	****************************************************************************
//	****************************************************************************
void InitInterruptTimer (void)
{

	//  irq_initialize_vectors();
	irq_register_handler(tc_test_int_handler, AVR32_TC_IRQ0, 0);
	
	
	
	AVR32_TC.channel[0].CCR.clkdis = 0;
	AVR32_TC.channel[0].CCR.clken  = 1;
	AVR32_TC.channel[0].CCR.swtrg  = 1;
	AVR32_TC.channel[0].CMR.capture.tcclks = 1;
	AVR32_TC.channel[0].CMR.capture.cpctrg = 1;
	AVR32_TC.channel[0].CMR.capture.wave   = 0;
	// AVR32_TC.channel[0].rc = 0x7947;  // stessa cosa dei precedenti 0x7947;  // Buono: oscilla tra 499,021Hz e 500,978 0x7945;  // Buono: oscilla tra 499,021Hz e 500,978 0x7946;
	AVR32_TC.channel[0].rc = 0x7947;  // stessa cosa dei precedenti 0x7947;  // Buono: oscilla tra 499,021Hz e 500,978 0x7945;  // Buono: oscilla tra 499,021Hz e 500,978 0x7946;
	
	InitTC();
	
	//Enable_global_interrupt();
	cpu_irq_enable();

  
}


