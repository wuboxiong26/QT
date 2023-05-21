#include "userlogin.h"
#include "ui_userlogin.h"
#include "insertlogin.h"
#include "manger.h"
#include "deletelogin.h"
#include "updatelogin.h"

userlogin::userlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userlogin)
{
    ui->setupUi(this);
}

userlogin::~userlogin()
{
    delete ui;
}

void userlogin::on_insert_loginButton_clicked() //插
{
    this->hide();
    insertlogin *wq=new insertlogin;
    wq->show();

}

void userlogin::on_user_login_back_clicked() //返回
{
    this->hide();
    manger *wq1=new manger;
    wq1->show();
}

void userlogin::on_delete_loginButton_clicked()  //删
{
    this->hide();
    deletelogin *er=new deletelogin;
    er->show();
}

void userlogin::on_update_userButton_clicked()  //改
{
    this->hide();
    updatelogin *ty=new updatelogin;
    ty->show();

}

void userlogin::on_user_login_back_2_clicked()
{
    exit(0);
}


//void userlogin::on_select_userButton_clicked() //查
//{
//    this->hide();

//}

