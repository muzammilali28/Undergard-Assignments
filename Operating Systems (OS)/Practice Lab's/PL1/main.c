#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define READ 0
#define WRITE 1

int main(int argc , char ** argv)
{
	pid_t pid;
	
	int fd1[2];
	int fd2[2];
	int fd3[2];
	int fd4[2];
	
	int size= argc - 1;
	
	int * array = (int*)malloc(size * sizeof(int));
	
	for(int i = 0; i < size; i++)
	{
		array[i] = atoi(argv[i+1]);
	}
	
	int tempArr[size];
	int tempArr2[size];
	int sum,SUM;
	int min,MINIMUM;
	
	pipe(fd1);
	pipe(fd2);
	
	pid = fork();
	
	if(pid > 0)
	{	
		//Writing Array to Child1 via FD1(pipe)
		close(fd1[READ]);
		
		write(fd1[WRITE],array,size*4);
		
		close(fd1[WRITE]);
		
		wait(NULL);
		
		//Reading the Sum from Child1 via FD2(pipe)
		close(fd2[WRITE]);
		
		read(fd2[READ],&SUM,4);
		
		printf("\nThe Sum is : %d\n",SUM);
		
		close(fd2[READ]);
		
		pipe(fd3);
		pipe(fd4);
		
		pid = fork();
		
		if(pid > 0)
		{
			//Writing Array to Child2 via FD3(pipe)
			close(fd3[READ]);
		
			write(fd3[WRITE],array,size*4);
		
			close(fd3[WRITE]);
			
			wait(NULL);
			
			//Reading the Min from Child2 via FD4(pipe)
			close(fd4[WRITE]);
		
			read(fd4[READ],&MINIMUM,4);
		
			printf("\nThe MIN number is : %d\n",MINIMUM);
		
			close(fd4[READ]);
		}
		else if(pid == 0)
		{
			//Read Array from Parent in Child2 FD3(pipe)
			close(fd3[WRITE]);
		
			read(fd3[READ],tempArr2,size*4);
			
			min = tempArr2[0];
			
			for(int i=1; i<size; i++)
			{
				if(tempArr2[i] < min)
				{
					min = tempArr2[i];
				}
			}
		
			close(fd3[READ]);
			
			//Write Min back to Parent via Child2 FD4(pipe)
			close(fd4[READ]);
		
			write(fd4[WRITE],&min,4);
		
			close(fd4[WRITE]);
		}
	}
	else if(pid == 0)
	{		
		//Read Array from Parent in Child1 FD1(pipe)
		close(fd1[WRITE]);
		
		read(fd1[READ],tempArr,size*4);
		
		printf("Array Revieced : ");
		for(int i=0; i<size; i++)
		{
			sum=sum+tempArr[i];
			printf("%d ",tempArr[i]);
		}
		
		close(fd1[READ]);
		
		//Write Sum back to Parent via Child1 FD2(pipe)
		close(fd2[READ]);
		
		write(fd2[WRITE],&sum,4);
		
		close(fd2[WRITE]);
	}
}
