#include "timee.h"

Time::Time(int initYear, int initMonth, int initDay, int initHour, int initMinute, int initSecond)
    : year(initYear), month(initMonth), day(initDay), hour(initHour), minute(initMinute), second(initSecond) {}

Time::Time()
    : year(0), month(0), day(0), hour(0), minute(0), second(0) {}

int Time::getYear() const {
    return year;
}

void Time::setYear(int newYear) {
    year = newYear;
}

int Time::getMonth() const {
    return month;
}

void Time::setMonth(int newMonth) {
    month = newMonth;
}

int Time::getDay() const {
    return day;
}

void Time::setDay(int newDay) {
    day = newDay;
}

int Time::getHour() const {
    return hour;
}

void Time::setHour(int newHour) {
    hour = newHour;
}

int Time::getMinute() const {
    return minute;
}

void Time::setMinute(int newMinute) {
    minute = newMinute;
}

int Time::getSecond() const {
    return second;
}

void Time::setSecond(int newSecond) {
    second = newSecond;
}

std::ostream& operator<<(std::ostream &out, const Time &timeInstance) {
    QString formattedTime = QString("%1-%2-%3 %4:%5:%6")
                            .arg(timeInstance.year, 4, 10, QChar('0'))
                            .arg(timeInstance.month, 2, 10, QChar('0'))
                            .arg(timeInstance.day, 2, 10, QChar('0'))
                            .arg(timeInstance.hour, 2, 10, QChar('0'))
                            .arg(timeInstance.minute, 2, 10, QChar('0'))
                            .arg(timeInstance.second, 2, 10, QChar('0'));
    out << formattedTime.toStdString();
    return out;
}
