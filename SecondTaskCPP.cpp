#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Time
{
public:
    int hours, minutes;

    Time()
        : hours(0), minutes(0) {}

    Time(int HTime, int MTime)
        : hours(HTime), minutes(MTime) {}

    void read(string s)
    {
        cout << s << endl;
        cout << "Hours: ";
        cin >> hours;
        cout << "Minutes: ";
        cin >> minutes;
    }

    void display()
    {
        cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << endl;
    }

    bool operator<(const Time &comparedTime) const
    {
        if (hours == comparedTime.hours)
            return minutes < comparedTime.minutes;
        return hours < comparedTime.hours;
    }

    Time subtract(const Time &lesserTime) const
    {
        int totalMinutes = (hours - lesserTime.hours) * 60 + (minutes - lesserTime.minutes);
        if (totalMinutes < 0)
        {
            totalMinutes += 24 * 60;
        }
        return Time(totalMinutes / 60, totalMinutes % 60);
    }

    Time operator+(const Time &time) const
    {
        int totalMinutes = hours * 60 + minutes + time.hours * 60 + time.minutes;
        return Time(totalMinutes / 60, totalMinutes % 60);
    }

    Time operator-(const Time &time) const
    {
        int totalMinutes = (hours - time.hours) * 60 + (minutes - time.minutes);
        if (totalMinutes < 0)
        {
            totalMinutes += 24 * 60;
        }
        return Time(totalMinutes / 60, totalMinutes % 60);
    }

    Time &operator++()
    {
        minutes++;
        if (minutes >= 60)
        {
            minutes = 0;
            hours = (hours + 1) % 24;
        }
        return *this;
    }

    Time operator++(int)
    {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    friend ostream &operator<<(ostream &os, const Time &time)
    {
        os << setfill('0') << setw(2) << time.hours << ":" << setw(2) << time.minutes;
        return os;
    }
};

void print(const vector<Time> &v)
{
    for (const Time &t : v)
    {
        cout << t << endl;
    }
}

int main()
{
    cout << "Task 2a:\n";
    Time time1, time2, duration;
    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1 < time2)
    {
        duration = time2.subtract(time1);
        cout << "Starting time was ";
        time1.display();
    }
    else
    {
        duration = time1.subtract(time2);
        cout << "Starting time was ";
        time2.display();
    }
    cout << "Duration was ";
    duration.display();

    cout << "Task 2b:\n";

    Time time1b, time2b, durationB, duration2B;

    time1b.read("Enter time 1");
    time2b.read("Enter time 2");

    if (time1b < time2b)
    {
        durationB = time2b - time1b;
        cout << "Starting time was " << time1b << endl;
        duration2B = time1b - time2b;
    }
    else
    {
        durationB = time1b - time2b;
        cout << "Starting time was " << time2b << endl;
        duration2B = time2b - time1b;
    }
    cout << "Duration was " << durationB << endl;
    cout << "Duration2 was " << duration2B << endl;

    vector<Time> tv(5);
    for (Time &t : tv)
    {
        t.read("Enter time:");
    }

    cout << "Times: " << endl;
    print(tv);
    Time sum;
    for (const Time &t : tv)
    {
        sum = sum + t;
    }

    cout << "+\nSum of times: " << sum << endl;

    cout << "\nPost-increment: " << endl;
    print(tv);
    for (Time &t : tv)
    {
        cout << t++ << endl;
    }

    print(tv);

    cout << "\nPre-increment: " << endl;
    for (Time &t : tv)
    {
        cout << ++t << endl;
    }

    sort(tv.begin(), tv.end());

    cout << "\nSorted times: " << endl;
    print(tv);

    return 0;
}