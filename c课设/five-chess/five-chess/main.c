#include "game.h"

ontrain = 0;
whoturn = 0;
weight[5][3] = {
	{0,0 ,0 },//这一行其实没用
	{30,15 ,0 },
	{60,40,0},
	{700,500,0},
	{10000,8000,0}
};
char* operation[5] = {
	"",
	"进入游戏",
	"复盘",
	"退出系统",
	"残局训练"
};

int main()
{
	system("color 60");
	printfwelcome();//只有在第一次打开的时候才会有
	printfhomepage();
	homepagechioce();
	return 0;
}

void printfwelcome() {
	printf("\n\t\t\t\t\t     五 子 兵 法\n\n\n\t\t\t\
		先手要攻  后手要守。\n\t\t\t\
		以攻为守  以守待攻。\n\t\t\t\
		攻守转换  慎思变化。 \n\t\t\t\
		先行争夺  地破天惊。 \n\t\t\t\
		守取外势  攻聚内力。 \n\t\t\t\
		八卦易守  成角易攻。 \n\t\t\t\
		阻断分隔  稳如泰山。 \n\t\t\t\
		不思争先  胜比登天。 \n\t\t\t\
		初盘争二  局终抢三。 \n\t\t\t\
		留三不冲  变化万千。 \n\t\t\t\
		多个先手  细算次先。 \n\t\t\t\
		五子要点  次序在前。 \n\t\t\t\
		斜线为阴  直线为阳。 \n\t\t\t\
		阴阳结合  防不胜防。 \n\t\t\t\
		连三连四  易见为明。 \n\t\t\t\
		跳三跳四  暗剑深藏。 \n\t\t\t\
		己落一子  敌增一兵。 \n\t\t\t\
		攻其要点  守其必争。 \n\t\t\t\
		势已形成  败即降临。 \n\t\t\t\
		五子精华  一子输赢。 \n");
	PlaySound(TEXT("five_star.wav"), NULL, SND_FILENAME | SND_ASYNC);
	system("pause");
	PlaySound(NULL, NULL, SND_FILENAME);
	system("cls");
}
void printfhomepage() {
	system("cls");
	printf("\n\n                               ----------------------五星说----------------------");
	printf("\n\n\n\n");
	printf("                                                  1. 进 入 游 戏\n\n");
	printf("                                                  2. 复 盘\n\n");
	printf("                                                  3. 退 出\n\n");
	printf("                                                  4. 训 练 模 式\n\n\n");
	printf("                                             ");
}
void printfgamepage() {
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t  请 选 择 游 戏 模 式\n\n\n\t\t\t\t\t\t1:pvp\n\n\t\t\t\t\t\t2:pve\n\n\t\t\t\t\t\t3.返回主页\n\n");
}
void homepagechioce() {
	int chioce;
	printf("您的选择为：");
	scanf("%d", &chioce);
	insert(chioce);
	switch (chioce) {
	case 1:
		printfgamepage();
		gamepagechioce();
		break;
	case 2:
		replay();
		break;
	case 3:
		system("cls");
			Savelogbook();
		exit(0);
		break;
	case 4:
		ontrain = 1;
		traingame();
	}
}
void gamepagechioce() {
	printf("\t\t\t\t\t您的选择为：");
	scanf("%d", &mode);
	system("cls");
	if (mode == pve) {
		to_com();
	}
	else if (mode == pvp) {
		to_per();
	}
	else if (mode == 3) {
		printfhomepage();
		homepagechioce();
	}
}
void printfendpage() {
	if (mode == pve) {
		if ((whoturn % 2 == 0 && humanfirst) || (whoturn % 2 == 1 && !humanfirst)) {
			printf("玩家获胜\n");
		}
		else {
			printf("电脑获胜\n");
		}
	}
	else if (mode == pvp) {
		printf("玩家%d获胜\n", 1 + whoturn % 2);
	}
	system("pause");
	system("cls");
	save();
	printf("\n\n\n                                            接下来，你想要的:\n\n");
	if (ontrain) {
		printf("                                            1:继续训练\n\n                                            2:返回主页面\n");
	}
	else {
		printf("                                            1:再来一局\n\n                                            2:返回主页面\n");
	}
}
void endchioce() {
	int chioce;
	scanf("%d", &chioce);
	system("cls");
	if (!ontrain) {
		switch (chioce) {
		case 1:
			printfgamepage();
			gamepagechioce();
			break;
		case 2:
			printfhomepage();
			homepagechioce();
			break;
		}
	}
	else {
		switch (chioce) {
		case 1://继续训练
			traingame();
			break;
		case 2:
			ontrain = 0;//训练模式结束
			printfhomepage();
			homepagechioce();
			break;
		}
	}
}

void printfendreplay() {
	system("pause");
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t  您接下来的选择:");
	printf("\n\n\n\n\n\t\t\t\t\t  1.再看一遍");
	printf("\n\n\n\n\n\t\t\t\t\t  2.返回主页\n");
}
void endreplaychioce() {
	int choice;
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		replay();
		break;
	case 2:
		//clear the record[][]
		printfhomepage();
		homepagechioce();
		break;
	}
}





