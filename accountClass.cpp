#include "accountClass.h"
#include "account.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>

// Constructors
Account::Account() : Username(""), Phone_Num(""), Email("") {}

Account::Account(const string &username, const string &phone, const string &email)
    : Username(username), Phone_Num(phone), Email(email) {}


// Getters
string Account::getUsername()
{
    return Username;
}

string Account::getPhone_Num()
{
    return Phone_Num;
}

string Account::getEmail(const QString Uid)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QSqlQuery q;
    q.exec("SELECT * FROM Person WHERE Username = '"+ Uid +"'");
    QString N = q.value("Email").toString();
    Email = N.toStdString();
    return Email;
}


vector<string> Account::getPersonConnectionID()
{
    return PersonConnectionID;
}



vector<string> Account::getPersonFollowingID()
{
    return PersonFollowingID;
}



vector<string> Account::getCompanyConnectionID()
{
    return CompanyConnectionID;
}



vector<string> Account::getCompanyFollowingID()
{
    return CompanyFollowingID;
}


vector<Post> Account::getPosts()
{
    return Posts;
}

vector<DirectMessage> Account::getDM()
{
    return DM;
}


// Setters
void Account::setUsername(const string &username)
{
    Username = username;
}

void Account::setPhone_Num(const string &phone)
{
    Phone_Num = phone;
}

void Account::setEmail(const string &email)
{
    Email = email;
}


void Account::addPersonConnectionID(const string &person)
{
    PersonConnectionID.push_back(person);
}

void Account::addPersonFollowingID(const string &person)
{
    PersonFollowingID.push_back(person);
}

void Account::addCompanyConnectionID(const string &company)
{
    CompanyConnectionID.push_back(company);
}

void Account::addCompanyFollowingID(const string &company)
{
    CompanyFollowingID.push_back(company);
}


void Account::addPost(const Post &post)
{
    Posts.push_back(post);
}

void Account::addDM(const DirectMessage &dm)
{
    DM.push_back(dm);
}


