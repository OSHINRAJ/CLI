/************************************************************************
 * @File        :   command.c
 * @brief       :   Contains the custom commands used by the CLI 
 * @Author      :   OSHINRAJ K M (oshinrajkm@gmail.com)
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "command.h"

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

int system_cmd(unsigned int argc, unsigned char **argv) {

	int i = 0;
	char buf[100] = "\0" ;
	for (i = 1; i < argc; ++i) {
		sprintf(buf, "%s%s ", buf, argv[i]);
	}
	system(buf);
	return 1;
}
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

entry_t cmd_table[] = {
	{"command_1", cmd_1},
	{"command_2", cmd_2},
	{"command_3", cmd_3},
	{"command_4", cmd_4},
	{"command_5", cmd_5},
	{"system", system_cmd},
	{"lscmd", cmd_7}
};

