#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "globle.h"
#include "manger.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->LoginButton, SIGNAL(clicked()), this, SLOT(on_LoginButton_clicked()));
    // ui->hide();
    // connect(ui->LoginButton, SIGNAL(clicked()), this, SLOT(show2()));
    ui->Login_password->setEchoMode(QLineEdit::Password);
    ui->Login_username->setText("吴博雄");
    ui->Login_password->setText("1922030114");
    ui->radioButton_2->setChecked(true);
}

QString MainWindow::password_qj = "";
QString MainWindow::username_qj = "";
//QVariantList list_all_student;
//QVariantList list_all_dormstudent;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginButton_clicked()
{
   QString username = ui->Login_username->text();
   QString password = ui->Login_password->text();
   qDebug()<<"用户名："<<username<<"密码:"<<password;
   QSqlDatabase db;
   if(QSqlDatabase::contains("qt_sql_default_connection"))
   db = QSqlDatabase::database("qt_sql_default_connection");
   else
   db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("xiaowu.db");
   db.setUserName("wuboxiong");
   db.setPassword("1922030114");
   if (!db.open())
   qDebug() << db.lastError();
   else qDebug() << "open";
   if( ui->radioButton->isChecked()){  //管理员
       QSqlQuery query(db);
       query.exec("select username,password from admin");
       bool T1=false;
       while(query.next())
       {
          QString user = query.value(0).toString();
          QString pass = query.value(1).toString();
          qDebug() << user << pass ;
          if(username.compare(user)==0&&password.compare(pass)==0){
               password_qj = password;
               username_qj = username;
               T1=true;
               this->hide();
               m=new manger;
               //emit sendData(username+"&"+password);
               m->show();
               break;
           }


        }


       if(T1==false)
        QMessageBox::information(this, "警告", "用户名或密码错误");
    }

   if( ui->radioButton_2->isChecked()){  //学生
       QSqlQuery query(db);
       query.exec("select name,password from student");
       bool T=false;
        while(query.next())
        {
                  QString user = query.value(0).toString();
                  QString pass = query.value(1).toString();
                  qDebug() << user << pass ;
                  if(username.compare(user)==0&&password.compare(pass)==0)
                  {
                      password_qj=password;
                      username_qj=username;
                      T=true;
                      this->hide();
                      f=new studentForm;
                      //emit sendData(username+"&"+password);
                      f->show();
                      break;
                   }
        }

     if(T==false)
         QMessageBox::information(this, "警告", "用户名或密码错误");
    }

}


//void MainWindow::show2(){
//    this->hide();
//    f=new studentForm;
//    f->show();
//}



void MainWindow::on_remitButton_clicked()
{
    ui->Login_username->clear();
    ui->Login_password->clear();
}
