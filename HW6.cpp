#include <iostream>
using namespace std;

int my_strlen(char *, int, char);

int main()
{
	char str[100];
	char ch = NULL;
	int size = sizeof(str)/sizeof(str[0]);
	int mystrlen;

	cout << "**********정혜경 C++ HW6**********" << endl;

	cout << "문자열 입력 : ";
	cin >> str;

	size = my_strlen(str, size, ch);
	mystrlen = size;
	cout << "문자열의 길이 : " << size << endl;

	cout << "문자 입력 : ";
	cin >> ch;

	size = my_strlen(str, size, ch);
	if (size != mystrlen)
	{
		cout << ch << "이전 까지의 길이 : " << size;
	}
	else
	{
		cout << str;
	}

}
int my_strlen(char * str, int size, char ch)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] != ch)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
