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

	int count = 0; // 10개 드갓는지 개수 표시
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
			printf("프로그램을 종료합니다.");
			exit = 0;
			break;
		}
		}
	}
}
int menu()
{
	int choice;
	printf("<DICIONARY MENU> 1. 입력하기 2. 출력하기 3. 검색하기 4. 삭제하기 (종료 : end) : ");
	if (scanf("%d", &choice) == 0) { return 5; }
	else { return choice; }
}
int inputDic(int count)
{
	char wordTemp[20];
	char meanTemp[80];

	while (count != 10)
	{
		printf("단어를 입력하세요 : ");
		scanf("%s", wordTemp);
		if (strcmp(wordTemp, "end") == 0) { return count; }
		strcpy((arr[count].word), wordTemp);

		arr[count].len = strlen(wordTemp);
		myflush();
		printf("뜻을 입력하세요 : ");
		fgets(meanTemp, sizeof(meanTemp), stdin);
		if (meanTemp[strlen(meanTemp)-1] == '\n') { meanTemp[strlen(meanTemp)-1] = '\0'; }
		strcpy((arr[count].mean), meanTemp);
		count++;

		strcpy(wordTemp, "");
		strcpy(meanTemp, "");
	}
	printf("최대 단어를 모두 입력하셨습니다\n");
	return count;
}
void outputDic(int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%2d.          %s(%2d) : %s\n", i + 1, arr[i].word, arr[i].len, arr[i].mean);
	}
	printf("총 단어의 개수 : %d", count);
	return;
}
void searchDic(int count)
{
	char temp[20];
	int res;
	while (1)
	{
		printf("검색할 단어를 입력하세요 : ");
		scanf("%s", temp);
		if (strcmp(temp, "end") == 0) { break;; }
		res = searchString(temp, count);
		if (res == -1) { printf("찾는 단어가 없습니다\n"); }
		else { printf("단어의 뜻 : %s\n", arr[res].mean); }
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
		printf("삭제할 단어를 입력하세요 :");
		scanf("%s", temp);
		if (strcmp(temp, "end") == 0) { return count; }
		res = searchString(temp, count);
		if (res == -1) { printf("찾으시는 단어가 없습니다\n"); continue; }
		printf("삭제하시겠습니까? (Y/N) : ");
		scanf(" %c", &ch);
		if (ch == 'N') { printf("삭제를 취소합니다\n");  continue; }
		else { printf("삭제를 성공하였습니다\n"); }
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
