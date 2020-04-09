#ifndef __HISTORY_H__
#define __HISTORY_H__

#define HISTORY_UP		1
#define HISTORY_DOWN	0
#define HISTORY_FILE	"history_file.txt"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct list {
	char		*buf;
	struct list *up;
	struct list *down;
};

struct hist_t {
	struct list	*hist_list;
	uint32_t	idx;
	uint32_t	count;
};
typedef struct hist_t history_t;

int addHistory(char *);
char *getHistory(int dir);
int clearHistoryList();
void checkCmd();

#endif /*__HISTORY_H__ */
