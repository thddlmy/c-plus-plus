#include <iostream>
using namespace std;

void swap_ptr(const char *(&a),const char *(&b));

int main()
{
	const char *ap = "apple";
	const char *bp = "banana";

	cout << "�ٲٱ� ���� ���ڿ� : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "�ٲ� ���� ���ڿ� : " << ap << " " << bp << endl;
}
void swap_ptr(const char *(&a),const char *(&b))
{
	const char *temp;
	temp = a;
	a = b;
	b = temp;
}