#include <iostream>
#include <string>
#pragma warning(disable : 4996)
#include "HW16.h"
using namespace std;

int main()
{
	Happy a("ö��"), b("����"), w;
	char item[100];
	int price;

	cout << "ö�̰� ���� ���ϴ�" << endl;
	while (1)
	{
		cout << "���� ���� : ";
		cin >> item;
		if (!strcmp(item, "end")) { break; }
		cout << "�ݾ� �Է� : ";
		cin >> price;
		a.use(item, price);
	}
	cout << "������ ���� ���ϴ�" << endl;
	while (1)
	{
		cout << "���� ���� : ";
		cin >> item;
		if (!strcmp(item, "end")) { break; }
		cout << "�ݾ� �Է� : ";
		cin >> price;
		b.use(item, price);
	}
	cout << "���� ���ڴ�?" << endl;
	w = a.winner(b);
	cout << w.getName()<< "�̰� �� " << w.getIndex() << "���� ����ϰ� ���� �ݾ��� " <<w.getMoney() << "��" << endl;
	cout << w.getName() << "�� ��� ������ : ";
	char **list = w.getList();
	for (int i = 0; i < w.getIndex(); i++)
	{
		cout << list[i] << " ";
	}
	return 0;
} 