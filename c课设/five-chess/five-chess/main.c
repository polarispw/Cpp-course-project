#include "game.h"

ontrain = 0;
whoturn = 0;
weight[5][3] = {
	{0,0 ,0 },//��һ����ʵû��
	{30,15 ,0 },
	{60,40,0},
	{700,500,0},
	{10000,8000,0}
};
char* operation[5] = {
	"",
	"������Ϸ",
	"����",
	"�˳�ϵͳ",
	"�о�ѵ��"
};

int main()
{
	system("color 60");
	printfwelcome();//ֻ���ڵ�һ�δ򿪵�ʱ��Ż���
	printfhomepage();
	homepagechioce();
	return 0;
}

void printfwelcome() {
	printf("\n\t\t\t\t\t     �� �� �� ��\n\n\n\t\t\t\
		����Ҫ��  ����Ҫ�ء�\n\t\t\t\
		�Թ�Ϊ��  ���ش�����\n\t\t\t\
		����ת��  ��˼�仯�� \n\t\t\t\
		��������  �����쾪�� \n\t\t\t\
		��ȡ����  ���������� \n\t\t\t\
		��������  �ɽ��׹��� \n\t\t\t\
		��Ϸָ�  ����̩ɽ�� \n\t\t\t\
		��˼����  ʤ�ȵ��졣 \n\t\t\t\
		��������  ���������� \n\t\t\t\
		��������  �仯��ǧ�� \n\t\t\t\
		�������  ϸ����ȡ� \n\t\t\t\
		����Ҫ��  ������ǰ�� \n\t\t\t\
		б��Ϊ��  ֱ��Ϊ���� \n\t\t\t\
		�������  ����ʤ���� \n\t\t\t\
		��������  �׼�Ϊ���� \n\t\t\t\
		��������  ������ء� \n\t\t\t\
		����һ��  ����һ���� \n\t\t\t\
		����Ҫ��  ��������� \n\t\t\t\
		�����γ�  �ܼ����١� \n\t\t\t\
		���Ӿ���  һ����Ӯ�� \n");
	PlaySound(TEXT("five_star.wav"), NULL, SND_FILENAME | SND_ASYNC);
	system("pause");
	PlaySound(NULL, NULL, SND_FILENAME);
	system("cls");
}
void printfhomepage() {
	system("cls");
	printf("\n\n                               ----------------------����˵----------------------");
	printf("\n\n\n\n");
	printf("                                                  1. �� �� �� Ϸ\n\n");
	printf("                                                  2. �� ��\n\n");
	printf("                                                  3. �� ��\n\n");
	printf("                                                  4. ѵ �� ģ ʽ\n\n\n");
	printf("                                             ");
}
void printfgamepage() {
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t  �� ѡ �� �� Ϸ ģ ʽ\n\n\n\t\t\t\t\t\t1:pvp\n\n\t\t\t\t\t\t2:pve\n\n\t\t\t\t\t\t3.������ҳ\n\n");
}
void homepagechioce() {
	int chioce;
	printf("����ѡ��Ϊ��");
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
	printf("\t\t\t\t\t����ѡ��Ϊ��");
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
			printf("��һ�ʤ\n");
		}
		else {
			printf("���Ի�ʤ\n");
		}
	}
	else if (mode == pvp) {
		printf("���%d��ʤ\n", 1 + whoturn % 2);
	}
	system("pause");
	system("cls");
	save();
	printf("\n\n\n                                            ������������Ҫ��:\n\n");
	if (ontrain) {
		printf("                                            1:����ѵ��\n\n                                            2:������ҳ��\n");
	}
	else {
		printf("                                            1:����һ��\n\n                                            2:������ҳ��\n");
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
		case 1://����ѵ��
			traingame();
			break;
		case 2:
			ontrain = 0;//ѵ��ģʽ����
			printfhomepage();
			homepagechioce();
			break;
		}
	}
}

void printfendreplay() {
	system("pause");
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t  ����������ѡ��:");
	printf("\n\n\n\n\n\t\t\t\t\t  1.�ٿ�һ��");
	printf("\n\n\n\n\n\t\t\t\t\t  2.������ҳ\n");
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





