#include "game.h"
void to_per()
{
	if (!ontrain) {
		initgame();
	}
	printfchessmap();
	printf("���������\n");
	while (1) {
		int x, y;
		if (0 == whoturn % 2)
		{
			//printf("�����ֵ����1�������ӣ�");
			scanf("%d %d", &x, &y);
			while (0 != map[x][y] || x >= 16 || x <= 0 || y >= 16 || y <= 0)
			{
				printf("�Ƿ����������������룺");
				scanf("%d %d", &x, &y);
			}
			map[x][y] = black;//�����Ǻ���
		}
		else if (1 == whoturn % 2)
		{
			//printf("�����ֵ����2�������ӣ�");
			scanf("%d %d", &x, &y);
			while (0 != map[x][y] || x >= 16 || x <= 0 || y >= 16 || y <= 0)
			{
				printf("�Ƿ����������������룺");
				scanf("%d %d", &x, &y);
			}
			map[x][y] = white;//�����ǰ���
		}
		record[whoturn][0] = x;
		record[whoturn][1] = y;
		system("cls");
		printfchessmap();
		PlaySound(TEXT("place.wav"), NULL, SND_FILENAME | SND_SYNC);
		PlaySound(NULL, NULL, SND_FILENAME);
		if (judge(x, y)) {
			printfendpage();
			endchioce();
		}
		else {
			whoturn++;
			if (whoturn % 2 == 1) {
				printf("���������\n");
			}
			else {
				printf("���������\n");
			}
		}
	}
}
int judge(int x, int y)
{
	int wx = 0;
	int i, j;
	int count;
	int winflag = 1;    //��һ���㲻���ٴζ�ȡ
	int cur;   //��¼��ǰ���µ���
	cur = map[x][y] == black ? black : white;
	count = 0;
	for (i = x, j = y - 1; j > 0 && count++ < 5; j--)
	{
		if (map[i][j] == cur)
		{
			winflag++;
		}
		else
			break;
	}
	count = 0;
	for (i = x, j = y + 1; j < N && count++ < 5; j++)
	{
		if (map[i][j] == cur)
		{
			winflag++;
		}
		else
			break;
	}
	if (winflag == 4) wx++;
	if (winflag >= 5)
		return OK;
	else
		winflag = 1;
	//��ֱ�����ж�
	count = 0;
	for (i = x - 1, j = y; i > 0 && count++ < 5; i--)
	{
		if (map[i][j] == cur)
		{
			winflag++;
		}
		else
			break;
	}
	count = 0;
	for (i = x + 1, j = y; i < N && count++ < 5; i++)
	{
		if (map[i][j] == cur)
		{
			winflag++;
		}
		else
			break;
	}
	if (winflag == 4) wx++;
	if (winflag >= 5)
		return OK;
	else
		winflag = 1;
	//���Խ����ж�
	count = 0;
	for (i = x - 1, j = y - 1; i > 0 && j > 0 && count++ < 5; j--, i--)
	{
		if (map[i][j] == cur)
		{
			winflag++;
		}
		else
			break;
	}
	count = 0;
	for (i = x + 1, j = y + 1; i < N && j < N && count++ < 5; j++, i++)
	{
		if (map[i][j] == cur)
		{
			winflag++;
		}
		else
			break;
	}
	if (winflag == 4) wx++;
	if (winflag >= 5)
		return OK;
	else
		winflag = 1;
	//б�Խ����ж�
	count = 0;
	for (i = x + 1, j = y - 1; x < N && j > 0 && count++ < 5; j--, i++)
	{
		if (map[i][j] == cur)
		{
			winflag++;
		}
		else
			break;
	}
	count = 0;
	for (i = x - 1, j = y + 1; i > 0 && j < N && count++ < 5; j++, i--)
	{
		if (map[i][j] == cur)
		{
			winflag++;
		}
		else
			break;
	}
	if (winflag == 4) wx++;
	if (winflag >= 5)
		return OK;
	else
		winflag = 1;
	if (wx > 0) {
		PlaySound(TEXT("��������.wav"), NULL, SND_FILENAME | SND_SYNC);
		PlaySound(NULL, NULL, SND_FILENAME);
	}
	return NO;
}