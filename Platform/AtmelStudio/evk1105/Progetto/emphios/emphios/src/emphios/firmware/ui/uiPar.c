/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: mdau $																										
   *	REVISION NUMBER:        $Revision: 375 $																											
   *	LAST DATE REVISION:     $Date: 2017-02-09 19:13:40 +0100 (Thu, 09 Feb 2017) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/uiPar.c $			
   *																																						
   ****************************************************************************************************************************************************

 */
 
#define _UI_PAR_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

// #include "krEventGlo.h"
// #include "krEvent.h"

#include INCLUDE_UI_BASE_GLO        //   "uiBaseGlo.h"
#include INCLUDE_UI_PAR_GLO         //   "uiParGlo.h"
#include INCLUDE_UI_STR_GLO         //   "uiStrGlo.h"
#include INCLUDE_UI_GENERAL_EDT     //   "ui_GeneralEdt.h"
#include INCLUDE_RS2_LCD            //   "rs2Lcd.h"
#include INCLUDE_KR_TIMER_GLO       //   "krTimerGlo.h"


extern char Lampeggio;
char Lampeggio;

typedef struct {
   BaseCoordinateStruct       coordinate;
   _ROM ParElementoStruct     *PtrParElemento;
   _ROM BaseElementoStruct    *PtrParBaseElemento;
} ParIstanzaDynStruct;

extern ParIstanzaDynStruct uiParIstanzaDyn;
ParIstanzaDynStruct uiParIstanzaDyn;

// uiParIstanzaDyn.coordinate.o_row,
// uiParIstanzaDyn.coordinate.o_col+16,
// *uiParIstanzaDyn.PtrParElemento->ptr_par
// uiParIstanzaDyn.PtrParBaseElemento
// StrElemento[uiParIstanzaDyn.PtrParElemento->id_label].Lang[Language]
// 
// 
// char ParRow;
// char ParCol;
// _ROM ParElementoStruct   *PtrParElemento;
// _ROM BaseElementoStruct  *PtrParBaseElemento;


//void uiParEventNull (void)
//{
//}

void uiParNull  (void)
{
    
}

void uiParTimer   (void)
{
   // aggiorna il timer
   Timer[TMR_UI_PAR] = 200;
   if(Lampeggio)
   {
      Lampeggio = 0;
      LcdRomStrRC(uiParIstanzaDyn.coordinate.o_row,
                  uiParIstanzaDyn.coordinate.o_col,
                  "               ");
   }
   else
   {
      Lampeggio = 1;
      LcdRomStrRC(uiParIstanzaDyn.coordinate.o_row,
                  uiParIstanzaDyn.coordinate.o_col,
                  StrElemento[uiParIstanzaDyn.PtrParElemento->id_label].Lang[Language]);
   }
   
}


void ValueDisplay    (void)
{
   // 1. Chiama la funzione del display alfanumerico
   LcdNumberRC(uiParIstanzaDyn.coordinate.o_row,
               uiParIstanzaDyn.coordinate.o_col+16,
               *uiParIstanzaDyn.PtrParElemento->ptr_par);
}

void LabelDisplay    (void)
{
   // 1. Chiama la funzione del display alfanumerico
   LcdRomStrRC(uiParIstanzaDyn.coordinate.o_row,
               uiParIstanzaDyn.coordinate.o_col,
               StrElemento[uiParIstanzaDyn.PtrParElemento->id_label].Lang[Language]);
}

void uiParEventButtonsUp      (void)
{
   // incementare il valore
//   *(PtrParElemento->ptr_par) = 47;
   (*uiParIstanzaDyn.PtrParElemento->ptr_par)++;

   // visualizza valore
   ValueDisplay();
}

void uiParEventButtonsDown      (void)
{
   // decementare il valore
   (*uiParIstanzaDyn.PtrParElemento->ptr_par)--;

   // visualizza valore
   ValueDisplay();
}

void uiParEventButtonsRight      (void)
{
   
}

void uiParEventButtonsLeft      (void)
{
   
}

void uiParEventButtonsEnter      (void)
{
   // riattiva la tabella eventi del elemento padre
   uiParIstanzaDyn.PtrParBaseElemento->EventOn(0xFF);
   
   Timer[TMR_UI_PAR] = 200;

}

extern _ROM EventTableDef uiParEvent[];
_ROM EventTableDef uiParEvent[NUMBER_EVENT_BUTTONS] = {
    uiParNull // EventNull                    //    EVENT_BUTTONS_RIGHT     0
   ,uiParEventButtonsUp          //    EVENT_BUTTONS_UP        1
   ,uiParEventButtonsEnter       //    EVENT_BUTTONS_ENTER     2
   ,uiParEventButtonsDown        //    EVENT_BUTTONS_DOWN      3
   ,uiParNull // EventNull                    //    EVENT_BUTTONS_LEFT      4
};                               //    NUMBER_EVENT_BUTTONS    5

void uiParDeselect		(void)
{
   // disattivare il timer di lampeggio dell'etichetta
   Timer[TMR_UI_PAR] = 1;
   
   // visualizza etichetta
   LabelDisplay();
   
//   // azzera il puntatore al parametro
//   PtrParElemento = 0;
}


void uiParInitLight		(char element_id)
{
   // disattiva il timer di lampeggio dell'etichetta
   Timer[TMR_UI_PAR] = 1;
}

void uiParInitCold			(void)
{
   // disattiva il timer di lampeggio dell'etichetta
   Timer[TMR_UI_PAR] = 1;
}

void uiParEventOn	   (unsigned char father_id)
{
   uiParIstanzaDyn.PtrParBaseElemento = BaseElemento + father_id;

   uiParDeselect();
   
   // imposta tabella eventi
   ButtonsEventMatrix[0].EventTable = uiParEvent;
   
}

//void uiParSelect		(char element_id, char o_row, char o_col, char n_row)
char uiParSelect		(char element_id, BaseCoordinateStruct coordinate)
{
   // 0. iniziailizzazione delle variabili globali circoscritte al modulo
   // 0.1. impostare il puntatore al parametro
   uiParIstanzaDyn.PtrParElemento = ParElemento + element_id;
   // 0.2. imposta le coordinate
   uiParIstanzaDyn.coordinate.o_row = coordinate.o_row;
   uiParIstanzaDyn.coordinate.o_col = coordinate.o_col;
   
   // attivare il timer di lampeggio dell'etichetta
   Timer[TMR_UI_PAR] = 200;
   
   return 1;
   
}

//void uiParVisualizza		(char element_id, char o_row, char o_col, char n_row)
void uiParVisualizza		(char element_id, BaseCoordinateStruct coordinate)
{

   // 0. iniziailizzazione delle variabili globali circoscritte al modulo
   // 0.1. impostare il puntatore al parametro
   uiParIstanzaDyn.PtrParElemento = ParElemento + element_id;
   // 0.2. imposta le coordinate
   uiParIstanzaDyn.coordinate.o_row = coordinate.o_row;
   uiParIstanzaDyn.coordinate.o_col = coordinate.o_col;
//   ParRow = o_row;
//   ParCol = o_col;
   
   // 1. visualizza etichetta
   LabelDisplay();
   
   // 1. visualizza valore
   ValueDisplay();
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

