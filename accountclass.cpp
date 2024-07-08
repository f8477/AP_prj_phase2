#include "accountclass.h"

// Constructors
AccountClass::AccountClass() : Username(""), Phone_Num(""), Email("") {}

AccountClass::AccountClass(const QString &username, const QString &phone, const QString &email)
    : Username(username), Phone_Num(phone), Email(email) {}

// Getters
QString AccountClass::getUsername() const {
    return Username;
}

QString AccountClass::getPhone_Num() const {
    return Phone_Num;
}

QString AccountClass::getEmail() const {
    return Email;
}

QVector<Person> AccountClass::getPersonConnection() const
{
    return PersonConnection;
}

QVector<Person> AccountClass::getPersonFollowing() const
{
    return PersonFollowing;
}

QVector<Company> AccountClass::getCompanyConnection() const
{
    return CompanyConnection;
}

QVector<Company> AccountClass::getCompanyFollowing() const
{
    return CompanyFollowing;
}

QVector<Post> AccountClass::getPosts() const
{
    return Posts;
}

// Setters
void AccountClass::setUsername(QString &username) {
    Username = username;
}

void AccountClass::setPhone_Num(const QString &phone) {
    Phone_Num = phone;
}

void AccountClass::setEmail(const QString &email) {
    Email = email;
}

void AccountClass::addPersonConnection(Person person)
{
    PersonConnection.append(person);
}

void AccountClass::addPersonFollowing(Person person)
{
    PersonFollowing.append(person);
}

void AccountClass::addCompanyConnection(Company company)
{
    CompanyConnection.append(company);
}

void AccountClass::addCompanyFollowing(Company company)
{
    CompanyFollowing.append(company);
}

void AccountClass::addPost(Post post)
{
    Posts.append(post);
}
