#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "HW4.h"
#pragma warning(disable: 4996)

int main()
{
	User user = { NULL, 0 };
	Com com = { NULL, 0 };
	int menuCount;
	int exit = 1;
	int nNum, size;
	srand((unsigned int)time(NULL));

	while (exit)
	{
		menuCount = menu();
		switch (menuCount)
		{
		case 1:
		{
			size = menu_input(&user, &com, menuCount);
			playUserBin(&user, size); break;
		}
		case 2: 
			size = menu_input(&user, &com, menuCount); 
			playUserBinTogather(&user, &com, size); break;
			if (user.userTurn > com.comTurn) { printf("컴퓨터 승!\n"); }
			else if (user.userTurn == com.comTurn) { printf("무승부 !\n"); }
			else { printf("사용자 승!\n"); }
		case 3: 
		{
			exit = 0;
			break;
		}
		}
		printf("# 아무키나 누르면 주 메뉴로 돌아갑니다\n");
		getch();
	}
	printf("<BINGO>를 종료합니다");
	if (com.comNum != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			free(user.userNum[i]);
			free(com.comNum[i]);
		}
		free(user.userNum);
		free(com.comNum);
		user.userNum = NULL;
		com.comNum = NULL;
		user.userTurn = 0;
		com.comTurn = 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			free(user.userNum[i]);
		}
		free(user.userNum);
		user.userNum = NULL;
		user.userTurn = 0;
	}
}
int menu()
{
	int menuNum;
	int res;

	while (1)
	{
		printf("1. 연습게임 (개인 연습용) 2. 대전게임 (컴퓨터와 대전용) 3. 종료 \n# 메뉴선택 : ");
		res = scanf("%d", &menuNum);
		if (res != 1) { printf("다시 입력해주세요. \n");}
		else { break; }
	}
	return menuNum;
}
int menu_input(User *user,Com *com,int inputCount)
{
	int nNum;
	printf("연습용 빙고게임을 시작합니다 \n");
	printf("# 빙고판의 가로,세로 크기를 입력해주세요 (2<=n<=10) : ");
	while (scanf("%d", &nNum))
	{
		if (nNum <= 0) { printf("잘못 입력하셨습니다\n"); continue; }
		break;
	}
	if (inputCount == 1)
	{
		if (!makeBin_User(user, nNum)) { printf("<User> 빙고 생성에 실패하였습니다 \n"); }
	}
	else
	{
		if (!makeBin_User(user, nNum)) { printf("<User> 빙고 생성에 실패하였습니다 \n"); }
		if (!makeBin_Com(com, nNum)) { printf("<Com> 빙고 생성에 실패하였습니다 \n"); } // mode1 mode2 빙고판 생성완료
	}
	return nNum;
}
int makeBin_User(User * bp, int size)
{
	int * binNum = NULL;
	if (bp == NULL) { return FALSE; }
	bp->userNum = allocBin(bp->userNum, size);
	if (bp->userNum == NULL) { return FALSE; }
	binNum = swap(binNum, size);
	setNum(bp->userNum, binNum, size); // 일단 생성,,,
	if (bp->userNum == NULL) { return FALSE; }
	free(binNum);
	return TRUE;
}
int makeBin_Com(Com * bp, int size)
{
	int * binNumC = NULL;
	if (bp == NULL) { return FALSE; }
	bp->comNum = allocBin(bp->comNum, size);
	if (bp->comNum == NULL) { return FALSE; }
	binNumC = swap2(binNumC, size);
	setNum(bp->comNum, binNumC, size); // 일단 생성,,,
	if (bp->comNum == NULL) { return FALSE; }
	free(binNumC);
	return TRUE;
}
int ** allocBin(int **binStart, int size)
{
	binStart = (int **)calloc(size, sizeof(int *));
	for (int i = 0; i < size; i++)
	{
		binStart[i] = (int *)calloc(size, sizeof(int));
	}
	return binStart;
}
int * swap(int * bin, int size)
{
	int res;
	int temp;
	int n = size * size;
	bin = (int *)calloc(size*size, sizeof(int));
	for (int i = 0; i < size * size; i++) { bin[i] = i+1; }
	for (int i = 0; i < size * size; i++) 
	{ 
		res = rand()%n; 
		temp = bin[i];
		bin[i] = bin[res];
		bin[res] = temp;
	}
	return bin;
}
int * swap2(int * bin, int size)
{
	int res;
	int temp;
	int n = size * size ;
	bin = (int *)calloc(size*size, sizeof(int));
	for (int i = 0; i < size * size; i++) { bin[i] = size*size-i; }
	for (int i = 0; i <size*size ; i++)
	{
		res = rand()%n;
		temp = bin[i];
		bin[i] = bin[res];
		bin[res] = temp;
	}
	return bin;
}
void setNum(int ** bp,int * binNum, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			bp[i][j] = binNum[count];
			count++;
		}
	}
}
