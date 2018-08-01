#ifndef G9_CLIENT_H
#define G9_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <iostream>
class G9_client : public QObject
{
    Q_OBJECT
public:
    explicit G9_client(QObject *parent = nullptr);
    void Connect();

signals:

public slots:

private:
    QTcpSocket* socket;
};

#endif // G9_CLIENT_H
