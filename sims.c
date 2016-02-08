#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "print.h"

int main(void)
{
	//FILE **user = NULL; 
	//FILE **stu = NULL;

	//System_Initialize(&(*user), &(*stu)); 
	while (1) {
		Print_Sys_Interface(); 
		if (getchar() == 'q')
			break; 
	}

	return 0; 
}
