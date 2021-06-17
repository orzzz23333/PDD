#include "managecommodity.h"
#include "ui_managecommodity.h"
#include <QDoubleValidator>
#include <QIntValidator>
#include <QDebug>
#include <QTimer>
#include <signal.h>

ManageCommodity::ManageCommodity(User *u, Client *client, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageCommodity), u(u), client(client)
{
    ui->setupUi(this);
    warn = new warning;
    QDoubleValidator *lineDouble = new QDoubleValidator(0, 1000000, 2, nullptr);
    ui->priceInput->setValidator(lineDouble);
    QIntValidator *lineInt = new QIntValidator(0, 99, nullptr);
    ui->discountInput->setValidator(lineInt);
    lineInt = new QIntValidator(0, 10000, nullptr);
    ui->inventoryInput->setValidator(lineInt);
    connect(client, SIGNAL(giveMsg(QString)), this, SLOT(generateModel()));
}

ManageCommodity::~ManageCommodity()
{
    delete ui;
}

void ManageCommodity::on_pushButton_2_clicked() {
    this->close();
}

void ManageCommodity::on_IDInput_editingFinished() {
    QString name, sql;
    name = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM commodity WHERE ID = '" + ui->IDInput->text() + "' AND belong = '" + name + "'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql);  loop.exec();
    if (model.at(0).toInt() == 0) {
        ui->name->setEnabled(true);
        ui->type->setEnabled(true);
        return;
    }
    else {
        ui->name->setEnabled(false);
        ui->type->setEnabled(false);
    }
    sql = "SELECT * FROM commodity WHERE ID = '" + ui->IDInput->text() + "' AND belong = '" + name + "'";
    client->sendMsg(sql); loop.exec();
    ui->name->setText(model.at(1));
    ui->priceInput->setText(model.at(2));
    ui->discountInput->setText(model.at(3));
    ui->inventoryInput->setText(model.at(4));
    ui->infoInput->setText(model.at(6));
    ui->type->setText(model.at(7));
}

void ManageCommodity::on_modifyButton_clicked() {
    if (ui->name->isEnabled()) {
        warn->setText("不能修改不存在的商品!");
        warn->show(); return;
        return;
    }
    QString id, sql;
    id = ui->IDInput->text();
    QString price, discount, inventory, info, type;
    price = ui->priceInput->text();
    if (price.length() == 0) {
        warn->setText("价格不能为空！");
        warn->show(); return;
    }
    discount = ui->discountInput->text();
    if (discount.length() == 0) {
        warn->setText("折扣不能为空！");
        warn->show(); return;
    }
    inventory = ui->inventoryInput->text();
    if (inventory.length() == 0) {
        warn->setText("库存不能为空！");
        warn->show(); return;
    }
    info = ui->infoInput->text();
    sql = "UPDATE commodity SET price='" + price +
          "', discount = '" + discount +
          "', inventory = '" + inventory +
          "', info = '" + info +
          "'WHERE ID = '" + id + "'";
    client->sendMsg(sql);
    warn->setText("修改成功！");
    warn->show();
}

void ManageCommodity::on_addButton_clicked() {
    if (!ui->name->isEnabled()) {
        warn->setText("不能这样添加商品!");
        warn->show(); return;
        return;
    }
    QString sql;
    sql = "SELECT COUNT(*) FROM commodity";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql); loop.exec();
    QString id, name, price, discount, inventory, belong, info, type;
    int tot = model.at(0).toInt();
    id = QString::number(tot + 1000);
    name = ui->name->text();
    if (name.length() == 0) {
        warn->setText("名字不能为空！");
        warn->show(); return;
    }
    price = ui->priceInput->text();
    if (price.length() == 0) {
        warn->setText("价格不能为空！");
        warn->show(); return;
    }
    discount = ui->discountInput->text();
    if (discount.length() == 0) {
        warn->setText("折扣不能为空！");
        warn->show(); return;
    }
    inventory = ui->inventoryInput->text();
    if (inventory.length() == 0) {
        warn->setText("库存不能为空！");
        warn->show(); return;
    }
    belong = QString(QLatin1String(u->uid));
    info = ui->infoInput->text();
    type = ui->type->text();
    if (type != "book" && type != "clothes" && type != "food") {
        warn->setText("类型只能是book, clothes或food！");
        warn->show(); return;
    }
    sql = "INSERT INTO commodity VALUES ('"
          + id + "', '"
          + name + "', '"
          + price + "', '"
          + discount + "', '"
          + inventory + "', '"
          + belong + "', '"
          + info + "', '"
          + type + "')";
    client->sendMsg(sql);
    warn->setText("添加成功！");
    warn->show();
}

void ManageCommodity::on_discountButton_clicked() {
    QString type, discount, name, sql;
    type = ui->type->text();
    if (type != "book" && type != "clothes" && type != "food") {
        warn->setText("类型只能是book, clothes或food！");
        warn->show(); return;
    }
    discount = ui->discountInput->text();
    if (discount.length() == 0) {
        warn->setText("折扣不能为空！");
        warn->show(); return;
    }
    name = QString(QLatin1String(u->uid));
    sql = "UPDATE commodity SET discount ='" + discount +
          "'WHERE type = '" + type + "' AND belong = '" + name + "'";
    client->sendMsg(sql);
    warn->setText("打折成功！");
    warn->show();
}

void ManageCommodity::generateModel() {
    model = client->model;
    emit finished();
}
