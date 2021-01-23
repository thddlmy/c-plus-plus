#include <iostream>
#include <string>
#pragma warning(disable : 4996)
#include "HW16.h"
using namespace std;

int main()
{
	Happy a("철이"), b("메텔"), w;
	char item[100];
	int price;

	cout << "철이가 돈을 씁니다" << endl;
	while (1)
	{
		cout << "구입 내역 : ";
		cin >> item;
		if (!strcmp(item, "end")) { break; }
		cout << "금액 입력 : ";
		cin >> price;
		a.use(item, price);
	}
	cout << "메텔이 돈을 씁니다" << endl;
	while (1)
	{
		cout << "구입 내역 : ";
		cin >> item;
		if (!strcmp(item, "end")) { break; }
		cout << "금액 입력 : ";
		cin >> price;
		b.use(item, price);
	}
	cout << "최종 승자는?" << endl;
	w = a.winner(b);
	cout << w.getName()<< "이고 총 " << w.getIndex() << "건을 사용하고 남은 금액은 " <<w.getMoney() << "원" << endl;
	cout << w.getName() << "의 사용 내역은 : ";
	char **list = w.getList();
	for (int i = 0; i < w.getIndex(); i++)
	{
		cout << list[i] << " ";
	}
	return 0;
} 