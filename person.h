#ifndef PERSON_H
#define PERSON_H

#include "accountclass.h"
#include "job.h"
#include <QString>
#include <QStringList>

class Person : public AccountClass {

private:
    QString name;
    QString lastname;
    QStringList skills;
    Job job;

public:
    // Constructor
    Person();
    Person(const QString &username, const QString &phone, const QString &email, const QString &name, const QString &lastname);

    // Getters
    QString getName() const;
    QString getLastName() const;
    QStringList getSkills() const;
    Job getJob() const;

    // Setters
    void setName(const QString &name);
    void setLastName(const QString &lastname);
    void addSkill(const QString &skill);
    void take_job(Job job);
};

#endif // PERSON_H
