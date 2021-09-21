#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Fun2(char *input)
{
	printf("I am the Actual function for Output\nProcessing Your Answer..\n");
	
	printf("The Char Input is : %c\n",*(input));
	
	return;
}

void Fun1(void (*f)(char*) , char *character)
{
	printf("I am Function-1 holding the Function Argument and Character Pointer\n");
	
	f(&(*character));
	
	return;	
}

int main()
{
	void (*f)(char*)=Fun2;
	char character = 'A';
	
	Fun1((*f),&character);
	
	return 0;
}
