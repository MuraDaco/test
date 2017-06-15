#ifndef FW_TEST_H
#define FW_TEST_H

#include <QObject>

class fw_test : public QObject
{
    Q_OBJECT
public:
    explicit fw_test(QObject *parent = 0);

    void event_process_init (void);
    void event_process_loop (void);

signals:

public slots:
};

#endif // FW_TEST_H
