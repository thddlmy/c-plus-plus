#include <iostream>
using namespace std;

void swap_ptr(const char *(&a),const char *(&b));

int main()
{
	const char *ap = "apple";
	const char *bp = "banana";

	cout << "바꾸기 전의 문자열 : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "바꾼 후의 문자열 : " << ap << " " << bp << endl;
}
void swap_ptr(const char *(&a),const char *(&b))
{
	const char *temp;
	temp = a;
	a = b;
	b = temp;
}