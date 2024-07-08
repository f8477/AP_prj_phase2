#include "post.h"

Post::Post(const std::string &postId,
           const std::string &senderID,
           const Time &timeSent,
           const std::string &contentText)
    : Content(senderID, timeSent, contentText), postIdentifier(postId), repostCounter(0) {}

std::string Post::getPostId() const {
    return postIdentifier;
}

void Post::setPostId(const std::string &postId) {
    postIdentifier = postId;
}

int Post::getRepostCounter() const {
    return repostCounter;
}

void Post::incrementRepostCounter() {
    repostCounter++;
}

void Post::addLike(const Like &like) {
    likes.push_back(like);
}

void Post::removeLike(const std::string &likeId) {
    for (auto it = likes.begin(); it != likes.end(); ++it) {
        if (it->getLikeId() == likeId) {
            likes.erase(it);
            break;
        }
    }
}

void Post::addComment(const Comment &comment) {
    comments.push_back(comment);
}

void Post::removeComment(const std::string &commentId) {
    for (auto it = comments.begin(); it != comments.end(); ++it) {
        if (it->getCommentId() == commentId) {
            comments.erase(it);
            break;
        }
    }
}

std::vector<Like> Post::getLikes() const {
    return likes;
}

std::vector<Comment> Post::getComments() const {
    return comments;
}
