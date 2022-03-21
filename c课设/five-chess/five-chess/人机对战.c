#include "game.h"
int Max3(int a, int b, int c) {
	return Max2(Max2(a, b), c);
}
int Max2(int a, int b) {
	return a > b ? a : b;
}
void to_com() {
	if (!ontrain) {
		initgame();
	}
	printf("\n\n\n                                          请选择下棋顺序:\n\n                                          1:电脑先手\n\n                                          2:玩家先手\n");
	printf("\n\n                                            ");
	scanf("%d", &humanfirst);
	humanfirst--;
	system("cls");
	printfchessmap();
	int x, y;
	while (1) {
		if (0 == whoturn % 2)
		{
			if (humanfirst) {
				//printf("现在轮到玩家，请落子：");
				scanf("%d %d", &x, &y);
				while (0 != map[x][y] || x <= 0 || x >= 16 || y <= 0 || y >= 16)
				{
					printf("非法操作，请重新输入：");
					scanf("%d %d", &x, &y);
				}
			}
			else {
				Sleep(1000);
				if (whoturn == 0) {
					x = 1 + rand() % (N - 1);
					y = 1 + rand() % (N - 1);//第一步的话，随机下
				}
				else {
					ai(&x, &y);//否则，选取权值最大的地方
				}
			}
			map[x][y] = black;//黑棋先手
		}
		else if (1 == whoturn % 2)
		{
			//电脑
			if (humanfirst) {
				Sleep(1000);
				ai(&x, &y);//否则，选取权值最大的地方
			}
			else {
				//printf("现在轮到玩家，请落子：");
				scanf("%d %d", &x, &y);
				while (0 != map[x][y] || x <= 0 || x >= 16 || y <= 0 || y >= 16)
				{
					printf("非法操作，请重新输入：");
					scanf("%d %d", &x, &y);
				}
			}
			map[x][y] = white;//白棋后手
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
			if ((!humanfirst && whoturn % 2 == 0) || (humanfirst && whoturn % 2 == 1)) {
				Sleep(500);
			}
		}
	}
}
void ai(int* x, int* y) {
	int weight = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			int w1 = cal_weight(i, j, black);
			int w2 = cal_weight(i, j, white);
			if (Max3(w1, w2, 0) > weight) {
				*x = i;
				*y = j;
				weight = w1 > w2 ? w1 : w2;
			}
		}
	}
}
int cal_weight(int x, int y, int cur)
{
	//计算四条线路权值之和

	//计算在(x,y)点的权值
	if (map[x][y] == black || map[x][y] == white) {
		return 0;
	}
	//没有放子
	//1.计算水平方向上的权值
	int w = 0;//权值初始化
	int n = 1;
	int d = 0;
	//往右走
	for (int row = x + 1, col = y; row < N; row++) {
		if (map[row][col] == cur) {
			n += 1;
		}
		else {
			if (map[row][col] != 0) {
				d++;
			}
			break;
		}
	}
	//往左走
	for (int row = x - 1, col = y; row > 0; row--) {
		if (map[row][col] == cur) {
			n += 1;
		}
		else {
			if (map[row][col] != 0) {
				d++;
			}
			break;
		}
	}
	if (n == 5) return inf;
	w += weight[n][d];
	//2.计算垂直方向上的权值
	n = 1;
	d = 0;
	//往上走
	for (int row = x, col = y - 1; col > 0; col--) {
		if (map[row][col] == cur) {
			n += 1;
		}
		else {
			if (map[row][col] != 0) {
				d++;
			}
			break;
		}
	}
	//往下走
	for (int row = x, col = y + 1; col < N; col++) {
		if (map[row][col] == cur) {
			n += 1;
		}
		else {
			if (map[row][col] != 0) {
				d++;
			}
			break;
		}
	}
	if (n == 5) return inf;
	w += weight[n][d];
	//3.计算主对角线上的权值
	n = 1; d = 0;
	for (int row = x + 1, col = y - 1; col > 0 && row < N; col--, row++) {
		if (map[row][col] == cur) {
			n += 1;
		}
		else {
			if (map[row][col] != 0) {
				d++;
			}
			break;
		}
	}
	//往下走
	for (int row = x - 1, col = y + 1; row > 0 && col < N; col++, row--) {
		if (map[row][col] == cur) {
			n += 1;
		}
		else {
			if (map[row][col] != 0) {
				d++;
			}
			break;
		}
	}
	if (n == 5) return inf;
	w += weight[n][d];
	//4.计算副对角线上的权值
	n = 1; d = 0;
	for (int row = x + 1, col = y + 1; col < N && row < N; col++, row++) {
		if (map[row][col] == cur) {
			n += 1;
		}
		else {
			if (map[row][col] != 0) {
				d++;
			}
			break;
		}
	}
	//往下走
	for (int row = x - 1, col = y - 1; row > 0 && col > 0; col--, row--) {
		if (map[row][col] == cur) {
			n += 1;
		}
		else {
			if (map[row][col] != 0) {
				d++;
			}
			break;
		}
	}
	if (n == 5) return inf;
	w += weight[n][d];
	return w;
}