
#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
public:
    Time();
    Time(int hh, int mm, int ss);
    virtual ~Time();

    int GetHour() const;
    int GetMin() const;
    int GetSec() const;

    void SetHour(int hh);
    void SetMin(int mm);
    void SetSec(int ss);
    void SetTime(int hh, int mm, int ss);

    void printTime() const;

    friend std::istream &operator>>(std::istream &input, Time &T);
    friend std::ostream &operator<<(std::ostream &os, const Time &T);

private:
    int hour, min, sec;
};

#endif // TIME_H
