#ifndef CONTENT_H
#define CONTENT_H

#include <QString>
#include <QDateTime>
#include <QImage>

class content{
public:
    content(const QString &senderID,
            const QDateTime &time,
            const QString &text,
            const QImage &image);

    QString getSender() const;
    void setSender(const QString &senderID);

    QDateTime getTime() const;
    void setTime(const QDateTime &time);

    QString getText() const;
    void setText(const QString &text);

    QImage getImage() const;
    void setImage(const QImage &image);

private:
    QString senderID;
    QDateTime time;
    QString text;
    QImage image;
};

#endif // CONTENT_H
