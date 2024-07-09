#ifndef DIRECTMESSAGE_H
#define DIRECTMESSAGE_H

#include "content.h"

class DirectMessage : public Content {
public:
    DirectMessage(const std::string &messageID,
                  const std::string &toWho,
                  const std::string &senderID,
                  const Time &timeSent,
                  const std::string &contentText);

    std::string getMessageID() const;
    void setMessageID(const std::string &messageID);

    std::string getToWho() const;
    void setToWho(const std::string &toWho);

private:
    std::string messageID;
    std::string toWho;
};

#endif // DIRECTMESSAGE_H
