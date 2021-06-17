#include "buy.h"
#include "ui_buy.h"
#include <qsqlquerymodel.h>
#include <QModelIndex>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QDebug>

Buy::Buy(User *u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buy), u(u) {
    ui->setupUi(this);
    warn = new warning;
    QIntValidator *lineInt = new QIntValidator(0, 10000, nullptr);
    ui->numInput->setValidator(lineInt);
}
Buy::~Buy() {
    delete ui;
    delete warn;
}


void Buy::on_pushButton_2_clicked() {
    this->close();
}

void Buy::on_IDInput_editingFinished() {
    QSqlQueryModel *model = new QSqlQueryModel;
    QModelIndex index;
    QString name, sql;
    name = QString(QLatin1String(u->uid));
    sql = "SELECT * FROM commodity WHERE ID = '" + ui->IDInput->text() + "'";
    qDebug()<<sql;
    model->setQuery(sql);
    index = model->index(0,1); ui->name->setText(index.data().toString());
    index = model->index(0,2);
    double price = index.data().toDouble();
    index = model->index(0,3);
    price *= 1.0 * (100 - index.data().toInt()) / 100;
    ui->price->setText(QString::number(price));
    index = model->index(0,4); ui->inventory->setText(index.data().toString());
    index = model->index(0,5); ui->merchant->setText(index.data().toString());
    index = model->index(0,6); ui->info->setText(index.data().toString());
    index = model->index(0,7); ui->type->setText(index.data().toString());
}

void Buy::on_buyButton_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel;
    QString name, sql;
    name = QString(QLatin1String(u->uid));
    sql = "SELECT * FROM commodity WHERE ID = '" + ui->IDInput->text() + "'";
    model->setQuery(sql);
    if (model->index(0,1).data().toString().length() == 0) {
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
    model->setQuery(sql);
    qDebug()<<sql;
    on_IDInput_editingFinished();
    warn->setText("购买成功");
    warn->show();
}
