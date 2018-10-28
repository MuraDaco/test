/*

   MODULE DESCRIPTION:

   AUTHOR:  Marco Ing. Dau

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY
   *
   *	USER who run commit:    $Author: Administrator $
   *	REVISION NUMBER:        $Revision: 370 $
   *	LAST DATE REVISION:     $Date: 2016-08-10 16:12:43 +0200 (Wed, 10 Aug 2016) $
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/uiApplication.c $
   *
   ****************************************************************************************************************************************************

 */

#define _UI_APPLICATION_C

#include "../cf/cfInclude.h"
#include INCLUDE_MS_PLATFORM


// definizione delle costanti presenti nella definizione dei paramteri
#include INCLUDE_UI_PAR_DISPLAY_GLO     // "uiParDisplayGlo.h"

// definizione dei parametri modificabili
#include INCLUDE_UI_GENERAL_EDT             // "ui_GeneralEdt.h"
#include INCLUDE_UI_FN_THERMOSTAT_EDT       // "ui_fnThermostatEdt.h"

// definizione delle variabili visualizzabili
#include INCLUDE_UI_RS2_BUTTONS_DSP         // "ui_rs2ButtonsDsp.h"
#include INCLUDE_UI_FN_THERMOSTAT_DSP       // "ui_fnThermostatDsp.h"

#include INCLUDE_UI_APP_FAT_TEST_DSP        // "ui_AppFatTestDsp.h"


// definizione delle funzioni evento del componente uiButton
#include INCLUDE_UI_APP_BUTTON              // "uiAppButton.h"


// definizione delle strutture e costanti dei componenti grafici
#include INCLUDE_UI_PAGE_GLO       // "uiPageGlo.h"
#include INCLUDE_UI_LBOX_GLO       // "uiLboxGlo.h"
#include INCLUDE_UI_PAR_GLO        // "uiParGlo.h"
#include INCLUDE_UI_VAR_GLO        // "uiVarGlo.h"
#include INCLUDE_UI_STR_GLO        // "uiStrGlo.h"
#include INCLUDE_UI_BUTTON_GLO     // "uiButtonGlo.h"







// SEZIONE - TABELLE MODULI

// MODULO STR

#define  ID_STR_WEB_SITE				                    0x00
#define  ID_STR_E_MAIL					                    0x01
#define  ID_STR_PHONE					                    0x02
#define  ID_STR_PAGE_HOME       	                        0x03
#define  ID_STR_PAGE_SETTINGS_A 	                        0x04
#define  ID_STR_PAGE_SETTINGS_B 	                        0x05
#define  ID_STR_PAGE_INFO    	                            0x06
#define  ID_STR_PAR_TERMOSTATO_SETPOINT			            0x07
#define  ID_STR_PAR_TERMOSTATO_SETPOINT_MIN	                0x08
#define  ID_STR_PAR_TERMOSTATO_SETPOINT_MAX	                0x09
#define  ID_STR_PAR_TERMOSTATO_DELTA				        0x0A
#define  ID_STR_PAR_TERMOSTATO_TEMPO_MINUTI	                0x0B
#define  ID_STR_PAR_TERMOSTATO_TEMPO_SECONDI	            0x0C
#define  ID_STR_PAR_GENERAL_LANGUAGE                        0x0D
#define  ID_STR_VAR_TERMOSTATO_TEMPERATURA	                0x0E
#define  ID_STR_VAR_TERMOSTATO_UMIDITA				        0x0F
#define  ID_STR_VAR_RS2_BUTTONS_TIMES_PRESSED			    0x10
#define  ID_STR_BUTTON_FUNCTION_0                           0x11
#define  ID_STR_BUTTON_FUNCTION_1                           0x12
#define  ID_STR_BUTTON_FUNCTION_2                           0x13
#define  ID_STR_BUTTON_FUNCTION_3                           0x14
#define  ID_STR_BUTTON_FUNCTION_4                           0x15
#define  ID_STR_BUTTON_FUNCTION_5                           0x16
#define  ID_STR_BUTTON_FUNCTION_6                           0x17
#define  ID_STR_VAR_SET_PARTITION_FLAG					    0x18
#define  ID_STR_PAGE_FAT_CMD							    0x19
#define  ID_STR_VAR_FAT_CMD_1								0x1A
#define  ID_STR_VAR_FAT_CMD_2								0x1B
#define  ID_STR_VAR_FAT_CMD_3								0x1C
#define  ID_STR_VAR_FAT_CMD_4								0x1D
#define  ID_STR_VAR_FAT_CMD_5								0x1E
#define  ID_STR_VAR_FAT_STR_TST								0x1F
#define  NUMERO_STR_ELEMENTI        				        0x20


