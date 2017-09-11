#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int size=1024;
	char* buff = (char*)malloc(size);
	
	//read lines
	while(gets(buff) != NULL){
		printf("Read line with len: %d\n", strlen(buff));  
        printf("%s", buff);  
	}
	
	// Õ∑≈buff 
	free buff; 

	return 0;
}
