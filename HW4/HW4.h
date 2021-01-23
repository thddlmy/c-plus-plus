#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)

#define FALSE 0
#define TRUE 1

typedef struct user {

	int **userNum;
	int userTurn;

}User;

typedef struct com {

	int **comNum;
	int comTurn;
}Com;

int menu();
int menu_input(User *user, Com *com, int inputCount);
int makeBin_User(User * bp, int size);
int ** allocBin(int **binStart, int size);
int * swap(int * bin, int size);
int * swap2(int * bin, int size);
void setNum(int ** bp, int * binNum, int size);
int makeBin_Com(Com * bp, int size);
void printUserBin(User *user, int size);
void printComBin(Com *com, int size);
void playUserBin(User *user, int size);
int findBin(User *user, int size, int num);
int BingoCheck(User *user, int size);
void printUserComBin(User *user, Com *com, int size);
void playUserBinTogather(User *user, Com *com, int size);
int findBinTogather(User *user, Com *com, int size, int num);
int BingoCheckCom(Com *com, int size);
