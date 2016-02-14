#define STU_ID_LEN 12
#define MAX_STU_ID_LEN STU_ID_LEN + 2 
#define STU_NAME_LEN 16 
#define MAX_STU_NAME_LEN STU_NAME_LEN + 2 
#define MarkType int  
#define STU_COURSE_NUM 3 

struct stu {
	char ID[MAX_STU_ID_LEN]; 
	char Name[MAX_STU_NAME_LEN]; 
	MarkType Grade[STU_COURSE_NUM]; 
	struct stu * next; 
}; 
