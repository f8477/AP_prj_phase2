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

#endif // USER_H
