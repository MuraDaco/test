/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 370 $																											
   *	LAST DATE REVISION:     $Date: 2016-08-10 16:12:43 +0200 (Wed, 10 Aug 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/uiVar.c $			
   *																																						
   ****************************************************************************************************************************************************

 */


#define _UI_VAR_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

#include INCLUDE_UI_BASE_GLO        //  "uiBaseGlo.h"
#include INCLUDE_UI_VAR_GLO         //  "uiVarGlo.h"
#include INCLUDE_KR_TIMER_GLO       //  "krTimerGlo.h"
#include INCLUDE_UI_STR_GLO         //  "uiStrGlo.h"
#include INCLUDE_RS2_LCD            //  "rs2Lcd.h"
#include INCLUDE_UI_GENERAL_EDT     //  "ui_GeneralEdt.h"
#include INCLUDE_UI_PAR_DISPLAY_GLO //  "uiParDisplayGlo.h"



extern char id_istanza_end;
char id_istanza_end;

typedef struct {
   BaseCoordinateStruct       coordinate;
   _ROM VarElementoStruct     *ptr_istanza_statica;   
} VarIstanzaDynStruct;

extern VarIstanzaDynStruct uiVarIstanzaDyn[3];
VarIstanzaDynStruct uiVarIstanzaDyn[3];



void uiVarElimina    (void)
{
   id_istanza_end = 0;
   Timer[TMR_UI_VAR] = 1;   
}

void uiVarValueDisplay    (unsigned char id)
{
//   char row, col;
//   char *ptr_par;
//   
//   ptr_par = uiVarIstanzaDyn[id_istanza_end].ptr_istanza_statica->ptr_par;
//   row = uiVarIstanzaDyn[id_istanza_end].coordinate.o_row;
//   col = uiVarIstanzaDyn[id_istanza_end].coordinate.o_col;
   // 1. Chiama la funzione del display alfanumerico
    if(uiVarIstanzaDyn[id].ptr_istanza_statica->flag1 == WORD) {
        LcdNumberRC(uiVarIstanzaDyn[id].coordinate.o_row,
                    uiVarIstanzaDyn[id].coordinate.o_col+16,
                    *uiVarIstanzaDyn[id].ptr_istanza_statica->ptr_par);
    } else if(uiVarIstanzaDyn[id].ptr_istanza_statica->flag1 == STR) {
        //*(uiVarIstanzaDyn[id].ptr_istanza_statica->ptr_par + 4) = 0;
        //(char *)(uiVarIstanzaDyn[id].ptr_istanza_statica->ptr_par)[4] = 0;
        uiVarIstanzaDyn[id].ptr_istanza_statica->ptr_par[3] = 0;
        LcdRomStrRC(uiVarIstanzaDyn[id].coordinate.o_row,
                    uiVarIstanzaDyn[id].coordinate.o_col+16,
                    uiVarIstanzaDyn[id].ptr_istanza_statica->ptr_par);
    }
               
}

void uiVarLabelDisplay    (unsigned char id)
{
//   char row, col;
//
//   row = uiVarIstanzaDyn[id_istanza_end].coordinate.o_row;
//   col = uiVarIstanzaDyn[id_istanza_end].coordinate.o_col;
   // 1. Chiama la funzione del display alfanumerico
   LcdRomStrRC(uiVarIstanzaDyn[id].coordinate.o_row,
               uiVarIstanzaDyn[id].coordinate.o_col,
               StrElemento[uiVarIstanzaDyn[id].ptr_istanza_statica->id_label].Lang[Language]);

}

void uiVarTimer (void)
{
   unsigned char i;
   
   for(i=0;i<id_istanza_end;i++)
   {
      // aggiorna valore
      uiVarValueDisplay(i);
   }
   
   Timer[TMR_UI_VAR] = 100;
}

void uiVarInitCold		      (void)
{  
   id_istanza_end = 0;
   Timer[TMR_UI_VAR] = 1;
}  
   
void uiVarInitLight		   (char element_id)
{  
}  

void uiVarVisualizza       (char element_id, BaseCoordinateStruct coordinate)
{
   uiVarIstanzaDyn[id_istanza_end].coordinate = coordinate;
   uiVarIstanzaDyn[id_istanza_end].ptr_istanza_statica = &VarElemento[element_id];
   uiVarLabelDisplay(id_istanza_end);
   
   id_istanza_end++;
   // visualizza etichetta e valore
   
   
   // attiva timer
   Timer[TMR_UI_VAR] = 0;
   
   
}
   
void uiVarDeselect           (void)
{
}

void VarSetState	      (void)
{
   
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

