#include "account.h"

User& User::getInstance() {
    static User instance;
    return instance;
}

QString User::getUsername() const {
    return username;
}

void User::setUsername(const QString &newUsername) {
    username = newUsername;
}
