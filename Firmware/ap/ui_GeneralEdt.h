/******************************************************************************
 *
 *   emphiOS - RTOS, User Interface & Business Logic libriaries
 *   Copyright (C) (2003-2018) Marco Dau
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


#ifdef _UI_DEF_C
#define _EXTERN_UI_DEF
#else
#define _EXTERN_UI_DEF extern
#endif
 
 

// Definizione dei parametri generali del sistema
#define  PAR_MIN_GENERAL_LANGUAGE      0
#define  PAR_MAX_GENERAL_LANGUAGE      1
#define  PAR_DEF_GENERAL_LANGUAGE      0
#define  PAR_GENERAL_LANGUAGE_NUMBER   PAR_MAX_GENERAL_LANGUAGE + 1
#define	ROW_PAR_GENERAL_LANGUAGE		{	ID_STR_PAR_GENERAL_LANGUAGE		,&Language		,PAR_DEF_GENERAL_LANGUAGE			,PAR_MIN_GENERAL_LANGUAGE		,PAR_MAX_GENERAL_LANGUAGE		,sizeof(Language)		,BYTE			,DIGIT_1		}

_EXTERN_UI_DEF	char Language;

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

