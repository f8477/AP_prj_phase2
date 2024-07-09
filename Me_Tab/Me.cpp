#include "Me.h"
#include "ui_Me.h"
#include "account.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>
#include <QStringList>

Me::Me(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Me),
    profile_edit(nullptr)

{
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();



    ui->accountProfile->setPixmap(QPixmap(":/images/assets/profile.png"));
    ui->companyImage->setPixmap(QPixmap(":/images/assets/company.png"));
}

Me::~Me()
{
    delete ui;
    if (profile_edit) {
            delete profile_edit;
    }
}



void Me::on_companySign_Button_2_clicked()
{
    if (!profile_edit) {
       profile_edit = new ProfileEdit(this);
    }
    profile_edit->show();
}


void Me::on_companySign_Button_3_clicked()
{
    QString useid = User::getInstance().getUsername();

    QSqlQuery q;
    q.exec("SELECT * FROM Person WHERE Username = '"+useid+"'");
    QString name = q.value("Name").toString();
    QString lastname = q.value("Lastname").toString();
    QString skills = q.value("Skills").toString();
    QString job = q.value("Take_Job").toString();
    QString phone = q.value("Phone_Num").toString();
    QString email = q.value("Email").toString();
    QString bio = q.value("Bio").toString();




    ui->namee->setText(name);
    ui->lastname->setText(lastname);
    ui->skills->setText(skills);
    ui->job->setText(job);
    ui->phone->setText(phone);
    ui->email->setText(email);
    ui->bio->setText(bio);
    ui->username->setText(useid);
}

