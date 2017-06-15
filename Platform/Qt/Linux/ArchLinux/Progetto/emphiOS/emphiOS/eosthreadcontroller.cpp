#include <QEventLoop>

#include "eosthreadcontroller.h"

#include "../../../../../../../Firmware/rs2ButtonsGlo.h"
#include "../../../../../../../Firmware/krTimer.h"
#include "../../../../../../../Firmware/krProcess.h"


eosThreadController::eosThreadController()
{
    eosWorker *worker = new eosWorker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &eosThreadController::operate, worker, &eosWorker::doWork);
    connect(this, &eosThreadController::stop_proc, worker, &eosWorker::doStop);
    connect(worker, &eosWorker::resultReady, this, &eosThreadController::handleResults);
    workerThread.start();
}

//myThreadController::~myThreadController() {
//        workerThread.quit();
//        workerThread.wait();
//}

void eosThreadController::handleResults(const QString &parameter) {

    qDebug() << "myThreadController::handleResults: " << parameter;
}


eosWorker::eosWorker() {
    startTimer(2);
}

void eosWorker::timerEvent(QTimerEvent *event)
{
    UpdateTimer();
}

void eosWorker::doWork(const QString &parameter) {
    QString result;
    QEventLoop event_loop;

    /* ... here is the expensive or blocking operation ... */
    qDebug() << "QThread doWork!!!! " << parameter;

    // 00 - Eseguire la funzione di init del processo
    // 01 - Iniziare il loop dei processi
    // 02 - All'interno del loop eseguire ProcessEvents, ma di chi?
    //      ci si ricava l'eventdispatcher e poi si  chiama il process event del dispatcher

    run = true;

    //thread()->eventDispatcher()->processEvents();


    //fw_test_instance.event_process_init();
    ProcessInit();
    while(run)
    {
        event_loop.processEvents();
        //fw_test_instance.event_process_loop();
        ProcessLoop();
    }


    result = parameter + "   Ended!!!!!!";
    emit resultReady(result);

}

void eosWorker::doStop(const QString &parameter) {
    QString result;

    /* ... here is the expensive or blocking operation ... */
    qDebug() << "QThread doStop!!!! " << parameter;

    run = false;


    result = parameter + "    Completed!!!!";
    emit resultReady(result);

}
