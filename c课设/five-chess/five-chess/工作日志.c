#include "game.h"
#include"struct.h"
void insert(int choice) {
	time_t ltime;
	time(&ltime);
	struct tm* today = localtime(&ltime);
	top->pnext = (Log*)malloc(sizeof(Log));
	top = top->pnext;
	top->time = today;
	top->op = operation[choice];
	top->sec = today->tm_sec;
	top->hour = today->tm_hour;
	top->min = today->tm_min;
}
void Savelogbook() {
	if (top != &head)
	{
		char filename[1000] = "E:\\C课设\\工作日志";
		strcat(filename, suffix);
		FILE* fp;
		/*打开文本文件以追加内容*/
		fp = fopen(filename, "a");
		if (!fp)
		{
			perror("cannot open file");
		}
		/*将工作日志写入文件*/
		Log* t = &head;
		while (t != top) {
			t = t->pnext;
			fprintf(fp, "%s   %d.%d.%d.%2d:%2d:%2d", t->op, t->time->tm_year + 1900, t->time->tm_mon + 1, t->time->tm_mday, t->hour, t->min, t->sec);
			fputc('\n', fp);
		}
		fclose(fp);
	}
}