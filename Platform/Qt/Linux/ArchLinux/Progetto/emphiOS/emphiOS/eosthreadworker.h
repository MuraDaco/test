#ifndef EOSTHREADWORKER_H
#define EOSTHREADWORKER_H

#include <QObject>


class eosThreadWorker : public QObject
{
    Q_OBJECT
public:
    eosThreadWorker();

public slots:
    void doWork(const QString &parameter);
signals:
    void resultReady(const QString &result);


};



#endif // EOSTHREADWORKER_H
