#include "comment.h"

Comment::Comment(const std::string &postId,
                 const std::string &commentId,
                 const std::string &senderID,
                 const Time &timeSent,
                 const std::string &contentText)
    : Content(senderID, timeSent, contentText),
      postIdentifier(postId),
      commentIdentifier(commentId) {}

std::string Comment::getPostId() const {
    return postIdentifier;
}

void Comment::setPostId(const std::string &postId) {
    postIdentifier = postId;
}

std::string Comment::getCommentId() const {
    return commentIdentifier;
}

void Comment::setCommentId(const std::string &commentId) {
    commentIdentifier = commentId;
}
