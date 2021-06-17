#include "cart.h"
#include "ui_cart.h"
#include <QStandardItemModel>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QDebug>

Cart::Cart(User *u, Client *client, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cart), u(u), client(client) {
    ui->setupUi(this);
    warn = new warning;
    totMoney = 0;
    QIntValidator *lineInt = new QIntValidator(0, 10000, nullptr);
    ui->numInput->setValidator(lineInt);
    connect(client, SIGNAL(giveMsg(QString)), this, SLOT(generateModel()));
    init();
}

Cart::~Cart() {
    delete ui;
}

void Cart::init() {
    QString CID, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT ID AS \"ID\", name AS \"商品名\", amount AS \"数量(件)\", price AS \"总价(元)\", chosen AS \"是否选中\" FROM cart WHERE CID = '" + CID + "'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql);  loop.exec();
    showTable(5);
}

void Cart::on_cartButton_clicked() {
    buy = new Buy(u, client);
    buy->show();
    connect(buy, SIGNAL(addOK()), this, SLOT(init()));
}

void Cart::on_dealButton_2_clicked() {
    int row = ui->tableView->currentIndex().row();
    QString CID, id, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT ID AS \"ID\", name AS \"商品名\", amount AS \"数量(件)\", price AS \"总价(元)\", chosen AS \"是否选中\" FROM cart WHERE CID = '" + CID + "'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql);  loop.exec();
    id = model.at(row * 5 + 0);
    int chosen = model.at(row * 5 + 4).toInt();
    chosen ^= 1;
    sql = "UPDATE cart SET chosen = '" + QString::number(chosen) + "' WHERE ID = '" + id + "' AND CID = '" + CID + "'";
    client->sendMsg(sql);  loop.exec();
    init();
}

void Cart::on_modifyButton_clicked() {
    int row = ui->tableView->currentIndex().row();
    QString CID, id, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT ID AS \"ID\", name AS \"商品名\", amount AS \"数量(件)\", price AS \"总价(元)\", chosen AS \"是否选中\" FROM cart WHERE CID = '" + CID + "'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql);  loop.exec();
    double money = model.at(row * 5 + 3).toDouble();
    int num = model.at(row * 5 + 2).toDouble();
    money /= num;
    num = ui->numInput->text().toInt();
    money *= num;
    id = model.at(row * 5 + 0);
    if (num == 0) {
        sql = "DELETE FROM cart WHERE ID = '" + id + "' AND CID = '" + CID + "'";
    }
    else {
        sql = "UPDATE cart SET amount = '"+ QString::number(num)
                + "', price = '" + QString::number(money)
                + "' WHERE ID = '" + id + "' AND CID = '" + CID + "'";
    }
    client->sendMsg(sql);  loop.exec();
    init();
    warn->setText("修改成功");
    warn->show();
}

void Cart::on_dealButton_clicked() {
    QString CID, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql);  loop.exec();
    int tot = model.at(0).toInt(), tot2 = tot;
    ui->dealButton_2->setEnabled(false);
    ui->cartButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    totMoney = 0;
    for (int i=0; i<tot; i++) {
        sql = "SELECT ID, amount, price FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
        client->sendMsg(sql);  loop.exec();
        QString id = model.at(i * 3 + 0);
        int num = model.at(i * 3 + 1).toInt();
        totMoney += model.at(i * 3 + 2).toDouble();
        sql = "SELECT inventory FROM commodity WHERE ID = '" + id + "'";
        client->sendMsg(sql);  loop.exec();
        int inventory = model.at(0).toInt();
        if (num > inventory) {
            warn->setText(id.toStdString() + "商品库存不足！\n" + "请修改数量后重新生成订单");
            warn->show(); tot = i;
            break;
        }
        inventory -= num;
        sql = "UPDATE commodity SET inventory = '" + QString::number(inventory) +"' WHERE ID = '" + id + "'";
        client->sendMsg(sql);  loop.exec();
    }
    if (tot != tot2) {
        on_cancelButton_clicked(tot);
        return;
    }
    sql = "SELECT ID AS \"ID\", name AS \"商品名\", amount AS \"数量(件)\", price AS \"总价(元)\" FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
    client->sendMsg(sql);  loop.exec();
    showTable(4);
    ui->dealButton->setEnabled(false);
    ui->cancelButton->setEnabled(true);
    ui->buyButton->setEnabled(true);
    ui->label->setText("订单总价：" + QString::number(totMoney) + "元");
}

void Cart::on_cancelButton_clicked(int tot) {
    QString CID, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql);  loop.exec();
    if (tot == -1) tot = model.at(0).toInt();
    ui->dealButton_2->setEnabled(true);
    ui->cartButton->setEnabled(true);
    ui->modifyButton->setEnabled(true);
    for (int i=0; i<tot; i++) {
        sql = "SELECT ID, amount, price FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
        client->sendMsg(sql);  loop.exec();
        QString id = model.at(i * 3 + 0);
        int num = model.at(i * 3 + 1).toInt();
        sql = "SELECT inventory FROM commodity WHERE ID = '" + id + "'";
        client->sendMsg(sql);  loop.exec();
        int inventory = model.at(0).toInt();
        inventory += num;
        sql = "UPDATE commodity SET inventory = '" + QString::number(inventory) +"' WHERE ID = '" + id + "'";
        qDebug()<<sql;
        client->sendMsg(sql);  loop.exec();
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
    QString CID, sql;
    CID = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql);  loop.exec();
    int tot = model.at(0).toInt();
    for (int i=0; i<tot; i++) {
        sql = "SELECT MID, price FROM cart WHERE CID = '" + CID + "' AND chosen = 1";
        client->sendMsg(sql);  loop.exec();
        QString MID = model.at(i * 2 + 0);
        double money = model.at(i * 2 + 1).toDouble();
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
    client->sendMsg(sql);  loop.exec();
    init();
    ui->dealButton->setEnabled(true);
    ui->cancelButton->setEnabled(false);
    ui->buyButton->setEnabled(false);
    ui->label->setText("等待生成订单中...");
    warn->setText("交易成功");
    warn->show();
}

void Cart::generateModel() {
    model = client->model;
    emit finished();
}

void Cart::showTable(int col) {
    QStandardItemModel *table = new QStandardItemModel();
    ui->tableView->setModel(table);
    table->setColumnCount(col);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    table->setHorizontalHeaderItem(0, new QStandardItem("ID") );
    table->setHorizontalHeaderItem(1, new QStandardItem("商品名"));
    table->setHorizontalHeaderItem(2, new QStandardItem("数量(件)"));
    table->setHorizontalHeaderItem(3, new QStandardItem("总价(元)"));
    if (col >= 5) table->setHorizontalHeaderItem(4, new QStandardItem("是否选中"));

    for(int i=0; i<model.size()/col; i++)
        for(int j=0; j<col; j++)
            table->setItem(i, j, new QStandardItem(model.at(i * col + j)));
}
