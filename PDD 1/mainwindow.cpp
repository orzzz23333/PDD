#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    log = new Login;
    warn = new warning;
    init();
    connect(ui->findNameText,SIGNAL(textChanged(QString)),this,SLOT(find()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete log;
    delete warn;
}

void MainWindow::init() {
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql = "select ID as \"ID\", name as \"商品名\", price as \"原价(元)\", discount as \"折扣(%)\", inventory as \"库存(件)\", belong as \"商家\", info as \"商品描述\", type as \"类型\" from commodity";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void MainWindow::find() {
    QSqlQueryModel *model=new QSqlQueryModel;
    QString name, sql;
    name = ui->findNameText->text();
    sql = "select ID as \"ID\", name as \"商品名\", price as \"原价(元)\", discount as \"折扣(%)\", inventory as \"库存(件)\", belong as \"商家\", info as \"商品描述\", type as \"类型\" from commodity where name LIKE '%" + name + "%'";
    model->setQuery(sql);
    ui->tableView->setModel(model);
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
    QSqlQueryModel *model = new QSqlQueryModel;
    QString name, sql;
    name = QString(QLatin1String(log->u->uid));
    sql = "select ID as \"ID\", name as \"商品名\", price as \"原价(元)\", discount as \"折扣(%)\", inventory as \"库存(件)\", belong as \"商家\", info as \"商品描述\", type as \"类型\" from commodity where belong LIKE '%" + name + "%'";
    model->setQuery(sql);
    ui->tableView->setModel(model);
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
    cu = new ManageCommodity(log->u);
    cu->show();
}

void MainWindow::on_buyButton_clicked() {
    if (!checkLogin()) return;
    if (log->getUserType() == 1) {
        warn->setText("您不是消费者！");
        warn->show();
        return;
    }
    buy = new Buy(log->u);
    buy->show();
}
