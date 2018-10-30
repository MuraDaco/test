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

