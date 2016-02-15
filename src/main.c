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
	//Print_All_Stu_Info(stu); 
	//Print_All_User_Info(user); 
	char COURSE[STU_COURSE_NUM][10] = {"Math", "English", "Chinese"}; 
		
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
								//Print_One_Stu_Info(stu, login.ID); 
								Print_One_Stu_Info(stu, login.Name); 
								System_Pause(); 
							}
							else if (choice == 'B' || choice == 'b') {
								char passwd_1[KEY_LEN] = {0}; 
								char passwd_2[KEY_LEN] = {0}; 
								int i; 
								for (i = 0; i < 3; i++) {
									printf("New password:"); 
									scanf("%s", passwd_1); 
									printf("Retype new password:"); 
									scanf("%s", passwd_2); 
									if (!strcmp(passwd_1, passwd_2)) {
										Modify_User_Password(&user, login.ID, passwd_1); 
										//Modify_User_Password(&user, login.Name, passwd_1); 
										File_Save(user, stu); 
										puts("all authentication tokens updated successfully."); 
										break; 
									}
									else 
										puts("Sorry, passwords do not match."); 

								}
								if (i == 3) 
									puts("Have exhausted maximum number of retries for service"); 
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

								printf("\033[1mNew Student Information\033[0m\n"); 
								printf("Student   ID:"); 
								scanf("%s", new_stu.ID);				 
								strcpy(new_user.ID, new_stu.ID); 
								printf("Student Name:"); 
								scanf("%s", new_stu.Name);
								strcpy(new_user.Name, new_stu.Name); 
								int i; 
								for (i = 0; i < STU_COURSE_NUM; i++){
									printf("%s\t Mark:", COURSE[i]); 
									scanf("%d", &(new_stu.Grade[i])); 
								}
								strcpy(new_user.Key, "123456"); 
								new_user.Level = 1; 

								Add_One_Stu_Info(&stu, new_stu); 
								Add_One_User_Info(&user, new_user); 
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
								//Modify_Stu_Info(&stu, key); 
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
