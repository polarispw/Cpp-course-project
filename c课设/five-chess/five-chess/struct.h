#pragma once
typedef struct item {
	char* op;//具体的操作
	struct tm* time;//操作的时间
	struct item* pnext;
	int sec;
	int hour;
	int min;
}Log;
Log head;
Log* top = &head;