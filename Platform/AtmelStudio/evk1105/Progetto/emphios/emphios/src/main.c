/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include <avr32/io.h>


#include "emphios_driver/hw_driver_glo.h"

#include "kr/krProcess.h"
#include "hw_rs2Buttons.h"
#include "hw_msMicro.h"

int main (void)
{

	ProcessInit();
	
	while(1)
	{
		hw_LcdRefresh();
		hw_driver_ButtonRefresh();
		my_task();
		ProcessLoop();
		
		
	}
	
}
