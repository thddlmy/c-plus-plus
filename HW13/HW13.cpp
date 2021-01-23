#include <iostream>
#include "HW13.h"
using namespace std;


int Time::mode = integer;

Time::Time()
{
	hour = 0;
	min = 0;
	time = 0;
}
Time::Time(int h, int m)
{
	hour = h;
	min = m;
	time = hour + (double)min / 60.0;
}
Time::Time(double d)
{
	hour = (int)d;
	min = (int)((d - hour)*60.0);
	time = d;
}
Time::Time(const Time &tr)
{
	hour = tr.hour;
	min = tr.min;
	time = tr.time;
}
Time Time::pius(const Time &tr)
{
	hour = hour + tr.hour;
	min = min + tr.min;
	if (min >= 60)
	{
		hour++;
		min = min % 60;
	}
	time = time + tr.time;

	return *this;
}
void Time::setHour(int h)
{
	hour = h;
}
int Time::getHour()
{
	return hour;
}
void Time::setMin(int m)
{
	if (m < 0) { return; }
	min = m;
}
int Time::getMin()
{
	return min;
}
void Time::mode_change()
{
	if (mode == integer) { mode = real; }
	else { mode = integer; }
}