#include <QDebug>
#include "eositem.h"


#include "../../../Driver/qtButtonsGlo.h"
#include "../../../../../../../Firmware/rs/rs2ButtonsGlo.h"

eosItem::eosItem()
{

}

bool eosItem::event(QEvent* ev)
{

//    qDebug("MyQuickItem Event!!!! ---- QEvent Type: (%05d)",ev->type());
//    qDebug() << "Puntatore oggetto MyQuickItem: " << QString("0x%1").arg((quintptr)this, QT_POINTER_SIZE * 2, 16, QChar('0'));
//    qDebug() << "Puntatore Thread MyQuickItem: " << QString("0x%1").arg((quintptr)this->thread(), QT_POINTER_SIZE * 2, 16, QChar('0'));

    // se il tipo di evento è tasto premuto/rilasciato
    // fare il recast dell'evento e ottenere il codice del tasto
    if (ev->type() == QEvent::KeyPress) {
        QKeyEvent *ke = static_cast<QKeyEvent *>(ev);

        switch (ke->key())
        {
        case Qt::Key_Return:
            qDebug("Premuto tasto Return");
            qtKeyPress = CODE_BUTTONS_ENTER;
            return true;
        case Qt::Key_Enter:
            qDebug("Premuto tasto Enter");
            qtKeyPress = CODE_BUTTONS_ENTER;
            return true;
        case Qt::Key_Up:
            qDebug("Premuto tasto Up");
            qtKeyPress = CODE_BUTTONS_UP;
            return true;
        case Qt::Key_Down:
            qDebug("Premuto tasto Down");
            qtKeyPress = CODE_BUTTONS_DOWN;
            return true;
        case Qt::Key_Left:
            qDebug("Premuto tasto Left");
            qtKeyPress = CODE_BUTTONS_LEFT;
            return true;
        case Qt::Key_Right:
            qDebug("Premuto tasto Right");
            qtKeyPress = CODE_BUTTONS_RIGHT;
            return true;

        }
    }



    //qDebug() << "MyItem Event---------------- MyQuickItem Event!!!!";
    //qDebug() << "Object Name: " << app.eventDispatcher()->objectName();
    //qDebug("QEvent Type: (%s)",qPrintable(ev->type()));
    //qDebug() << QString("0x%1").arg((quintptr)app.eventDispatcher(), QT_POINTER_SIZE * 2, 16, QChar('0'));


    // Make sure the rest of events are handled
    return QQuickItem::event(ev);
    // return true;

}
