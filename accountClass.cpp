#include "accountClass.h"

// Constructors
Account::Account() : Username(""), Phone_Num(""), Email("") {}

Account::Account(const string &username, const string &phone, const string &email)
    : Username(username), Phone_Num(phone), Email(email) {}


// Getters
string Account::getUsername() const
{
    return Username;
}

string Account::getPhone_Num() const
{
    return Phone_Num;
}

string Account::getEmail() const
{
    return Email;
}


vector<string> Account::getPersonConnectionID() const
{
    return PersonConnectionID;
}



vector<string> Account::getPersonFollowingID() const
{
    return PersonFollowingID;
}



vector<string> Account::getCompanyConnectionID() const
{
    return CompanyConnectionID;
}



vector<string> Account::getCompanyFollowingID() const
{
    return CompanyFollowingID;
}


vector<Post> Account::getPosts() const
{
    return Posts;
}

vector<DirectMessage> Account::getDM() const
{
    return DM;
}


// Setters
void Account::setUsername(const string &username)
{
    Username = username;
}

void Account::setPhone_Num(const string &phone)
{
    Phone_Num = phone;
}

void Account::setEmail(const string &email)
{
    Email = email;
}


void Account::addPersonConnectionID(const string &person)
{
    PersonConnectionID.push_back(person);
}

void Account::addPersonFollowingID(const string &person)
{
    PersonFollowingID.push_back(person);
}

void Account::addCompanyConnectionID(const string &company)
{
    CompanyConnectionID.push_back(company);
}

void Account::addCompanyFollowingID(const string &company)
{
    CompanyFollowingID.push_back(company);
}


void Account::addPost(const Post &post)
{
    Posts.push_back(post);
}

void Account::addDM(const DirectMessage &dm)
{
    DM.push_back(dm);
}


