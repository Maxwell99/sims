#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h" 
#include "student.h"
#include "init.h"
#include "print.h"
#include "login.h"
#include "linklist.h"

int main(void)
{
	struct user *user_head = NULL; 
	struct stu *stu_head = NULL; 
	struct user login; 
	memset(&login, 0, sizeof(struct user)); 

	System_Init(&user_head, &stu_head); 

	/*
	Print_Sys_Interface(); 
	User_Login(&login); 

	*/
	
	Add_One_Stu_Info(&stu_head); 
	Print_Stu_Info(stu_head); 

	return 0; 
}