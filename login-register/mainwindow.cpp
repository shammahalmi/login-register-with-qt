#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db=QSqlDatabase::addDatabase("QSQLITE","MyConnect");
    db.setDatabaseName("login.db");
    if (!db.open()) {
        qDebug()<<"database açılmadı";
    } else qDebug()<<"database açıldı!!!";



    r_w=new registerWindow();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{


   r_w->show();




}



void MainWindow::on_pushButton_3_clicked()
{
    if(ui->login_pass_txt->echoMode()==QLineEdit::Password){

      ui->login_pass_txt->setEchoMode(QLineEdit::Normal);

    }
     else   ui->login_pass_txt->setEchoMode(QLineEdit::Password);
}


void MainWindow::on_pushButton_clicked()
{
    // login butonu
    QString mail=ui->login_email_txt->text();
    QString password= ui->login_pass_txt->text();
    db.open();


     QSqlQuery q (QSqlDatabase::database("MyConnect"));
q.prepare("SELECT * FROM register_data WHERE mail=:mail AND password=:password ");
q.bindValue(":mail",mail);
q.bindValue(":password",password);

if (!q.exec()) {
   qDebug()<<"FAİLED TO EXECUTE";
}
else {
    q.exec();
qDebug()<<"başladı ";
    if(q.next()) {

       QString mailFromDb= q.value(1).toString();
       QString passwordFromDb= q.value(3).toString();



       qDebug()<<"from db:"+passwordFromDb;
       qDebug()<<"from ui:"+password;
       password=qHash(password,3);
      passwordFromDb=qHash(passwordFromDb,3);
       qDebug()<<"from db2:"+passwordFromDb;
       qDebug()<<"the new one: "+password;
       if (mailFromDb==mail && passwordFromDb==password) {
           qDebug()<<"login succes";
           ui->state->setText("login succes");
       }
       else {
           qDebug()<<"login failed";
            ui->state->setText("login failed");

       }
    }

}



}

