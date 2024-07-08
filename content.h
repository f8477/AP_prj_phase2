#ifndef CONTENT_H
#define CONTENT_H

#include <QString>
#include "timee.h" // Include Timee header

class Content {
public:
    Content(const std::string &senderID,
            const Time &timeSent,
            const std::string &contentText);

    std::string getSenderID() const;
    void setSenderID(const std::string &senderID);

    Time getTimeSent() const;
    void setTimeSent(const Time &timeSent);

    std::string getContentText() const;
    void setContentText(const std::string &contentText);

private:
    std::string senderID;
    Time timeSent;
    std::string contentText;
};

#endif // CONTENT_H
