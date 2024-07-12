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
}

veiwperson::~veiwperson()
{
    delete ui;
}
