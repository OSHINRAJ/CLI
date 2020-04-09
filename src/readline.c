/************************************************************************
 * @File		:	readline.c
 * @brief		:	read a line form the CLI.	
 * @Author		:	OSHINRAJ K M (oshinrajkm@gmail.com)
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include "version.h"
#include "command.h"
#include "parseline.h"
#include "history.h"
#include "readline.h"

int getch( )
{
	struct termios oldt,
				   newt;
	int            ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}

unsigned char *read_line(unsigned char *promt)
{
	char ch;
	int i, length = 0, pos = 0;
	unsigned char *cmdBuffer = (unsigned char *)malloc(MAX_CMD_LENGTH * sizeof(char));
	printf("\n%s", promt);
	while(1) {
		for (i = pos; i < length; i++)
			printf("\b");
		ch = getch();
		if (ch == '\n') {
			if (length == 0) {
				printf("\n%s", promt);
				continue;
			} else {
				printf("\n");
				return cmdBuffer;
			}
		}
		if (ch == 127 || ch == 8) {
			if (pos == 0) {
				continue;
			} else {
				for (i = pos; i < length; i++) {
					cmdBuffer[i-1] = cmdBuffer[i];
				}

				cmdBuffer[length - 1] = '\0';
				printf("%c[2K\r", 27);
				printf("%s%s", promt, cmdBuffer);
				pos--;
				length--;
				continue;
			}
		}
		if (ch == '\033') {
			getch();
			switch(getch()) {
				case 'A': /* Arrow_Key_UP */
					strcpy(cmdBuffer, getHistory(HISTORY_UP));
					length = strlen(cmdBuffer);
					pos = length;
					break;
				case 'B': /* Arrow_Key_DOWN */
					strcpy(cmdBuffer, getHistory(HISTORY_DOWN));
					length = strlen(cmdBuffer);
					pos = length;
					break;
				case 'C': if (pos < length)
							  pos ++;
						  break;
				case 'D': if (pos > 0)
							  pos --;
							break;
			}
			printf("%c[2K\r", 27);
			printf("%s%s", promt, cmdBuffer);
		}
		if (ch != '\n' && ch != '\b' && ch != '\033' && ch != 127 && ch != 8) {
			if (length < MAX_CMD_LENGTH) {
				length++;
				for (i = length; i >=pos; i--) {
					cmdBuffer[i+1] = cmdBuffer[i];
				}
				cmdBuffer[pos] = ch;
				cmdBuffer[length] = '\0';
				pos++;
			}
			printf("%c[2K\r", 27);
			printf("%s%s", promt, cmdBuffer);
		}

	}
	free(cmdBuffer);
	return NULL;

}
