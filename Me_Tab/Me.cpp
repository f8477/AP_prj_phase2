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
#include <QMessageBox>
#include "person.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

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

//bool PersonInfoWidget::openDatabase(QSqlDatabase &db) {
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");

//    if (!db.open()) {
//        qWarning() << "Error: connection with database failed";
//        return false;
//    }
//    return true;
//}
void Me::on_companySign_Button_3_clicked()
{
    QString useid = User::getInstance().getUsername();

    QSqlQuery q;
    q.exec("SELECT Name FROM Person WHERE Username = '"+ useid +"'");
    if (!q.next()){
        QMessageBox::information(this, "Error", "name");
    }
//    q.prepare("SELECT ALL FROM Person WHERE Username = :username");
//    q.bindValue(":username", useid);
//        QSqlDatabase db;
//        if (!openDatabase(db)) {
//            return;
//        }

    QSqlQuery query;
    query.prepare("SELECT Name, LastName, Email, Skills, Take_Job, Phone_Num,Bio  FROM Person WHERE Username = '"+ useid +"'");

    if (!query.exec()) {
        qWarning() << "Error: query execution failed -" << query.lastError();
//            db.close();
        return;
    }

    if (query.next()) {
        QString name = query.value("Name").toString();
        QString lastName = query.value("LastName").toString();
        QString email = query.value("Email").toString();
        QString job = query.value("Take_Job").toString();
        QString skills = query.value("Skills").toString();
        QString phone = query.value("Phone_Num").toString();
        QString bio = query.value("Bio").toString();

        ui->namee->setText(name);
        ui->lastnamee->setText(lastName);
        ui->email->setText(email);
        ui->job->setText(job);
        ui->bio->setText(bio);
        ui->phone->setText(phone);
        ui->skills->setText(skills);
    } else {
        qWarning() << "No data found";
    }

//        db.close();

//    ui->namee->setText(name);
//    ui->lastname->setText(lastname);
//    ui->skills->setText(skills);
//    ui->job->setText(job);
//    ui->phone->setText(phone);
//    ui->email->setText(email);
//    ui->bio->setText(bio);

//    QString name = q.value(0).toString();
//    QMessageBox::warning(this, "Error", name);
//    ui->namee->setText(name);
//    QString lastnames = q.value("Lastname").toString();
//    ui->label_9->setText(lastnames);
//    QString skills = q.value(2).toString();
//    QString job = q.value(3).toString();
//    QString phone = q.value(5).toString();
//    QString email = q.value(6).toString();
//    QString bio = q.value(11).toString();
//    Person person;
//    string name = person.getName(useid);
//    QString N =QString::fromStdString(name);
//    string N = name.toStdString();

//    QMessageBox::warning(this, N, N);


//    ui->skills->setText(skills);
//    ui->job->setText(job);
//    ui->phone->setText(phone);
//    ui->email->setText(email);
//    ui->bio->setText(bio);
    ui->username->setText(useid);
}


void Me::on_companySign_Button_clicked()
{
    CompanySignup companySignup(this);
    if(companySignup.exec() == QDialog::Accepted)
    {
        companySignup.clickForSignup();
    }
}

