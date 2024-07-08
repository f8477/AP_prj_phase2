#include "content.h"

Content::Content(const std::string &senderID,
                 const Time &timeSent,
                 const std::string &contentText)
    : senderID(senderID), timeSent(timeSent), contentText(contentText) {}

std::string Content::getSenderID() const {
    return senderID;
}

void Content::setSenderID(const std::string &senderID) {
    this->senderID = senderID;
}

Time Content::getTimeSent() const {
    return timeSent;
}

void Content::setTimeSent(const Time &timeSent) {
    this->timeSent = timeSent;
}

std::string Content::getContentText() const {
    return contentText;
}

void Content::setContentText(const std::string &contentText) {
    this->contentText = contentText;
}

//std::ostream& operator<<(std::ostream &out, const Content &contentInstance) {
//    out << "Sender ID: " << contentInstance.senderID << std::endl;
//    out << "Time Sent: " << contentInstance.timeSent << std::endl;
//    out << "Content Text: " << contentInstance.contentText << std::endl;
//    return out;
//}
