#include "seeallstuinfor.h"
#include "ui_seeallstuinfor.h"
#include "globle.h"
#include "stuinformanage.h"
#include "mainwindow.h"

seeallstuinfor::seeallstuinfor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seeallstuinfor)
{
    ui->setupUi(this);
    setWindowTitle(QString("设计者1922030114，吴博雄"));

    for(int i1=0;i1<Globel::list_all_student.size();i1++)
    {

        int row = ui->tableWidget->rowCount();

        ui->tableWidget->insertRow(row);
        QStringList rowdata=Globel::list_all_student[i1].toStringList();

        for(int i  = 0 ; i <rowdata .size() ; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(i));
            ui->tableWidget->setItem(row , i , item);

            //ui->tableWidget->setItem(1,1,item);


        }

    }

}

seeallstuinfor::~seeallstuinfor()
{
    delete ui;
}

void seeallstuinfor::on_backButton_clicked()
{
    this->hide();
    Globel::list_all_student.clear();
    ui->tableWidget->clear();
    stuinformanage *f1=new stuinformanage;
    f1->show();
}
