/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: mdau $																										
   *	REVISION NUMBER:        $Revision: 377 $																											
   *	LAST DATE REVISION:     $Date: 2017-02-10 16:06:23 +0100 (Fri, 10 Feb 2017) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/hw_rs2Buttons.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define _BUTTONS_C

#include "..\..\..\Include\Driver\msPlatform.h"


#include <p18f45k22.h>

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



void hw_InitButtons  (void)
{
   // J17 a Vcc
   // impostare gli ultimi due pin delle porte B e C in pull_down
   
   // prendere gli ultimi tre pin della port B e della port C
   ANSELB &= 0x3F;
   TRISB  |= 0xC0;
   
   // prendere gli ultimi tre pin della port B e della port C
   ANSELC &= 0x1F;
   TRISC  |= 0xE0;
      
}

unsigned char hw_ButtonsRead		(void)
{
	unsigned char temp, codice;
	
	codice = PORTC&0xE0;
	codice >>=3;
	
	temp = PORTB&0xC0;
	temp >>=6;
	
	codice += temp;
	
	return codice;
}

void hw_ButtonsReset		(void)
{
    
}
