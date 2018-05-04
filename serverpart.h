#ifndef SERVERPART_H
#define SERVERPART_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

class ServerPart : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServerPart(QObject *parent = 0);
    void startServer();
signals:

public slots:
    //void newConnection();

private:
    QTcpServer *server;

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // SERVERPART_H
