#include "Time.h"

Time::Time()
    : hours(0), minutes(0) {}

Time::Time(int HTime, int MTime)
    : hours(HTime), minutes(MTime) {}

void Time::read(const std::string &s)
{
    std::cout << s << std::endl;
    std::cout << "Hours: ";
    std::cin >> hours;
    std::cout << "Minutes: ";
    std::cin >> minutes;
}

void Time::display() const
{
    std::cout << std::setfill('0') << std::setw(2) << hours << ":" << std::setw(2) << minutes << std::endl;
}

bool Time::operator<(const Time &comparedTime) const
{
    if (hours == comparedTime.hours)
        return minutes < comparedTime.minutes;
    return hours < comparedTime.hours;
}

Time Time::subtract(const Time &lesserTime) const
{
    int totalMinutes = (hours - lesserTime.hours) * 60 + (minutes - lesserTime.minutes);
    if (totalMinutes < 0)
    {
        totalMinutes += 24 * 60;
    }
    return Time(totalMinutes / 60, totalMinutes % 60);
}

Time Time::operator+(const Time &time) const
{
    int totalMinutes = hours * 60 + minutes + time.hours * 60 + time.minutes;
    return Time(totalMinutes / 60, totalMinutes % 60);
}

Time Time::operator-(const Time &time) const
{
    int totalMinutes = (hours - time.hours) * 60 + (minutes - time.minutes);
    if (totalMinutes < 0)
    {
        totalMinutes += 24 * 60;
    }
    return Time(totalMinutes / 60, totalMinutes % 60);
}

Time &Time::operator++()
{
    minutes++;
    if (minutes >= 60)
    {
        minutes = 0;
        hours = (hours + 1) % 24;
    }
    return *this;
}

Time Time::operator++(int)
{
    Time temp = *this;
    ++(*this);
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Time &time)
{
    os << std::setfill('0') << std::setw(2) << time.hours << ":" << std::setw(2) << time.minutes;
    return os;
}

std::istream& operator>>(std::istream& is, Time& time)
{
    char colon;
	is >> time.hours >> colon >> time.minutes;
	return is;
}