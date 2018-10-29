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

#define _UI_BUTTON_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM

#include INCLUDE_UI_BASE_GLO        //   "uiBaseGlo.h"
#include INCLUDE_UI_BUTTON_GLO      //   "uiButtonGlo.h"
#include INCLUDE_UI_STR_GLO         //   "uiStrGlo.h"
#include INCLUDE_UI_GENERAL_EDT     //   "ui_GeneralEdt.h"
#include INCLUDE_RS2_LCD            //   "rs2Lcd.h"
#include INCLUDE_KR_TIMER_GLO       //   "krTimerGlo.h"


extern bool uiButtonPressedFlag;
bool uiButtonPressedFlag;


extern char ButtonLampeggio;
char ButtonLampeggio;

typedef struct {
   BaseCoordinateStruct       coordinate;
   _ROM ButtonElementoStruct     *PtrButtonElemento;
   _ROM BaseElementoStruct    *PtrButtonBaseElemento;
} ButtonIstanzaDynStruct;

extern ButtonIstanzaDynStruct uiButtonIstanzaDyn;
ButtonIstanzaDynStruct uiButtonIstanzaDyn;

//extern void uiAppButtonEventPress (void);

void uiButtonEventButtonsEnter      (void);


void uiButtonNull  (void)
{

}

void uiButtonTimer   (void)
{
    if(uiButtonPressedFlag) {
        uiButtonPressedFlag = false;
        uiButtonEventButtonsEnter();
    }
    else {

        // aggiorna il timer
        Timer[TMR_UI_BUTTON] = 200;
        if(ButtonLampeggio)
        {
           ButtonLampeggio = 0;
           LcdRomStrRC(uiButtonIstanzaDyn.coordinate.o_row,
                       uiButtonIstanzaDyn.coordinate.o_col,
                       "               ");
        }
        else
        {
           ButtonLampeggio = 1;
           LcdRomStrRC(uiButtonIstanzaDyn.coordinate.o_row,
                       uiButtonIstanzaDyn.coordinate.o_col,
                       StrElemento[uiButtonIstanzaDyn.PtrButtonElemento->id_label].Lang[Language]);
        }
    }

}


void ValueButtonDisplay    (void)
{
   // 1. Chiama la funzione del display alfanumerico
}

void LabelButtonDisplay    (void)
{
   // 1. Chiama la funzione del display alfanumerico
   LcdRomStrRC(uiButtonIstanzaDyn.coordinate.o_row,
               uiButtonIstanzaDyn.coordinate.o_col,
               StrElemento[uiButtonIstanzaDyn.PtrButtonElemento->id_label].Lang[Language]);
}

void uiButtonEventButtonsUp      (void)
{
   // incementare il valore
//   *(PtrButtonElemento->ptr_par) = 47;
   //(*uiButtonIstanzaDyn.PtrButtonElemento->ptr_par)++;

   // visualizza valore
   ValueButtonDisplay();
}

void uiButtonEventButtonsDown      (void)
{
   // decementare il valore
   //(*uiButtonIstanzaDyn.PtrButtonElemento->ptr_par)--;

   // visualizza valore
   ValueButtonDisplay();
}

void uiButtonEventButtonsRight      (void)
{

}

void uiButtonEventButtonsLeft      (void)
{

}

void uiButtonEventButtonsEnter      (void)
{
   // riattiva la tabella eventi del elemento padre
   // uiButtonIstanzaDyn.PtrButtonBaseElemento->EventOn(0xFF);
   //
   // Timer[TMR_UI_BUTTON] = 200;


}

