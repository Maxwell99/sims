#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "student.h"

char COURSE[STU_COURSE_NUM][10] = {"Math", "English", "Chinese", "Sum"}; 

void Init_Stu_Link_List(struct stu ** stuLinkList)
{
		*stuLinkList = (struct stu *) malloc(sizeof(struct stu)); 
		memset(*stuLinkList, 0, sizeof(struct stu)); 
}

void Init_User_Link_List(struct user ** userLinkList)
{
		*userLinkList = (struct user *) malloc(sizeof(struct user)); 
		memset(*userLinkList, 0, sizeof(struct user)); 
}

void Delete_Stu_Link_List(struct stu ** stuLinkList)
{
		struct stu * pcur = NULL; 
		while (*stuLinkList!= NULL){
				pcur = *stuLinkList; 
				*stuLinkList = (*stuLinkList)->next; 
				pcur->next = NULL; 
				free(pcur); 
				pcur = NULL; 
		}
		stuLinkList = NULL; 
}

void Add_One_Stu_Info(struct stu ** stuLinkList)
{
		int i; 
		struct stu *  pcur = *stuLinkList; 
		struct stu * temp = NULL; 
		temp = (struct stu *) malloc(sizeof(struct stu)); 
		memset(temp, 0, sizeof(struct stu)); 

		printf("Please input all information of a sutdent:\n"); 
		printf("Please input the student ID:"); 
		scanf("%s", temp->ID); 
		printf("Please input the student name:"); 
		scanf("%s", temp->Name);
		for (i = 0; i < STU_COURSE_NUM - 1; i++){
				printf("Please input the %s grade:", COURSE[i]); 
				scanf("%d", &(temp->Grade[i])); 
				temp->Grade[STU_COURSE_NUM - 1]	+= temp->Grade[i]; 
		}

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

void Print_Single_Course_highest_Stu_Info(struct stu * stuLinkList)
{
		int i, j, k; 
		struct stu * pcur = NULL; 
		struct stu * hightest = NULL; 
		hightest = (struct stu *) malloc(sizeof(struct stu)); 

		for (i = 0; i < STU_COURSE_NUM - 1; i++){
				memset(hightest, 0, sizeof(struct stu)); 
				pcur = stuLinkList->next; 
				while (pcur != NULL){
						if (pcur->Grade[i] > hightest->Grade[i]){
								strcpy(hightest->ID, pcur->ID); 
								strcpy(hightest->Name, pcur->Name); 
								for (j = 0; j < STU_COURSE_NUM; j++)
										hightest->Grade[j] = pcur->Grade[j]; 
						}
						pcur = pcur->next; 
				}
				printf("The %s grade highest student is:\n", COURSE[i]); 
				printf("%s\t%s\t", hightest->ID, hightest->Name); 
				for (k = 0; k < STU_COURSE_NUM; k++){
						printf("%d\t",hightest->Grade[k]);
				}
				printf("\n"); 
		}

		free(hightest); 
		hightest = NULL; 
		pcur = NULL; 
}

void Print_Stu_Info(struct stu * stuLinkList)
{
		int i; 
		printf("The following are all students information\n"); 
		printf("ID\tName\t"); 
		for (i = 0; i < STU_COURSE_NUM; i++){
				printf("%s\t", COURSE[i]); 
		}
		printf("\n"); 

		stuLinkList = stuLinkList->next; 
		while (stuLinkList!= NULL){
				printf("%s\t%s\t", stuLinkList->ID, stuLinkList->Name); 
				for (i = 0; i < STU_COURSE_NUM; i++){
						printf("%d\t",stuLinkList->Grade[i]);
				}
				printf("\n"); 
				stuLinkList = stuLinkList->next; 
		}		
}

/*
void Print_Average_Grade(struct stu * stuLinkList)
{
		int i, j, sum; 
		struct stu * pcur; 

		for (i = 0; i < STU_COURSE_NUM - 1; i++){
				sum = 0; 
				pcur = stuLinkList->next; 		
				for (j = 0; j < STU_NUM; j++){
						sum += pcur->Grade[i]; 
						pcur = pcur->next; 
				}
				printf("The %s average grade is %d\n", COURSE[i], sum / STU_NUM); 
		}
}
*/
