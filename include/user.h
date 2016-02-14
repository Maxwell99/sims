#define ID_LEN	12 
#define NAME_LEN 16
#define KEY_LEN 20 

struct user {
	char ID[ID_LEN]; 
	char Name[NAME_LEN]; 
	char Key[KEY_LEN]; 
	int Level; 
	struct user *next; 
}; 
