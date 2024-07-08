#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include "content.h"

class Comment : public Content {
public:
    Comment(const std::string &postId,
            const std::string &commentId,
            const std::string &senderID,
            const Time &timeSent,
            const std::string &contentText);

    std::string getPostId() const;
    void setPostId(const std::string &postId);

    std::string getCommentId() const;
    void setCommentId(const std::string &commentId);

private:
    std::string postIdentifier;
    std::string commentIdentifier;
};

#endif // COMMENT_H
