#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Time.h"
#include "Day.h"

//JJ
using namespace std;

void print(const vector<Time>& v)
{
	for (const Time& t : v)
	{
		cout << t << endl;
	}
}

int main()
{
	ifstream inputFile("calendar.txt");
	if (!inputFile.is_open()) {
		cout << "Unable to open file" << endl;
		return 1;
	}
	string line;
	vector<Day> cal;
	Day day;
	while (getline(inputFile, line)) {
		if (day.from_str(line)) {
			cal.push_back(day);
		}
	}
	cout << "Calendar" << endl;
	for (auto& e : cal) {
		cout << e.to_str() << endl;
	}
	// DST shift
	for (auto& e : cal) {
		e.dst(1);
	}
	cout << "DST" << endl;
	for (auto& e : cal) {
		cout << e.to_str() << endl;
	}
	cout << "End" << endl;
/*cout << "Task 3 A and B\n";

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
	for (Time& t : tv)
	{
		t.read("Enter time:");
	}

	cout << "Times: " << endl;
	print(tv);
	Time sum;
	for (const Time& t : tv)
	{
		sum = sum + t;
	}

	cout << "+\nSum of times: " << sum << endl;

	cout << "\nPost-increment: " << endl;
	print(tv);
	for (Time& t : tv)
	{
		cout << t++ << endl;
	}

	print(tv);

	cout << "\nPre-increment: " << endl;
	for (Time& t : tv)
	{
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "\nSorted times: " << endl;
	print(tv);
	*/
	return 0;
}
