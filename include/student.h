#define STU_NAME_LEN 17
#define STU_ID_LEN 13
#define MarkType int  
#define STU_COURSE_NUM 4

struct stu {
	char ID[STU_ID_LEN]; 
	char Name[STU_NAME_LEN]; 
	MarkType Grade[STU_COURSE_NUM]; 
	struct stu * next; 
}; 
