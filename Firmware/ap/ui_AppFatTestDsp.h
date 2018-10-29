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

#ifndef UI_APPFATTESTDSP_H_
#define UI_APPFATTESTDSP_H_


#ifdef _UI_DEF_C
#define _EXTERN_UI_DEF
#define _UI_DEF_INIT_STRING
#else
#define _EXTERN_UI_DEF extern
#endif



//																Etichetta variabile di stato				,ptr_variabile		,sizeof()					,FLAG1		,FLAG2
#define	ROW_VAR_SET_PARTITION_FLAG		{	ID_STR_VAR_SET_PARTITION_FLAG		,&fatPartitionSetFlag		,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_VAR_FAT_CMD_1				{	ID_STR_VAR_FAT_CMD_1   				,&fatCmd1					,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_VAR_FAT_CMD_2				{	ID_STR_VAR_FAT_CMD_2   				,&fatCmd2					,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_VAR_FAT_CMD_3				{	ID_STR_VAR_FAT_CMD_3   				,&fatCmd3					,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_VAR_FAT_CMD_4				{	ID_STR_VAR_FAT_CMD_4   				,&fatCmd4					,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_VAR_FAT_CMD_5				{	ID_STR_VAR_FAT_CMD_5   				,&fatCmd5					,sizeof(SetPointMax)		,WORD			,DIGIT_3		}
#define	ROW_VAR_FAT_STR_TST     		{	ID_STR_VAR_FAT_STR_TST				,str_tst					,sizeof(SetPointMax)		,STR			,DIGIT_3		}

_EXTERN_UI_DEF char fatPartitionSetFlag;
_EXTERN_UI_DEF char fatCmd1;
_EXTERN_UI_DEF char fatCmd2;
_EXTERN_UI_DEF char fatCmd3;
_EXTERN_UI_DEF char fatCmd4;
_EXTERN_UI_DEF char fatCmd5;

#if defined(_UI_DEF_INIT_STRING)
_EXTERN_UI_DEF char str_tst[10]={'X','-','X','-','X','0'};
#else
_EXTERN_UI_DEF char str_tst[10];
#endif





#endif /* UI_APPFATTESTDSP_H_ */
