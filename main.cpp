#include <QCoreApplication>
#include <serverpart.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerPart server;
    server.startServer();
    return a.exec();
}
