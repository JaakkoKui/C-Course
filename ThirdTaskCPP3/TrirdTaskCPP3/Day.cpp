
#include "time.h"
#include "day.h"

using namespace std;

Day::Day()
	: day(0), month("") {}

bool Day::from_str(const string& s)
{
	istringstream is(s);
	is >> day >> month;
	if (!is)
	{
		return false;
	}
	Time t;
	while (is >> t)
	{
		list.push_back(t);
	}
	return true;
}

string Day::to_str()
{
	ostringstream os;
	os << day << " " << month << " ";
	for (const Time& t : list)
	{
		os << t << " ";
	}
	return os.str();
}

void Day::dst(int offset)
{
	for (Time& t : list)
	{
		t.hours += offset;
	}
}



