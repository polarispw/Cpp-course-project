#include "game.h"
void to_per()
{
	if (!ontrain) {
		initgame();
	}
	printfchessmap();
	printf("请黑棋落子\n");
	while (1) {
		int x, y;
		if (0 == whoturn % 2)
		{
			//printf("现在轮到玩家1，请落子：");
			scanf("%d %d", &x, &y);
			while (0 != map[x][y] || x >= 16 || x <= 0 || y >= 16 || y <= 0)
			{
				printf("非法操作，请重新输入：");
				scanf("%d %d", &x, &y);
			}
			map[x][y] = black;//先手是黑棋
		}
		else if (1 == whoturn % 2)
		{
			//printf("现在轮到玩家2，请落子：");
			scanf("%d %d", &x, &y);
			while (0 != map[x][y] || x >= 16 || x <= 0 || y >= 16 || y <= 0)
			{
				printf("非法操作，请重新输入：");
				scanf("%d %d", &x, &y);
			}
			map[x][y] = white;//后手是白棋
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
				printf("请白棋落子\n");
			}
			else {
				printf("请黑棋落子\n");
			}
		}
	}
}
int judge(int x, int y)
{
	int wx = 0;
	int i, j;
	int count;
	int winflag = 1;    //第一个点不用再次读取
	int cur;   //记录当前所下的棋
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
	//垂直方向判断
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
	//主对角线判断
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
	//斜对角线判断
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
		PlaySound(TEXT("四子连珠.wav"), NULL, SND_FILENAME | SND_SYNC);
		PlaySound(NULL, NULL, SND_FILENAME);
	}
	return NO;
}