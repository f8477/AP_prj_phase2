#include "company.h"

Company::Company() : Account(), CompanyName("") {}

Company::Company(const string &username, const string &phone, const string &email, const string &companyName)
    : Account(username, phone, email), CompanyName(companyName) {}


string Company::getCompanyName() const
{
    return CompanyName;
}

Job Company::createJob() const
{
    // need to open window for implement variable of Job Class and create a job
    Job newJob;
    /*
    newJob.setCompanyName("");
    newJob.setJobTitle("");
    newJob.setLocation("");
    newJob.setSalary();
    newJob.setSkillsRequired("");
    */
    return newJob;
}

vector<Job> Company::getCompanyJobs() const
{
    return CompanyJobs;
}

vector<Person> Company::getEmployees() const
{
    return Employees;
}


vector<string> Company::getFollowersID() const
{
    return FollowersID;
}


void Company::setCompanyName(const string &companyName)
{
    CompanyName = companyName;
}

void Company::addEmployee(const Person &person)
{
    Employees.push_back(person);
}


void Company::addFollower(const string &username)
{
    FollowersID.push_back(username);
}

