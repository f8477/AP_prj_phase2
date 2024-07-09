#include "directmessage.h"

DirectMessage::DirectMessage(const std::string &messageID,
                             const std::string &toWho,
                             const std::string &senderID,
                             const Time &timeSent,
                             const std::string &contentText)
    : Content(senderID, timeSent, contentText), messageID(messageID), toWho(toWho) {}

std::string DirectMessage::getMessageID() const {
    return messageID;
}

void DirectMessage::setMessageID(const std::string &messageID) {
    this->messageID = messageID;
}

std::string DirectMessage::getToWho() const {
    return toWho;
}

void DirectMessage::setToWho(const std::string &toWho) {
    this->toWho = toWho;
}
