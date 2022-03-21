#include "game.h"
void initgame()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
	whoturn = 0;
}
void printfchessmap()
{
	printf("\n\n\n\n");
	int i = 0;
	int j = 0;
	printf("\t\t\t");
	for (i = 1; i < N; i++)
	{
		if (i < 10) {
			printf("  %d  ", i); //��ӡ���� x ��������ʾ
		}
		else {
			printf(" %d  ", i);
		}
	}
	printf("\n\t\t\t");
	for (j = 1; j < N; j++)
	{
		printf("----|"); //��ӡ��һ������
	}
	printf("\n\t\t\t");
	for (i = 1; i < N; i++)
	{
		for (j = 1; j < N; j++)
		{
			if (map[i][j] == 0)
				printf("    |"); //��ӡ����
			if (map[i][j] == black)
				printf(" �� |");
			if (map[i][j] == white)
				printf(" �� |");

		}
		printf(" %d ", i); //��ӡ���� y ��������ʾ
		printf("\n\t\t\t");
		for (j = 1; j < N; j++)
		{
			printf("----|"); //��ӡ���
		}
		printf("\n\t\t\t");
	}
}