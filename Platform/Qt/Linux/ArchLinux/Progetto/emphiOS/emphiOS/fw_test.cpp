#include <QDebug>

#include "fw_test.h"

#include "../../../../../../../Include/Driver/hw_rs2Lcd.h"
#include "../../../../../../../Include/Driver/hw_rs2Buttons.h"
#include "../../../../../../../Firmware/krTimerGlo.h"
#include "../../../../../../../Firmware/rs2ButtonsGlo.h"


fw_test::fw_test(QObject *parent) : QObject(parent)
{

}

void fw_test::event_process_init()
{
    hw_LcdInit();
    hw_ButtonsReset();

}

void fw_test::event_process_loop()
{
    unsigned char key;


    // test Interrupt timer
    if(Timer[TMR_SECOND] == 0) {
        qDebug() << "Timer TMR_SECOND scaduto!!!! - Adesso lo ricarico!";
        Timer[TMR_SECOND] = 1000;
    }

    // test tastiera
    key = hw_ButtonsRead();
    if(key != 0)
    {
        hw_LcdInit();
        // visualizza su Lcd il tasto premuto

        if(key == CODE_BUTTONS_UP)
        {
            hw_LcdSetPosition(1,3);
            hw_LcdCh('A');
            hw_LcdCh('B');
            hw_LcdCh('C');
        }

        if(key == CODE_BUTTONS_DOWN)
        {
            hw_LcdSetPosition(2,3);
            hw_LcdCh('D');
            hw_LcdCh('E');
            hw_LcdCh('F');
        }

        if(key == CODE_BUTTONS_LEFT)
        {
            hw_LcdSetPosition(3,3);
            hw_LcdCh('G');
            hw_LcdCh('H');
            hw_LcdCh('I');
        }

        if(key == CODE_BUTTONS_RIGHT)
        {
            hw_LcdSetPosition(4,3);
            hw_LcdCh('L');
            hw_LcdCh('M');
            hw_LcdCh('N');
        }

        qDebug() << "Tasto premuto da Test!!!! ";


        hw_ButtonsReset();
    }

}
