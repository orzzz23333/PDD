#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include "warn.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void sendMsg(QString);

private:
    QTcpSocket *socket;
    Warn *warn;
    void solve(QString sql);

signals:

private slots:
    void incomingConnection(qintptr handle);
    void rcvMsg();
};

#endif // SERVER_H
