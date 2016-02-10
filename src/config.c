#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "user.h"
#include "student.h"
#include "linklist.h"

#define FILE_NAME_LEN 30

void System_Init(struct user **user_head, struct stu **stu_head)
{
	FILE *config = fopen("./etc/config", "r"); 
	if (config == NULL) {
		perror("fopen config"); 
		exit(-1); 
	}
	char fuser[FILE_NAME_LEN] = {0}; 
	char fstu[FILE_NAME_LEN] = {0}; 
	fscanf(config, "%s%s", fuser, fstu); 
	//printf("%s\n%s\n", fuser, fstu); 
	
	FILE *fp_user = fopen(fuser, "r"); 
	if (fp_user == NULL) {
		perror("fopen fuser"); 
		exit(-1); 
	}
	//puts("open fp_user success"); 
	
	FILE *fp_stu = fopen(fstu, "w+"); 
	if (fp_stu == NULL) {
		perror("fopen fstu"); 
		exit(-1); 
	}
	
	Init_Stu_Link_List(stu_head); 
	//puts("open fp_stu success"); 
	
	fclose(fp_user); 
	fclose(fp_stu); 
	fclose(config); 
}

