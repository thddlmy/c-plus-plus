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
	Profile ary[20]; // ������ ���� ��ü �迭
	int profileCnt = 0; // �Է� ���� �������� ���� ī��Ʈ ����
	char ch; // �޴���ȣ ���� ����
	while (1)
	{
		ch = menu(); // �Էµ� �޴��� ��ȣ�� ch�� ���Ϲ���
		if (ch == '4') { break; } // 4�� �����ϱ� �޴� �Է½� ���ѹݺ����� Ż��
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
	char menulist[4][20] = { "������ �Է�", "������ ����", "������ ���","����" };
	for (i = 0; i < 4; i++) // �޴� ���ڿ��� ����ϴ� �ݺ���
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}
	while (n<'1' || n>'4') // ��ȿ�� ��ȣ�� �ƴϸ� �ٽ� �Է�
	{
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
//--------------------------------------------------------------------------------------------
int proInput(Profile *ap, int cnt) // �ο����� & �̾����� �Է°��� 
{
	char name[50];
	char addr[80];
	int age;
	double height;
	//int cnt = 0; // �Է� ���� �������� ������ ī��Ʈ�ϴ� ����
	while (1)
	{
		cout << "�̸��Է� : ";
		cin >> name;
		if (strcmp(name, "��") == 0) { break; }
		cout << "�ּ��Է� : "; cin >> addr;
		cout << "�����Է� : "; cin >> age;
		cout << "Ű�Է� : "; cin >> height;
		ap[cnt] = Profile(name, addr, age, height); // �Է� ���� �����ͷ� ��ü �ʱ�ȭ
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
			<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "��/"
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
		cout << "������ �̸��� �Է� : ";
		cin >> temp;
		if (!strcmp(temp, "��")) { break; }
		if (res = proFind(ap, temp, cnt) == -1) { cout << "No Find Name" << endl; continue; }
		cout << ap[res].getName().getStr() << "/" << ap[res].getAddr().getStr() << "/" << ap[res].getAge() << "/" << ap[res].getHeight() << endl;
		cout << "���� �ּ� �Է� : "; cin >> addr;
		cout << "���� ���� �Է� : "; cin >> age;
		cout << "���� Ű �Է� : "; cin >> height;
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