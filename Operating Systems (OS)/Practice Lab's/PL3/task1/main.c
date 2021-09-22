#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

void* Even(void* Arr)
{
	int* arr = (int*)Arr;
	int size = arr[0];
	
	printf("The even no are ");
	for(int i=1; i<size; i++)
	{
		if(arr[i]%2 == 0)
		{
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
	
	pthread_exit(NULL);
	
	return (void*)(NULL);
}

void* Odd(void* Arr)
{
	int* arr = (int*)Arr;
	int size = arr[0];
	
	printf("The odd no are ");
	for(int i=1; i<size; i++)
	{
		if(arr[i]%2 != 0)
		{
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
	
	pthread_exit(NULL);
	
	return (void*)(NULL);
}

int main(int argv, char ** argc)
{
	const int size = argv;
	
	int arr[size];
	
	arr[0] = size; //sending the Size of array at index 0
	
	for(int i=1; i<size; i++)
	{
		arr[i]= atoi(argc[i]);
	} 
	
	pthread_t pid1;
	pthread_t pid2;
	
	pthread_create(&pid1,NULL,&Even,(void*)arr);
	pthread_create(&pid2,NULL,&Odd,(void*)arr);
	
	pthread_join(pid1,NULL); 
	pthread_join(pid2,NULL);
	
	pthread_exit(NULL); 
}
