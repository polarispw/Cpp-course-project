#pragma once
typedef struct item {
	char* op;//����Ĳ���
	struct tm* time;//������ʱ��
	struct item* pnext;
	int sec;
	int hour;
	int min;
}Log;
Log head;
Log* top = &head;