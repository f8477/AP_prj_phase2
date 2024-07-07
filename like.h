#ifndef LIKE_H
#define LIKE_H

#include <QString>

class Like {
public:
    Like(const QString &userID);

    QString getUserID() const;
    void setUserID(const QString &userID);

private:
    QString userID;
};

#endif // LIKE_H
