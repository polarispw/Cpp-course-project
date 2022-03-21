#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#include<string.h>
#include <time.h>
#pragma  comment(lib,"Winmm.lib") 
#define inf 40001
#define N 16
#define OK 1
#define NO 0
#define black 1
#define white 2
#define pve 2
#define pvp 1
#define train 3
#define suffix ".txt"
#define blank "                                                  "

int ontrain ;
int whoturn ;
int mode;
int humanfirst;
int map[N][N];
int record[225][2];
//map[i][j] == 1:一号选手或者玩家 2:二号选手或者电脑 0：无人下棋
int weight[5][3];
//weight[i][j]表示在有i个连成一条线，并且有j端遭到围堵

char* operation[5];
void insert(int choice);
void initgame();
void to_per();
void printfchessmap();
void to_com();
void ai(int* x, int* y);
int judge(int x, int y);
int Max2(int a, int b);
int Max3(int a, int b, int c);
int cal_weight(int x, int y, int cur);
void printfwelcome();
void printfgamepage();
void printfhomepage();
void homepagechioce();
void gamepagechioce();
void printfendpage();
void printfendreplay();
void Savelogbook();
void printdoclist();
void endreplaychioce();
void get_file_list(const char* path, char** filename);
void printfilelist();
void traingame();
void loadchessmap();
void load();
void endchioce();
void save();
void replay();
