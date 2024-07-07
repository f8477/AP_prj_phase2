#include "post.h"

Post::Post(const QString &senderID,
           const QDateTime &time,
           const QString &text,
           const QImage &image,
           int postID)
    : content(senderID, time, text, image), postID(postID), repostCount(0) {}

int Post::getPostID() const {
    return postID;
}

void Post::setPostID(int postID) {
    this->postID = postID;
}

QVector<Like*> Post::getLikes() const {
    return likes;
}

void Post::addLike(Like* like) {
    likes.append(like);
}

void Post::removeLike(int index) {
    likes.removeAt(index);
}

QVector<Comment*> Post::getComments() const {
    return comments;
}

void Post::addComment(Comment* comment) {
    comments.append(comment);
}

void Post::removeComment(int index) {
    comments.removeAt(index);
}

int Post::getRepostCount() const {
    return repostCount;
}

void Post::incrementRepostCount() {
    repostCount++;
}
