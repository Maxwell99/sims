#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "print_ui.h"

int main(void)
{
	FILE **user = NULL; 
	FILE **stu = NULL;

	System_Initialize(&(*user), &(*stu)); 
	Print_Sys_Interface(); 

	return 0; 
}
