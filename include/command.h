#ifndef __COMMAND_H__
#define __COMMAND_H__

#define NO_OF_CMDS 7

#define color_red() printf("\033[0;31m");
#define color_reset() printf("\033[0m");


typedef struct {
	    const char *cmd_name;
		    int (*cmd_ptr)(unsigned int , unsigned char **);
} entry_t;
int cmd_1(unsigned int argc, unsigned char **argv);
int cmd_2(unsigned int argc, unsigned char **argv);
int cmd_3(unsigned int argc, unsigned char **argv);
int cmd_4(unsigned int argc, unsigned char **argv);
int cmd_5(unsigned int argc, unsigned char **argv);
int system_cmd(unsigned int argc, unsigned char **argv);
int cmd_7(unsigned int argc, unsigned char **argv);

#endif // __COMMAND_H__
