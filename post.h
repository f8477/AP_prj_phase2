#ifndef POST_H
#define POST_H

#include "content.h"
#include "like.h"
#include "comment.h"
#include <QVector>

class Post : public content {
public:
    Post(const QString &senderID,
         const QDateTime &time,
         const QString &text,
         const QImage &image,
         int postID);

    int getPostID() const;
    void setPostID(int postID);

    QVector<Like*> getLikes() const;
    void addLike(Like* like);
    void removeLike(int index);

    QVector<Comment*> getComments() const;
    void addComment(Comment* comment);
    void removeComment(int index);

    int getRepostCount() const;
    void incrementRepostCount();

private:
    int postID;
    QVector<Like*> likes;
    QVector<Comment*> comments;
    int repostCount;
};

#endif // POST_H
