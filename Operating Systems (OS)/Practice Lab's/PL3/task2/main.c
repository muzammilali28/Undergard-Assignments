#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

//gcc main.c -o main.out -lm -lpthread -Wall -Werror

void* Pi(void* threads)
{
	long n = (long)threads;
	
	double sum = 0;
	double firstPart;
	double secondPart;
	double result;
	
	for(int i=0; i<=n; i++)
	{	
		//(-1)^n
		firstPart = pow((double)-1,(double)i);
	
		//x^(2n+1)
		//--------
		//  2n+1
		secondPart = pow((double)1,(double)((2*i)+1))/((2*i)+1);
	
		result = firstPart * secondPart;
		
		printf("Result : %lf\n",result);
	
		sum = sum + result;
	}
	
	sum = 4 * sum; //4*[1 - 1/3 + 1/5 - 1/7 + 1/9 - . . . ] 
	
	printf("Pi : %lf\n",sum);
	
	return (void*)(NULL);
}

int main()
{
	pthread_t thrd1;
	
	long N = 1000;
	void*result;
	
	pthread_create(&thrd1,NULL,&Pi,(void*)N);
	pthread_join(thrd1,&result);
	
	pthread_exit(NULL);
}
