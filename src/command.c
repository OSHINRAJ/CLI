/************************************************************************
 * @File        :   command.c
 * @brief       :   Contains the custom commands used by the CLI 
 * @Author      :   OSHINRAJ K M (oshinrajkm@gmail.com)
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "command.h"


/************************************************************************
 *	cmd_table : array containing command name and corresponding function 
 *				pointer.
 ************************************************************************/
entry_t cmd_table[] = {
	{"command_1", cmd_1},
	{"command_2", cmd_2},
	{"command_3", cmd_3},
	{"command_4", cmd_4},
	{"command_5", cmd_5},
	{"system", system_cmd},
	{"lscmd", cmd_7},
	{"help", help_cmd}
};


/************************************************************************
 * @Func	:	cmd_1	
 * @brief	:	
 * @Param	:	argc : no.of arguments,  argv : array of arguments	
 * @Return	:	0 for success and -1 for failure 	
 ************************************************************************/
int cmd_1(unsigned int argc, unsigned char **argv) {
	
	int i = 0;
	color_red();
	printf("\n[%s] COMMAND : %s | %d", __DATE__, argv[0], argc);
	for (i = 1; i < argc; ++i) {
		printf("\n argv[%d]\t: %s", i, argv[i]);
	}
	color_reset();
	return 1;
}

/************************************************************************
 * @Func	:	cmd_2
 * @brief	:	
 * @Param	:	argc : no.of arguments,  argv : array of arguments
 * @Return	:	0 for success and -1 for failure 
 ************************************************************************/
int cmd_2(unsigned int argc, unsigned char **argv) {

	int i = 0;
	color_red();
	printf("\n[%s] COMMAND : %s | %d", __DATE__, argv[0], argc);
	for (i = 1; i < argc; ++i) {
		printf("\n argv[%d]\t: %s", i, argv[i]);
	}
	color_reset();
	return 1;
}

/************************************************************************
 * @Func	:	cmd_3	
 * @brief	:	
 * @Param	:	argc : no.of arguments,  argv : array of arguments
 * @Return	:	0 for success and -1 for failure 
 ************************************************************************/
int cmd_3(unsigned int argc, unsigned char **argv) {

	int i = 0;
	color_red();
	printf("\n[%s] COMMAND : %s | %d", __DATE__, argv[0], argc);
	for (i = 1; i < argc; ++i) {
		printf("\n argv[%d]\t: %s", i, argv[i]);
	}
	color_reset();
	return 1;
}

/************************************************************************
 * @Func	:	cmd_4
 * @brief	:	
 * @Param	:	argc : no.of arguments,  argv : array of arguments
 * @Return	:	0 for success and -1 for failure 
 ************************************************************************/
int cmd_4(unsigned int argc, unsigned char **argv) {

	int i = 0;
	color_red();
	printf("\n[%s] COMMAND : %s | %d", __DATE__, argv[0], argc);
	for (i = 1; i < argc; ++i) {
		printf("\n argv[%d]\t: %s", i, argv[i]);
	}
	color_reset();
	return 1;
}

/************************************************************************
 * @Func	:	cmd_5
 * @brief	:	
 * @Param	:	argc : no.of arguments,  argv : array of arguments
 * @Return	:	0 for success and -1 for failure 
 ************************************************************************/
int cmd_5(unsigned int argc, unsigned char **argv) {

	int i = 0;
	color_red();
	printf("\n[%s] COMMAND : %s | %d", __DATE__, argv[0], argc);
	for (i = 1; i < argc; ++i) {
		printf("\n argv[%d]\t: %s", i, argv[i]);
	}
	color_reset();
	return 1;
}

/************************************************************************
 * @Func	:	system_cmd
 * @brief	:	commands which can be executed in linux terminal
 * @Param	:	argc : no.of arguments,  argv : array of arguments
 * @Return	:	0 for success and -1 for failure 
 ************************************************************************/
int system_cmd(unsigned int argc, unsigned char **argv) {

	int i = 0;
	char buf[100] = "\0" ;
	for (i = 1; i < argc; ++i) {
		sprintf(buf, "%s%s ", buf, argv[i]);
	}
	system(buf);
	return 1;
}

/************************************************************************
 * @Func	:	cmd_7	
 * @brief	:	
 * @Param	:	argc : no.of arguments,  argv : array of arguments
 * @Return	:	0 for success and -1 for failure	
 ************************************************************************/
int cmd_7(unsigned int argc, unsigned char **argv) {

	int i = 0;
	color_red();
	printf("\n[%s] COMMAND : %s | %d", __DATE__, argv[0], argc);
	for (i = 1; i < argc; ++i) {
		printf("\n argv[%d]\t: %s", i, argv[i]);
	}
	color_reset();
	return 1;
}

/************************************************************************
 * @Func	:	help_cmd
 * @brief	:	
 * @Param	:	argc : no.of arguments,  argv : array of arguments
 * @Return	:	0 for success and -1 for failure	
 ************************************************************************/
int help_cmd(unsigned int argc, unsigned char **argv) {

	int i;

	printf("\n==================================\n\tAvailable Commands\n==================================");
	for (i = 0; i < NO_OF_CMDS; i++) {
		printf("\n%d\t: %s", i, cmd_table[i].cmd_name);
	}

	printf("\n%d\t: %s\n==================================\n", i, "exit");
	return 0;
}


