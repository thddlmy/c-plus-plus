#pragma once
#include <iostream>
#pragma warning (disable : 4996)
#include "HW10_Time.h"
using namespace std;

int main()
{
	cout << "********************정혜경 C++ 오후반 HW10******************** " << endl;
	Time a(3, 20), b;
	cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "시간" << b.getMin() << "분" << endl;
	Time res = a.plus(b);
	cout << "두 시간을 더하면 : " << res.getHour() << "시간" << res.getMin() << "분" << endl;
	return 0;
}