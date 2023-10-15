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

    void read(string s)
    {
        cout << s << endl;
        cout << "Hours: ";
        cin >> hours;
        cout << "Minutes: ";
        cin >> minutes;
    };

    Time()
    {
        hours = 0;
        minutes = 0;
    };

    Time(int HTime, int MTime)
    {
        this->hours = HTime;
        this->minutes = MTime;
    }

    void display()
    {
        cout << hours << ":" << minutes << endl;
    };

    int lessThan(Time comparedTime)
    {
        if (hours > comparedTime.hours)
        {
            cout << "Time 1 is greater than compared time\n";
            return 0;
        }
        else if (hours < comparedTime.hours)
        {
            cout << "Compared time is greater than time 1\n";
            return 1;
        }
        else
        {
            if (minutes > comparedTime.minutes)
            {
                cout << "Time 1 is greater than compared time\n";
                return 0;
            }
            else if (hours < comparedTime.hours)
            {
                cout << "Compared time is greater than time 1\n";
                return 1;
            }
            else
            {
                cout << "Time 1 is equal to compared time\n";
            }
        }
        return 0;
    };

    Time subtract(Time lesserTime)
    {
        if (minutes < lesserTime.minutes)
        {
            minutes += 60;
            hours--;
        }

        Time duration = {hours - lesserTime.hours, minutes - lesserTime.minutes};
        return duration;
    };

    Time operator+(const Time &time) const
    {
        int totalMinutes = (minutes + time.minutes) + (hours + time.hours) * 60;
        int newHours = totalMinutes / 60;
        int newMinutes = totalMinutes % 60;
        return Time(newHours, newMinutes);
    }

    Time operator-(const Time &time) const
    {
        int totalMinutes = (minutes - time.minutes) + (hours - time.hours) * 60;
        int newHours = totalMinutes / 60;
        int newMinutes = totalMinutes % 60;

        if (newHours < 0)
        {
            newHours += 24;
        }

        if (newMinutes < 0)
        {
            newMinutes += 60;
            newHours--;
        }

        return Time(newHours, newMinutes);
    }

    friend ostream &operator<<(ostream &os, const Time &time)
    {
        os << std::setfill('0') << std::setw(2) << time.hours << ":"
           << std::setw(2) << time.minutes;
        return os;
    }

    bool operator<(const Time &comparedTime) const
    {
        if (hours < comparedTime.hours)
        {
            return true;
        }
        else if (hours == comparedTime.hours)
        {
            return minutes < comparedTime.minutes;
        }
        return false;
    }

    Time &operator++()
    {
        minutes++;
        if (minutes >= 60)
        {
            minutes = 0;
            hours++;
            if (hours >= 24)
            {
                hours = 0;
            }
        }
        return *this;
    }
 
    Time operator++(int)
    {
        Time temp = *this;
        ++(*this);
        return temp;
};

void print(vector<Time> &v)
{
    for (Time &t : v)
    {
        cout << t << endl;
    }
};

int main()
{
    cout << "Task 2a:\n";
    Time time1, time2, duration;
    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1.lessThan(time2))
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

// --------------TASK 2B--------------

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
    for (auto &t : tv)
    {
        t.read("Enter time:");
    }

    cout << "Times: " << endl;
    print(tv);
    Time sum;
    for (auto t : tv)
    {
        sum = sum + t;
    }

    cout << "+\nSum of times: " << sum << endl;

    cout << "\nPost-increment: " << endl;
    print(tv);
    for (auto &t : tv)
    {
        cout << t++ << endl;
    }

    print(tv);

    cout << "\nPre-increment: " << endl;
    for (auto &t : tv)
    {
        cout << ++t << endl;
    }

    sort(tv.begin(), tv.end());

    cout << "\nSorted times: " << endl;
    print(tv);

    return 0;
}
};
