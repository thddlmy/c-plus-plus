#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char name[20];
	double average, korean, english, math;

	cout << "�̸� : ";
	cin.getline(name, sizeof(name));

	cout << "�� ������ ���� : ";
	cin >> korean >> english >> math;

	average = (double)(korean + english + math) / 3;

	cout << right << setw(40) << "=====<<����ǥ>>=====" << endl;
	cout << "================================================================"<<endl;

	cout << setw(10)<< "�̸�" << setw(10) << "����" << setw(10) << "����" << setw(10) << "����" << setw(10) << "����" << setw(10) << "���" << endl;
	cout << "================================================================" << endl;
	cout << setw(10) << name << setw(10) << korean << setw(10) << math << setw(10) << english << setw(10) << korean + english + math << setw(10) << setprecision(4) << average << endl;

}