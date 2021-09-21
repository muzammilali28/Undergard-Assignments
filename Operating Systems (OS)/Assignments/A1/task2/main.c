#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void *add(void*,void*);

int main(int argc ,char **argv)
{
	int value1 = atoi(argv[1]);
	int value2 = atoi(argv[2]);
	
	void *a = &value1;
	void *b = &value2;
	
	void *result = add(a,b);
	
	printf("Sum is %d\n\n",*(int*)result);
	
	return 0;
}

void *add(void *a , void *b)
{	
	int *total = (int*)malloc(1*sizeof(int));
	
	*total = *(int*)a + *(int*)b;
	
	void * answer = &(*total);
	
	printf("Num-1 = %d and Num-2 = %d\n",*(int*)a,*(int*)b);
	
	return answer;
}
