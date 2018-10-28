/*

   MODULE DESCRIPTION:  manage project timer

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 359 $																											
   *	LAST DATE REVISION:     $Date: 2016-05-12 16:42:43 +0200 (Thu, 12 May 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/krTimer.h $			
   *																																						
   ****************************************************************************************************************************************************

 */

#ifndef	_TIMER_H
#define	_TIMER_H
 
#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

#include INCLUDE_KR_EVENT_GLO       // "krEventGlo.h"
// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE


// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE

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

#if defined _HW_INTERRUPT_C || defined _FORM1_H || defined EOSTHREADCONTROLLER_H
void UpdateTimer (void);
#endif

#if defined(_PROCESS_TABLE_C)
void InitTimer (void);
//unsigned char ControlloTimer0 (char);
_INTERFACE_EVENT_SUPPLY_(ControlloTimer0,i);
#endif

// SECTION END
//	****************************************************************************


//	****************************************************************************
// SECTION - LIBRTARY FUNCTION DEFINITION

// SECTION END
//	****************************************************************************

#endif	// fine define _TIMER_H



