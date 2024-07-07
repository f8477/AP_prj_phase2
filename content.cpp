#include "content.h"

content::content(const QString &senderID,
                 const QDateTime &time,
                 const QString &text,
                 const QImage &image)
        : senderID(senderID),
          time(time),
          text(text),
          image(image){}

QString content::getSender() const {
    return senderID;
}

void content::setSender(const QString &senderID) {
    this->senderID = senderID;
}

QDateTime content::getTime() const {
    return time;
}

void content::setTime(const QDateTime &time) {
    this->time = time;
}

QString content::getText() const {
    return text;
}

void content::setText(const QString &text) {
    this->text = text;
}

QImage content::getImage() const {
    return image;
}

void content::setImage(const QImage &image) {
    this->image = image;
}
