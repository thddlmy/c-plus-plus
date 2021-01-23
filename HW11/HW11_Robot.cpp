#include <iostream>
#pragma warning(disable :4996)
#include "HW11_Robot.h"

using namespace std;

void Robot::errPrn()
{
	cout << "에너지가 부족합니다" << endl;
}

Robot::Robot()
{
	this->name = new char[strlen("") + 1];
	strcpy(this->name, "");
	this->energy = 0;
}
Robot::~Robot()
{
	delete[] this->name;
}
Robot::Robot(const char *name, int energy)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}
Robot::Robot(Robot &r)
{
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->energy = r.energy;
}
void Robot::go()
{
	if (this->energy < 10) { this->errPrn(); return; }
	cout << this->name << " 전진!" << endl;
	this->energy -= 10;
}
void Robot::back()
{
	if (this->energy < 20) { this->errPrn(); return; }
	cout << this->name << " 후진!" << endl;
	this->energy -= 20;
}
void Robot::turn()
{
	if (this->energy < 30) { this->errPrn(); return; }
	cout << this->name << " 회전!" << endl;
	this->energy -= 30;
}
void Robot::jump()
{
	if (this->energy < 40) { this->errPrn(); return; }
	cout << this->name << " 점프!" << endl;
	this->energy -= 40;
}
void Robot::charge(int e)
{
	if (e < 0) { return; }
	cout << this->name << " " << e << " 충전!" << endl;
	this->energy += e;
}
char * Robot::getName()
{
	return this->name;
}
void Robot::setName(const char *n)
{
	if (this->name != NULL) { delete[] this->name; }
	if (n == NULL) { return; }
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}
int Robot::getEnergy()
{
	return this->energy;
}
void Robot::setEnergy(int e)
{
	if (e < 0) { return ; }
	this->energy = e;
}