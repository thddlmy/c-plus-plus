#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char name[20];
	double average, korean, english, math;

	cout << "이름 : ";
	cin.getline(name, sizeof(name));

	cout << "세 과목의 점수 : ";
	cin >> korean >> english >> math;

	average = (double)(korean + english + math) / 3;

	cout << right << setw(40) << "=====<<성적표>>=====" << endl;
	cout << "================================================================"<<endl;

	cout << setw(10)<< "이름" << setw(10) << "국어" << setw(10) << "수학" << setw(10) << "영어" << setw(10) << "총점" << setw(10) << "평균" << endl;
	cout << "================================================================" << endl;
	cout << setw(10) << name << setw(10) << korean << setw(10) << math << setw(10) << english << setw(10) << korean + english + math << setw(10) << setprecision(4) << average << endl;

}