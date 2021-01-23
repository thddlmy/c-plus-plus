#include <iostream>
#include "HW13.h"
using namespace std;

ostream &operator <<(ostream &os, const Time &br);

int main()
{
	Time a(3, 21);
	Time b(2.7);
	cout << "�⺻ ��� ���� (�ð�,��)" << endl;
	cout << a;
	cout << b;
	Time::mode_change();
	cout << "��� ��� CHANGE" << endl;
	cout << a ;
	cout << b ;
	return 0;
}
ostream &operator <<(ostream &os, const Time &tr)
{
	if (tr.mode == Time::integer)
	{
		cout << tr.hour << "�ð� " << tr.min << "��" << endl;
	}
	else
	{
		cout << tr.time << "�ð�" << endl;
	}
	return os;
}