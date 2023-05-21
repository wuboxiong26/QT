#include "mainwindow.h"
#include "globle.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connect();  //建库、建表、造数据
    MainWindow w;
    w.show();

    return a.exec();
}
