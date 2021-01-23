#include "HW4.h"

//
void printUserBin(User *user, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("| ");
		for (int j = 0; j < size; j++)
		{
			if (user->userNum[i][j] == -1) { printf("  X "); }
			else { printf("%3d ", user->userNum[i][j]); }
		}
		printf("|\n");
	}
}
void printUserComBin(User *user,Com *com, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("|");
		for (int j = 0; j < size; j++)
		{
			if (user->userNum[i][j] == -1) { printf("  X "); }
			else { printf("%3d ", user->userNum[i][j]); }
		}
		printf("|       |");
		for (int j = 0; j < size; j++)
		{
			if (com->comNum[i][j] == -1) { printf("  X "); }
			else { printf("  ? "); }
		}
		printf("|\n");
	}
}

void playUserBin(User *user, int size)
{
	int num;
	int res;
	printUserBin(user, size);
	while (1)
	{
		printf("# 지울 숫자 입력 (1~%d) : ", size*size);
		res = scanf("%d", &num);
		if (res != 1) { break; }
		if (findBin(user, size, num) == FALSE) 
		{ 
			printf("이미지워진 숫자 입니다\n");
			printUserBin(user, size);
			continue; 
		}
		res = BingoCheck(user, size);
		if (res > 0)
		{
			printf("# %d줄 빙고완성\n", res);
		}
		if (res >= 3) { break; }
		printUserBin(user, size);
	}
	printUserBin(user, size);
}
void playUserBinTogather(User *user,Com *com, int size)
{
	int num, comNum;
	int res;
	int binU, binC;
	printUserComBin(user, com, size);
	while (1)
	{
		printf("# 지울 숫자를 입력하세요 : ");
		res = scanf("%d", &num);
		if (res != 1) { break; }
		if (findBinTogather(user,  com, size, num) == FALSE)
		{
			printf("이미지워진 숫자 입니다\n");
			printUserComBin(user, com, size);
			continue;
		}
		comNum = rand() % (size*size - 2) + 1;
		while (!findBinTogather(user, com, size, comNum))
		{
			comNum = rand() % (size*size - 2) + 1;
		}
		printf("컴퓨터가 선택한 숫자는 (%d) 입니다\n", comNum);
		binU = BingoCheck(user, size);
		user->userTurn++;
		binC = BingoCheckCom(com, size);
		com->comTurn++;
		if (binC > 0 || binU > 0)
		{
			printf("# 사용자 : %d줄 컴퓨터 : %d줄 빙고완성\n", binU, binC);
		}
		if (binU >= 3 || binC >= 3) { printUserComBin(user, com, size); break; }
		printUserComBin(user, com, size);
	}
}
int findBin(User *user,int size,int num)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (num == user->userNum[i][j])
			{
				user->userNum[i][j] = -1;
				return TRUE;
			}
		}
	}
	return FALSE;
}
int findBinTogather(User *user,Com *com, int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (num == user->userNum[i][j])
			{
				if (user->userNum[i][j] == -1) { return FALSE; }
				user->userNum[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (num == com->comNum[i][j])
			{
				com->comNum[i][j] = -1;
				return TRUE;
			}
		}
	}

	return FALSE;
}
int BingoCheck(User *user, int size)
{
	int bin = 0;
	int size_bin1 = 0;
	int size_bin2 = 0;
	int size_bin3 = 0;
	int size_bin4 = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			size_bin1 += user->userNum[i][j]; //가로빙고
			size_bin2 += user->userNum[j][i]; //세로 빙고
		}
		if (size_bin1 == -1*size) { bin++; }
		if (size_bin2 == -1*size) { bin++; }
		size_bin1 = 0;
		size_bin2 = 0;
		size_bin3 += user->userNum[i][i]; // 대각선
		size_bin4 += user->userNum[i][size-1-i]; // 대각선반대
	}
	if (size_bin3 == -1*size) { bin++; }
	if (size_bin4 == -1*size) { bin++; }

	return bin;
}
int BingoCheckCom(Com *com, int size)
{
	int bin = 0;
	int size_bin1 = 0;
	int size_bin2 = 0;
	int size_bin3 = 0;
	int size_bin4 = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			size_bin1 += com->comNum[i][j]; //가로빙고
			size_bin2 += com->comNum[j][i]; //세로 빙고
		}
		if (size_bin1 == -1*size) { bin++; }
		if (size_bin2 == -1 * size) { bin++; }
		size_bin1 = 0;
		size_bin2 = 0;
		size_bin3 += com->comNum[i][i]; // 대각선
		size_bin4 += com->comNum[i][size-1 - i]; // 대각선반대
	}
	if (size_bin3 == -1 * size) { bin++; }
	if (size_bin4 == -1 * size) { bin++; }

	return bin;
}
