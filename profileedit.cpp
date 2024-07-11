#include "profileedit.h"
#include "ui_profileedit.h"
#include "account.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

ProfileEdit::ProfileEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileEdit)
{
    ui->setupUi(this);
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:\\Users\\Sajjad\\Desktop\\AP Project_july 2024\\AP_prj_phase2\\project.db");
    database.open();

}

ProfileEdit::~ProfileEdit()
{
    delete ui;
}

void ProfileEdit::on_pushButton_clicked()
{
    QString useid = User::getInstance().getUsername();

    QString name = ui->lineEdit->text();
    QString lastname = ui->lineEdit_2->text();
    QString bio = ui->textEdit->toPlainText();
    QString skills = ui->textEdit_2->toPlainText();
    QString job = ui->lineEdit_3->text();

    QSqlQuery q;
    q.exec("UPDATE Person SET Name = '"+name+"' WHERE Username = '"+useid+"' ");
    q.exec("UPDATE Person SET Lastname = '"+lastname+"' WHERE Username = '"+useid+"' ");
    q.exec("UPDATE Person SET Bio = '"+bio+"' WHERE Username = '"+useid+"' ");
    q.exec("UPDATE Person SET Skills = '"+skills+"' WHERE Username = '"+useid+"' ");
    q.exec("UPDATE Person SET Take_Job = '"+job+"' WHERE Username = '"+useid+"' ");

    close();

}

