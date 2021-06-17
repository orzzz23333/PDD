#include "server.h"
#include <QDebug>
#include <QSqlQueryModel>

Server::Server(QObject *parent) : QTcpServer(parent) {
    listen(QHostAddress::Any, 7777);
    warn = new Warn;
}

void Server::sendMsg(QString str) {
    socket->write(str.toUtf8());
}

void Server::solve(QString sql) {
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql);
    int row = model->rowCount(), col = model->columnCount();
    sql = "";
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            sql += model->index(i,j).data().toString() + "|";
    if (sql == "") sql = "Success";
    sendMsg(sql);
    warn->setText(sql);
    warn->show();
}

void Server::incomingConnection(qintptr handle) {
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(handle);
    connect(socket, SIGNAL(readyRead()), this, SLOT(rcvMsg()));
}

void Server::rcvMsg() {
    QByteArray arr = socket->readAll();
    QString str = arr.data();
    solve(str);
}


