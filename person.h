#ifndef PERSON_H
#define PERSON_H

#include "accountClass.h"
#include "job.h"
#include <string>

using namespace std;

class Person : public Account
{
private:
    string Name;
    string Lastname;
    string Skills;
    Job job;


public:
    // Constructors
    Person();
    Person(const string &username, const string &phone, const string &email, const string &name, const string &lastname);

    // Getters
    string getName(const QString Uid) ;
    string getLastName(const QString Uid);
    string getSkills(const QString Uid) ;
    Job getJob() const;

    // Setters
    void setName(const string &name, const QString Uid);
    void setLastName(const string &lastname, const QString Uid);
    void setSkills(const string &skills, const QString Uid);
    void addSkill(const string &skill, const QString Uid);
    void take_job(Job &job);
};

#endif // PERSON_H
