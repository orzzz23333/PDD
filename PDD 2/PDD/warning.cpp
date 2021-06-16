#include "warning.h"
#include "ui_warning.h"

warning::warning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::warning)
{
    ui->setupUi(this);
}

warning::~warning()
{
    delete ui;
}

void warning::setText(std::string str) {
    ui->label->setText(QString::fromStdString(str));
}
