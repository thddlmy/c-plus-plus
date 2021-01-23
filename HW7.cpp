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

void init(Savings &s); // 구조체내의 4개 멤버를 모두 0으로 초기화 함
void input(Savings &s,int &unit, int &cnt); // 동전금액, 동전 개수를 저장할 변수
void save(Savings &s, int unit, int cnt); // 저금통 구조체 변수의 멤버를 전달 받은 동전의 개수 만큼 누적함
int total(Savings &s); // 저금통의 총 저축액을 계산하여 리턴하는 함수
void myflush();

int main()
{
	cout << "**********정혜경 C++ 오후반 HW7**********" << endl;
	Savings money;
	int unit, cnt;
	init(money);
	input(money,unit, cnt);
	cout << "총 저금액 :" << total(money) << endl;
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
		cout << "동전의 금액 (문자 입력시 종료) : ";
		cin >> unit;
		if(cin.fail()) { myflush(); break; } 
		if (unit != 500 && unit != 100 && unit != 50 && unit != 10) 
		{
			cout << "단위를 다시 입력하세요" << endl;
			continue;
		}
		cout << "동전의 개수 : ";
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