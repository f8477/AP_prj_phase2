#ifndef JOB_H
#define JOB_H

#include <string>
#include <QStringList>

class Job
{
private:
    unsigned int Salary;
    std::string JobTitle;
    std::string CompanyName;
    std::string SkillsRequired;
    QStringList WorkplaceType = {"On-site", "Hybrid", "Remote"};
    QStringList Type = {"Full-time", "Part-time", "Contract", "Temporary", "Volunteer", "Internship", "Other"};
    std::string Location;

public:
    Job();
    Job(const unsigned int &salary, const std::string &title, const std::string &companyName, const std::string &skillsRequired, const std::string location);

    unsigned int getSalary() const;
    std::string getJobTitle() const;
    std::string getCompanyName() const;
    std::string getSkillsRequired() const;
    QStringList getWorkplaceType() const;
    QStringList getType() const;
    std::string getLocation() const;


    void setSalary(const unsigned int &salary);
    void setJobTitle(const std::string &jobTitle);
    void setCompanyName(const std::string &companyName);
    void setSkillsRequired(const std::string &skillsRequired);
    void setLocation(const std::string &location);
};

#endif // JOB_H
