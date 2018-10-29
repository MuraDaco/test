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

#ifndef QTLCDGLO_H
#define QTLCDGLO_H

#ifdef _QT_DEF_CPP
#define _EXTERN_QT_DEF
#else
#define _EXTERN_QT_DEF extern
#endif


#define     LCD_COLUMN     20
#define     LCD_ROW        4

_EXTERN_QT_DEF char lcd_string[LCD_ROW+1][LCD_COLUMN+1];

#endif // QTLCDGLO_H
