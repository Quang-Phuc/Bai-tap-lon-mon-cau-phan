#ifndef KHOACNTT_H
#define KHOACNTT_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class KhoaCNTT;
}

class KhoaCNTT : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
{
        mydb=QSqlDatabase ::addDatabase("QSQLITE");
       mydb.setDatabaseName("E:/Cau_Phan/Quanlysinhvien.sqlite");
       if(!mydb.open())
          { qDebug()<<("Faile to open the database");
          return false;
       }
       else
           qDebug()<<("Connetcted...");
           return true;
}

public:
    explicit KhoaCNTT(QWidget *parent = 0);
    ~KhoaCNTT();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::KhoaCNTT *ui;

};

#endif // KHOACNTT_H
