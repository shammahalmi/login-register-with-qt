#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include<QDebug>
#include<QFileInfo>


namespace Ui {
class registerWindow;
}

class registerWindow : public QMainWindow
{
    Q_OBJECT

public:
      // QSqlDatabase db;
    explicit registerWindow(QWidget *parent = nullptr);
    ~registerWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::registerWindow *ui;
    QSqlDatabase db;
};

#endif // REGISTERWINDOW_H
