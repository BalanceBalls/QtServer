#include "serverpart.h"
#include "workerthread.h"

ServerPart::ServerPart(QObject *parent) :
    QTcpServer(parent)
{

}

void ServerPart::startServer()
{
    int port = 1234;

    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";
    }
}



void ServerPart::incomingConnection(qintptr socketDescriptor)
{
   qDebug() << socketDescriptor << " Connecting...";


    WorkerThread *thread = new WorkerThread(socketDescriptor, this);

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
