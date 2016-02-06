#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define FILE_NAME_LEN 10

void System_Initialize(FILE **user, FILE **stu)
{
	
	FILE *config = fopen("config", "w+"); 
	char user_info[FILE_NAME_LEN] = {0}; 
	char stu_info[FILE_NAME_LEN] = {0}; 
	if (config == NULL) {
		perror("fopen config"); 
		exit(1); 
	}

	fscanf(config, "%s%s", user_info, stu_info); 
	printf("%s\n%s\n", user_info, stu_info); 
		
	*user = (FILE*) malloc(sizeof(FILE*)); 
	printf("get dynamic memory success"); 
	*user = fopen(user_info, "w+"); 
	if (user == NULL) {
		perror("get user information failed"); 
		exit(1); 
	}
	*stu = (FILE*) malloc(sizeof(FILE*)); 
	printf("get dynamic memory success"); 
	*stu = fopen(stu_info, "w+"); 
	if (stu == NULL) {
		perror("get student information failed"); 
		exit(1); 
	}

	fclose(*user); 
	fclose(*stu); 
	fclose(config); 
}