extern _ROM StringTipoItem StrElemento[];
_ROM StringTipoItem StrElemento[NUMERO_STR_ELEMENTI] = {
//   English                 Italiano
//     123456789012345        123456789012345
    {{"www.emphil.com "     ,"www.emphil.com "}}        // ID_STR_WEB_SITE				                    0x00
   ,{{"info@emphil.com"     ,"info@emphil.com"}}        // ID_STR_E_MAIL					                0x01
   ,{{"  xxx-aa.bb.cc "     ,"  xxx-aa.bb.cc "}}        // ID_STR_PHONE					                    0x02
   ,{{"Home           "     ,"Principale     "}}        // ID_STR_PAGE_HOME       	                        0x03
   ,{{"Settings A     "     ,"Parmetri A     "}}        // ID_STR_PAGE_SETTINGS_A 	                        0x04
   ,{{"Settings B     "     ,"Parmetri B     "}}        // ID_STR_PAGE_SETTINGS_B 	                        0x05
   ,{{"Info           "     ,"Info           "}}        // ID_STR_PAGE_INFO    	                            0x06
   ,{{"Setpoin:       "     ,"Setpoint       "}}        // ID_STR_PAR_TERMOSTATO_SETPOINT			        0x07
   ,{{"Setpoint min:  "     ,"Setpoint min:  "}}        // ID_STR_PAR_TERMOSTATO_SETPOINT_MIN	            0x08
   ,{{"Setpoint max:  "     ,"Setpoint max:  "}}        // ID_STR_PAR_TERMOSTATO_SETPOINT_MAX	            0x09
   ,{{"Delta:         "     ,"Delta:         "}}        // ID_STR_PAR_TERMOSTATO_DELTA				        0x0A
   ,{{"Time minutes:  "     ,"Tempo Minuti:  "}}        // ID_STR_PAR_TERMOSTATO_TEMPO_MINUTI	            0x0B
   ,{{"Time seconds:  "     ,"Tempo Secondi: "}}        // ID_STR_PAR_TERMOSTATO_TEMPO_SECONDI	            0x0C
   ,{{"Language       "     ,"Lingua         "}}        // ID_STR_PAR_GENERAL_LANGUAGE				        0x0D
   ,{{"Temperature:   "     ,"Temperatura    "}}        // ID_STR_VAR_TERMOSTATO_TEMPERATURA	            0x0E
   ,{{"Humidity       "     ,"Umidita        "}}        // ID_STR_VAR_TERMOSTATO_UMIDITA				    0x0F
   ,{{"TimesPressed   "     ,"Volte premuto  "}}        // ID_STR_VAR_RS2_BUTTONS_TIMES_PRESSED			    0x10
   ,{{"Button Func 0  "     ,"Bottone Funz 0 "}}        // ID_STR_BUTTON_FUNCTION_0                         0x11
   ,{{"Button Func 1  "     ,"Bottone Funz 1 "}}        // ID_STR_BUTTON_FUNCTION_1                         0x12
   ,{{"Button Func 2  "     ,"Bottone Funz 2 "}}        // ID_STR_BUTTON_FUNCTION_2                         0x13
   ,{{"Button Func 3  "     ,"Bottone Funz 3 "}}        // ID_STR_BUTTON_FUNCTION_3                         0x14
   ,{{"Button Func 4  "     ,"Bottone Funz 4 "}}        // ID_STR_BUTTON_FUNCTION_4                         0x15
   ,{{"Button Func 5  "     ,"Bottone Funz 5 "}}        // ID_STR_BUTTON_FUNCTION_5                         0x16
   ,{{"Button Func 6  "     ,"Bottone Funz 6 "}}        // ID_STR_BUTTON_FUNCTION_6                         0x17
   ,{{"Fat Partition  "     ,"Partizione FAT "}}        // ID_STR_VAR_SET_PARTITION_FLAG                    0x18
   ,{{"PageFAT command"     ,"Pg. comandi FAT"}}        // ID_STR_VAR_FAT_CMD			                    0x19
   ,{{"FAT Cmd Status1"     ,"Stato Cmd FAT 1"}}        // ID_STR_VAR_FAT_CMD_1   		                    0x1A
   ,{{"FAT Cmd Status2"     ,"Stato Cmd FAT 2"}}        // ID_STR_VAR_FAT_CMD_2   		                    0x1B
   ,{{"FAT Cmd Status3"     ,"Stato Cmd FAT 3"}}        // ID_STR_VAR_FAT_CMD_3   		                    0x1C
   ,{{"FAT Cmd Status4"     ,"Stato Cmd FAT 4"}}        // ID_STR_VAR_FAT_CMD_4   		                    0x1D
   ,{{"FAT Cmd Status5"     ,"Stato Cmd FAT 5"}}        // ID_STR_VAR_FAT_CMD_5   		                    0x1E
   ,{{"FAT String Test"     ,"Test String FAT"}}        // ID_STR_VAR_STR_TST   		                    0x1F
};

