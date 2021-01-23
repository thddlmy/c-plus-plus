#pragma once
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

class Time
{
private :
	int hour;
	int min;
public :
	Time(); // default cons
	Time(int, int); // overloaded cons
	Time(double); // onerloaded cons
	Time(const Time &tr); // copy cons
	Time plus(const Time &tr); // plus func
	void setHour(int); 
	int getHour();
	void setMin(int);
	int getMin();
};