extern _ROM EventTableDef uiButtonEvent[];
_ROM EventTableDef uiButtonEvent[NUMBER_EVENT_BUTTONS] = {
    uiButtonNull // EventNull                    //    EVENT_BUTTONS_RIGHT     0
   ,uiButtonEventButtonsUp          //    EVENT_BUTTONS_UP        1
   ,uiButtonEventButtonsEnter       //    EVENT_BUTTONS_ENTER     2
   ,uiButtonEventButtonsDown        //    EVENT_BUTTONS_DOWN      3
   ,uiButtonNull // EventNull                    //    EVENT_BUTTONS_LEFT      4
};                               //    NUMBER_EVENT_BUTTONS    5

void uiButtonDeselect		(void)
{
   // disattivare il timer di lampeggio dell'etichetta
   Timer[TMR_UI_BUTTON] = 1;

   // visualizza etichetta
   LabelButtonDisplay();

//   // azzera il puntatore al parametro
//   PtrButtonElemento = 0;

   // azzera flag Button Pressed
   uiButtonPressedFlag = false;

}


void uiButtonInitLight		(char element_id)
{
   // disattiva il timer di lampeggio dell'etichetta
   Timer[TMR_UI_BUTTON] = 1;
}

void uiButtonInitCold			(void)
{
   // disattiva il timer di lampeggio dell'etichetta
   Timer[TMR_UI_BUTTON] = 1;
}

void uiButtonEventOn	   (unsigned char father_id)
{
   uiButtonIstanzaDyn.PtrButtonBaseElemento = BaseElemento + father_id;

   // uiButtonDeselect();

   // imposta tabella eventi
   // ButtonsEventMatrix[0].EventTable = uiButtonEvent;

   // attiva il timer che automaticamente ritorna il controllo
   // al componente padre ovvero che esegue la funzione uiButtonEnter
   // quasi quasi si può usare lo stesso timer del lampeggio, il problema è che
   // non riesco ad andare oltre i 255 ms (non è proprio così dal momento
   // che il timer è un array di int)

   // avrò bisogno di una flag di stato in cui stabilire come deve comportrsi
   // la funzione timer
   // impostare
   uiButtonPressedFlag = true;
   Timer[TMR_UI_BUTTON] = 2000;

   ButtonLampeggio = 1;
   LcdRomStrRC(uiButtonIstanzaDyn.coordinate.o_row,
               uiButtonIstanzaDyn.coordinate.o_col,
               StrElemento[uiButtonIstanzaDyn.PtrButtonElemento->id_label].Lang[Language]);

    //uiAppButtonEventPress();

    uiButtonIstanzaDyn.PtrButtonElemento->EventPress();

}

//void uiButtonSelect		(char element_id, char o_row, char o_col, char n_row)
char uiButtonSelect		(char element_id, BaseCoordinateStruct coordinate)
{
   // 0. iniziailizzazione delle variabili globali circoscritte al modulo
   // 0.1. impostare il puntatore al parametro
   uiButtonIstanzaDyn.PtrButtonElemento = ButtonElemento + element_id;
   // 0.2. imposta le coordinate
   uiButtonIstanzaDyn.coordinate.o_row = coordinate.o_row;
   uiButtonIstanzaDyn.coordinate.o_col = coordinate.o_col;

   // attivare il timer di lampeggio dell'etichetta
   Timer[TMR_UI_BUTTON] = 200;

   return 1;

}

//void uiButtonVisualizza		(char element_id, char o_row, char o_col, char n_row)
void uiButtonVisualizza		(char element_id, BaseCoordinateStruct coordinate)
{

   // 0. iniziailizzazione delle variabili globali circoscritte al modulo
   // 0.1. impostare il puntatore al parametro
   uiButtonIstanzaDyn.PtrButtonElemento = ButtonElemento + element_id;
   // 0.2. imposta le coordinate
   uiButtonIstanzaDyn.coordinate.o_row = coordinate.o_row;
   uiButtonIstanzaDyn.coordinate.o_col = coordinate.o_col;
//   ParRow = o_row;
//   ParCol = o_col;

   // 1. visualizza etichetta
   LabelButtonDisplay();

   // 1. visualizza valore
   ValueButtonDisplay();
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