// MODULO VAR

// Definizione identificativi delle variabili di stato
#define  ID_VAR_TERMOSTATO_TEMPERATURA	   	      0
#define  ID_VAR_TERMOSTATO_UMIDITA				  1
#define  ID_VAR_RS2_BUTTONS_TIMES_PRESSED		  2
#define  ID_VAR_SET_PARTITION_FLAG				  3
#define  ID_VAR_FAT_CMD_1						  4
#define  ID_VAR_FAT_CMD_2						  5
#define  ID_VAR_FAT_CMD_3						  6
#define  ID_VAR_FAT_CMD_4						  7
#define  ID_VAR_FAT_CMD_5						  8
#define  ID_VAR_FAT_STR_TST						  9
#define  NUMERO_VAR_ELEMENTI                      10

// Definizione tabella
extern _ROM VarElementoStruct VarElemento[];
_ROM VarElementoStruct VarElemento[NUMERO_VAR_ELEMENTI] = {
    ROW_VAR_TERMOSTATO_TEMPERATURA     // ID_VAR_TERMOSTATO_TEMPERATURA             0
   ,ROW_VAR_TERMOSTATO_UMIDITA         // ID_VAR_TERMOSTATO_UMIDITA                 1
   ,ROW_VAR_RS2_BUTTONS_TIMES_PRESSED  // ID_VAR_RS2_BUTTONS_TIMES_PRESSED			2
   ,ROW_VAR_SET_PARTITION_FLAG		   // ID_VAR_SET_PARTITION_FLAG				    3
   ,ROW_VAR_FAT_CMD_1				   // ID_VAR_FAT_CMD_1							4
   ,ROW_VAR_FAT_CMD_2				   // ID_VAR_FAT_CMD_2							5
   ,ROW_VAR_FAT_CMD_3				   // ID_VAR_FAT_CMD_3							6
   ,ROW_VAR_FAT_CMD_4				   // ID_VAR_FAT_CMD_4							7
   ,ROW_VAR_FAT_CMD_5				   // ID_VAR_FAT_CMD_5							8
   ,ROW_VAR_FAT_STR_TST				   // ID_VAR_FAT_STR_TST						9
};

// MODULO PAR

// Definizione identificativi dei parametri
#define  ID_PAR_TERMOSTATO_SETPOINT		           0
#define  ID_PAR_TERMOSTATO_SETPOINT_MIN	           1
#define  ID_PAR_TERMOSTATO_SETPOINT_MAX	           2
#define  ID_PAR_TERMOSTATO_DELTA			       3
#define  ID_PAR_TERMOSTATO_TEMPO_MINUTI            4
#define  ID_PAR_TERMOSTATO_TEMPO_SECONDI           5
#define  ID_PAR_GENERAL_LANGUAGE                   6
#define  NUMERO_PAR_ELEMENTI                       7

// Definizione tabella
extern _ROM ParElementoStruct ParElemento[];
_ROM ParElementoStruct ParElemento[NUMERO_PAR_ELEMENTI] = {
    ROW_PAR_TERMOSTATO_SETPOINT		   // ID_PAR_TERMOSTATO_SETPOINT		      0
   ,ROW_PAR_TERMOSTATO_SETPOINT_MIN	   // ID_PAR_TERMOSTATO_SETPOINT_MIN	      1
   ,ROW_PAR_TERMOSTATO_SETPOINT_MAX	   // ID_PAR_TERMOSTATO_SETPOINT_MAX	      2
   ,ROW_PAR_TERMOSTATO_DELTA		   // ID_PAR_TERMOSTATO_DELTA			      3
   ,ROW_PAR_TERMOSTATO_TEMPO_MINUTI    // ID_PAR_TERMOSTATO_TEMPO_MINUTI          4
   ,ROW_PAR_TERMOSTATO_TEMPO_SECONDI   // ID_PAR_TERMOSTATO_TEMPO_SECONDI         5
   ,ROW_PAR_GENERAL_LANGUAGE	       // ID_PAR_GENERAL_LANGUAGE                 6
};


