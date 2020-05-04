/************************************************************************
 * @File		:	history.c
 * @brief		:	History related api and buffers	
 * @Author		:	OSHINRAJ K M (oshinrajkm@gmail.com)
 ************************************************************************/

#include "history.h"

history_t hist = {NULL, 0, 0};

/************************************************************************
 * @Func	:	addHistory	
 * @brief	:	add command to the history buffer.
 * @Param	:	command buffer to be added to history.
 * @Return	:	0 for sucess and -1 for failure.
 ************************************************************************/
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

/************************************************************************
 * @Func	:	getHistory	
 * @brief	:	get command form history buffer.
 * @Param	:	direction of the arrow key pressed.
 * @Return	:	pointer to the history command buffer.
 ************************************************************************/
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

/************************************************************************
 * @Func	:	clearHistory	
 * @brief	:	dump the cmd history to a file & clear history buffer.
 * @Param	:	Nill
 * @Return	:	0 for success and -1 for failure.
 ************************************************************************/
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

/************************************************************************
 * @Func	:	checkCmd	
 * @brief	:	Sample function to print the command history buffer.
 * @Param	:	Nill
 * @Return	:	Nill
 ************************************************************************/
void checkCmd()
{
	struct list *node  = hist.hist_list;
	printf("\n");
	while ( node != NULL) {
		printf("[%s]\t:\t%s\n", __DATE__, node->buf);
		node = node->up;
	}
}
