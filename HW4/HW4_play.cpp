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
		printf("# ���� ���� �Է� (1~%d) : ", size*size);
		res = scanf("%d", &num);
		if (res != 1) { break; }
		if (findBin(user, size, num) == FALSE) 
		{ 
			printf("�̹������� ���� �Դϴ�\n");
			printUserBin(user, size);
			continue; 
		}
		res = BingoCheck(user, size);
		if (res > 0)
		{
			printf("# %d�� ����ϼ�\n", res);
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
		printf("# ���� ���ڸ� �Է��ϼ��� : ");
		res = scanf("%d", &num);
		if (res != 1) { break; }
		if (findBinTogather(user,  com, size, num) == FALSE)
		{
			printf("�̹������� ���� �Դϴ�\n");
			printUserComBin(user, com, size);
			continue;
		}
		comNum = rand() % (size*size - 2) + 1;
		while (!findBinTogather(user, com, size, comNum))
		{
			comNum = rand() % (size*size - 2) + 1;
		}
		printf("��ǻ�Ͱ� ������ ���ڴ� (%d) �Դϴ�\n", comNum);
		binU = BingoCheck(user, size);
		user->userTurn++;
		binC = BingoCheckCom(com, size);
		com->comTurn++;
		if (binC > 0 || binU > 0)
		{
			printf("# ����� : %d�� ��ǻ�� : %d�� ����ϼ�\n", binU, binC);
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
			size_bin1 += user->userNum[i][j]; //���κ���
			size_bin2 += user->userNum[j][i]; //���� ����
		}
		if (size_bin1 == -1*size) { bin++; }
		if (size_bin2 == -1*size) { bin++; }
		size_bin1 = 0;
		size_bin2 = 0;
		size_bin3 += user->userNum[i][i]; // �밢��
		size_bin4 += user->userNum[i][size-1-i]; // �밢���ݴ�
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
			size_bin1 += com->comNum[i][j]; //���κ���
			size_bin2 += com->comNum[j][i]; //���� ����
		}
		if (size_bin1 == -1*size) { bin++; }
		if (size_bin2 == -1 * size) { bin++; }
		size_bin1 = 0;
		size_bin2 = 0;
		size_bin3 += com->comNum[i][i]; // �밢��
		size_bin4 += com->comNum[i][size-1 - i]; // �밢���ݴ�
	}
	if (size_bin3 == -1 * size) { bin++; }
	if (size_bin4 == -1 * size) { bin++; }

	return bin;
}
