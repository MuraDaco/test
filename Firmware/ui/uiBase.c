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

#define _UI_BASE_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM


//#include "uiApplicationGlo.h" // per eventuali funzioni evento generate dall'utente

#include INCLUDE_UI_GENERAL_EDT // "ui_GeneralEdt.h"

#include INCLUDE_UI_BASE_GLO    // "uiBaseGlo.h"
#include INCLUDE_UI_PAGE_GLO    // "uiPageGlo.h"
#include INCLUDE_UI_LBOX_GLO    // "uiLboxGlo.h"
#include INCLUDE_UI_PAR_GLO     // "uiParGlo.h"
#include INCLUDE_UI_VAR_GLO     // "uiVarGlo.h"
#include INCLUDE_UI_STR_GLO     // "uiStrGlo.h"
#include INCLUDE_UI_BUTTON_GLO  // "uiButtonGlo.h"

#include INCLUDE_UI_PAGE           // "uiPage.h"
#include INCLUDE_UI_LBOX           // "uiLbox.h"
#include INCLUDE_UI_PAR            // "uiPar.h"
#include INCLUDE_UI_VAR            // "uiVar.h"
#include INCLUDE_UI_STR            // "uiStr.h"
#include INCLUDE_UI_BUTTON         // "uiButton.h"


void BaseNull  (void)
{
   
}

void BaseNullPar  (char par)
{
   
}

char BaseNullSelect  (char element_id, BaseCoordinateStruct coordinate)
{
   return 0;
}

void BaseEventOn  (unsigned char par)
{
   
}


//void BaseNullParCoordinate  (char element_id, char o_row, char o_col, char n_row)
//{
//   
//}

void BaseNullParCoordinate  (char element_id, BaseCoordinateStruct coordinate)
{
   
}

#pragma

// _ROM BaseElementoStruct BaseElemento[EL_NUMBER] = {
//                             //,Init			      ,InitLight			   ,EventOn         ,Visualizza                ,Select                     ,Deselect
// /* EL_PAGE		0  */       {	 uiPageInitCold	,uiPageInitLight		,BaseNullPar	  ,BaseNullParCoordinate	  ,BaseNullParCoordinate	   ,BaseNull		}
// /* EL_LBOX		1  */      ,{	 uiLboxInitCold	,uiLboxInitLight		,BaseNullPar	  ,BaseNullParCoordinate	  ,BaseNullParCoordinate	   ,BaseNull		}
// /* EL_PAR		2  */      ,{	 uiParInitCold		,uiParInitLight		,BaseNullPar	  ,BaseNullParCoordinate	  ,BaseNullParCoordinate	   ,BaseNull		}
// /* EL_VAR		3  */      ,{	 uiVarInitCold		,uiVarInitLight		,BaseNullPar	  ,BaseNullParCoordinate	  ,BaseNullParCoordinate	   ,BaseNull		}
// /* EL_STR		4  */      ,{	 uiStrInitCold		,uiStrInitLight		,BaseNullPar	  ,BaseNullParCoordinate	  ,BaseNullParCoordinate	   ,BaseNull		}
// };

extern _ROM BaseElementoStruct BaseElemento[];
_ROM BaseElementoStruct BaseElemento[EL_NUMBER] = {
//                        Init			   ,InitLight			,EventOn         ,Elimina        ,Visualizza             ,Select           ,Deselect
/* EL_PAGE		0  */     {uiPageInitCold	,uiPageInitLight  ,uiPageEventOn	  ,BaseNull	      ,BaseNullParCoordinate  ,BaseNullSelect   ,BaseNull		   }
/* EL_LBOX		1  */    ,{uiLboxInitCold	,BaseNullPar		,uiLboxEventOn	  ,BaseNull       ,uiLboxVisualizza       ,uiLboxSelect	   ,uiLboxDeselect   }
/* EL_PAR		2  */    ,{uiParInitCold	,uiParInitLight	,uiParEventOn	  ,uiParInitCold       ,uiParVisualizza        ,uiParSelect      ,uiParDeselect	   }
/* EL_VAR		3  */    ,{uiVarInitCold	,BaseNullPar		,BaseEventOn	  ,uiVarElimina   ,uiVarVisualizza	      ,BaseNullSelect   ,uiVarDeselect		}
/* EL_STR		4  */    ,{BaseNull		   ,BaseNullPar		,BaseEventOn	  ,BaseNull       ,BaseNullParCoordinate  ,BaseNullSelect   ,BaseNull		   }
/* EL_BUTTON	5  */    ,{uiButtonInitCold	,uiButtonInitLight	,uiButtonEventOn	  ,uiButtonInitCold       ,uiButtonVisualizza        ,uiButtonSelect      ,uiButtonDeselect	   }
};

// _ROM uiFunction0Param BaseElemento_InitCold[EL_NUMBER] = 
// {
//                             //,Init			   
// /* EL_PAGE		0  */       BaseNull	   
// /* EL_LBOX		1  */      ,BaseNull	   
// /* EL_PAR		2  */      ,BaseNull		
// /* EL_VAR		3  */      ,BaseNull		
// /* EL_STR		4  */      ,BaseNull		
// };
// 
// _ROM uiFunction1Param BaseElemento_InitLight[EL_NUMBER] = 
// {
// //InitLight			
// BaseNullPar		
// ,BaseNullPar		
// ,BaseNullPar		
// ,BaseNullPar		
// ,BaseNullPar		
// };
// 
// 
// _ROM uiFunction1Param BaseElemento_EventOn[EL_NUMBER] = 
// {
// //EventOn      
// BaseNullPar	  
// ,BaseNullPar	  
// ,BaseNullPar	  
// ,BaseNullPar	  
// ,BaseNullPar	  
// };
// 
// 
// _ROM uiFunction4Param BaseElemento_Visualizza[EL_NUMBER] = 
// {
// //Visualizza               
// BaseNullParCoordinate	  
// ,BaseNullParCoordinate	  
// ,BaseNullParCoordinate	  
// ,BaseNullParCoordinate	  
// ,BaseNullParCoordinate	  
// };
// 
// _ROM uiFunction4Param BaseElemento_Select[EL_NUMBER] = 
// {
// //Select                    
// BaseNullParCoordinate	   
// ,BaseNullParCoordinate	   
// ,BaseNullParCoordinate	   
// ,BaseNullParCoordinate	   
// ,BaseNullParCoordinate	   
// };
// 
// _ROM uiFunction0Param BaseElemento_Deselect[EL_NUMBER] = 
// {
// //Deselect
// BaseNull
// ,BaseNull
// ,BaseNull
// ,BaseNull
// ,BaseNull
// };

void uiBaseInitCold      (void)
{
   unsigned char i;

   // 1. seleziona la lingua
   Language = 0;
   
   for(i=0;i<EL_NUMBER;i++)
   {
      (BaseElemento[i].InitCold)();
   }

   // Inizializza la pagina attivando il primo elemento
   // N.B.: il primo elemento ha indice '0' (zero)
//   (BaseElemento[EL_PAGE].InitLight)(0);
   uiPageInitLight(0);
}



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

