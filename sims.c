#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h" 
#include "login.h"
#include "config.h"
#include "print.h"

int main(void)
{
	FILE *fuser = NULL; 
	FILE *fstu = NULL;
	struct user login; 
	memset(&login, 0, sizeof(struct user)); 
	//System_Initialize(&fuser, &fstu); 

	Print_Sys_Interface(); 
	User_Login(&login); 
	printf("\n%s\n", login.ID); 
	printf("%s\n", login.KEY); 

	return 0; 
}
