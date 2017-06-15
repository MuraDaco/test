/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: mdau $																										
   *	REVISION NUMBER:        $Revision: 377 $																											
   *	LAST DATE REVISION:     $Date: 2017-02-10 16:06:23 +0100 (Fri, 10 Feb 2017) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/rs2Lcd.c $			
   *																																						
   ****************************************************************************************************************************************************

 */

#define _LCD_C

#include "../Include/Driver/msPlatform.h"

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE



// SECTION END
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

#include "../Include/Driver/hw_rs2Lcd.h"
#include "krTimerGlo.h"


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


void LcdInit (void)
{
	hw_LcdInit();
}


void LcdStrRC  (unsigned char row,unsigned char column,char *str)
{
   hw_LcdSetPosition(row,column);
   
   // write string
   while (*str>0)
   {
      hw_LcdCh(*str);
      str++;
   }   
   
}

void LcdRomStrRC  (unsigned char row,unsigned char column,const _ROM char *str)
{
   hw_LcdSetPosition(row,column);
   
   // write string
   while (*str>0)
   {
      hw_LcdCh(*str);
      str++;
   }   
   
}

void LcdNumberRC  (unsigned char row,unsigned char column,unsigned char par)
{
//   char par;
   unsigned char num[4];
   unsigned char i;
   
   hw_LcdSetPosition(row,column);
   
//   par = *ptr_par;
   num[3] = 0;
   num[2] = par%10;
   num[1] = (par/10)%10;
   num[0] = par/100;
   
   
   // write string
   for(i=0;i<3;i++)
   {
      hw_LcdCh('0'+num[i]);
   }   
   
}

