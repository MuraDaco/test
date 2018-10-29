/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 363 $																											
   *	LAST DATE REVISION:     $Date: 2016-06-16 17:34:11 +0200 (Thu, 16 Jun 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/uiPageGlo.h $			
   *																																						
   ****************************************************************************************************************************************************

 */

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

#include INCLUDE_KR_EVENT_GLO       // "krEventGlo.h"
#include INCLUDE_UI_BASE_GLO        // "uiBaseGlo.h"
 
typedef struct {
   char titolo;
   char list_element_id_start;
   char list_element_number;
	char page_prev_id;
	char page_next_id;
} PageElementoStruct;


//typedef struct {
//   char id_elemento;
//   char tipo_elemento;
//   char row;
//	char column;
//	char width;
//} PageListaElementiStruct;

typedef struct {
   char id_elemento;
   char tipo_elemento;
	BaseCoordinateStruct coordinate;
} PageListaElementiStruct;



#if defined(_UI_BASE_C) || defined(_UI_PAGE_C)
extern _ROM PageElementoStruct			PageElemento[];
#endif

#if defined(_UI_APPLICATION_C) || defined(_UI_PAGE_C)
extern _ROM PageListaElementiStruct	PageListaElementi[];
#endif

#if defined(_UI_BASE_C) || defined(_EVENT_TABLE_C)
extern _ROM EventTableDef uiPageEvent[];
#endif

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

