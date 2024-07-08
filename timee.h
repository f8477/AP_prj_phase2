#ifndef TIMEE_H
#define TIMEE_H

#include <iostream>
#include <QString>

class Time {
public:
    Time(int initYear, int initMonth, int initDay, int initHour, int initMinute, int initSecond);
    Time();

    int getYear() const;
    void setYear(int newYear);

    int getMonth() const;
    void setMonth(int newMonth);

    int getDay() const;
    void setDay(int newDay);

    int getHour() const;
    void setHour(int newHour);

    int getMinute() const;
    void setMinute(int newMinute);

    int getSecond() const;
    void setSecond(int newSecond);

    friend std::ostream& operator<<(std::ostream &out, const Time &timeInstance);

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

#endif // TIMEE_H
