#include <QDebug>
#include "eosthreadworker.h"


eosThreadWorker::eosThreadWorker()
{

}


void eosThreadWorker::doWork(const QString &parameter) {
        QString result;
        /* ... here is the expensive or blocking operation ... */
        qDebug() << "QThread doWork!!!! " << parameter;
        emit resultReady(result);
}
