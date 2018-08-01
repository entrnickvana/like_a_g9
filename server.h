#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
    void newConnection();

private:
    QTcpServer* server;

};

#endif // SERVER_H
