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
			if (user.userTurn > com.comTurn) { printf("��ǻ�� ��!\n"); }
			else if (user.userTurn == com.comTurn) { printf("���º� !\n"); }
			else { printf("����� ��!\n"); }
		case 3: 
		{
			exit = 0;
			break;
		}
		}
		printf("# �ƹ�Ű�� ������ �� �޴��� ���ư��ϴ�\n");
		getch();
	}
	printf("<BINGO>�� �����մϴ�");
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
		printf("1. �������� (���� ������) 2. �������� (��ǻ�Ϳ� ������) 3. ���� \n# �޴����� : ");
		res = scanf("%d", &menuNum);
		if (res != 1) { printf("�ٽ� �Է����ּ���. \n");}
		else { break; }
	}
	return menuNum;
}
int menu_input(User *user,Com *com,int inputCount)
{
	int nNum;
	printf("������ ��������� �����մϴ� \n");
	printf("# �������� ����,���� ũ�⸦ �Է����ּ��� (2<=n<=10) : ");
	while (scanf("%d", &nNum))
	{
		if (nNum <= 0) { printf("�߸� �Է��ϼ̽��ϴ�\n"); continue; }
		break;
	}
	if (inputCount == 1)
	{
		if (!makeBin_User(user, nNum)) { printf("<User> ���� ������ �����Ͽ����ϴ� \n"); }
	}
	else
	{
		if (!makeBin_User(user, nNum)) { printf("<User> ���� ������ �����Ͽ����ϴ� \n"); }
		if (!makeBin_Com(com, nNum)) { printf("<Com> ���� ������ �����Ͽ����ϴ� \n"); } // mode1 mode2 ������ �����Ϸ�
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
	setNum(bp->userNum, binNum, size); // �ϴ� ����,,,
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
	setNum(bp->comNum, binNumC, size); // �ϴ� ����,,,
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
