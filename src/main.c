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
	struct user * user = NULL; 
	struct stu * stu = NULL; 
	struct user login; 
	memset(&login, 0, sizeof(struct user)); 

	System_Init(&user, &stu); 
	Print_All_User_Info(user); 
	Print_All_Stu_Info(stu); 

	/*
	Print_Sys_Interface(); 
	User_Login(&login); 
	*/

	//Add_One_Stu_Info(&stu); 

	Print_All_Stu_Info(stu); 
	Print_Single_Mark_highest_Stu_Info(stu); 

	File_Save(user,stu); 

	Stu_Link_List_Destroy(&stu); 
	User_Link_List_Destroy(&user); 

	return 0; 
}
