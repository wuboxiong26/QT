#include "manger.h"
#include "ui_manger.h"
#include "globle.h"
#include "mainwindow.h"
#include "userlogin.h"
#include "stuinformanage.h"
#include "dormmanage.h"
#include "awardmanage.h"
#include "scoremanage.h"
#include "coursemanage.h"
#include "classmanage.h"
#include "feemanage.h"

manger::manger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manger)
{
    ui->setupUi(this);
    QLabel *lab= ui->label_useradmin;
    lab->setStyleSheet("color:#ff6600;");
    lab->setText("欢迎"+MainWindow::username_qj);
}

manger::~manger()
{
    delete ui;
}

void manger::on_pushButton_9_clicked()  //返回
{
    MainWindow *dh;
    this->hide();
    dh=new MainWindow  ;

    dh->show();
}

void manger::on_userloginButton_clicked()  //用户登录
{
    this->hide();
    userlogin *ti=new userlogin;
    ti->show();
}

void manger::on_stu_inform_guanlipushButton_clicked()  //学生
{
    this->hide();
    stuinformanage *ij=new stuinformanage;
    ij->show();
}

void manger::on_dorm_guanliButton_clicked()  //宿舍
{
    this->hide();
    dormmanage *yf=new dormmanage;
    yf->show();
}

void manger::on_award_managepushButton_clicked()  //奖惩
{
    this->hide();
    awardmanage *nl=new awardmanage;
    nl->show();
}

void manger::on_scoremanagepushButton_clicked()  //成绩
{
    this->hide();
    scoremanage *pk=new scoremanage;
    pk->show();

}

void manger::on_course_manageButton_clicked()  //课程
{
    this->hide();
  coursemanage *ew=new coursemanage;
   ew->show();
}

void manger::on_class_managepushButton_clicked()  //课程
{
    this->hide();
    classmanage *wq=new classmanage;
    wq->show();
}

void manger::on_feemanagepushButton_clicked()  //缴费
{
    this->hide();
    feemanage *eg=new feemanage;
    eg->show();
}

void manger::on_pushButton_10_clicked()
{
    exit(0);
}

