#include <iostream>
#include <cstring>
#include <iomanip>
#pragma warning(disable : 4996)
using namespace std;

class Save
{
private: char name[20];
		 int capital;
		 int profit;
		 int tax;
		 int tot;
		 static double ratio;
public:
	static double tax_ratio;
	Save(const char *np = "�ƹ���", int n = 0);
	void calculate();
	static void set_ratio(double r);
	char * getName();
	int getCapital();
	int getProfit();
	int getTax();
	int getTot();
	double getRatio();
};

double Save::ratio = 0.2;
double Save::tax_ratio = 0.1;

Save::Save(const char *np, int n)
{
	if (np == NULL) { return; }
	strcpy(name, np);
	capital = n;
}
void Save::calculate()
{
	profit = (double)capital * ratio;
	tax = (double)profit * tax_ratio;
	tot = (double)capital + profit - tax;
}
void Save::set_ratio(double r)
{
	if (r < 0) { return; }
	ratio = r;
}
char * Save::getName()
{
	return name;
}
int Save::getCapital()
{
	return capital;
}
int Save::getProfit()
{
	return profit;
}
int Save::getTax()
{
	return tax;
}
int Save::getTot()
{
	return tot;
}
double Save::getRatio()
{
	return ratio;
}

int main()
{
	Save a("ö��", 1000000), b("����", 2000000);

	cout << "�̸� : " << a.getName() << endl << "���� : " << a.getCapital() << endl;
	a.calculate();
	cout << "���ڼҵ� : " << a.getProfit() << endl << "���� : " << a.getTax() << endl << "�ѱݾ� : " << a.getTot() << endl << "���� : " << a.getRatio() << endl <<"���� : " << a.tax_ratio << endl;
	Save::tax_ratio = 0.15;
	Save::set_ratio(0.25);
	cout << "�̸� : " << b.getName() << endl << "���� : " << b.getCapital() << endl;
	b.calculate();
	cout << "���ڼҵ� : " << b.getProfit() << endl << "���� : " << b.getTax() << endl << "�ѱݾ� : " << b.getTot() << endl << "���� : " << b.getRatio() << endl << "���� : " << b.tax_ratio << endl;
}