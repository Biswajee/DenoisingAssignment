#include <stdio.h> 
#include <stdlib.h>

int main() 
{ 
	FILE *fptr1, *fptr2; 
	char c; 

	fptr1 = fopen("feep.pgm", "r"); 
	if (fptr1 == NULL) 
	{ 
		printf("Cannot open file\n"); 
		exit(0); 
	} 

	fptr2 = fopen("processed.pgm", "w"); 
	if (fptr2 == NULL) 
	{ 
		printf("Cannot open file\n"); 
		exit(0); 
	} 

	c = fgetc(fptr1); 
	while (c != EOF) 
	{ 
		fputc(c, fptr2); 
		c = fgetc(fptr1); 
	} 

	printf("\nContents copied"); 

	fclose(fptr1); 
	fclose(fptr2); 
	return 0; 
}

