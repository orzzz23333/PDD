#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>

bool opendatabase() {
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/orzzz/Desktop/PDD/data/commodity.db");
    //mydb.setDatabaseName("./student.db");//release用
    if(mydb.open()) {
        qDebug()<<"open success";
        return true;
    }
    else {
        qDebug()<<"open failed";
        return false;
    }
}

int main(int argc, char *argv[]) {
    opendatabase();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
