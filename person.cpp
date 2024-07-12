#include "person.h"
#include "account.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>

// Constructor

Person::Person() : Account(), Name(""), Lastname("") {}

Person::Person(const string &username, const string &phone, const string &email, const string &name, const string &lastname)
    : Account(username, phone, email), Name(name), Lastname(lastname) {}

// Getters
string Person::getName(const QString Uid)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QSqlQuery q;
    q.exec("SELECT * FROM Person WHERE Username = '"+ Uid +"'");
    QString N = q.value("Name").toString();
    Name = N.toStdString();
    return Name;
}

string Person::getLastName(const QString Uid)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QSqlQuery q;
    q.exec("SELECT * FROM Person WHERE Username = '"+ Uid +"'");
    QString N = q.value("LastName").toString();
    Lastname = N.toStdString();
    database.close();
    return Lastname;

}

string Person::getSkills(const QString Uid)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QSqlQuery q;
    q.exec("SELECT * FROM Person WHERE Username = '"+ Uid +"'");
    QString N = q.value("Skills").toString();
    Skills = N.toStdString();
    database.close();

    return Skills;
}

Job Person::getJob() const
{
    return job;
}


// Setters
void Person::setName(const string &name, const QString Uid)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QSqlQuery q;
    QString N = QString::fromStdString(name);
    q.exec("UPDATE Person SET Name = '"+N+"' WHERE Username = '"+Uid+"' ");
    Name = name;
    database.close();
}

void Person::setLastName(const string &lastname, const QString Uid)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QSqlQuery q;
    QString N = QString::fromStdString(lastname);
    q.exec("UPDATE Person SET LastName = '"+N+"' WHERE Username = '"+Uid+"' ");
    Lastname = lastname;
    database.close();
}

void Person::setSkills(const string &skills, const QString Uid)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QSqlQuery q;
    QString N = QString::fromStdString(skills);
    q.exec("UPDATE Person SET Skills = '"+N+"' WHERE Username = '"+Uid+"' ");
    Skills = skills;
    database.close();
}

void Person::addSkill(const string &skill, const QString Uid)
{


    Skills = getSkills(Uid);
    Skills += skill;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QSqlQuery q;
    QString N = QString::fromStdString(Skills);
    q.exec("UPDATE Person SET Skills = '"+N+"' WHERE Username = '"+Uid+"' ");
    database.close();
}

void Person::take_job(Job &job)
{
    this->job = job;
}


