#ifndef USER_H
#define USER_H

#include <QString>

class User {
public:

    static User& getInstance();

    QString getUsername() const;
    void setUsername(const QString &newUsername);

private:
    User() {}

    User(const User&) = delete;
    User& operator=(const User&) = delete;

    QString username;
};




// Setting the username
//GlobalUser::getInstance().setUsername("new_username");

// Getting the username
//QString currentUsername = GlobalUser::getInstance().getUsername();

class GlobalUser {
public:
    static GlobalUser& getInstance() {
        static GlobalUser instance;
        return instance;
    }

    QString getUsername() const {
        return username;
    }

    void setUsername(const QString &newUsername) {
        username = newUsername;
    }

private:
    QString username;

    // Private constructor to prevent instantiation
    GlobalUser() {}

    // Delete copy constructor and assignment operator to prevent copying
    GlobalUser(const GlobalUser&) = delete;
    void operator=(const GlobalUser&) = delete;
};

#endif // USER_H
