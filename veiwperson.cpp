#include "veiwperson.h"
#include "ui_veiwperson.h"
#include "account.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <string>
#include <QString>
#include "person.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>


veiwperson::veiwperson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::veiwperson)
{
    ui->setupUi(this);
    Person person;
    QString Uid = GlobalUser::getInstance().getUsername();
    QString N;
    string name = person.getName(Uid);
    N = QString::fromStdString(name);
    ui->name->setText(N);
    string lastname = person.getLastName(Uid);
    N = QString::fromStdString(lastname);
    ui->Lastname->setText(N);
    string email = person.getEmail(Uid);
    N = QString::fromStdString(email);
    ui->email->setText(N);
    string skills = person.getSkills(Uid);
    N = QString::fromStdString(skills);
    ui->skills->setText(N);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();

    QSqlQuery query;
    query.prepare("SELECT Name, LastName, Email, Skills, Take_Job, Phone_Num,Bio  FROM Person WHERE Username = '"+ Uid +"'");

    if (!query.exec()) {
        qWarning() << "Error: query execution failed -" << query.lastError();
//            db.close();
        return;
    }

    if (query.next()) {
        QString name = query.value("Name").toString();
        QString lastName = query.value("LastName").toString();
        QString email = query.value("Email").toString();
        QString skills = query.value("Skills").toString();

        ui->name->setText(name);
        ui->Lastname->setText(lastName);
        ui->email->setText(email);
//        ui->job->setText(job);
//        ui->bio->setText(bio);
//        ui->phone->setText(phone);
        ui->skills->setText(skills);
    } else {
        qWarning() << "No data found";
    }



    QSqlQuery q;
    q.exec("SELECT * FROM Post");
    q.last();
    int i = 1;
    while (q.isValid() && i <= 5){
        QString username = q.value("Sender_ID").toString();
        QString text = q.value("Content_Text").toString();
        if (username == Uid){
            if (i == 1){
                ui->label_6->setText(username);
                ui->textEdit_2->setText(text);
            }else if (i == 2){
                ui->label_29->setText(username);
                ui->textEdit_8->setText(text);
            }else if (i == 3){
                ui->label_10->setText(username);
                ui->textEdit_4->setText(text);
            }else if (i == 4){
                ui->label_12->setText(username);
                ui->textEdit_5->setText(text);
            }else if (i == 5){
                ui->label_14->setText(username);
                ui->textEdit_6->setText(text);
            }
            i++;
        }
        q.previous();

    }


}

veiwperson::~veiwperson()
{
    delete ui;
}

void veiwperson::on_Reload_clicked()
{
    QString Uid = GlobalUser::getInstance().getUsername();

    QSqlQuery query;
    query.prepare("SELECT Name, LastName, Email, Skills, Take_Job, Phone_Num,Bio  FROM Person WHERE Username = '"+ Uid +"'");

    if (!query.exec()) {
        qWarning() << "Error: query execution failed -" << query.lastError();
//            db.close();
        return;
    }

    if (query.next()) {
        QString name = query.value("Name").toString();
        QString lastName = query.value("LastName").toString();
        QString email = query.value("Email").toString();
        QString skills = query.value("Skills").toString();

        ui->name->setText(name);
        ui->Lastname->setText(lastName);
        ui->email->setText(email);
//        ui->job->setText(job);
//        ui->bio->setText(bio);
//        ui->phone->setText(phone);
        ui->skills->setText(skills);
    } else {
        qWarning() << "No data found";
    }




    QSqlQuery q;
    q.exec("SELECT * FROM Post");
    q.last();
    int i = 1;
    while (q.isValid() && i <= 5){
        QString username = q.value("Sender_ID").toString();
        QString text = q.value("Content_Text").toString();
        if (username == Uid){
            if (i == 1){
                ui->label_6->setText(username);
                ui->textEdit_2->setText(text);
            }else if (i == 2){
                ui->label_29->setText(username);
                ui->textEdit_8->setText(text);
            }else if (i == 3){
                ui->label_10->setText(username);
                ui->textEdit_4->setText(text);
            }else if (i == 4){
                ui->label_12->setText(username);
                ui->textEdit_5->setText(text);
            }else if (i == 5){
                ui->label_14->setText(username);
                ui->textEdit_6->setText(text);
            }
            i++;
        }
        q.previous();

    }






}

