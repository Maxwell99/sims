#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

#include "user.h"

void User_Login(struct user **pUser)
{
	struct user log; 
	memset(&log, 0, sizeof(struct user)); 

	int i; 
	char ch; 
	printf("\033[11;27H"); 
	for (i = 0; i < ID_LEN; i++) {
		scanf("%c", &log.ID[i]); 
		if (log.ID[i] == '\n') {
			log.ID[i] = 0; 
			break; 
		}
	}
	printf("\033[11;27H\033[32m%s\033[0m", log.ID); 

	printf("\033[14;27H"); 
	for (i = 0; i < KEY_LEN; i++) {
		log.KEY[i] = getchar(); 
		if (log.KEY[i] == '\n') {
			log.KEY[i] == 0; 
			break; 
		}
		putchar('\b'); 
		fputs("*", stdout); 
	}

}
