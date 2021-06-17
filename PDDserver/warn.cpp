#include "warn.h"
#include "ui_warn.h"

Warn::Warn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Warn)
{
    ui->setupUi(this);
}

Warn::~Warn()
{
    delete ui;
}

void Warn::setText(QString str)
{
    ui->label->setText(str);
}
