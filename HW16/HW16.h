#pragma once
#include <iostream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

class Happy
{
private:
	string name;
	int money;
	char *list[100];
	int index;
public:
	Happy(string np = "", int money = 10000);
	Happy(Happy &r);
	~Happy();
	Happy & operator= (Happy &r);
	void use(char *lp, int n);
	Happy &winner(Happy &r);
	void setName(string &name);
	string & getName();
	int getMoney();
	void setMoney(int money);
	char **getList();
	int getIndex();
};