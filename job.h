#ifndef JOB_H
#define JOB_H

#include <QString>
#include <QStringList>

class Job
{

private:
    unsigned int Salary;
    QString JobTitle;
    QString CompanyName;
    QString SkillsRequired;
    QStringList WorkplaceType = {"On-site", "Hybrid", "Remote"};
    QStringList Type = {"Full-time", "Part-time", "Contract", "Temporary", "Volunteer", "Internship", "Other"};
    QString Location;

public:
    // Constructor
    Job();

    // Getters
    unsigned int getSalary() const;
    QString getJobTitle() const;
    QString getCompanyName() const;
    QString getSkillsRequired() const;
    QStringList getWorkplaceType() const;
    QStringList getType() const;
    QString getLocation() const;

    // Setters
    void setSalary(const unsigned int &salary);
    void setJobTitle(const QString &jobTitle);
    void setCompanyName(const QString &companyName);
    void setSkillsRequired(const QString &skillsRequired);
    void setLocation(const QString &location);

};

#endif // JOB_H
