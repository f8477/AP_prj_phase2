#ifndef COMPANY_H
#define COMPANY_H

#include "accountclass.h"
#include "person.h"
#include "job.h"
#include <QString>
#include <QStringList>
#include <QVector>

class Company : public AccountClass {

private:
    QString CompanyName;
    QVector<Job> CompanyJobs;
    QVector<Person> Employees;
    QVector<AccountClass> Followers;

public:
    // Constructor
    Company();
    Company(const QString &username, const QString &phone, const QString &email, const QString &companyName);

    // Getters
    QString getCompanyName() const;
    Job createJob() const;
    QVector<Job> getCompanyJobs() const;
    QVector<Person> getEmployees() const;
    QVector<AccountClass> getFollowers() const;

    // Setters
    void setCompanyName(const QString &companyName);
    void setEmployee(Person person);
    void setFollower(AccountClass account);
};

#endif // COMPANY_H
