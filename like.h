#ifndef LIKE_H
#define LIKE_H

#include "timee.h"
#include <string>

class Like {
public:
    Like(const std::string &whoLikeId, const std::string &likeId, const Time &time);

    std::string getWhoLikeId() const;
    void setWhoLikeId(const std::string &whoLikeId);

    std::string getLikeId() const;
    void setLikeId(const std::string &likeId);

    Time getTime() const;
    void setTime(const Time &time);

private:
    std::string who_like_id;
    std::string like_id;
    Time time;
};

#endif // LIKE_H
