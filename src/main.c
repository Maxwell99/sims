#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h" 
#include "student.h"
#include "sys.h"
#include "linklist.h"
#include "getch.h"
#include "pause.h"

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
				if (!User_Authonrize(user, &login)) {
					if (login.Level == 1) {
						for (;;) {
							Print_Stu_Interface(); 
							choice = getchar(); 
							if (choice == 'A' || choice == 'a') {
								//Print_One_Stu_Info(stu, login.Name); 
								Print_One_Stu_Info(stu, login.ID); 
								System_Pause(); 
							}
							else if (choice == 'B' || choice == 'b') {
								//Change_User_Passwd(&user, login.Name); 
								if (Change_User_Passwd(&user, login.ID)) {
									perror("Change_User_Passwd"); 
									exit(-1); 
								}
								File_Save(user, stu); 
								System_Pause(); 
							}
							else if (choice == 'C' || choice == 'c') {
								choice = Esc; 
								break; 
							}
						}
					}
					else if (login.Level == 0) {
						for (;;) {
							Print_Tch_Interface(); 
							char key[KEY_LEN]; 
							choice = getchar(); 
							if (choice == 'A' || choice == 'a') {
								Print_All_Stu_Info(stu); 
								System_Pause(); 
							}
							else if (choice == 'B' || choice == 'b') {
								struct stu new_stu; 
								memset(&new_stu, 0, sizeof(struct stu)); 
								struct user new_user; 
								memset(&new_user, 0, sizeof(struct user)); 

								Obtain_One_Stu_Info(&new_stu); 
								strcpy(new_user.ID, new_stu.ID); 
								strcpy(new_user.Name, new_stu.Name); 
								strcpy(new_user.Key, "123456"); 
								new_user.Level = 1; 

								Add_One_Stu_Info(&stu, new_stu); 
								Print_One_Stu_Info(stu, new_stu.ID); 
								Add_One_User_Info(&user, new_user); 
								Print_One_User_Info(user, new_stu.ID); 
								File_Save(user, stu); 
								System_Pause(); 
							}
							else if (choice == 'C' || choice == 'c') {
								printf("Please input student ID or name:"); 
								scanf("%s", key); 
								Del_One_Stu_Info(&stu, key); 
								Del_One_User_Info(&user, key); 
								File_Save(user, stu); 
								System_Pause(); 
							}
							else if (choice == 'D' || choice == 'd') {
								struct stu new_stu, old_stu; 
								memset(&new_stu, 0, sizeof(struct stu)); 
								memset(&old_stu, 0, sizeof(struct stu)); 
								struct user new_user, old_user; 
								memset(&new_user, 0, sizeof(struct user)); 
								memset(&old_user, 0, sizeof(struct user)); 

								printf("Please input student ID or Name:"); 
								scanf("%s", key); 
								Print_One_Stu_Info(stu, key); 
								Modify_Stu_Info(&stu, key, &new_stu, &old_stu); 
								Print_One_Stu_Info(stu, new_stu.ID); 

								if (!((!strcmp(old_stu.ID, new_stu.ID)) && \
									  (!strcmp(old_stu.Name, new_stu.Name)))) {
									Del_One_User_Info(&user, key); 
									strcpy(new_user.ID, new_stu.ID); 
									strcpy(new_user.Name, new_stu.Name); 
									strcpy(new_user.Key, "123456"); 
									new_user.Level = 1; 
									Add_One_User_Info(&user, new_user); 
									Print_One_User_Info(user, new_stu.ID); 
								}

								File_Save(user, stu); 
								System_Pause(); 
							}
							else if (choice == 'E' || choice == 'e') {
								Print_Single_Mark_highest_Stu_Info(stu); 
								System_Pause(); 
							}
							else if (choice == 'F' || choice == 'f') {
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
