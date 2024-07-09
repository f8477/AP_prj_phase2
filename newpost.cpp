#include "newpost.h"
#include "ui_newpost.h"
#include "account.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QString>
//#include "timee.h"

newpost::newpost(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newpost)
{
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();



}

newpost::~newpost()
{
    delete ui;
}
void newpost::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    int post_id = 1;
    int sender_id = 0;
//    Time T(0, 0, 0, 0, 0, 0);
    QString useid = User::getInstance().getUsername();
    QSqlQuery q;
//    ui->label->setText(useid);
    q.exec("INSERT INTO Post(Content_Text, Sender_ID)VALUES('"+text+"', '"+useid+"')");


    close();
}

