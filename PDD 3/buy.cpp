#include "buy.h"
#include "ui_buy.h"
#include <QDoubleValidator>
#include <QIntValidator>
#include <QDebug>

Buy::Buy(User *u, Client *client, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buy), u(u), client(client) {
    ui->setupUi(this);
    warn = new warning;
    QIntValidator *lineInt = new QIntValidator(0, 10000, nullptr);
    ui->numInput->setValidator(lineInt);
    connect(client, SIGNAL(giveMsg(QString)), this, SLOT(generateModel()));
}
Buy::~Buy() {
    delete ui;
    delete warn;
}

void Buy::on_pushButton_2_clicked() {
    this->close();
}

void Buy::on_IDInput_editingFinished() {
    QString name, sql;
    name = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM commodity WHERE ID = '" + ui->IDInput->text() + "'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql);  loop.exec();
    if (model.at(0).toInt() == 0) return;
    sql = "SELECT * FROM commodity WHERE ID = '" + ui->IDInput->text() + "'";
    client->sendMsg(sql); loop.exec();
    ui->name->setText(model.at(1));
    double price = model.at(2).toDouble();
    price *= 1.0 * (100 - model.at(3).toInt()) / 100;
    ui->price->setText(QString::number(price));
    ui->inventory->setText(model.at(4));
    ui->merchant->setText(model.at(5));
    ui->info->setText(model.at(6));
    ui->type->setText(model.at(7));
}

void Buy::on_buyButton_clicked() {
    QString name, sql;
    name = QString(QLatin1String(u->uid));
    sql = "SELECT * FROM commodity WHERE ID = '" + ui->IDInput->text() + "'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql); loop.exec();
    if (model.at(1).length() == 0) {
        warn->setText("不能购买不存在的商品!");
        warn->show();
        return;
    }
    int num = ui->numInput->text().toInt(), inventory = ui->inventory->text().toInt();
    if (num > inventory) {
        warn->setText("库存不足！");
        warn->show();
        return;
    }
    double money = ui->price->text().toDouble() * num;
    if (u->getBalance() < money) {
        warn->setText("余额不足，请充值！");
        warn->show();
        return;
    }
    u->recharge(-1.0 * money);
    inventory -= num;
    int index = ui->merchant->text().toInt() - 100000;
    size_t block;
    std::ifstream in;
    block = sizeof(Merchant);
    in.open(USER_FILE[1], std::ios::binary);
    in.seekg(0, std::ios::end);
    in.seekg(index * block, std::ios::beg);
    Merchant *m = new Merchant;
    in.read((char *)m, block);
    in.close();
    m->recharge(money);
    sql = "UPDATE commodity SET inventory = '" + QString::number(inventory) + "' WHERE ID = '" + ui->IDInput->text() + "'";
    client->sendMsg(sql); loop.exec();
    on_IDInput_editingFinished();
    warn->setText("购买成功");
    warn->show();
}

void Buy::on_cartButton_clicked() {
    QString sql;
    sql = "SELECT * FROM commodity WHERE ID = '" + ui->IDInput->text() + "'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql); loop.exec();
    if (model.at(1).length() == 0) {
        warn->setText("不能购买不存在的商品!");
        warn->show();
        return;
    }
    int num = ui->numInput->text().toInt();
    double money = ui->price->text().toDouble() * num;
    QString id, name, price, CID, MID;
    id = ui->IDInput->text();
    name = ui->name->text();
    price = QString::number(money);
    CID = QString(QLatin1String(u->uid));
    MID = ui->merchant->text();
    sql = "SELECT COUNT(*) FROM cart WHERE ID = '" + ui->IDInput->text() + "' AND CID = '" + CID + "'";
    client->sendMsg(sql); loop.exec();
    if (model.at(0).toInt() == 0) {
        sql = "INSERT INTO cart VALUES ('"
                + id + "', '"
                + name + "', '"
                + QString::number(num) + "', '"
                + price + "', '0', '"
                + CID + "', '"
                + MID + "')";
    }
    else {
        sql = "SELECT amount, price FROM cart WHERE ID = '" + ui->IDInput->text() + "' AND CID = '" + CID + "'";
        client->sendMsg(sql); loop.exec();
        num += model.at(0).toInt();
        money += model.at(1).toDouble();
        price = QString::number(money);
//        sql = "UPDATE cart SET amount = '" + "num" + "' WHERE ID = '" + ui->IDInput->text() + "' AND CID = '" + CID + "'";
        sql = "UPDATE cart SET amount = '" + QString::number(num) + "', price = '" + price
                + "' WHERE ID = '" + ui->IDInput->text() + "' AND CID = '" + CID + "'";
    }
    client->sendMsg(sql); loop.exec();
    on_IDInput_editingFinished();
    warn->setText("已加入购物车");
    warn->show();
    emit(addOK());
}

void Buy::generateModel() {
    model = client->model;
    emit finished();
}
