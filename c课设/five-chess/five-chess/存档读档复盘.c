#include "game.h"
void replay() {
	//ask him/her which contest he/she wants to replay
	//load the information into a 2-d array called record
	load();
	initgame();
	int t = 0;
	int x, y;
	while (1) {
		x = record[t][0];
		y = record[t][1];
		if (t % 2 == 0) {
			map[x][y] = black;
		}
		else {
			map[x][y] = white;
		}
		system("cls");
		printfchessmap();
		PlaySound(TEXT("place.wav"), NULL, SND_FILENAME | SND_SYNC);
		PlaySound(NULL, NULL, SND_FILENAME);
		t++;
		if (judge(x, y)) {
			printfendreplay();
			endreplaychioce();
		}
		else {
			if (t % 2 == 1) {
				printf("���������\n");
			}
			else {
				printf("���������\n");
			}
			Sleep(2000);
		}
	}
}
void load()
{
	int i = 0;
	FILE* fp;
	system("cls");
	printdoclist();
	char name[100];
	getchar();
	do
	{
		printf("\t\t\t����ع��Ĵ�����:");
		char filename[1000] = "E:\\C����\\��¼\\";
		gets(name);
		strcat(name, suffix);
		strcat(filename, name);
		fp = fopen(filename, "r");
	} while (!fp);
	fscanf(fp, "%d", &whoturn);
	//printf("%d", whoturn);
	for (i = 0; i <= whoturn; i++)
		fscanf(fp, "%d,%d", &record[i][0], &record[i][1]);
	fclose(fp);
}
void save()
{
	if (!ontrain) {
		char filename[1000] = "E:\\C����\\��¼\\";
		system("cls");
		printf("\n\n\n\n\t\t\t\t\t  �Ƿ�Ҫ����?\n\n\t\t\t\t\t  1:����\n\n\t\t\t\t\t  2:������\n");
		int a;
		scanf("%d", &a);
		char name[100];
		if (a == 1) {
			printf("\n\t\t\t\t\t  �����ļ�����");
			getchar();
			gets(name);
			strcat(name, suffix);
			strcat(filename, name);
			int i = 0;
			FILE* fp;
			/*���ı��ļ���д������*/
			fp = fopen(filename, "w");
			if (!fp)
			{
				perror("cannot open file");
			}
			/*���Ծּ�¼д���ļ�*/
			fprintf(fp, "%d\n", whoturn);
			for (i = 0; i <= whoturn; i++)
			{
				fprintf(fp, "%d,%d", record[i][0], record[i][1]);
				fputc('\n', fp);
			}
			fclose(fp);
		}
		system("cls");
	}
}
void loadchessmap()
{
	ontrain = 1;
	system("cls");
	char name[100];
	FILE* fp;
	printfilelist();
	getchar();
	//gets(name);
	//strcat(name, suffix);
	//strcat(filename, name);
	//fp = fopen(filename, "r");
	do
	{
		char filename[1000] = "E:\\C����\\�о�\\";
		printf("\t\t\t������о�����:\t");
		gets(name);
		strcat(name, suffix);
		strcat(filename, name);
		fp = fopen(filename, "r");
	} while (!fp);
	int x = 0, y = 0;
	whoturn = 0;
	for (x = 1; x < N; x++)
		for (y = 1; y < N; y++)
		{
			fscanf(fp, "%d", &map[x][y]);
			if (map[x][y] != 0) { whoturn++; }//Ҫ��ʼ��
		}
	fclose(fp);
}
void traingame()
{
	loadchessmap();
	system("cls");
	printfchessmap();
	printf("��ѡ����Ϸģʽ��1����Ҷ�ս 2���˻���ս");
	scanf("%d", &mode);
	if (mode == pve)
	{
		system("cls");
		to_com();
	}
	if (mode == pvp)
	{
		system("cls");
		to_per();
	}
}
void get_file_list(const char* path, char** filename) {
	char cmd[150] = ""; FILE* fptr;
	strcat(cmd, "dir "); strcat(cmd, path); strcat(cmd, " /s /b > a.log");
	system(cmd);
	fptr = fopen("a.log", "r+");
	if (fptr == NULL) {
		printf("path '/s' is not exit/n", path);
		return -1;
	}
	char temp[100] = ""; int i = 0;
	while (fgets(temp, 100, fptr) != NULL) {
		strcpy(filename[i], strrchr(temp, '\\') + 1);
		filename[i][strlen(filename[i]) - 1] = 0;
		i++;
	}
	fclose(fptr);
}
void printfilelist()
{
	char path[1000] = "E:\\C����\\�о�";
	char filename[100][100]; char* pfn[100];
	for (int i = 0; i < 100; i++) {
		filename[i][0] = 0;
		pfn[i] = filename[i];
	}
	get_file_list(path, pfn);
	for (int i = 0; i < 100; i++) {
		if (filename[i][0] == 0) break;
		char* t = filename[i];
		printf("\n\n\n\t\t\t\t\t%d.", i + 1);
		for (int j = 0; j < strlen(t) - 4; j++)
		{
			printf("%c", t[j]);
		}
		printf("\n\n");
	}
}
void printdoclist()
{
	char path[1000] = "E:\\C����\\��¼";
	char filename[100][100]; char* pfn[100];
	for (int i = 0; i < 100; i++) {
		filename[i][0] = 0;
		pfn[i] = filename[i];
	}
	get_file_list(path, pfn);
	for (int i = 0; i < 100; i++) {
		if (filename[i][0] == 0) break;
		char* t = filename[i];
		printf("\n\n\n\t\t\t\t\t%d.", i + 1);
		for (int j = 0; j < strlen(t) - 4; j++)
		{
			printf("%c", t[j]);
		}
		printf("\n\n");
	}
}