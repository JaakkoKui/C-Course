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

    Time(){
        hours = 0;
        minutes = 0;
    };

    Time(int HTime, int MTime){
        this->hours = HTime;
        this->minutes = MTime;
    }
    
    void display()
    {
        cout << hours << ":" << minutes << endl;
        /*  std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                    << std::setw(2) << minutes << std::endl;*/
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

    Time operator+(const Time &time)
    {
        Time sum = {hours + time.hours, minutes + time.minutes};
        return sum;
    };

    Time operator-(const Time &time)
    {
        Time difference = {hours - time.hours, minutes - time.minutes};
        return difference;
    };

    Time operator++(){
        int raisedHours = hours;
        int raisedMinutes = minutes++;
        if(raisedMinutes >= 60){
            raisedMinutes = 0;
            raisedHours++;
        }
        Time raised = {raisedHours, raisedMinutes};
        return raised;
    };


};

int main()
{
    cout << "Task 1b:\n";
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
/*    Time sum = time1 + time2;
    Time difference = time1 - time2;
    Time raised = time++;
    cout << "Raised time is ";
    cout << "Sum of times is ";
    sum.display();
    cout << "Time 1 minus time 2 is ";
    difference.display();
*/    

    cout << "Task 2b:\n";

    Time time1b, time2b, durationB, duration2B;

	time1b.read("Enter time 1");
	time2b.read("Enter time 2");
	if (time1b<time2b) {
		durationB = time2b - time1b;
		cout << "Starting time was " << time1b << endl;
		duration2B = time1b - time2b;
	} else {
		durationB = time1b - time2b;
		cout << "Starting time was " << time2b << endl;
		duration2B = time2b - time1b;

	}
	cout << "Duration was " << durationB << endl;

	// check that we don't get negative times
	cout << "Duration2 was " << duration2B << endl;


	vector<Time> tv(5); 
	for(auto &t : tv) {
		t.read("Enter time:");
	}

	cout << "Times: " << endl;
	print(tv);
	
	Time sum;
	for(auto t : tv) {
		sum = sum + t;
	}
	
	cout << "Sum of times: " << sum << endl;
	
	cout << "Post-increment: " << endl;
	print(tv);
	for(auto &t : tv) {
		cout << t++ << endl;
	}
	
	print(tv);

	cout << "Pre-increment: " << endl;
	for(auto &t : tv) {
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	return 0;
}