/************************************************************************
 * @File        :   parseline.c
 * @brief       :	parse a string and count the number of substrings and
 *					return an array of string containing the parsed sub-
 *					strings
 * @Author      :   OSHINRAJ K M (oshinrajkm@gmail.com)
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseline.h"


/************************************************************************
 * @Func	:	parse_line
 * @brief	:	parse a command line string to its sub-strings and store 
 *				the sub-string to an array, calculate the no.of agruments
 * @Param1	:	command line string.	
 * @Param2	:	pointer to the argument count.
 * @Return	:	array of pointers to the command argumnets.
 ************************************************************************/
unsigned char **parse_line(unsigned char *line, unsigned int *count) {

	char *ch , **tokens = NULL;
	int init_cnt = 0 , cnt = 0, index = 0;

	if (line == NULL) {
		return NULL;
	}

	ch = line;
	while (*ch != '\0') {
		if (*ch != DELIMITER) {
			init_cnt = 1;
		}
		if (*ch == DELIMITER && init_cnt == 1) {
			init_cnt = 0;
			cnt ++;
		}
		ch++;
	}
	if (init_cnt == 1)
		cnt++;
	tokens  = malloc((cnt + 1) * sizeof(char *));
	if (tokens == NULL)
		return NULL;
	tokens[index] = strtok (line," ");
	while (tokens[index] != NULL) {
		index ++;
		tokens[index] = strtok (NULL, " ");
	}
	*count = cnt;
	return (unsigned char **)tokens;
}
