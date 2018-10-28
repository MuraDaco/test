/*

   MODULE DESCRIPTION:  manage interrupt: timer, adc, sci, etc
   
   AUTHOR:  Marco Ing. Dau		 																									
   
   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: mdau $																										
   *	REVISION NUMBER:        $Revision: 373 $																											
   *	LAST DATE REVISION:     $Date: 2017-02-02 16:55:34 +0100 (Thu, 02 Feb 2017) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/hw_krInterrupt.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

 
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


