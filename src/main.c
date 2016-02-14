#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h" 
#include "student.h"
#include "sys.h"
#include "linklist.h"
#include "tools.h"

#define Esc 27
#define Enter '\r'

int main(void)
{
	struct user * user = NULL; 
	struct stu * stu = NULL; 
	struct user login; 
	memset(&login, 0, sizeof(struct user)); 
	System_Init(&user, &stu); 
		
	char choice = 0; 
	for (;;) {
		Print_Sys_Interface(); 
		choice = getch(); 
		if (choice == Enter) 
			for (;;) {
				if (!User_Authonrize(user, &login))
					for (;;) {
						Print_Stu_Interface(); 
						choice = getch(); 
						if (choice == Enter) {
							//Print_One_Stu_Info(stu, login); 
							Print_All_Stu_Info(stu); 
							printf("Press any key to exit:"); 
							getchar(); 
							choice = Esc; 
							break; 
						}
						else if (choice == Esc)
							break; 
					}
				else
					printf("ID or Key was wrong! You may input again.\n"); 
				if (choice == Esc)
					break; 
			}
		if (choice == Esc) 
			break; 
	}

	File_Save(user, stu); 
	Stu_Link_List_Destroy(&stu); 
	User_Link_List_Destroy(&user); 

	return 0; 
}
