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
    string getName() const;
    string getLastName() const;
    string getSkills() const;
    Job getJob() const;

    // Setters
    void setName(const string &name);
    void setLastName(const string &lastname);
    void setSkills(const string &skills);
    void addSkill(const string &skill);
    void take_job(Job &job);
};

#endif // PERSON_H
