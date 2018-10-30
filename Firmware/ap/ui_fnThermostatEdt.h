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


#ifdef _UI_DEF_C
#define _EXTERN_UI_DEF
#else
#define _EXTERN_UI_DEF extern
#endif


//																Etichetta parametro							,ptr_parametro		,Default 	,Min		,Max		,sizeof()					,FLAG1		,FLAG2 		
#define	ROW_PAR_TERMOSTATO_SETPOINT			{	ID_STR_PAR_TERMOSTATO_SETPOINT			,&SetPoint			,0x7F			,0x00		,0xFF		,sizeof(SetPoint)			,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_SETPOINT_MIN		{	ID_STR_PAR_TERMOSTATO_SETPOINT_MIN		,&SetPointMin		,0x7F			,0x00		,0xFF		,sizeof(SetPointMin)		,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_SETPOINT_MAX		{	ID_STR_PAR_TERMOSTATO_SETPOINT_MAX		,&SetPointMax		,0x7F			,0x00		,0xFF		,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_DELTA				{	ID_STR_PAR_TERMOSTATO_DELTA				,&Delta				,0x7F			,0x00		,0xFF		,sizeof(Delta)				,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_TEMPO_MINUTI		{	ID_STR_PAR_TERMOSTATO_TEMPO_MINUTI		,&TempoMinuti		,0x7F			,0x00		,0xFF		,sizeof(TempoMinuti)		,WORD			,DIGIT_3		}
#define	ROW_PAR_TERMOSTATO_TEMPO_SECONDI		{	ID_STR_PAR_TERMOSTATO_TEMPO_SECONDI		,&TempoSecondi		,0x7F			,0x00		,0xFF		,sizeof(TempoSecondi)	,WORD			,DIGIT_3		}


_EXTERN_UI_DEF	char SetPoint;		
_EXTERN_UI_DEF	char SetPointMin;	
_EXTERN_UI_DEF	char SetPointMax;	
_EXTERN_UI_DEF	char Delta;
_EXTERN_UI_DEF	char TempoMinuti;	
_EXTERN_UI_DEF	char TempoSecondi;	







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
