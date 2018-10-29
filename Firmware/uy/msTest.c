/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: mdau $																										
   *	REVISION NUMBER:        $Revision: 377 $																											
   *	LAST DATE REVISION:     $Date: 2017-02-10 16:06:23 +0100 (Fri, 10 Feb 2017) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/msTest.c $			
   *																																						
   ****************************************************************************************************************************************************

 */


#define	_TEST_C
 
#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
#include <string.h>

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)

//#include "../cf/ConfigEasyPicV7.h"


// direct dependecies:

//	reverse dependecies: Timer, Glcd, Touch
#include INCLUDE_KR_TIMER_GLO //  "krTimerGlo.h"
#include INCLUDE_RS2_LCD    //  "rs2Lcd.h"
//#include INCLUDE_RS2_GLCD   //  "rs2Glcd.h"

//#include "rs2TouchGlo.h"
#include INCLUDE_RS2_BUTTONS_GLO        // "rs2ButtonsGlo.h"


// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION

// ----------------4567890
#define _DATA_FW  "170215_"
// -----------------890
#define _NUMBER_FW "R01"

// ------------------------123---4567890--1234567--------890
#define  STR_VERSIONE_FW  "FW " _DATA_FW _COMPILER_INFO _NUMBER_FW

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

char Flag;
char Counter;

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

// void InitMicro (void)
// {
// 
//    // set RC0 and RC11 as digital output
//    ANSELC &= 0xCF;
//    TRISC  &= 0xCF;
// 
// }

void TestInit (void)
{
//   ram char str[21];
   //char str[21];

   //strcpypgm2ram(str,(const far _ROM char *)STR_VERSIONE_FW);
   //LcdStrRC(1,0,str);
   
   LcdRomStrRC(1,0,STR_VERSIONE_FW);
   
   
//   LcdSetPosition(3,16);
//   LcdCh('1');
//   LcdCh('6');
//
//   LcdSetPosition(2,17);
//   LcdCh('1');
//   LcdCh('7');
//   
//   LcdSetPosition(4,18);
//   LcdCh('1');
//   LcdCh('2');
//   
//   LcdSetPosition(1,15);
//   LcdCh('1');
//   LcdCh('3');
   
}


void TestTmrSecond (void)
{
   Timer[TMR_SECOND] = 10;
   
//   if(Flag == 0)
//   {
//      Flag = 1;
//      LATC &= 0xCF;            
//   }
//   else
//   {
//      Flag = 0;
//      LATC |= 0x30;            
//   }
}


void TestTmrGLCD (void)
{
//    char centinaia, decine, unita;
//    
//    centinaia = Buttons.Codice/100;
//    decine = (Buttons.Codice - centinaia*100)/10;
//    unita = Buttons.Codice%10;
// 
//    Timer[TMR_TEST_GLCD] = 200;
// 
//    Counter++;
//    Counter &= 0x0F;
// 
//    LcdSetPosition(3,3);
//    LcdCh('0'+centinaia);
//    LcdCh('0'+decine);
//    LcdCh('0'+unita);
// 
//    LcdSetPosition(2,Counter+2);
//    LcdCh(' ');
//    LcdCh('7');
//    
//    LcdSetPosition(4,3);
//    LcdCh('0'+Buttons.Stato);
// //   LcdCh('2');
//    LcdCh(' ');
//    
// //   LcdSetPosition(1,Counter+1);
// //   LcdCh('1');
// //   LcdCh('5');
}
