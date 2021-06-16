#include "cart.h"
#include "ui_cart.h"
#include <QModelIndex>
#include <QSqlQueryModel>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QDebug>

Cart::Cart(User *u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cart), u(u) {
    ui->setupUi(this);
    warn = new warning;
    totMoney = 0;
    init();
    QIntValidator *lineInt = new QIntValidator(0, 10000, nullptr);
    ui->numInput->setValidator(lineInt);
}

Cart::~Cart() {
    delete ui;
}

void Cart::init() {
    QSqlQueryModel *model=new QSqlQueryModel;
    QString CID, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT ID AS \"ID\", name AS \"商品名\", amount AS \"数量(件)\", price AS \"总价(元)\", chosen AS \"是否选中\" FROM cart WHERE CID = '" + CID + "'";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void Cart::on_cartButton_clicked() {
    buy = new Buy(u);
    buy->show();
    init();
}

void Cart::on_dealButton_2_clicked() {
    int row = ui->tableView->currentIndex().row();
    QSqlQueryModel *model=new QSqlQueryModel;
    QString CID, id, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT ID AS \"ID\", name AS \"商品名\", amount AS \"数量(件)\", price AS \"总价(元)\", chosen AS \"是否选中\" FROM cart WHERE CID = '" + CID + "'";
    model->setQuery(sql);
    id = model->index(row, 0).data().toString();
    qDebug()<<row<<" "<<id;
    int chosen = model->index(row, 4).data().toInt();
    chosen ^= 1;
    sql = "UPDATE cart SET chosen = '" + QString::number(chosen) + "' WHERE ID = '" + id + "' AND CID = '" + CID + "'";
    qDebug()<<sql;
    model->setQuery(sql);
    init();
}

void Cart::on_modifyButton_clicked() {
    int row = ui->tableView->currentIndex().row();
    QSqlQueryModel *model=new QSqlQueryModel;
    QString CID, id, sql;
    CID = QString(QLatin1String(u->uid));
    id = model->index(row, 0).data().toString();
    sql = "SELECT ID AS \"ID\", name AS \"商品名\", amount AS \"数量(件)\", price AS \"总价(元)\", chosen AS \"是否选中\" FROM cart WHERE CID = '" + CID + "'";
    model->setQuery(sql);
    double money = model->index(row, 3).data().toDouble();
    int num = model->index(row, 2).data().toDouble();
    money /= num;
    num = ui->numInput->text().toInt();
    money *= num;
    id = model->index(row, 0).data().toString();
    if (num == 0) {
        sql = "DELETE FROM cart WHERE ID = '" + id + "' AND CID = '" + CID + "'";
    }
    else {
        sql = "UPDATE cart SET amount = '"+ QString::number(num)
                + "', price = '" + QString::number(money)
                + "' WHERE ID = '" + id + "' AND CID = '" + CID + "'";
    }
    qDebug()<<sql;
    model->setQuery(sql);
    init();
    warn->setText("修改成功");
    warn->show();
}

void Cart::on_dealButton_clicked() {
    QSqlQueryModel *model=new QSqlQueryModel;
    QString CID, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
    model->setQuery(sql);
    int tot = model->index(0,0).data().toInt(), tot2 = tot;
    ui->dealButton_2->setEnabled(false);
    ui->cartButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    totMoney = 0;
    for (int i=0; i<tot; i++) {
        sql = "SELECT ID, amount, price FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
        model->setQuery(sql);
        QString id = model->index(i,0).data().toString();
        int num = model->index(i,1).data().toInt();
        totMoney += model->index(i,2).data().toDouble();
        sql = "SELECT inventory FROM commodity WHERE ID = '" + id + "'";
        model->setQuery(sql);
        int inventory = model->index(0,0).data().toInt();
        if (num > inventory) {
            warn->setText(id.toStdString() + "商品库存不足！\n" + "请修改数量后重新生成订单");
            warn->show(); tot = i;
            break;
        }
        inventory -= num;
        sql = "UPDATE commodity SET inventory = '" + QString::number(inventory) +"' WHERE ID = '" + id + "'";
        qDebug()<<sql;
        model->setQuery(sql);
    }
    if (tot != tot2) {
        on_cancelButton_clicked(tot);
        return;
    }
    sql = "SELECT ID AS \"ID\", name AS \"商品名\", amount AS \"数量(件)\", price AS \"总价(元)\" FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
    model->setQuery(sql);
    ui->tableView->setModel(model);
    ui->dealButton->setEnabled(false);
    ui->cancelButton->setEnabled(true);
    ui->buyButton->setEnabled(true);
    ui->label->setText("订单总价：" + QString::number(totMoney) + "元");
}

void Cart::on_cancelButton_clicked(int tot) {
    QSqlQueryModel *model=new QSqlQueryModel;
    QString CID, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
    model->setQuery(sql);
    if (tot == -1) tot = model->index(0,0).data().toInt();
    ui->dealButton_2->setEnabled(true);
    ui->cartButton->setEnabled(true);
    ui->modifyButton->setEnabled(true);
    for (int i=0; i<tot; i++) {
        sql = "SELECT ID, amount, price FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
        model->setQuery(sql);
        QString id = model->index(i,0).data().toString();
        int num = model->index(i,1).data().toInt();
        sql = "SELECT inventory FROM commodity WHERE ID = '" + id + "'";
        model->setQuery(sql);
        int inventory = model->index(0,0).data().toInt();
        inventory += num;
        sql = "UPDATE commodity SET inventory = '" + QString::number(inventory) +"' WHERE ID = '" + id + "'";
        qDebug()<<sql;
        model->setQuery(sql);
    }
    init();
    ui->dealButton->setEnabled(true);
    ui->cancelButton->setEnabled(false);
    ui->buyButton->setEnabled(false);
    ui->label->setText("等待生成订单中...");
}

void Cart::on_buyButton_clicked() {
    if (u->getBalance() < totMoney) {
        warn->setText("余额不足，请充值！");
        warn->show();
        return;
    }
    u->recharge(-1.0 * totMoney);
    QSqlQueryModel *model=new QSqlQueryModel;
    QString CID, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
    model->setQuery(sql);
    int tot = model->index(0,0).data().toInt();
    for (int i=0; i<tot; i++) {
        sql = "SELECT MID, price FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
        model->setQuery(sql);
        QString MID = model->index(i,0).data().toString();
        double money = model->index(i,1).data().toDouble();
        int index = MID.toInt() - 100000;
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
    }
    sql = "DELETE FROM cart WHERE chosen = 1";
    model->setQuery(sql);
    init();
    ui->dealButton->setEnabled(true);
    ui->cancelButton->setEnabled(false);
    ui->buyButton->setEnabled(false);
    ui->label->setText("等待生成订单中...");
    warn->setText("交易成功");
    warn->show();
}
