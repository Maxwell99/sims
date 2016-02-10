#define ID_LEN 13
#define KEY_LEN 21

struct user {
	char ID[ID_LEN]; 
	char KEY[KEY_LEN]; 
	struct user *next; 
}; 
