#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "post.h"
#include "directmessage.h"

using namespace std;

class Account
{
private:
    string Username;   // The Username is the same as Account_ID
    string Phone_Num;
    string Email;
    vector<string> PersonConnectionID;
    vector<string> PersonFollowingID;
    vector<string> CompanyConnectionID;
    vector<string> CompanyFollowingID;
    vector<Post> Posts;
    vector<DirectMessage> DM;


public:
    Account();
    Account(const string &username, const string &phone, const string &email);

    // Getters
    string getUsername() ;
    string getPhone_Num() ;
    string getEmail(const QString Uid) ;
    vector<string> getPersonConnectionID() ;
    vector<string> getPersonFollowingID() ;
    vector<string> getCompanyConnectionID() ;
    vector<string> getCompanyFollowingID() ;
    vector<Post> getPosts() ;
    vector<DirectMessage> getDM() ;

    // Setters
    void setUsername(const string &username);
    void setPhone_Num(const string &phone);
    void setEmail(const string &email);
    void addPersonConnectionID(const string &person);
    void addPersonFollowingID(const string &person);
    void addCompanyConnectionID(const string &company);
    void addCompanyFollowingID(const string &company);
    void addPost(const Post &post);
    void addDM(const DirectMessage &dm);
};

#endif // ACCOUNT_H
