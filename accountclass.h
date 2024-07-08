#ifndef ACCOUNTCLASS_H
#define ACCOUNTCLASS_H

#include <QString>
#include <QVector>
#include "post.h"
#include "person.h"
#include "company.h"

class AccountClass
{

private:
    QString Username;   // The Username is the same as Account_ID
    QString Phone_Num;
    QString Email;
    QVector<Person> PersonConnection;
    QVector<Person> PersonFollowing;
    QVector<Company> CompanyConnection;
    QVector<Company> CompanyFollowing;
    QVector<Post> Posts;

public:
    AccountClass();
    AccountClass(const QString &username, const QString &phone, const QString &email);

    // Getters
    QString getUsername() const;
    QString getPhone_Num() const;
    QString getEmail() const;
    QVector<Person> getPersonConnection() const;
    QVector<Person> getPersonFollowing() const;
    QVector<Company> getCompanyConnection() const;
    QVector<Company> getCompanyFollowing() const;
    QVector<Post> getPosts() const;

    // Setters
    void setUsername(QString &username);
    void setPhone_Num(const QString &phone);
    void setEmail(const QString &email);
    void addPersonConnection(Person person);
    void addPersonFollowing(Person person);
    void addCompanyConnection(Company company);
    void addCompanyFollowing(Company company);
    void addPost(Post post);

};

#endif // ACCOUNTCLASS_H
