#include <iostream>
#pragma warning(disable :4996)
using namespace std;

struct Goods
{
	char items[50]; // ǰ���̸�
	int price; // ����
	int year; // ������� ��
	int month;// ������� ��
	int day; // ������� ��
	int discount; // ������
};
int tolDay(int , int , int );
int isYear(int *); // �ش� �⵵�� �������� �˻��ϴ� �Լ�
void input(Goods *s);
void selling_price(Goods *s,int,int);
void output(const Goods *s);
void checkDay(Goods *s);
int isYear(int year);
void getdate(struct date *);
void callPresent(int *, int *, int *);

int main()
{
	struct Goods s;
	int tol1;
	int tol2;
	int pyear, pmonth, pday;

	cout << "**********������ C++ ���Ĺ� HW9**********" << endl;

	input(&s);
	tol1 = tolDay(s.year, s.month, s.day);
	callPresent(&pyear, &pmonth, &pday);
	tol2 = tolDay(pyear, pmonth, pday);
	selling_price(&s, tol1, tol2);
	output(&s);
}
void input(Goods *s)
{
	if (s == NULL) { return; }
	cout << "ǰ�� �Է� : ";
	cin.getline(s->items, sizeof(s->items));
	cout << "���� �Է� : ";
	cin >> s->price;
	cout << "������� �Է� : ";
	cin >> s->year >> s->month >> s->day;
	checkDay(s);
	return;
}
void checkDay(Goods *s)
{
	while (1)
	{

		if (s->month > 12 || s->month < 1)
		{
			cout << "�ٽ� �Է��ϼ��� : ";
			cin >> s->year >> s->month >> s->day;
		}
		else if (s->day > 28 && s->month == 2 && isYear(s->year) != 1)
		{
			cout << "�ٽ� �Է��ϼ��� : ";
			cin >> s->year >> s->month >> s->day;
		}
		else if (s->day > 31)
		{
			cout << "�ٽ� �Է��ϼ��� : ";
			cin >> s->year >> s->month >> s->day;
		}
		else
		{
			break;
		}
	}
	return;
}
int tolDay(int year, int month, int day)
{
	int tol = 0;
	int monthDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1990; i < year; i++)
	{
		if (isYear(i) == 0){tol = tol + 365;}
		else{tol = tol + 366;}
	}
	for (int i = 1; i < month; i++){tol = tol + monthDay[i - 1];}
	tol = tol + day;
	if (isYear(year) == 1 && month > 2){tol = tol + 1;}
	else if (isYear(year) == 1 && month <= 2 && day == 29){	tol = tol + 1;}
	else;
	return tol;
}
int isYear(int year)
{
	int isyear;
	if ((year % 4) == 0)
	{
		if ((year % 100) == 0)
		{
			if ((year % 400) == 0){isyear = 1;}
			else{isyear = 0;}
		}
		else{isyear = 1;}
	}
	else {isyear = 0;}
	return isyear;
}
void selling_price(Goods *s, int tol1, int tol2)
{
	if (s == NULL) { return; }
	int sub = tol1 - tol2;
	if (sub < 0) 
	{ 
		cout << "��������� �������ϴ� " << endl;  
		s->discount = -1;
		return;
	}
	if (sub >= 0 && sub <= 3) { s->discount = 50; }
	else if (sub >= 4 && sub <= 10) { s->discount = 20; }
	else { s->discount = 0; }
	
	s->price = (double)s->price-(s->price*s->discount*0.01);
}
void output(const Goods *s)
{
	cout << "--------------------------------------------------------------------------"<< endl;
	cout << "ǰ�� : " << s->items << endl;
	cout << "�ǸŰ� : " << s->price << endl;
	cout << "������� : " << s->year << "�� " << s->month << "�� " << s->day << "��" << endl;
	if (s->discount != -1)
	{
		cout << "������ : " << s->discount << "%"<< endl;
	}
	else { cout << "���� �Ҽ� ���� ǰ���Դϴ�"<<endl; }
	cout << "--------------------------------------------------------------------------" << endl;
}
