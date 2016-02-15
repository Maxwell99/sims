#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "user.h"
#include "student.h"
#include "linklist.h"
#include "getch.h"

#define FILE_NAME_LEN 20
#define TRUE 0
#define FALSE -1

void System_Init(struct user ** user_list_head, struct stu ** stu_list_head)
{
	FILE * config = fopen("src/config", "r"); 
	if (config == NULL) {
		perror("fopen config"); 
		exit(-1); 
	}
	char user_file_name[FILE_NAME_LEN] = {0}; 
	char stu_file_name[FILE_NAME_LEN] = {0}; 
	fscanf(config, "%s%s", user_file_name, stu_file_name); 
	//printf("%s\n%s\n", user_file_name, stu_file_name); 
	fclose(config); 
		
	//Init user linklist 
	Init_User_Link_List(user_list_head); 
	FILE *fp_user = fopen(user_file_name, "r"); 
	if (fp_user == NULL) {
		perror("fopen user_file_name"); 
		exit(-1); 
	}
	struct user * puser = NULL; 
	struct user * temp_user = NULL; 
	do {
		puser = *user_list_head; 
		temp_user = (struct user *) malloc(sizeof(struct user)); 
		memset(temp_user, 0, sizeof(struct user)); 
		fscanf(fp_user, "%s%s%s%d", temp_user->ID, temp_user->Name, temp_user->Key, &(temp_user->Level)); 

		//sorting insert
		while ((puser->next != NULL) && (strcmp(temp_user->ID, puser->next->ID) > 0)){
				puser = puser->next; 
		}
		if (puser->next == NULL){
				puser->next = temp_user; 
		}
		else {
				temp_user->next = puser->next; 
				puser->next = temp_user; 
		}
	} while (getc(fp_user) != EOF); 
	temp_user = NULL; 
	puser = *user_list_head; 
	*user_list_head = (*user_list_head)->next; 
	free(puser); 
	puser = NULL; 
	fclose(fp_user); 
	
	//Init student linklist 
	Init_Stu_Link_List(stu_list_head); 
	FILE *fp_stu = fopen(stu_file_name, "r"); 
	if (fp_stu == NULL) {
		perror("fopen stu_file_name"); 
		exit(-1); 
	}
	struct stu * pstu = NULL; 
	struct stu * temp_stu = NULL; 
	do {
		pstu = *stu_list_head; 
		temp_stu = (struct stu *) malloc(sizeof(struct stu)); 
		memset(temp_stu, 0, sizeof(struct stu)); 
		fscanf(fp_stu, "%s%s%d%d%d", temp_stu->ID, temp_stu->Name, &(temp_stu->Grade[0]), &(temp_stu->Grade[1]), &(temp_stu->Grade[2])); 

		//sorting insert
		while ((pstu->next != NULL) && strcmp(temp_stu->ID, pstu->next->ID) > 0){
				pstu = pstu->next; 
		}
		if (pstu->next == NULL){
				pstu->next = temp_stu; 
		}
		else {
				temp_stu->next = pstu->next; 
				pstu->next = temp_stu; 
		}
	} while (getc(fp_stu) != EOF); 
	temp_stu = NULL; 
	pstu = *stu_list_head; 
	*stu_list_head = (*stu_list_head)->next; 
	free(pstu); 
	pstu = NULL; 
	fclose(fp_stu); 
}

