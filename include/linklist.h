void Init_Stu_Link_List(struct stu **); 
void Init_User_Link_List(struct user **); 

void Print_All_Stu_Info(struct stu *); 
void Print_All_User_Info(struct user *); 

void Add_One_Stu_Info(struct stu **); 
void Add_One_User_Info(struct user **); 

void Del_One_Stu_Info(struct stu **, char *); 
void Del_One_User_Info(struct user **, char *); 

void Modify_One_Stu_Info(struct stu **, char *); 
void Modify_One_User_Info(struct user **, char *); 

void Print_Single_Mark_highest_Stu_Info(struct stu *); 

void Stu_Link_List_Destroy(struct stu **); 
void User_Link_List_Destroy(struct user **); 
