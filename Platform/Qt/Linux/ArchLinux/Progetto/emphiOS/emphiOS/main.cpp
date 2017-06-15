#include <QGuiApplication>

//#include <QQmlApplicationEngine>

#include <QDebug>
#include <QQuickView>
#include <QQuickItem>

#include "eosguiapplication.h"
#include "eosquickview.h"
#include "eositem.h"
#include "eosthreadcontroller.h"


int main(int argc, char *argv[])
{
    eosGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qmlRegisterType<eosItem>("Eos_Item_Cpp", 1, 0, "EosItemCpp");

    //    QQuickView view(QUrl(QStringLiteral("qrc:/main.qml")));
    eosQuickView view(QUrl(QStringLiteral("qrc:/main.qml")));

    view.show();


    QObject *item = view.rootObject();

    eosThreadController *ProvaController = new eosThreadController;

    QObject::connect(item, SIGNAL(qmlSignal_Start(QString)),
                     ProvaController, SIGNAL(operate(QString)));

    QObject::connect(item, SIGNAL(qmlSignal_Stop(QString)),
                     ProvaController, SIGNAL(stop_proc(QString)));


    //emit ProvaController->operate("Prova Start Process");
    //emit ProvaController->stop_proc("Prova Stop Process");



    return app.exec();
}
