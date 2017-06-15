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

#include "..\..\..\Include\Driver\msPlatform.h"

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
#include <p18f45k22.h>
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Application and Dependecies)

// applications
#include "..\..\..\Firmware\krTimer.h"



#if defined(_COMPILER_MICROCHIP_OLD_C18) && defined(_COMPILER_MICROCHIP_GNU_XC8)
#error DEFINITI TROPPI COMPILATORI, DEFINIRNE UNO SOLO!!!!
#endif

// ----------------------------------------------------------------------------


// SECTION END
//	****************************************************************************



// ----------------------------------------------------------------------------

#ifdef _COMPILER_MICROCHIP_OLD_C18
//	****************************************************************************
void high_isr(void);
//	****************************************************************************
//#pragma code high_vector=0x08
//	****************************************************************************

/* From Pic Documentation
 *
 * For PIC18 devices the high interrupt vector is found at
 * 00000008h. The following code will branch to the
 * high_interrupt_service_routine function to handle
 * interrupts that occur at the high vector.
 *
 */
 
//	****************************************************************************
void interrupt_at_high_vector(void)
{
  _asm GOTO high_isr _endasm
}
//#pragma interrupt high_isr
void high_isr (void)
#elif defined _COMPILER_MICROCHIP_GNU_XC8
void interrupt high_priority high_isr (void)
#endif
{
   // check flag Timer 0
   if(INTCONbits.TMR0IF)
   {
      // clear flag Timer 0 for next interrupt
      INTCONbits.TMR0IF = 0;
      
      // register reload for next interrupt
      TMR0H = 0xC1;  // it MUST write the high byte first
      TMR0L = 0x80;  // writing low byte automatically update the high byte (see the pic datasheet)

      UpdateTimer();
   }
}


#ifdef _COMPILER_MICROCHIP_OLD_C18
void low_isr(void);
#pragma code low_vector=0x18
//	****************************************************************************

/* From Pic Documentation
 *
 * For PIC18 devices the low interrupt vector is found at
 * 00000018h. The following code will branch to the
 * low_interrupt_service_routine function to handle
 * interrupts that occur at the low vector.
 */

 //	****************************************************************************
void interrupt_at_low_vector(void)
{
  _asm GOTO low_isr _endasm
}

#pragma code /* return to the default code section */
#pragma interrupt low_isr

void low_isr (void)
#elif defined _COMPILER_MICROCHIP_GNU_XC8
void interrupt low_priority low_isr (void)
#endif
{
  /* ... */
}


#ifdef _COMPILER_MICROCHIP_OLD_C18
#pragma code /* return to the default code section */
#endif

//	****************************************************************************
//	****************************************************************************
void InitInterruptTimer (void)
{

   // Interrupt
   // switch-off all interrupt
   
   // Timer 0

   // register timer setup for a period of 2ms correspondent to 16000 Tcy
   // so the register have to have the following value 65536-16000 = 49536 = 0xC180
   TMR0H = 0xC1;  // it MUST write the high byte first
   TMR0L = 0x80;  // writing low byte automatically update the high byte (see the pic datasheet)
   
   // set timer 0 to 16bit
   T0CONbits.T08BIT = 0; // by default is 1
   
   // disable the prescaler 
   T0CONbits.PSA  = 1;   // by default is 1, you may omit this instruction
   T0CONbits.T0PS = 0;   // set minimum prescaler value
   
   // enable timer 0 ----------------------------- T0CONbits.TMR0ON = 1;      // by default is 1

   // select source timer 0
   T0CONbits.T0CS   = 0;   // by default is 1
   
   // set timer0 priority (by default is high) --- INTCON2bits.TMR0IP = 1;    // by default is 1
   
   // clear interrupt flag to enable interrupt - INTCONbits.TMR0IF = 0;     // by default is 0
   
   // enable interrupt 
   INTCONbits.TMR0IE = 1; // by default is 0
   
   
   // disable priority level interrupt ----------- RCONbits.IPEN 0;           // by default is 0

   // enable all non-maskered interrupt
   INTCONbits.GIE = 1; // di default ? 0
  
}