// MODULO BUTTON

// Definizione identificativi dei parametri
#define  ID_BUTTON_FUNCTION_0           0
#define  ID_BUTTON_FUNCTION_1           1
#define  ID_BUTTON_FUNCTION_2           2
#define  ID_BUTTON_FUNCTION_3           3
#define  ID_BUTTON_FUNCTION_4           4
#define  ID_BUTTON_FUNCTION_5           5
#define  ID_BUTTON_FUNCTION_6           6
#define  NUMERO_BUTTON_ELEMENTI         7

// Definizione tabella
extern _ROM ButtonElementoStruct ButtonElemento[];
_ROM ButtonElementoStruct ButtonElemento[NUMERO_BUTTON_ELEMENTI] = {
     ROW_BUTTON_FUNCTION_0	    // ID_BUTTON_FUNCTION_0      0
    ,ROW_BUTTON_FUNCTION_1      // ID_BUTTON_FUNCTION_1      1
    ,ROW_BUTTON_FUNCTION_2      // ID_BUTTON_FUNCTION_2      2
    ,ROW_BUTTON_FUNCTION_3      // ID_BUTTON_FUNCTION_3      3
    ,ROW_BUTTON_FUNCTION_4      // ID_BUTTON_FUNCTION_4      4
    ,ROW_BUTTON_FUNCTION_5      // ID_BUTTON_FUNCTION_5      5
    ,ROW_BUTTON_FUNCTION_6      // ID_BUTTON_FUNCTION_6      6
};


// MODULO LBOX

// Definizione identificativi degli elementi presenti negli "lbox"
#define  ID_LBOX_ELEMENT_0                          0
#define  ID_LBOX_ELEMENT_1                          1
#define  ID_LBOX_ELEMENT_2                          2
#define  ID_LBOX_ELEMENT_3                          3
#define  ID_LBOX_ELEMENT_4                          4
#define  ID_LBOX_ELEMENT_5                          5
#define  ID_LBOX_ELEMENT_6                          6
#define  ID_LBOX_ELEMENT_7                          7
#define  ID_LBOX_ELEMENT_8                          8
#define  ID_LBOX_ELEMENT_9_FAT_CMD                  9
#define  ID_LBOX_ELEMENT_10_FAT_CMD                10
#define  ID_LBOX_ELEMENT_11_FAT_CMD                11
#define  ID_LBOX_ELEMENT_12_FAT_CMD_STATUS         12
#define  ID_LBOX_ELEMENT_13_FAT_CMD_STATUS         13
#define  ID_LBOX_ELEMENT_14_FAT_CMD_STATUS         14
#define  NUMERO_LBOX_LISTA_ELEMENTI                15
// -------------------------------------------------

// Definizione identificativi dei list box
#define	ID_LBOX_TST_1					  0
#define	ID_LBOX_TST_2					  1
#define	ID_LBOX_TST_3				      2
#define	ID_LBOX_TST_4				      3
#define	ID_LBOX_FAT_CMD				      4
#define ID_LBOX_FAT_CMD_STATUS            5
#define  NUMERO_LBOX_ELEMENTI             6

// Definizione tabella
extern _ROM LboxElementoStruct LboxElemento[];
_ROM LboxElementoStruct LboxElemento[NUMERO_LBOX_ELEMENTI] = {
//	   dimensione (numero righe)	,Id_Start_lista_elementi	              ,numero_elementi
    {	2							      ,ID_LBOX_ELEMENT_2				  ,4	               }  //	ID_LBOX_TST_1				0
   ,{	1							      ,ID_LBOX_ELEMENT_1				  ,3	               }  //	ID_LBOX_TST_2				1
   ,{	3							      ,ID_LBOX_ELEMENT_0      			  ,6	               }  //	ID_LBOX_TST_3	   	   		2
   ,{	2							      ,ID_LBOX_ELEMENT_3				  ,3	               }  //	ID_LBOX_TST_4  	   			3
   ,{	2							      ,ID_LBOX_ELEMENT_9_FAT_CMD          ,3	               }  //	ID_LBOX_FAT_CMD  	   		4
   ,{	2							      ,ID_LBOX_ELEMENT_12_FAT_CMD_STATUS  ,3	               }  //	ID_LBOX_FAT_CMD  	   		4
};


