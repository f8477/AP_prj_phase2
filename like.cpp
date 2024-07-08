#include "like.h"

Like::Like(const std::string &whoLikeId, const std::string &likeId, const Time &time)
    : who_like_id(whoLikeId), like_id(likeId), time(time) {}

std::string Like::getWhoLikeId() const {
    return who_like_id;
}

void Like::setWhoLikeId(const std::string &whoLikeId) {
    who_like_id = whoLikeId;
}

std::string Like::getLikeId() const {
    return like_id;
}

void Like::setLikeId(const std::string &likeId) {
    like_id = likeId;
}

Time Like::getTime() const {
    return time;
}

void Like::setTime(const Time &time) {
    this->time = time;
}
