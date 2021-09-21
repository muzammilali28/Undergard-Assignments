#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define Num_threads 4

struct Data
{
    int SearchNum;
    int fileNum;
    int found;
};

void* SearchElement(void* Searching)
{
    struct Data *data = (struct Data*)Searching;

    if(data->fileNum == data->SearchNum)
    {
        data->found = 1;
    }

    pthread_exit(0);

    return (void*)(NULL);
}

int main()
{
    int values = 0;
    int num = 0;
    pthread_t threads[Num_threads];

    struct Data obj;
    obj.SearchNum = 20;
    obj.found = 0;

    FILE *fp = fopen("input.txt","r");
    
    if(fp == NULL)
    {
        printf("Couldn't Open the File!\n");
    }
    else
    {
        while(!feof(fp))
    	{
    		fscanf(fp,"%d",&num);
        	values++;
    	}
    	values--;
    	
    	printf("Integers in File : %d\n\n",values);
    	
        fclose(fp);

        FILE *fp = fopen("input.txt","r");

        int j = 0;
        for(int i = 0; i < values; i++)
        {
            fscanf(fp,"%d",&num);
            
            obj.fileNum = num;
            
            printf("%d ",obj.fileNum);
            
            if(j == Num_threads) //We need to search the numbers in only 4 threads so loop back to 0 thread if number not found!
            {
                j = 0;
            }
            else
            {
                pthread_create(&threads[j], NULL, &SearchElement, (void*)&obj);
                pthread_join(threads[j], NULL);
                j++;
            }
        }

        fclose(fp);

        if(obj.found == 1)
        {
            printf("\n\nKey Element (%d) Found!\n",obj.SearchNum);
        }
        else
        {
            printf("\n\nKey (%d) NOT FOUND!\n",obj.SearchNum);
        }
    }

    pthread_exit(0);

    return 0;
}
