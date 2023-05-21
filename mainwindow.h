#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include "studentform.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include<manger.h>
namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static QString password_qj;
    static QString username_qj;
    //static QVariantList list_all_student;
    //static QVariantList list_all_dormstudent;


private slots:
    void on_LoginButton_clicked();
    //void show2();
    // void open();
    void on_remitButton_clicked();  //撤销

signals:
    void sendData(QString);
private:
    Ui::MainWindow *ui;
    studentForm *f;
    manger *m;
};

#endif // MAINWINDOW_H
