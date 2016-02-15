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
#define KEY_LEN 20

int main(void)
{
	struct user * user = NULL; 
	struct stu * stu = NULL; 
	struct user login; 
	memset(&login, 0, sizeof(struct user)); 
	System_Init(&user, &stu); 
	Print_All_Stu_Info(stu); 
	//Print_All_User_Info(user); 
		
	char choice = 0; 
	for (;;) {
		Print_Sys_Interface(); 
		choice = getch(); 
		if (choice == Enter) 
			for (;;) {
				if (!User_Authonrize(user, &login)) {
					if (login.Level == 1) {
						for (;;) {
							Print_Stu_Interface(); 
							choice = getch(); 
							if (choice == Enter) {
								//Print_One_Stu_Info(stu, login); 
								printf("Press any key to exit:"); 
								getch(); 
								putchar('\n'); 
								choice = Esc; 
								break; 
							}
							else if (choice == Esc)
								break; 
						}
					}
					else if (login.Level == 0) {
						for (;;) {
							Print_Tch_Interface(); 
							char key[KEY_LEN]; 
							choice = getchar(); 
							if (choice == 'A' || choice == 'a') {
								Print_All_Stu_Info(stu); 
								getchar(); 
								printf("Press any key back:"); 
								getch(); 
							}
							else if (choice == 'B' || choice == 'b') {
								Add_One_Stu_Info(&stu); 
							}
							else if (choice == 'C' || choice == 'c') {
								Del_One_Stu_Info(&stu, key); 
							}
							else if (choice == 'D' || choice == 'd') {
								//Modify_One_Stu_Info(&stu, key); 
							}
							else if (choice == 'E' || choice == 'e') {
								choice = Esc; 
								break; 
							}
						}
					}
				}
				else {
					printf("ID or Key was wrong! You may input again.\n"); 
				}
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
