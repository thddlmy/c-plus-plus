#include <iostream>
#include <string.h>
#include "Profile.h"
#include "MyString.h"
using namespace std;

void userScreen(void);
char menu(void);
int proInput(Profile *,int);
void proUpdate(Profile *ap, int cnt);
int proFind(Profile *ap, char * temp, int cnt);
void proDisplay(Profile *, int);


int main()
{
	userScreen();
	return 0;
}
//----------------------------------------------------------------------------------------------
void userScreen()
{
	Profile ary[20]; // 프로필 저장 객체 배열
	int profileCnt = 0; // 입력 받은 프로필의 개수 카운트 변수
	char ch; // 메뉴번호 저장 변수
	while (1)
	{
		ch = menu(); // 입력된 메뉴의 번호를 ch에 리턴받음
		if (ch == '4') { break; } // 4번 종료하기 메뉴 입력시 무한반복문을 탈출
		switch (ch)
		{
		case '1': profileCnt = proInput(ary,profileCnt); break;
		case '2' : proUpdate(ary,profileCnt); break;
		case '3': proDisplay(ary, profileCnt); break;
		}
	}
}
//----------------------------------------------------------------------------------------------
char menu(void)
{
	char n = 0, i;
	char menulist[4][20] = { "프로필 입력", "프로필 수정", "프로필 출력","종료" };
	for (i = 0; i < 4; i++) // 메뉴 문자열을 출력하는 반복문
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}
	while (n<'1' || n>'4') // 유효한 번호가 아니면 다시 입력
	{
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
//--------------------------------------------------------------------------------------------
int proInput(Profile *ap, int cnt) // 인원제한 & 이어지는 입력가능 
{
	char name[50];
	char addr[80];
	int age;
	double height;
	//int cnt = 0; // 입력 받은 프로필의 개수를 카운트하는 변수
	while (1)
	{
		cout << "이름입력 : ";
		cin >> name;
		if (strcmp(name, "끝") == 0) { break; }
		cout << "주소입력 : "; cin >> addr;
		cout << "나이입력 : "; cin >> age;
		cout << "키입력 : "; cin >> height;
		ap[cnt] = Profile(name, addr, age, height); // 입력 받은 데이터로 객체 초기화
		cnt++;
		if (cnt == 21) { cout <<"Full Profile" << endl; break; }
	}
	return cnt;
}
//---------------------------------------------------------------
void proDisplay(Profile *ap, int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		cout << i + 1 << ". " << ap[i].getName().getStr() << " : "
			<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "세/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}
//---------------------------------------------------------------
void proUpdate(Profile *ap, int cnt)
{
	char temp[20];
	char addr[80];
	int age;
	double height;
	int res;
	while (1)
	{
		cout << "수정할 이름을 입력 : ";
		cin >> temp;
		if (!strcmp(temp, "끝")) { break; }
		if (res = proFind(ap, temp, cnt) == -1) { cout << "No Find Name" << endl; continue; }
		cout << ap[res].getName().getStr() << "/" << ap[res].getAddr().getStr() << "/" << ap[res].getAge() << "/" << ap[res].getHeight() << endl;
		cout << "수정 주소 입력 : "; cin >> addr;
		cout << "수정 나이 입력 : "; cin >> age;
		cout << "수정 키 입력 : "; cin >> height;
		ap[res] = Profile(temp, addr, age, height);
		//ap[res].getAddr().setStr(addr);
		/*ap[res].setName(ap[res].getAddr());
		ap[res].setAge(age);
		ap[res].setHeight(height);*/
	}
}
int proFind(Profile *ap, char * temp, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(ap[i].getName().getStr(), temp) == 0) { return i; }
	}
	return -1;
}