#include "workerthread.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
WorkerThread::WorkerThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
  this->socketDescriptor = ID;
}

void WorkerThread::run(){

    qDebug() << "New Thread ID - " << this->socketDescriptor;

    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor)){

        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));


    qDebug() << socketDescriptor << " - Client connected";

    QString val;
    QFile file;
    //Необходимо указать полный путь к папке с temp.json
    file.setFileName("/Users/admin/temp.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qDebug() << val;



    socket->write(val.toUtf8());
    exec();
}

void WorkerThread::readyRead(){

        QByteArray Data = socket->readAll();


        qDebug() << socketDescriptor << " Data in: " << Data;


}
void WorkerThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    socket->deleteLater();
    exit(0);
}
