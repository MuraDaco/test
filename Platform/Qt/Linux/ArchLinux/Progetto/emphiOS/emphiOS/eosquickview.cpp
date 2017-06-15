#include <QDebug>
#include "eosquickview.h"

#include "../../../Driver/qtlcdglo.h"
#include "../../../Driver/qtButtonsGlo.h"


//MyQuickView::MyQuickView(QQuickView *parent)
//{
//}

//QQuickItem *item = view.rootObject()->findChild<QQuickItem*>("Testo1");
//if (item)
//    item->setProperty("text", QString("Qt::yellow"));


eosQuickView::eosQuickView(QUrl qurl_file) : QQuickView(qurl_file)
{
    item_riga1 = this->rootObject()->findChild<QQuickItem*>("LcdRiga1");
    item_riga2 = this->rootObject()->findChild<QQuickItem*>("LcdRiga2");
    item_riga3 = this->rootObject()->findChild<QQuickItem*>("LcdRiga3");
    item_riga4 = this->rootObject()->findChild<QQuickItem*>("LcdRiga4");

    startTimer(100);   // 1-second timer
    startTimer(2500);  // 2,5-second timer
}

bool eosQuickView::event(QEvent* ev)
{

//    qDebug("MyQuickView Event!!!! ----------- QEvent Type: (%05d)",ev->type());

    //qDebug() << "MyQuickView Event!!!!";

    // Make sure the rest of events are handled
    return QQuickView::event(ev);
    // return true;

}

void eosQuickView::timerEvent(QTimerEvent *event)
{

    // aggiorna il valore del text

    QString QString_riga1 = QString::fromUtf8(const_cast<char *> (lcd_string[0]));
    QString QString_riga2 = QString::fromUtf8(const_cast<char *> (lcd_string[1]));
    QString QString_riga3 = QString::fromUtf8(const_cast<char *> (lcd_string[2]));
    QString QString_riga4 = QString::fromUtf8(const_cast<char *> (lcd_string[3]));

//    qDebug() << "Timer ID:" << event->timerId();
//    qDebug() << "Prova lcd_string" << myString;

    if (item_riga1)
        item_riga1->setProperty("text", QString_riga1);
    if (item_riga2)
        item_riga2->setProperty("text", QString_riga2);
    if (item_riga3)
        item_riga3->setProperty("text", QString_riga3);
    if (item_riga4)
        item_riga4->setProperty("text", QString_riga4);

}

void eosQuickView::InitLcd1 ()
{
    item_riga1 = this->rootObject()->findChild<QQuickItem*>("LcdRiga1");
    item_riga2 = this->rootObject()->findChild<QQuickItem*>("LcdRiga2");
    item_riga3 = this->rootObject()->findChild<QQuickItem*>("LcdRiga3");
    item_riga4 = this->rootObject()->findChild<QQuickItem*>("LcdRiga4");

}


