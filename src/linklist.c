#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "student.h"
#include "tools.h"

#define ElemType_STU struct stu
#define ElemType_USER struct user
#define KEY char *

char COURSE[STU_COURSE_NUM][10] = {"Math", "English", "Chinese"}; 

void Init_Stu_Link_List(ElemType_STU ** list_head)
{
	*list_head = (ElemType_STU *) malloc(sizeof(ElemType_STU)); 
	memset(*list_head, 0, sizeof(ElemType_STU)); 
}

void Init_User_Link_List(ElemType_USER ** list_head)
{
	*list_head = (ElemType_USER *) malloc(sizeof(ElemType_USER)); 
	memset(*list_head, 0, sizeof(ElemType_USER)); 
}

void Stu_Link_List_Destroy(ElemType_STU ** list_head)
{
	ElemType_STU * temp = NULL; 
	while (*list_head != NULL){
		temp = *list_head; 
		*list_head = (*list_head)->next; 
		temp->next = NULL; 
		free(temp); 
	}
	temp = NULL; 
	list_head = NULL; 
}

void User_Link_List_Destroy(ElemType_USER ** list_head)
{
	ElemType_USER * temp = NULL; 
	while (*list_head != NULL){
		temp = *list_head; 
		*list_head = (*list_head)->next; 
		temp->next = NULL; 
		free(temp); 
	}
	temp = NULL; 
	list_head = NULL; 
}

void Add_One_User_Info(ElemType_USER ** list_head)
{
	ElemType_USER * pcur = *list_head; 
	ElemType_USER * temp = (ElemType_USER *) malloc(sizeof(ElemType_USER)); 
	memset(temp, 0, sizeof(ElemType_USER)); 

	printf("\033[1mNew User Information\033[0m\n"); 
	printf("User   ID:"); 
	scanf("%s", temp->ID); 
	printf("User Name:"); 
	scanf("%s", temp->Name);

	//sorting insert
	while ((pcur->next != NULL) && strcmp(temp->ID, pcur->next->ID) > 0){
		pcur = pcur->next; 
	}
	if (pcur->next == NULL){
		pcur->next = temp; 
	}
	else {
		temp->next = pcur->next; 
		pcur->next = temp; 
	}

	temp = NULL; 
	pcur = NULL; 
}

void Add_One_Stu_Info(ElemType_STU ** list_head)
{
	ElemType_STU * pcur = *list_head; 
	ElemType_STU * temp = NULL; 
	temp = (ElemType_STU *) malloc(sizeof(ElemType_STU)); 
	memset(temp, 0, sizeof(ElemType_STU)); 

	printf("\033[1mNew Student Information\033[0m\n"); 
	printf("Student   ID:"); 
	scanf("%s", temp->ID); 
	printf("Student Name:"); 
	scanf("%s", temp->Name);
	int i; 
	for (i = 0; i < STU_COURSE_NUM; i++){
		printf("%s\t Mark:", COURSE[i]); 
		scanf("%d", &(temp->Grade[i])); 
	}

	//sorting insert
	while ((pcur->next != NULL) && strcmp(temp->ID, pcur->next->ID) > 0){
		pcur = pcur->next; 
	}
	if (pcur->next == NULL){
		pcur->next = temp; 
	}
	else {
		temp->next = pcur->next; 
		pcur->next = temp; 
	}

	temp = NULL; 
	pcur = NULL; 
}

struct stu Del_One_Stu_Info(ElemType_STU ** list_head, KEY key)
{
	ElemType_STU * pcur = *list_head; 
	ElemType_STU * temp = NULL; 
	ElemType_STU ret;
	memset(&ret, 0, sizeof(struct stu)); 
	while (pcur->next != NULL){
		if (!strcmp(pcur->next->ID, key) || !strcmp(pcur->next->Name, key)) {
			temp = pcur->next; 
			pcur->next = temp->next; 
			temp->next = NULL; 
			memcpy(&ret, temp, sizeof(struct stu)); 
			free(temp); 
			break; 
		}
		pcur = pcur->next; 
	}
	temp = NULL; 
	pcur = NULL; 
	return ret;  
}

struct user Del_One_User_Info(ElemType_USER ** list_head, KEY key)
{
	ElemType_USER * pcur = *list_head; 
	ElemType_USER * temp = NULL; 
	ElemType_USER ret;
	memset(&ret, 0, sizeof(struct user)); 
	while (pcur->next != NULL){
		if (!strcmp(pcur->next->ID, key) || !strcmp(pcur->next->Name, key)) {
			temp = pcur->next; 
			pcur->next = temp->next; 
			temp->next = NULL; 
			memcpy(&ret, temp, sizeof(struct user)); 
			free(temp); 
			break; 
		}
		pcur = pcur->next; 
	}
	temp = NULL; 
	pcur = NULL; 
	return ret;  
}

void Print_All_Stu_Info(ElemType_STU * list_head)
{
	list_head = list_head->next; 
	if (list_head != NULL) {
		int i; 
		printf("\n-----------------------------------------\n"); 
		printf("\033[31mID\tName\t\033[0m"); 
		for (i = 0; i < STU_COURSE_NUM; i++){
			printf("\033[31m%s\t\033[0m", COURSE[i]); 
		}
		printf("\n-----------------------------------------\n"); 

		while (list_head!= NULL) {
			printf("%s\t%s\t", list_head->ID, list_head->Name); 
			for (i = 0; i < STU_COURSE_NUM; i++) {
				printf("%3d\t",list_head->Grade[i]);
			}
			printf("\n"); 
			list_head = list_head->next; 
		}
		printf("\n"); 
	}		
}

void Print_All_User_Info(ElemType_USER * list_head)
{
	list_head = list_head->next; 
	if (list_head != NULL) {
		printf("\n-----------------------------------------\n"); 
		printf("\033[31mID\tName\tKey\tLevel\033[0m"); 
		printf("\n-----------------------------------------\n"); 

		while (list_head!= NULL) {
			//printf("%s\t%s\t%s\t%d", list_head->ID, list_head->Name, list_head->Key, list_head->Level); 
			printf("%s\t%s\t%s\t%d", list_head->ID, list_head->Name, list_head->Key, list_head->Level); 
			printf("\n"); 
			list_head = list_head->next; 
		}
	}		
}

void Print_Single_Mark_highest_Stu_Info(ElemType_STU * list_head)
{
	printf("-----------------------------------------\n"); 
	printf("\033[31m Single Mark Highest Student Information\n\033[0m"); 
	printf("-----------------------------------------\n"); 

	int i, j; 
	ElemType_STU * pcur = NULL; 
	ElemType_STU temp; 
	for (i = 0; i < STU_COURSE_NUM; i++){
		memset(&temp, 0, sizeof(ElemType_STU)); 
		pcur = list_head->next; 
		while (pcur != NULL){
			if (pcur->Grade[i] > temp.Grade[i]){
					strcpy(temp.ID, pcur->ID); 
					strcpy(temp.Name, pcur->Name); 
					for (j = 0; j < STU_COURSE_NUM; j++)
					temp.Grade[j] = pcur->Grade[j]; 
			}
			pcur = pcur->next; 
		}

		printf("%s\t%s\t", temp.ID, temp.Name); 
		for (j = 0; j < STU_COURSE_NUM; j++){
			printf("%3d\t",temp.Grade[j]);
		}
		printf("\n"); 
	}
	pcur = NULL; 
}
