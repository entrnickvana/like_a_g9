#include "server.h"


Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    qDebug("Beginning Application\n");

    printf("Beginning Application\n");

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "SERVER COULD NOT START";
    }
    else
    {
        qDebug() << "SERVER STARTED";

    }


}

void Server::newConnection()
{
        // Old Code
        /*
        QTcpSocket* socket = server->nextPendingConnection();

        socket->write("hello client");
        socket->flush();

        socket->waitForBytesWritten(3000);

        socket->readLine();

        socket->close();
        */

    QTcpSocket *socket=server->nextPendingConnection();
    socket->waitForReadyRead(5000);
    if(socket->readLine()=="start")
    {
        qDebug()<<"start";
        socket->write("start");
        socket->flush();
        QString clientmove="something";
        while(clientmove!="close")
        {
            char move[9];
            std::cout<<"ENTER THE MOVE=";
            std::cin>>move;
            socket->write(move);
            socket->flush();
            socket->waitForBytesWritten(10000);
            socket->waitForReadyRead(30000);
            clientmove=socket->readLine();
            qDebug()<<clientmove;
        }
     }
    socket->close();
    socket->waitForDisconnected(3000);

}
