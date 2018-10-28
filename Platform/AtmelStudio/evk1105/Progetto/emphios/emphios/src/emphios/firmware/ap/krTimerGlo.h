/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: mdau $																										
   *	REVISION NUMBER:        $Revision: 377 $																											
   *	LAST DATE REVISION:     $Date: 2017-02-10 16:06:23 +0100 (Fri, 10 Feb 2017) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/krTimerGlo.h $			
   *																																						
   ****************************************************************************************************************************************************

 */

#ifdef _DEF_C
#define _EXTERN_DEF
#else
#define _EXTERN_DEF extern
#endif


#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

// definizione della funzione evento
#include INCLUDE_KR_EVENT_GLO       // "krEventGlo.h"



// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE (Dependecies)


// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION

#define	TMR_SECOND		0  //  modulo Test  
#define	TMR_TEST_GLCD	1  //  modulo Test 
#define	TMR_TOUCH		2  //  modulo Touch
#define	TMR_LCD_INIT	3  //  non fare niente
#define	TMR_BUTTONS		4  //  modulo Buttons
#define	TMR_UI_PAR		5  //  modulo Parameter
#define	TMR_UI_LBOX		6  //  modulo ListBox
#define	TMR_UI_VAR		7  //  modulo Variable
#define	TMR_UI_BUTTON	8  //  modulo Parameter
#define TMR_NUMBER		9


// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

#if defined(_DEF_C) || defined(_TIMER_C) || defined(_TEST_C) || defined(_TOUCH_C) || defined(_HW_LCD_C) || defined(_BUTTONS_C) || \
    defined(_UI_PAR_C) || defined(_UI_VAR_C) || defined(_UI_LBOX_C) || defined(_UI_BUTTON_C) || defined(FW_TEST_H)
_EXTERN_DEF	int TmrSecond;
_EXTERN_DEF	int TmrError;
_EXTERN_DEF	int TmrTouch;
_EXTERN_DEF	int Timer[TMR_NUMBER];
#endif


extern _ROM EventTableDef EventTimer[];

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

