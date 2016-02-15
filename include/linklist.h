//link list operation
void Init_Stu_Link_List(struct stu **); 
void Init_User_Link_List(struct user **); 

void Add_One_Stu_Info(struct stu **, struct stu); 
void Add_One_User_Info(struct user **, struct user); 

struct stu Del_One_Stu_Info(struct stu **, char *); 
struct user Del_One_User_Info(struct user **, char *); 

struct stu Modify_One_Stu_Info(struct stu **, char *); 
struct user Modify_One_User_Info(struct user **, char *); 

void Stu_Link_List_Destroy(struct stu **); 
void User_Link_List_Destroy(struct user **); 

//print link list node
void Print_All_Stu_Info(struct stu *); 
void Print_All_User_Info(struct user *); 

void Print_One_Stu_Info(struct stu *, char *); 
void Print_One_User_Info(struct stu *, char *); 

void Print_Single_Mark_highest_Stu_Info(struct stu *); 
