#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client) {
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 7777);
    connect(socket, SIGNAL(readyRead()), this, SLOT(recvMsg()));
}

Client::~Client()
{
    delete ui;
}

void Client::sendMsg(QString str) {
    ui->label->setText(str);
    socket->write(str.toUtf8());
}

void Client::recvMsg() {
    QByteArray arr = socket->readAll();
    QString str = arr.data();
    model = str.split("|");
    emit giveMsg(str);
}
