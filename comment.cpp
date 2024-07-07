#include "comment.h"

Comment::Comment(const QString &userID, const QString &text, const QDateTime &time)
    : userID(userID), text(text), time(time) {}

QString Comment::getUserID() const {
    return userID;
}

void Comment::setUserID(const QString &userID) {
    this->userID = userID;
}

QString Comment::getText() const {
    return text;
}

void Comment::setText(const QString &text) {
    this->text = text;
}

QDateTime Comment::getTime() const {
    return time;
}

void Comment::setTime(const QDateTime &time) {
    this->time = time;
}
