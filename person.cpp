#include "person.h"

// Constructors
Person::Person() : AccountClass(), name(""), lastname("") {}

Person::Person(const QString &username, const QString &phone, const QString &email, const QString &name, const QString &lastname)
    : AccountClass(username, phone, email), name(name), lastname(lastname) {}

// Getters
QString Person::getName() const {
    return name;
}

QString Person::getLastName() const {
    return lastname;
}

QStringList Person::getSkills() const {
    return skills;
}

Job Person::getJob() const
{
    return job;
}

// Setters
void Person::setName(const QString &name) {
    this->name = name;
}

void Person::setLastName(const QString &lastname) {
    this->lastname = lastname;
}

void Person::addSkill(const QString &skill) {
    skills.append(skill);
}

void Person::take_job(Job job)
{
    this->job = job;
}
