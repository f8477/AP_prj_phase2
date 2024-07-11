#include "job.h"

Job::Job() :  Salary(-1), JobTitle("not defined"), CompanyName("not defined"), SkillsRequired("not defined"), Location("not defined") {}

Job::Job(const unsigned int &salary, const std::string &title, const std::string &companyName, const std::string &skillsRequired, const std::string location)
    : Salary(salary), JobTitle(title), CompanyName(companyName), SkillsRequired(skillsRequired), Location(location) {}


unsigned int Job::getSalary() const
{
    return Salary;
}

std::string Job::getJobTitle() const
{
    return JobTitle;
}

std::string Job::getCompanyName() const
{
    return CompanyName;
}

std::string Job::getSkillsRequired() const
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

std::string Job::getLocation() const
{
    return Location;
}



void Job::setSalary(const unsigned int &salary)
{
    Salary = salary;
}

void Job::setJobTitle(const std::string &jobTitle)
{
    JobTitle = jobTitle;
}

void Job::setCompanyName(const std::string &companyName)
{
    CompanyName = companyName;
}

void Job::setSkillsRequired(const std::string &skillsRequired)
{
    SkillsRequired = skillsRequired;
}

void Job::setLocation(const std::string &location)
{
    Location = location;
}


