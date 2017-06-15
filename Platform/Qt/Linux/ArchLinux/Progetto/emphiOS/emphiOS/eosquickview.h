#ifndef EOSQUICKVIEW_H
#define EOSQUICKVIEW_H

#include <QQuickView>
#include <QQuickItem>


class eosQuickView : public QQuickView
{
    Q_OBJECT

public:
    eosQuickView(QUrl);
    bool event(QEvent* ev);
    void timerEvent(QTimerEvent *event);
    void InitLcd1 ();

private:
    QQuickItem *item_riga1;
    QQuickItem *item_riga2;
    QQuickItem *item_riga3;
    QQuickItem *item_riga4;


//    ~MyQuickView();

};


#endif // EOSQUICKVIEW_H
