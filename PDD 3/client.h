#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QByteArray>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    void sendMsg(QString);
    QStringList model;

private slots:
    void recvMsg();

private:
    Ui::Client *ui;
    QTcpSocket *socket;

signals:
    void giveMsg(QString);
};

#endif // CLIENT_H
