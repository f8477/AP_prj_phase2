#ifndef POST_H
#define POST_H

#include <string>
#include <vector>
#include "content.h"
#include "like.h"
#include "comment.h"

class Post : public Content {
public:
    Post(const std::string &postId,
         const std::string &senderID,
         const Time &timeSent,
         const std::string &contentText);

    std::string getPostId() const;
    void setPostId(const std::string &postId);

    int getRepostCounter() const;
    void incrementRepostCounter();

    void addLike(const Like &like);
    void removeLike(const std::string &likeId);

    void addComment(const Comment &comment);
    void removeComment(const std::string &commentId);

    std::vector<Like> getLikes() const;
    std::vector<Comment> getComments() const;

private:
    std::string postIdentifier;
    int repostCounter;
    std::vector<Like> likes;
    std::vector<Comment> comments;
};

#endif // POST_H
