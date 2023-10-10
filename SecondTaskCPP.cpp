#include <iostream>
#include <string>
#include <iomanip>

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
    void display()
    {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setw(2) << minutes << std::endl;
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
    /*ostream& Time::operator<<(ostream& os, const Time& time)
    {
        os << std::setfill('0') << std::setw(2) << time.hours << ":"
                  << std::setw(2) << time.minutes << std::endl;
        return os;
    }*/

    Time operator+(const Time& time)
    {
        Time sum = {hours + time.hours, minutes + time.minutes};
        return sum;
    }


};

int main()
{
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
    cout << "Sum of times is ";
    Time sum = time1 + time2;
    sum.display();
    return 0;
}