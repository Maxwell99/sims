#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "user.h"

int getch(void) 
{  
	int ch; 
	struct termios tm, tm_bak;  

	if (tcgetattr(STDIN_FILENO, &tm) < 0) {
		perror("tcgetattr"); 
		exit(-1); 
	}
	tm_bak = tm;  

	cfmakeraw(&tm);  
	if(tcsetattr(STDIN_FILENO, TCSANOW, &tm) < 0) {
		perror("tcsetattr"); 
		exit(-1); 
	}
	ch = getchar(); 

	if(tcsetattr(STDIN_FILENO, TCSANOW, &tm_bak) < 0) {
		perror("tcsetattr"); 
		exit(-1); 
	}
	return ch; 
}  

void User_Login(struct user *login)
{
	int i; 
	char ch; 
	printf("\033[11;27H"); 
	for (i = 0; i < ID_LEN; i++) {
		ch = getch(); 
		if (ch == '\r') {
			break; 
		}
		else if (ch >= '!' && ch <= '~') {
			login->ID[i] = ch; 
			putchar(login->ID[i]); 
		}
		else {
			i--; 
		}
	}
	login->ID[i] = 0; 

	printf("\033[14;27H"); 
	for (i = 0; i < KEY_LEN; i++) {
		ch = getch(); 
		if (ch == '\r') {
			break; 
		}
		else if (ch >= '!' && ch <= '~') {
			login->Key[i] = ch; 
			putchar('*'); 
		}
		else {
			i--; 
		}
	}
	login->Key[i] = 0; 
}
