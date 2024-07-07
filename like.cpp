#include "like.h"

Like::Like(const QString &userID) : userID(userID) {}

QString Like::getUserID() const {
    return userID;
}

void Like::setUserID(const QString &userID) {
    this->userID = userID;
}
