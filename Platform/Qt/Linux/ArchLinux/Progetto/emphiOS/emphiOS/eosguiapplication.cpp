#include <QDebug>
#include "eosguiapplication.h"


eosGuiApplication::eosGuiApplication(int &argc, char **argv) : QGuiApplication(argc, argv)
{

}

bool eosGuiApplication::event(QEvent* ev)
{

    qDebug("MyGuiApplication Event!!!! --------------------- QEvent Type: (%05d)",ev->type());

    // qDebug() << "MyGuiApplication Event!!!!";


    // Make sure the rest of events are handled
    return QGuiApplication::event(ev);
    // return false;
    // return true;

}