// MODULO PAGE

// -------------------------------------------------------------------------

// Definizione identificativi degli elementi presenti nelle "pagine"
#define  ID_PAGE_ELEMENT_00_HOME                     0
#define  ID_PAGE_ELEMENT_01_HOME                     1
#define  ID_PAGE_ELEMENT_02_SETT_A                   2
#define  ID_PAGE_ELEMENT_03_SETT_A                   3
#define  ID_PAGE_ELEMENT_04_SETT_B                   4
#define  ID_PAGE_ELEMENT_05_SETT_B                   5
#define  ID_PAGE_ELEMENT_06_SETT_B                   6
#define  ID_PAGE_ELEMENT_07_INFO                     7
#define  ID_PAGE_ELEMENT_08_INFO                     8
#define  ID_PAGE_ELEMENT_09_INFO                     9
#define  ID_PAGE_ELEMENT_10_FAT_CMD                 10
#define  ID_PAGE_ELEMENT_11_FAT_CMD                 11
#define  NUMERO_PAGE_LISTA_ELEMENTI                 12

// Definizione identificativi delle pagine
#define  ID_PAGE_HOME			         0
#define  ID_PAGE_SETTINGS_A	             1
#define  ID_PAGE_SETTINGS_B	             2
#define  ID_PAGE_FAT_CMD	             3
#define  ID_PAGE_INFO			         4
#define  NUMERO_PAGE_ELEMENTI            5


// Definizione tabella
extern _ROM PageElementoStruct	PageElemento[];
_ROM PageElementoStruct	PageElemento[NUMERO_PAGE_ELEMENTI] = {
//	   Titolo		   	      ,Id_Start_lista_elementi   ,numero_elementi  ,IdPrevNext             ,IdPageNext
    {	ID_STR_PAGE_HOME       	,ID_PAGE_ELEMENT_00_HOME    ,2       		   ,ID_PAGE_FAT_CMD		   ,ID_PAGE_SETTINGS_A  }	//	ID_PAGE_HOME				0
   ,{	ID_STR_PAGE_SETTINGS_A 	,ID_PAGE_ELEMENT_02_SETT_A  ,2       		   ,ID_PAGE_HOME           ,ID_PAGE_SETTINGS_B  }	//	ID_PAGE_SETTINGS_A		1
   ,{	ID_STR_PAGE_SETTINGS_B 	,ID_PAGE_ELEMENT_04_SETT_B  ,3       		   ,ID_PAGE_SETTINGS_A     ,ID_PAGE_FAT_CMD     }	//	ID_PAGE_SETTINGS_B		2
   ,{	ID_STR_PAGE_FAT_CMD		,ID_PAGE_ELEMENT_10_FAT_CMD ,2       		   ,ID_PAGE_SETTINGS_B     ,ID_PAGE_HOME        }	//	ID_PAGE_FAT_CMD		    3
   ,{	ID_STR_PAGE_INFO    	,ID_PAGE_ELEMENT_07_INFO	,3       		   ,ID_PAGE_INFO		   ,ID_PAGE_INFO        }	//	ID_PAGE_INFO				4
};


// SEZIONE - TABELLE DELLE LISTE ELEMENTI DEI MODULI PAGE E LBOX

