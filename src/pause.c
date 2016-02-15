#include <stdio.h>
#include <getch.h>

void System_Pause(void)
{
	getchar(); 
	printf("\nPress any key to continue:"); 
	getch(); 
}
