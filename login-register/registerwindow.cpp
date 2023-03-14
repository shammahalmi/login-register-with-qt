#include "registerwindow.h"
#include "ui_registerwindow.h"

registerWindow::registerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);
db=QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("login.db");
if (!db.open()) {
    qDebug()<<"database açılmadı";
} else qDebug()<<"database açıldı!!!";
}

registerWindow::~registerWindow()
{
    delete ui;
}

void registerWindow::on_pushButton_2_clicked()
{

    this->close();
}


void registerWindow::on_pushButton_clicked()
{
    //KAYDOL BUTONU
    db.open();
    QSqlQuery q;


q.prepare("INSERT INTO register_data(name_surname,mail,t_numarasi,password)"
          "VALUES (:name_surname,:mail,:t_numarasi,:password)");

QString name=ui->reg_isim->text();
QString mail=ui->reg_mail->text();
QString telefon=ui->reg_tel->text();
QString pass =ui->reg_pass->text();
pass=qHash(pass,3);
 qDebug()<<"register window pass: "+pass;

  q.bindValue(":name_surname",name);
  q.bindValue(":mail",mail);
  q.bindValue(":t_numarasi",telefon);
  q.bindValue(":password",pass);

  if (q.exec()) {
      qDebug()<<"data inserted ";
      ui->state->setText("işlem yapıldı");
  }else  qDebug()<<"data is not inserted ";

    q.clear();
    db.close();


}


void registerWindow::on_pushButton_3_clicked()
{
    if(ui->reg_pass->echoMode()==QLineEdit::Password){

      ui->reg_pass->setEchoMode(QLineEdit::Normal);

    }
     else   ui->reg_pass->setEchoMode(QLineEdit::Password);

}

