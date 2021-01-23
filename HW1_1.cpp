#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct dic
{
	char word[20];
	char mean[80];
	int len;
}Dic;

Dic arr[10];

int menu();
int inputDic(int count);
void outputDic(int count);
void searchDic(int count);
int searchString(char * temp, int count);
int removeDic(int count);
void myflush();

int main()
{
	Dic arr[10];

	int count = 0; // 10�� �尫���� ���� ǥ��
	int exit = 1;

	while (exit)
	{
		switch (menu())
		{
		case 1: {count = inputDic(count); break;}
		case 2: {outputDic(count); break;}
		case 3: {searchDic(count); break; }
		case 4: {count = removeDic(count); break; }
		case 5:
		{
			printf("���α׷��� �����մϴ�.");
			exit = 0;
			break;
		}
		}
	}
}
int menu()
{
	int choice;
	printf("<DICIONARY MENU> 1. �Է��ϱ� 2. ����ϱ� 3. �˻��ϱ� 4. �����ϱ� (���� : end) : ");
	if (scanf("%d", &choice) == 0) { return 5; }
	else { return choice; }
}
int inputDic(int count)
{
	char wordTemp[20];
	char meanTemp[80];

	while (count != 10)
	{
		printf("�ܾ �Է��ϼ��� : ");
		scanf("%s", wordTemp);
		if (strcmp(wordTemp, "end") == 0) { return count; }
		strcpy((arr[count].word), wordTemp);

		arr[count].len = strlen(wordTemp);
		myflush();
		printf("���� �Է��ϼ��� : ");
		fgets(meanTemp, sizeof(meanTemp), stdin);
		if (meanTemp[strlen(meanTemp)-1] == '\n') { meanTemp[strlen(meanTemp)-1] = '\0'; }
		strcpy((arr[count].mean), meanTemp);
		count++;

		strcpy(wordTemp, "");
		strcpy(meanTemp, "");
	}
	printf("�ִ� �ܾ ��� �Է��ϼ̽��ϴ�\n");
	return count;
}
void outputDic(int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%2d.          %s(%2d) : %s\n", i + 1, arr[i].word, arr[i].len, arr[i].mean);
	}
	printf("�� �ܾ��� ���� : %d", count);
	return;
}
void searchDic(int count)
{
	char temp[20];
	int res;
	while (1)
	{
		printf("�˻��� �ܾ �Է��ϼ��� : ");
		scanf("%s", temp);
		if (strcmp(temp, "end") == 0) { break;; }
		res = searchString(temp, count);
		if (res == -1) { printf("ã�� �ܾ �����ϴ�\n"); }
		else { printf("�ܾ��� �� : %s\n", arr[res].mean); }
		strcpy(temp, "");
	}
}
int searchString(char * temp,int count)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp((arr[i].word), temp) == 0){return i;}
	}
	return -1;
}
int removeDic(int count)
{
	char temp[20];
	char ch;
	int res;
	while (1)
	{
		printf("������ �ܾ �Է��ϼ��� :");
		scanf("%s", temp);
		if (strcmp(temp, "end") == 0) { return count; }
		res = searchString(temp, count);
		if (res == -1) { printf("ã���ô� �ܾ �����ϴ�\n"); continue; }
		printf("�����Ͻðڽ��ϱ�? (Y/N) : ");
		scanf(" %c", &ch);
		if (ch == 'N') { printf("������ ����մϴ�\n");  continue; }
		else { printf("������ �����Ͽ����ϴ�\n"); }
		strcpy((arr[res].word), (arr[count - 1].word));
		strcpy((arr[res].mean), (arr[count - 1].mean));
		arr[res].len = arr[count - 1].len;
		count--;
		strcpy(temp, "");
	}
}
void myflush()
{
	while (getchar() != '\n')
		;
}
