#pragma once
#include <iostream>
#pragma warning (disable : 4996)
#include "HW10_Time.h"
using namespace std;

int main()
{
	cout << "********************������ C++ ���Ĺ� HW10******************** " << endl;
	Time a(3, 20), b;
	cout << a.getHour() << "�ð�" << a.getMin() << "��" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "�ð�" << b.getMin() << "��" << endl;
	Time res = a.plus(b);
	cout << "�� �ð��� ���ϸ� : " << res.getHour() << "�ð�" << res.getMin() << "��" << endl;
	return 0;
}