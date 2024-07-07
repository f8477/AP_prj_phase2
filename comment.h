#ifndef COMMENT_H
#define COMMENT_H

#include <QString>
#include <QDateTime>

class Comment {
public:
    Comment(const QString &userID, const QString &text, const QDateTime &time);

    QString getUserID() const;
    void setUserID(const QString &userID);

    QString getText() const;
    void setText(const QString &text);

    QDateTime getTime() const;
    void setTime(const QDateTime &time);

private:
    QString userID;
    QString text;
    QDateTime time;
};

#endif // COMMENT_H
