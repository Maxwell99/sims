#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int getch(void) 
{  
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
	int ch = getchar(); 

	if(tcsetattr(STDIN_FILENO, TCSANOW, &tm_bak) < 0) {
		perror("tcsetattr"); 
		exit(-1); 
	}

	if (ch == 3 || ch == 4) 
		exit(0); 
	else
		return ch; 
}  
