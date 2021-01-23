#include <iostream>
#include <string>
#include "MyString.h"
#pragma warning(disable :4996)
using namespace std;

MyString::MyString()
{
	str = new char[strlen("") + 1];
	strcpy(str, "");
	len = 0;
}
MyString::MyString(const char *cp)
{
	str = new char[strlen(cp) + 1];
	strcpy(str, cp);
	len = strlen(cp);
}
MyString::MyString(const MyString &br)
{
	str = new char[strlen(br.str) + 1];
	strcpy(str, br.str);
	len = br.len;
}
MyString::~MyString()
{
	delete[] str;
	len = 0;
}
MyString& MyString::operator=(const MyString &br)
{
	if (this == &br) { return *this; }
	delete[] str;
	str = new char[strlen(br.str) + 1];
	strcpy(str, br.str);
	len = br.len;
	return *this;
}
MyString MyString::operator+(const MyString &br)
{
	char *cp;
	cp = new char[this->len + br.len + 1];
	strcpy(cp, str);
	strcat(cp, br.str);
	MyString temp(cp);
	delete[] cp;
	return temp;
}
bool MyString::operator>(const MyString &br)
{
	/*if (len > br.len) { return 1; }
	else { return 0; }*/
	//return strlen(str) > strlen(br.str); // 길이변경
	return strcmp(this->str, br.str);
}
void MyString::setStr(const char *cp)
{
	if (str == cp) {return;}
	delete[] str;
	len = strlen(cp);
	str = new char[len + 1];
	strcpy(str, cp);
}
char * MyString::getStr(void)
{
	return this->str;
}
int MyString::getLen(void)
{
	return this->len;
}
