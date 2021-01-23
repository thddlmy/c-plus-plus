#pragma once
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

#define FALSE (0)
#define TRUE (1)

class Robot
{
private :
	char * name;
	int energy;
	void errPrn();
public :
	Robot();
	~Robot();
	Robot(const char *name, int energy = 0);
	Robot(Robot &r);
	void go();
	void back();
	void turn();
	void jump();
	void charge(int e);
	char * getName();
	void setName(const char *);
	int getEnergy();
	void setEnergy(int);
};
int inputCnt();
int inputInfo(Robot *rp, int cnt);
void work(Robot *rp, int cnt);
int findIndex(Robot *rp, int cnt, char * n);
void myfiush();
void output(Robot *rp, int cnt);