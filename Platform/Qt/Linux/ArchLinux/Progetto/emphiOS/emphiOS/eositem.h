#ifndef EOSITEM_H
#define EOSITEM_H

#include <QQuickItem>

class eosItem : public QQuickItem
{
    Q_OBJECT
public:
    eosItem();
    bool event(QEvent* ev);

signals:

public slots:
};

#endif // EOSITEM_H
