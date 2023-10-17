#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include "Time.h"

using namespace std;

class Day {
public:
	Day();
	bool from_str(const string& s);
	string to_str();
	void dst(int offset);
private:
	int day;
	string month;
	vector<Time> list;
};