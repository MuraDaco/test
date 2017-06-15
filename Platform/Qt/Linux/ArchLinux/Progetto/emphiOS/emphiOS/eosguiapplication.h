#ifndef EOSGUIAPPLICATION_H
#define EOSGUIAPPLICATION_H



#include <QGuiApplication>


class eosGuiApplication : public QGuiApplication
{
    Q_OBJECT

public:
    eosGuiApplication(int &argc, char **argv);
    bool event(QEvent* ev);


};



#endif // EOSGUIAPPLICATION_H
