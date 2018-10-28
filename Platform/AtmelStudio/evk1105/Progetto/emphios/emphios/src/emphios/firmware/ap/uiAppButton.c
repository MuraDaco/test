/*

   MODULE DESCRIPTION:  uiAppButton.c

   AUTHOR:  Marco Ing. Dau



 */

#define _UI_APP_BUTTON_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM


#include INCLUDE_UI_RS2_BUTTONS_DSP     // "ui_rs2ButtonsDsp.h"
#include INCLUDE_UI_APP_BUTTON          // "uiAppButton.h"
#include INCLUDE_UI_APP_FAT_TEST_DSP    // "ui_AppFatTestDsp.h"
//#include "navigation.h"



void uiButtonFunction_0(void){
    // azzerare la variabile contatore tasti premuti
    //rs2ButtonsTimesPressed = 0;

    //fatPartitionSetFlag = nav_partition_set(0);
    //fatPartitionSetFlag = (char) nav_partition_mount();
    fatPartitionSetFlag = 0;

}

void uiButtonFunction_1(void){
    // azzerare la variabile contatore tasti premuti
    fatPartitionSetFlag = 0;
    fatCmd5 = 50;

}

void uiButtonFunction_2(void){
    // azzerare la variabile contatore tasti premuti
    // fatCmd = (char) nav_partition_mount();
    fatCmd1 = 20;
    str_tst[0] = 'S';
    str_tst[1] = 'i';
    str_tst[2] = 'S';
    str_tst[3] = 'i';
    str_tst[4] = 'S';
    str_tst[5] = 'i';

}

void uiButtonFunction_3(void){
    // azzerare la variabile contatore tasti premuti
    //fatCmd = (char) nav_partition_type();
    fatCmd2 = 30;
    str_tst[0] = 'N';
    str_tst[1] = 'o';
    str_tst[2] = 'N';
    str_tst[3] = 'o';
    str_tst[4] = 'N';
    str_tst[5] = 'o';

}

void uiButtonFunction_4(void){
    // azzerare la variabile contatore tasti premuti
    fatCmd3 = 40;

}

void uiButtonFunction_5(void){
    // azzerare la variabile contatore tasti premuti
    //rs2ButtonsTimesPressed = 50;
    fatCmd4 = 50;

}

void uiButtonFunction_6(void){
    // azzerare la variabile contatore tasti premuti
    //rs2ButtonsTimesPressed = 60;
    fatCmd1 = 0;
    fatCmd2 = 0;
    fatCmd3 = 0;
    fatCmd4 = 0;
    fatCmd5 = 0;
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

