/************************************************************************
 * @File        :   cmdmain.c
 * @brief       :   Top level main program for CLI 
 * @Author      :   OSHINRAJ K M (oshinrajkm@gmail.com)
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "version.h"
#include "command.h"
#include "parseline.h"
#include "history.h"
#include "readline.h"

BUILD_VERSION("OSHINRAJ", "MY_CLI", "1");
extern entry_t cmd_table[];



int main()
{
	int i, argc;
	unsigned char *line = NULL, **argv = NULL;
	while (1) {
		line = read_line(TERMINAL_PROMT);
		addHistory(line);
//		printf("\nlength of command : %d | cmd : %s \n", strlen(line), line);
		argv = parse_line(line, &argc);
		if (argc != 0) {
			if (!strcmp(argv[0], "exit")) {
				free(line);
				free(argv);
				printf("\n");
				break;
			}
			if (!strcmp(argv[0], "lscmd")) {
				checkCmd();
			}
			for (i = 0; i < NO_OF_CMDS; i++) {
				if (!strcmp(argv[0], cmd_table[i].cmd_name)){
					cmd_table[i].cmd_ptr(argc, argv);
				}
			}
		}
		free(line);
		free(argv);

	}
	clearHistoryList();
	return 0;
}
