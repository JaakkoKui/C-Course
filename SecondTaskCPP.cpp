#include <iostream>
#include <string>

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
            }else{
                cout << "Time 1 is equal to compared time\n";
            }
        }
        return 0;
    };

    Time subtract(Time lesserTime)
    {
        Time duration = {hours - lesserTime.hours, minutes - lesserTime.minutes};
        return duration;
    };
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
    return 0;
}