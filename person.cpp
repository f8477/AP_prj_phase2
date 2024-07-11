#include "person.h"

// Constructor

Person::Person() : Account(), Name(""), Lastname("") {}

Person::Person(const string &username, const string &phone, const string &email, const string &name, const string &lastname)
    : Account(username, phone, email), Name(name), Lastname(lastname) {}

// Getters
string Person::getName() const
{
    return Name;
}

string Person::getLastName() const
{
    return Lastname;
}

string Person::getSkills() const
{
    return Skills;
}

Job Person::getJob() const
{
    return job;
}


// Setters
void Person::setName(const string &name)
{
    Name = name;
}

void Person::setLastName(const string &lastname)
{
    Lastname = lastname;
}

void Person::setSkills(const string &skills)
{
    Skills = skills;
}

void Person::addSkill(const string &skill)
{
    Skills += skill;
}

void Person::take_job(Job &job)
{
    this->job = job;
}


