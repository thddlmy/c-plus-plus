#pragma once
#include <iostream>
#pragma warning (disable : 4996)
#include "HW10_Time.h"
using namespace std;

Time::Time()
{
	hour = 0;
	min = 0;
}// default cons
Time::Time(int hour, int min)
{
	this->hour = hour;
	if (min < 0 || min > 59) { this->min = 0; }
	this->min = min;
}// overloaded cons
Time::Time(double hour)
{
	this->hour = hour;
}// onerloaded cons
Time::Time(const Time &tr)
{
	this->hour = tr.hour;
	this->min = tr.min;
}// copy cons
Time Time::plus(const Time &tr)
{
	Time res;
	res.hour = tr.hour + this->hour;
	res.min = tr.min + this->min;
	if (res.min > 59)
	{
		res.min -= 60;
	}
	res.hour++;
	return res;
}	// plus func
void Time::setHour(int hour)
{
	this->hour = hour;
}
int Time::getHour()
{
	return hour;
}
void Time::setMin(int min)
{
	this->min = min;
}
int Time::getMin()
{
	return min;
}