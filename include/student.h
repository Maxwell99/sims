#define STU_NAME_LEN 17
#define STU_ID_LEN 13
#define MarkType float 
#define STU_COURSE_NUM 4

struct stu_tag {
	char name[STU_NAME_LEN]; 
	char ID[STU_ID_LEN]; 
	MarkType mark[STU_COURSE_NUM]; 
	struct stu_tag *next; 
}