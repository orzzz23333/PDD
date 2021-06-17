#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    log = new Login;
    warn = new warning;
    client = new Client;
    connect(client, SIGNAL(giveMsg(QString)), this, SLOT(generateModel()));
    init();
    connect(ui->findNameText,SIGNAL(textChanged(QString)),this,SLOT(find()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete log;
    delete warn;
    delete client;
}

void MainWindow::init() {
    QString sql;
    sql = "select ID as \"ID\", name as \"商品名\", price as \"原价(元)\", discount as \"折扣(%)\", inventory as \"库存(件)\", belong as \"商家\", info as \"商品描述\", type as \"类型\" from commodity";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql); loop.exec();
    showTable();
}

void MainWindow::find() {
    QString name, sql;
    name = ui->findNameText->text();
    sql = "select ID as \"ID\", name as \"商品名\", price as \"原价(元)\", discount as \"折扣(%)\", inventory as \"库存(件)\", belong as \"商家\", info as \"商品描述\", type as \"类型\" from commodity where name LIKE '%" + name + "%'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql); loop.exec();
    showTable();
}

bool MainWindow::checkLogin() {
    if (log->u == NULL || log->u == (User *)-1) {
        warn->setText("请先登录！");
        warn->show();
        return false;
    }
    return true;
}

void MainWindow::on_loginButton_clicked() {
    if (log->u != NULL && log->u != (User *)-1) {
        warn->setText("您已登录，请先退出！");
        warn->show();
        return;
    }
    log->show();
}

void MainWindow::on_logoutButton_clicked() {
    if (!checkLogin()) return;
    std::string text(log->u->nickname);
    text = "再见，" + text + "！";
    delete log->u; log->u = NULL;
    warn->setText(text);
    warn->show();
}

void MainWindow::on_userButton_clicked() {
    if (!checkLogin()) return;
    mu = new ManageUser(log->u);
    mu->show();
}

void MainWindow::on_mineButton_clicked() {
    if (!checkLogin()) return;
    if (log->getUserType() == 0) {
        warn->setText("您不是商家！");
        warn->show();
        return;
    }
    QString name, sql;
    name = QString(QLatin1String(log->u->uid));
    sql = "select ID as \"ID\", name as \"商品名\", price as \"原价(元)\", discount as \"折扣(%)\", inventory as \"库存(件)\", belong as \"商家\", info as \"商品描述\", type as \"类型\" from commodity where belong LIKE '%" + name + "%'";
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    client->sendMsg(sql); loop.exec();
    showTable();
}

void MainWindow::on_allButton_clicked() {
    init();
}

void MainWindow::on_commodityButton_clicked() {
    if (!checkLogin()) return;
    if (log->getUserType() == 0) {
        warn->setText("您不是商家！");
        warn->show();
        return;
    }
    cu = new ManageCommodity(log->u, client);
    cu->show();
}

void MainWindow::on_cartButton_clicked() {
    if (!checkLogin()) return;
    if (log->getUserType() == 1) {
        warn->setText("您不是消费者！");
        warn->show();
        return;
    }
    cart = new Cart(log->u, client);
    cart->show();
}

void MainWindow::generateModel() {
    model = client->model;
    emit finished();
}

void MainWindow::showTable() {
    QStandardItemModel *table = new QStandardItemModel();
    ui->tableView->setModel(table);
    table->setColumnCount(8);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    table->setHorizontalHeaderItem(0, new QStandardItem("ID") );
    table->setHorizontalHeaderItem(1, new QStandardItem("商品名"));
    table->setHorizontalHeaderItem(2, new QStandardItem("原价(元)"));
    table->setHorizontalHeaderItem(3, new QStandardItem("折扣(%)"));
    table->setHorizontalHeaderItem(4, new QStandardItem("库存(件)"));
    table->setHorizontalHeaderItem(5, new QStandardItem("商家"));
    table->setHorizontalHeaderItem(6, new QStandardItem("商品描述"));
    table->setHorizontalHeaderItem(7, new QStandardItem("类型"));

    for(int i=0; i<model.size()/8; i++)
        for(int j=0; j<8; j++)
            table->setItem(i, j, new QStandardItem(model.at(i * 8 + j)));
}
