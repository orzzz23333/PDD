#include "form.h"
#include "ui_form.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowTitle(tr("TableWidget"));//设置对话框的标题
    ui->table->setColumnCount(7);//设置列数
    ui->table->setRowCount(10);//设置行数
    ui->table->setWindowTitle("QTableWidget");
    QStringList m_Header;
    m_Header<<QString("序号")<<QString("名称")<<QString("原价")<<QString("库存")<<QString("折扣")<<QString("店铺")<<QString("信息");
    ui->table->setHorizontalHeaderLabels(m_Header);//添加横向表头
    ui->table->verticalHeader()->setVisible(true);//纵向表头可视化
    ui->table->horizontalHeader()->setVisible(true);//横向表头可视化
    //ui->tableWidget->setShowGrid(false);//隐藏栅格
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置编辑方式：禁止编辑表格
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
    //ui->table->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
    ui->table->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    ui->table->setStyleSheet("selection-background-color:pink");//设置选中颜色：粉色
}

Form::~Form()
{
    delete ui;
}