//
_ROM LboxListaElementiStruct LboxListaElementi[NUMERO_LBOX_LISTA_ELEMENTI] = {
//    IdParametro				               ,TipoElemento (Label, EditBox)
// ---------------------------------------------------------------------------------------------
     {	ID_PAR_TERMOSTATO_SETPOINT	   		,EL_PAR  }     // ID_LBOX_ELEMENT_0                0
    ,{	ID_PAR_TERMOSTATO_SETPOINT_MIN		,EL_PAR  }     // ID_LBOX_ELEMENT_1                1
    ,{	ID_PAR_TERMOSTATO_SETPOINT_MAX		,EL_PAR  }     // ID_LBOX_ELEMENT_2                2
    ,{	ID_PAR_TERMOSTATO_DELTA     		,EL_PAR  }     // ID_LBOX_ELEMENT_3                3
    ,{	ID_PAR_TERMOSTATO_TEMPO_MINUTI		,EL_PAR  }     // ID_LBOX_ELEMENT_4                4
    ,{	ID_PAR_TERMOSTATO_TEMPO_SECONDI		,EL_PAR  }     // ID_LBOX_ELEMENT_5                5
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
    ,{	ID_VAR_TERMOSTATO_TEMPERATURA	   	,EL_VAR  }     // ID_LBOX_ELEMENT_6                6
    ,{	ID_VAR_TERMOSTATO_UMIDITA			,EL_VAR  }     // ID_LBOX_ELEMENT_7                7
    ,{	ID_PAR_GENERAL_LANGUAGE 			,EL_PAR  }     // ID_LBOX_ELEMENT_8                8
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
    ,{	ID_BUTTON_FUNCTION_2	   			,EL_BUTTON  }  // ID_LBOX_ELEMENT_9_FAT_CMD        9
    ,{	ID_BUTTON_FUNCTION_3				,EL_BUTTON  }  // ID_LBOX_ELEMENT_10_FAT_CMD       10
    ,{	ID_BUTTON_FUNCTION_6 				,EL_BUTTON  }  // ID_LBOX_ELEMENT_11_FAT_CMD       11
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
    ,{	ID_VAR_FAT_CMD_1    	   			,EL_VAR  }     // ID_LBOX_ELEMENT_9_FAT_CMD        13
//    ,{	ID_VAR_FAT_CMD_2    				,EL_VAR  }     // ID_LBOX_ELEMENT_10_FAT_CMD       14
    ,{	ID_VAR_FAT_STR_TST    				,EL_VAR  }     // ID_LBOX_ELEMENT_10_FAT_CMD       14
    ,{	ID_VAR_FAT_CMD_3     				,EL_VAR  }     // ID_LBOX_ELEMENT_11_FAT_CMD       15
// ---------------------------------------------------------------------------------------------
};


//
_ROM PageListaElementiStruct	PageListaElementi[NUMERO_PAGE_LISTA_ELEMENTI] = {
//    IdElemento     					   ,TipoElemento	,Pos:Row			,Pos:Column		Dim:Width
// -------------------------------------------------------------------------------------------------------------------------
    {	ID_PAR_TERMOSTATO_SETPOINT_MIN	   ,EL_PAR			,{1			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_0_HOME
   ,{	ID_LBOX_TST_3     				   ,EL_LBOX			,{2			   ,1		         ,0}	}     // ID_PAGE_ELEMENT_1_HOME
// -------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------
   ,{	ID_VAR_RS2_BUTTONS_TIMES_PRESSED   ,EL_VAR			,{1			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_2_SETT_A
   ,{	ID_LBOX_TST_4     				   ,EL_LBOX			,{2			   ,1		         ,0}	}     // ID_PAGE_ELEMENT_3_SETT_A
// -------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------
   ,{	ID_VAR_SET_PARTITION_FLAG		   ,EL_VAR			,{2			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_4_SETT_B
   ,{	ID_BUTTON_FUNCTION_0		       ,EL_BUTTON		,{3			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_5_SETT_B
   ,{	ID_BUTTON_FUNCTION_1               ,EL_BUTTON		,{4			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_6_SETT_B
// -------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------
   ,{	ID_STR_WEB_SITE					   ,EL_STR			,{2			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_7_INFO
   ,{	ID_STR_E_MAIL					   ,EL_STR			,{3			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_8_INFO
   ,{	ID_STR_PHONE					   ,EL_STR			,{4			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_9_INFO
// -------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------
   ,{	ID_LBOX_FAT_CMD_STATUS  		   ,EL_LBOX			,{1			   ,1		         ,0}	}     // ID_PAGE_ELEMENT_10_FAT_CMD
   ,{	ID_LBOX_FAT_CMD    				   ,EL_LBOX			,{3			   ,1		         ,0}	}     // ID_PAGE_ELEMENT_11_FAT_CMD
// -------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------
//   ,{	ID_VAR_FAT_CMD_1				   ,EL_VAR			,{1			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_10_FAT_CMD
//   ,{	ID_VAR_FAT_CMD_2				   ,EL_VAR			,{2			   ,0		         ,0}	}     // ID_PAGE_ELEMENT_10_FAT_CMD
//   ,{	ID_LBOX_FAT_CMD    				   ,EL_LBOX			,{3			   ,1		         ,0}	}     // ID_PAGE_ELEMENT_11_FAT_CMD
// -------------------------------------------------------------------------------------------------------------------------
};


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

