#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class Time
{
public:
    int hours, minutes;

    Time();
    Time(int HTime, int MTime);

    void read(const std::string& s);
    void display() const;
    bool operator<(const Time& comparedTime) const;
    Time subtract(const Time& lesserTime) const;
    Time operator+(const Time& time) const;
    Time operator-(const Time& time) const;
    Time& operator++();
    Time operator++(int);

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
    friend std::istream& operator>>(std::istream& is, Time& time);
};

#endif // TIME_H_INCLUDED