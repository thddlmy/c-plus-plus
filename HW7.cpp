#include <iostream>
#include <cstring>
#pragma warning (disable: 4996)
using namespace std;

struct Savings {
	int w500;
	int w100;
	int w50;
	int w10;
};

void init(Savings &s); // ����ü���� 4�� ����� ��� 0���� �ʱ�ȭ ��
void input(Savings &s,int &unit, int &cnt); // �����ݾ�, ���� ������ ������ ����
void save(Savings &s, int unit, int cnt); // ������ ����ü ������ ����� ���� ���� ������ ���� ��ŭ ������
int total(Savings &s); // �������� �� ������� ����Ͽ� �����ϴ� �Լ�
void myflush();

int main()
{
	cout << "**********������ C++ ���Ĺ� HW7**********" << endl;
	Savings money;
	int unit, cnt;
	init(money);
	input(money,unit, cnt);
	cout << "�� ���ݾ� :" << total(money) << endl;
}
void init(Savings &s)
{
	s.w500 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w10 = 0;
}
void input(Savings &s,int &unit, int &cnt)
{
	while (1)
	{
		cout << "������ �ݾ� (���� �Է½� ����) : ";
		cin >> unit;
		if(cin.fail()) { myflush(); break; } 
		if (unit != 500 && unit != 100 && unit != 50 && unit != 10) 
		{
			cout << "������ �ٽ� �Է��ϼ���" << endl;
			continue;
		}
		cout << "������ ���� : ";
		cin >> cnt;
		save(s, unit, cnt);
	}
}
void save(Savings &s, int unit, int cnt)
{
	switch (unit)
	{
	case 500: s.w500 = cnt; break;
	case 100: s.w100 = cnt; break;
	case 50: s.w50 = cnt; break;
	case 10: s.w10 = cnt; break;
	}
}
int total(Savings &s)
{
	int tol = 0;
	tol = s.w500 * 500 + s.w100 * 100 + s.w50 * 50 + s.w10 * 10;
	return tol;
}
void myflush()
{
	cin.clear();
	while (cin.get() != '\n');
}