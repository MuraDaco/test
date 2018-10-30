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

#include "msPlatform.h"

#ifdef _COMPILER_MICROCHIP_OLD_C18
#include <p18f45k22.h>
#elif defined _COMPILER_MICROCHIP_GNU_XC8
#include <xc.h>
#endif


#include "rs2ADCGlo.h"

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


#define	ADC_CHS_MASK_0	0x83
#define	ADC_CHS_MASK_1	0x7C
#define	ADC_CHS_AN0		0x00
#define	ADC_CHS_AN1		0x04
#define	ADC_CHS_AN7		0x1C



char adcCHSBuff [ADC_CH_NUMBER] = {
	ADC_CHS_AN0,	// CH_TOUCH_BOTTOM
	ADC_CHS_AN1,	// CH_TOUCH_LEFT
	ADC_CHS_AN7		// CH_LM35
};




void adcInit (void)
{
   // Configure Port
   // see the application
   
   // Configure ADC
   // 01 - Select ADC Conversion Clock
   // ADCS bits in ADCON2
   ADCON2 |= 0x01;
   
   // 02 - Configure Voltage Reference
   // PVCFG e NVCFG bitz in ADCON1
   
   
   // 03 - Select ADC Input Channel - see the read routine
   // CHS in ADCON0
   
   // 04 - Select result format
   //ADFM in ADCON2
   ADCON2bits.ADFM = 0;
   
   // 05 - Select acquisition delay: it's about the acqusition time; 
   //                                  see Fig 17-3 and 17-4 to best understanding its meaning
   // ACQT in ADCON2
   ADCON2 |= 0x30; 
   
   // 06 - Turn on ADC module
   // ADON in ADCON0
   ADCON0bits.ADON = 1;
   
   // Configure ADC Interrupt (Optional)
   
   // 01 - Clear ADC interrupt flag
   // ADIF in PIR1
   PIR1bits.ADIF = 0;
   
   // 02 - Enable ADC interrupot
   // ADIE in PIE1
   // PIE1bits.ADIE = 1
   
   // 03 - Enable peripheral interrupt
   // ADIP in IPR1
   // IPR1bits.ADIP = 0  // default = 0, istruzione non necessaria infatti il valore ?i default
   
   // 04 - Enable global interrupt
   // GIE in INTCON
   // valore impostato nella routine hwInit.c
}


unsigned char adcReadChannel (unsigned char channel)
{
 
   char adc_register;
   
   // select channel
   // 00 - read ADCON0
   adc_register = ADCON0;
   // 01 - clear bit
   adc_register &= ADC_CHS_MASK_0;
   // 02 - set bit
   adc_register |= adcCHSBuff[channel];
   // 03 - set ADCON register
   ADCON0 = adc_register;
   
   
   // Start adc
   ADCON0bits.GO = 1;   

   // adcWait()
   while(ADCON0bits.DONE){ _ASM_01_NOP_50ns }
               
   // read adc value
   return ADRESH;
   
   
}







