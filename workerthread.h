#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
struct jsonTemplate {
    QString date ;
    QString type;
    QString market;
    int pos;
    double bid;
    double current_rate;
    double total;
};
class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(qintptr ID, QObject *parent = 0);

    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:

    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
    void formJSON();
};

#endif // WORKERTHREAD_H
