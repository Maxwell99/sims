#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h" 
#include "student.h"
#include "sys.h"
#include "linklist.h"

int main(void)
{
	struct user * user = NULL; 
	struct stu * stu = NULL; 
	struct user login; 
	memset(&login, 0, sizeof(struct user)); 

	System_Init(&user, &stu); 
	Print_Sys_Interface(); 
	
	for (;;) {
		if (!User_Authonrize(user, &login)) {
			Print_All_Stu_Info(stu); 
		}
		else {
			printf("ID or Key was wrong!\n"); 
		}	
	}

	//Add_One_Stu_Info(&stu); 
	//File_Save(user,stu); 

	Stu_Link_List_Destroy(&stu); 
	User_Link_List_Destroy(&user); 

	return 0; 
}
