#ifndef EOSTHREADCONTROLLER_H
#define EOSTHREADCONTROLLER_H


#include <QDebug>

#include <QObject>
#include <QThread>

#include "fw_test.h"


class eosWorker : public QObject
{

    Q_OBJECT

public:
    eosWorker();
    void timerEvent(QTimerEvent *event);

public slots:
    void doWork(const QString &parameter);
    void doStop(const QString &parameter);
signals:
    void resultReady(const QString &result);

private:
    bool run;
    fw_test fw_test_instance;
};



class eosThreadController : public QObject
{

    Q_OBJECT

public:
    eosThreadController();

public slots:
    void handleResults(const QString &parameter);

signals:
    void operate(const QString &parameter);
    void stop_proc(const QString &parameter);

public:
    QThread workerThread;
};


#endif // EOSTHREADCONTROLLER_H
