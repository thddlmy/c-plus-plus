#include <iostream>
#include <string>
#pragma warning(disable : 4996)
#include "HW16.h"
using namespace std;

Happy::Happy(string np, int money)
{
	name = np;
	this->money = money;
	index = 0;
}
Happy::Happy(Happy &r)
{
	for (int i = 0; i < index; i++)
	{
		delete[] list[i];
	}
	name = r.name;
	money = r.money;
	for (int i = 0; i < index; i++)
	{
		strcpy(this->list[i], r.list[i]);
	}
	index = r.index;
}
Happy::~Happy()
{
	for (int i = 0; i < index; i++)
	{
		delete[] list[i];
	}
}
Happy & Happy::operator= (Happy &r)
{
	for (int i = 0; i < r.index; i++)
	{
		list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(list[i], r.list[i]);
	}
	name = r.name;
	money = r.money;
	index = r.index;

	return *this;
}
void Happy::use(char *lp, int n)
{
	list[index] = new char[strlen(lp) + 1];
	strcpy(list[index], lp);
	this->money -= n;
	index++;
}
Happy &Happy::winner(Happy &r)
{
	if (this->money > r.money) { return *this; }
	else { return r; }
}
void Happy::setName(string &name)
{
	this->name = name;
}
string & Happy::getName()
{
	return name;
}
void Happy::setMoney(int money)
{
	this->money = money;
}
char **Happy::getList()
{
	return list;
}
int Happy::getIndex()
{
	return index;
}
int Happy::getMoney()
{
	return money;
}