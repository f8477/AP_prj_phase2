#include "job.h"

// Constructor
Job::Job() : Salary(0), JobTitle(""), CompanyName(""), SkillsRequired(""), Location("") {}


// Getter
unsigned int Job::getSalary() const
{
    return Salary;
}

QString Job::getJobTitle() const
{
    return JobTitle;
}

QString Job::getCompanyName() const
{
    return CompanyName;
}

QString Job::getSkillsRequired() const
{
    return SkillsRequired;
}

QStringList Job::getWorkplaceType() const
{
    return WorkplaceType;
}

QStringList Job::getType() const
{
    return Type;
}

QString Job::getLocation() const
{
    return Location;
}


// Setter
void Job::setSalary(const unsigned int &salary)
{
    Salary = salary;
}

void Job::setJobTitle(const QString &jobTitle)
{
    JobTitle = jobTitle;
}

void Job::setCompanyName(const QString &companyName)
{
    CompanyName = companyName;
}

void Job::setSkillsRequired(const QString &skillsRequired)
{
    SkillsRequired = skillsRequired;
}

void Job::setLocation(const QString &location)
{
    Location = location;
}
