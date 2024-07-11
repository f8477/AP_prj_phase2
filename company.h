#ifndef COMPANY_H
#define COMPANY_H

#include "accountClass.h"
#include "person.h"
#include "job.h"
#include <string>
#include <vector>

using namespace std;

class Company : public Account
{
private:
    string CompanyName;
    vector<Job> CompanyJobs;
    vector<Person> Employees;
    vector<string> FollowersID;


public:
    // Constructor
    Company();
    Company(const string &username, const string &phone, const string &email, const string &companyName);

    string getCompanyName() const;
    Job createJob() const;
    vector<Job> getCompanyJobs() const;
    vector<Person> getEmployees() const;
    vector<string> getFollowersID() const;

    void setCompanyName(const string &companyName);
    void addEmployee(const Person &person);
    void addFollower(const string &username);
};

#endif // COMPANY_H
