#include <iostream>
using namespace std;

int my_strlen(char *, int, char);

int main()
{
	char str[100];
	char ch = NULL;
	int size = sizeof(str)/sizeof(str[0]);
	int mystrlen;

	cout << "**********������ C++ HW6**********" << endl;

	cout << "���ڿ� �Է� : ";
	cin >> str;

	size = my_strlen(str, size, ch);
	mystrlen = size;
	cout << "���ڿ��� ���� : " << size << endl;

	cout << "���� �Է� : ";
	cin >> ch;

	size = my_strlen(str, size, ch);
	if (size != mystrlen)
	{
		cout << ch << "���� ������ ���� : " << size;
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
