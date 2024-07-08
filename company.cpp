#include "company.h"

// Constructors
Company::Company() : AccountClass(), CompanyName("") {}

Company::Company(const QString &username, const QString &phone, const QString &email, const QString &companyName)
    : AccountClass(username, phone, email), CompanyName(companyName) {}

// Getters
QString Company::getCompanyName() const
{
    return CompanyName;
}

Job Company::createJob() const
{
    // show window for create a new job
}

QVector<Job> Company::getCompanyJobs() const
{
    return CompanyJobs;
}

QVector<Person> Company::getEmployees() const
{
    return Employees;
}

QVector<AccountClass> Company::getFollowers() const
{
    return Followers;
}

// Setters
void Company::setCompanyName(const QString &companyName)
{
    CompanyName = companyName;
}

void Company::setEmployee(Person person)
{
    Employees.append(person);
}

void Company::setFollower(AccountClass account)
{
    Followers.append(account);
}
