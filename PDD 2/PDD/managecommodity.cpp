#include "managecommodity.h"
#include "ui_managecommodity.h"
#include <qsqlquerymodel.h>
#include <QModelIndex>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QDebug>

ManageCommodity::ManageCommodity(User *u, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageCommodity), u(u)
{
    ui->setupUi(this);
    warn = new warning;
    QDoubleValidator *lineDouble = new QDoubleValidator(0, 1000000, 2, nullptr);
    ui->priceInput->setValidator(lineDouble);
    QIntValidator *lineInt = new QIntValidator(0, 99, nullptr);
    ui->discountInput->setValidator(lineInt);
    lineInt = new QIntValidator(0, 10000, nullptr);
    ui->inventoryInput->setValidator(lineInt);
}

ManageCommodity::~ManageCommodity()
{
    delete ui;
}

void ManageCommodity::on_pushButton_2_clicked() {
    this->close();
}

void ManageCommodity::on_IDInput_editingFinished() {
    QSqlQueryModel *model = new QSqlQueryModel;
    QModelIndex index;
    QString name, sql;
    name = QString(QLatin1String(u->uid));
    sql = "SELECT COUNT(*) FROM commodity WHERE ID = '" + ui->IDInput->text() + "' AND belong = '" + name + "'";
    model->setQuery(sql);
    if (model->index(0,0).data().toInt() == 0) {
        ui->name->setEnabled(true);
        ui->type->setEnabled(true);
    }
    else {
        ui->name->setEnabled(false);
        ui->type->setEnabled(false);
    }
    sql = "SELECT * FROM commodity WHERE ID = '" + ui->IDInput->text() + "' AND belong = '" + name + "'";
    qDebug()<<sql;
    model->setQuery(sql);
    index = model->index(0,1); ui->name->setText(index.data().toString());
    index = model->index(0,2); ui->priceInput->setText(index.data().toString());
    index = model->index(0,3); ui->discountInput->setText(index.data().toString());
    index = model->index(0,4); ui->inventoryInput->setText(index.data().toString());
    index = model->index(0,6); ui->infoInput->setText(index.data().toString());
    index = model->index(0,7); ui->type->setText(index.data().toString());
}

void ManageCommodity::on_modifyButton_clicked() {
    if (ui->name->isEnabled()) {
        warn->setText("不能修改不存在的商品!");
        warn->show(); return;
        return;
    }
    QSqlQueryModel *model = new QSqlQueryModel;
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
    qDebug()<<sql;
    model->setQuery(sql);
    warn->setText("修改成功！");
    warn->show();
}

void ManageCommodity::on_addButton_clicked() {
    if (!ui->name->isEnabled()) {
        warn->setText("不能这样添加商品!");
        warn->show(); return;
        return;
    }
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sql;
    sql = "SELECT COUNT(*) FROM commodity";
    model->setQuery(sql);
    QModelIndex index = model->index(0, 0);
    QString id, name, price, discount, inventory, belong, info, type;
    int tot = index.data().toInt();
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
    qDebug()<<sql;
    model->setQuery(sql);
    warn->setText("添加成功！");
    warn->show();
}

void ManageCommodity::on_discountButton_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel;
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
    model->setQuery(sql);
    warn->setText("打折成功！");
    warn->show();
}
