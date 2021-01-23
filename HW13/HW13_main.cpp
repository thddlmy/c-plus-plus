#include <iostream>
#include "HW13.h"
using namespace std;

ostream &operator <<(ostream &os, const Time &br);

int main()
{
	Time a(3, 21);
	Time b(2.7);
	cout << "기본 출력 형태 (시간,분)" << endl;
	cout << a;
	cout << b;
	Time::mode_change();
	cout << "출력 모드 CHANGE" << endl;
	cout << a ;
	cout << b ;
	return 0;
}
ostream &operator <<(ostream &os, const Time &tr)
{
	if (tr.mode == Time::integer)
	{
		cout << tr.hour << "시간 " << tr.min << "분" << endl;
	}
	else
	{
		cout << tr.time << "시간" << endl;
	}
	return os;
}