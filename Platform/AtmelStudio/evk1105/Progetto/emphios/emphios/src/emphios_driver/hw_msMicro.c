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

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE

#include <asf.h>
#include <avr32/io.h>

#include "msPlatform.h"
#include "hw_krInterrupt.h"
#include "hw_rs2Lcd.h"

#include "qt1081.h"
#include "tc.h"
#include "et024006dhu.h"
#include "conf_board.h"
#include "cycle_counter.h"
#include "emphios_driver/clocks.h"

#include "navigation.h"

#include "uhc.h"

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

// direct dependecies:

//	reverse dependecies:

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


//#include "usbb_311.h"
#include "usbb_host.h"
#include "hw_msMicro.h"

//sysclk_init();
//irq_initialize_vectors();
//cpu_irq_enable();
//board_init();
//sleepmgr_init(); // Optional

static bool my_flag_autorize_msc_check = false;
static bool happened_usb_interrupt = false;


//void InitMicro (void);
void InitUSB (void);
//bool my_callback_msc_change(uhc_device_t dev, bool b_plug);
void my_task(void);


bool my_callback_msc_change(uhc_device_t* dev, bool b_plug);


bool my_callback_msc_change(uhc_device_t* dev, bool b_plug)
{
	if (b_plug) {
		my_flag_autorize_msc_check = true;
		
	} else {
		my_flag_autorize_msc_check = false;
	}
	
	happened_usb_interrupt=true;
	
	return true;
}



void InitUSB (void) {
	registro_usbb=0;
	registro_usbb1=0;
	registro_usbb2=0;
	uhc_start();
}

void my_task(void)
{
	if(happened_usb_interrupt) {

		happened_usb_interrupt=false;
		
		if (!my_flag_autorize_msc_check) {

			et024006_PrintString("++",
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*1, 180,
			WHITE, BLACK);
			
			et024006_PrintString("22",
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*3, 180,
			WHITE, BLACK);
			
			//uhc_stop(false);
			//uhc_start();
			
		} else {
		    unsigned char drive_nb;
			
			
			et024006_PrintString("OK",
			//(const unsigned char*) &FONT6x8,
			(const unsigned char*) &FONT8x16,
			30*1, 180,
			WHITE, BLACK);
			
		    drive_nb = nav_drive_nb();
	    
			if(drive_nb > 0) {
				et024006_PrintString("QQ",
				//(const unsigned char*) &FONT6x8,
				(const unsigned char*) &FONT8x16,
				30*2, 180,
				WHITE, BLACK);
			}

			if(uhi_msc_mem_get_lun() > 0) {
				et024006_PrintString("11",
				//(const unsigned char*) &FONT6x8,
				(const unsigned char*) &FONT8x16,
				30*3, 180,
				WHITE, BLACK);
			}
		}
	}
	// Check all new USB disks plugged
	// for (uint8_t lun=0; lun < uhi_msc_mem_get_lun(); lun++) {
	// 	// Wait the end of USB disk install
	// 	while (CTRL_BUSY == uhi_msc_mem_test_unit_ready(lun));
	// 	if (CTRL_GOOD != uhi_msc_mem_test_unit_ready(lun)) {
	// 		// Removal disk not present or fail
	// 		continue;
	// 	}
	// 	// Read capacity
	// 	uint32_t max_lba;
	// 	uhi_msc_mem_read_capacity(lun, &max_lba);
	// }
}


void InitMicro (void)
{

	init_sys_clocks();

	//irq_initialize_vectors();
	//cpu_irq_enable();
	//board_init();
	
	board_init();

	//init_sys_clocks();
	//board_init();

	qt1081_power_up();

	// irq_initialize_vectors();
	// irq_register_handler(tc_test_int_handler, AVR32_TC_IRQ0, 0);
	// 
	// 
	// 
	// AVR32_TC.channel[0].CCR.clkdis = 0;
	// AVR32_TC.channel[0].CCR.clken  = 1;
	// AVR32_TC.channel[0].CCR.swtrg  = 1;
	// AVR32_TC.channel[0].CMR.capture.tcclks = 1;
	// AVR32_TC.channel[0].CMR.capture.cpctrg = 1;
	// AVR32_TC.channel[0].CMR.capture.wave   = 0;
	// AVR32_TC.channel[0].rc = 0x7947;  // stessa cosa dei precedenti 0x7947;  // Buono: oscilla tra 499,021Hz e 500,978 0x7945;  // Buono: oscilla tra 499,021Hz e 500,978 0x7946;
	// 
	// InitTC();
	// 
	// Enable_global_interrupt();
	
	irq_initialize_vectors();
	// -----------------------
	InitInterruptTimer();

	
	
	// -----------------------
	
	//cpu_irq_enable();
	//board_init();
	
	et024006_Init(FCPU_HZ, FHSB_HZ);
	et024006_DrawFilledRect(0, 0, ET024006_WIDTH, ET024006_HEIGHT, BLACK);
	gpio_set_gpio_pin(ET024006DHU_BL_PIN);
	et024006_PrintConsole("Marco",BLACK,WHITE);
	et024006_PrintConsole("Gennarina",WHITE,BLACK);

	// FONT6x8 FONT8x8 FONT8x16  
	et024006_PrintString("Marco1234567890",
	(const unsigned char*) &FONT6x8,
	0, 30,
	WHITE, BLACK);

	et024006_PrintString("Marco234567890",
	(const unsigned char*) &FONT6x8,
    6, 40,
	WHITE, BLACK);

	et024006_PrintString("Marco34567890",
	(const unsigned char*) &FONT6x8,
	12, 50,
	WHITE, BLACK);

	et024006_PrintString("Marco4567890",
	(const unsigned char*) &FONT6x8,
	18, 60,
	WHITE, BLACK);
	
	hw_LcdInit();

	uhc_start();
}

