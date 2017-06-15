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