void File_Save(struct user * user_list_head, struct stu * stu_list_head)
{
	FILE * config = fopen("src/config", "r"); 
	if (config == NULL) {
		perror("fopen config"); 
		exit(-1); 
	}
	char user_file_name[FILE_NAME_LEN] = {0}; 
	char stu_file_name[FILE_NAME_LEN] = {0}; 
	fscanf(config, "%s%s", user_file_name, stu_file_name); 
	//printf("%s\n%s\n", user_file_name, stu_file_name); 
	fclose(config); 
	
	//Save User Infomation
	FILE *fp_user = fopen(user_file_name, "w"); 
	if (fp_user == NULL) {
		perror("fopen user_file_name"); 
		exit(-1); 
	}
	struct user * puser = user_list_head->next; 
	while (puser!= NULL) {
		fprintf(fp_user, "%s %s %s %d\n", puser->ID, puser->Name, puser->Key, puser->Level);
		puser = puser->next; 
	}
	fclose(fp_user); 
	
	//Save User Infomation
	FILE *fp_stu = fopen(stu_file_name, "w"); 
	if (fp_stu == NULL) {
		perror("fopen stu_file_name"); 
		exit(-1); 
	}
	struct stu * pstu = stu_list_head->next; 
	while (pstu!= NULL) {
		fprintf(fp_stu, "%s %s %d %d %d\n", pstu->ID, pstu->Name, pstu->Grade[0], pstu->Grade[1], pstu->Grade[2]); 
		pstu = pstu->next; 
	}
	fclose(fp_stu); 
}

void User_Login(struct user *login)
{
	int i; 
	char ch; 
	printf("\033[1mUserID:\033[0m"); 
	for (i = 0; i < ID_LEN; i++) {
		ch = getch(); 
		if (ch == '\r') {
			printf("\n"); 
			break; 
		}
		else if (ch >= '!' && ch <= '~') {
			login->ID[i] = ch; 
			putchar(login->ID[i]); 
		}
		else if (ch == '\b') {
			i--; 
			if (i >= 0) {
				putchar('\b'); 
				putchar(' '); 
				putchar('\b');
				login->ID[i] = 0; 
				i--; 
			}
		}
	}
	login->ID[i] = 0; 
	//puts(login->ID); 

	printf("\033[1mPassWD:\033[0m"); 
	for (i = 0; i < KEY_LEN; i++) {
		ch = getch(); 
		if (ch == '\r') {
			printf("\n"); 
			break; 
		}
		else if (ch >= ' ' && ch <= '~') {
			login->Key[i] = ch; 
			putchar('*'); 
		}
		else if (ch == '\b') {
			i--; 
			if (i >= 0) {
				putchar('\b'); 
				putchar(' '); 
				putchar('\b');
				login->Key[i] = 0; 
				i--; 
			}
		}
	}
	login->Key[i] = 0; 
	//puts(login->Key); 
}

int User_Authonrize(struct user * list_head, struct user * login)
{
	User_Login(login);
	list_head = list_head->next; 
	while (list_head != NULL) {
		if (!strcmp(login->ID,list_head->ID)) {
			if (!strcmp(login->Key,list_head->Key)) {
				login->Level = list_head->Level; 
				return TRUE;
			}
		}
		list_head = list_head->next; 
	}
	return FALSE; 
}

void Print_Sys_Interface(void)
{
	system("clear"); 
	printf("+---------------------------------------+\n"); 
	printf("|                                       |\n"); 
	printf("| \033[1mStudent Information Management System \033[0m|\n"); 
	printf("|                                       |\n"); 
	printf("| Esc                             Enter |\n"); 
	printf("+---------------------------------------+\n"); 
}

void Print_Tch_Interface(void)
{
	system("clear"); 
	printf("+---------------------------------------+\n"); 
	printf("|                                       |\n"); 
	printf("| \033[1mA.Echo All Student Information\033[0m        |\n"); 
	printf("| \033[1mB.Add New Student Information\033[0m         |\n"); 
	printf("| \033[1mC.Delete a Student Information\033[0m        |\n"); 
	printf("| \033[1mD.Modify a Student Information\033[0m        |\n"); 
	printf("| \033[1mE.Echo Single Mark Highest\033[0m            |\n"); 
	printf("| \033[1mF.Exit System\033[0m                         |\n"); 
	printf("|                                       |\n"); 
	printf("+---------------------------------------+\n"); 
}

void Print_Stu_Interface(void)
{
	system("clear"); 
	printf("+---------------------------------------+\n"); 
	printf("|                                       |\n"); 
	printf("| \033[1mA.Echo Your Information\033[0m               |\n"); 
	printf("| \033[1mB.Modify Your Login Password\033[0m          |\n"); 
	printf("| \033[1mC.Exit System\033[0m                         |\n"); 
	printf("|                                       |\n"); 
	printf("+---------------------------------------+\n"); 
}
