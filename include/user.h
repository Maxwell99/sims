#define ID_LEN	12 
#define KEY_LEN 20 
#define ID_MAX_LEN ID_LEN + 2
#define KEY_MAX_LEN KEY_LEN + 2

struct user {
	char ID[ID_LEN]; 
	char KEY[KEY_LEN]; 
	struct user *next; 
}; 
