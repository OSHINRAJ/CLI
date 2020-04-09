/************************************************************************
 * @File		:	history.c
 * @brief		:	History related api and buffers	
 * @Author		:	OSHINRAJ K M (oshinrajkm@gmail.com)
 ************************************************************************/

#include "history.h"

history_t hist = {NULL, 0, 0};

int addHistory(char *cmd)
{		
	struct list *temp = (struct list *)malloc(sizeof(struct list));
	hist.idx = 0;
	if (temp == NULL)
		return -1;

	temp->buf = (char *)malloc(strlen(cmd)+10);
	strcpy(temp->buf, cmd);
	temp->up = hist.hist_list;
	if (hist.count != 0) {
		hist.hist_list->down = temp;
	}
	temp->down = NULL;
	hist.hist_list = temp;
	hist.count++;
	return 0;
}

char *getHistory(int dir)
{
	int i;
	struct list *node  = hist.hist_list;

	if (dir == HISTORY_UP) {
		for (i = 0; i < hist.idx ; i++) {
			if (node->up == NULL) {
				return "\0";
			}
			node = node->up;		
		}
		if (node == NULL) {
			return "\0";
		}
		hist.idx++;
		return node->buf;
	}
	if (dir == HISTORY_DOWN) {

		if (hist.idx > 0)
			hist.idx--;
		for (i = 0; i < hist.idx ; i++) {
			if (node->up == NULL)
				return "\0";
			node = node->up;
		}
		if (node == NULL) {
			return "\0";
		}
		return node->buf;
	}
}
int clearHistoryList()
{
	FILE *fp = fopen(HISTORY_FILE, "w+");
	struct list *node  = hist.hist_list;
	struct list *temp;

	if (fp == NULL) {
		return -1;
	}

	while ( node != NULL) {
		temp = node;
		node = node->up;
		fprintf(fp, "[%s]\t:\t%s\n", __DATE__, temp->buf);
		free(temp->buf);
		free(temp);
	}
	fclose(fp);
	return 0;
}
void checkCmd()
{
	struct list *node  = hist.hist_list;
	printf("\n");
	while ( node != NULL) {
		printf("[%s]\t:\t%s\n", __DATE__, node->buf);
		node = node->up;
	}
}
