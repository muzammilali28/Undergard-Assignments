#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct Inputs{
	
	char *MatchString;
	char check[1000];
	char *compare;
	int row;
	int col;
};

void* checkString(void* input)
{
	struct Inputs *data = (struct Inputs*)input;
	
	if(strcmp(data->MatchString,data->compare) == 0)
	{
		printf("Your String : %s",data->MatchString);
	printf("\nis on Line (%d) and Column (%d)\n",data->row,data->col);
	}
	else
	{
		pthread_exit(NULL);
	}
	
	return (void*)(NULL);
}

int main(int agrv, char **argc)
{
	int N = atoi(argc[2]);
	
	int Matchsize = strlen(argc[3]);
	int SubSsize = 0;
	
	int line=0;
	
	struct Inputs data;
	data.MatchString = (char*)malloc(Matchsize*sizeof(char));
	strcpy(data.MatchString,argc[3]);
	data.row = 1;
	data.col = 1;
	
	char*token;
	
	FILE *fp = fopen(argc[1],"r");
	
	pthread_t thrd1[N];
	
	if(fp == NULL)
	{
		printf("Couldn't Open File!\n");
	}
	else
	{
		while(fgets(data.check,1000,fp))
		{
			line++;
		}
		fclose(fp);
		
		fp = fopen(argc[1],"r");
		
		int j=0;
		for(int i = 0; i < line; i++)
		{
		  fgets(data.check,1000,fp);
		  
		  token = strtok(data.check," ");
			
		  while(j < N)
		  {
		    //printf("Tokened String : %s\n",token);
		    
		    if(token!=NULL)
		    {
		    	SubSsize = strlen(token);
		    	data.compare=(char*)malloc(SubSsize*sizeof(char));
		    	strcpy(data.compare,token);
		    
		    pthread_create(&thrd1[j],NULL,checkString,(void*)&data);
		    	
		    	pthread_join(thrd1[j],NULL);
		    
		    	data.col++;
		    }
		    else
		    {
		    	data.col = 1;
		    	data.row++;
		    	break;
		    }
		    
		    token = strtok(NULL," ");
		    
		    j++;
		    if(j == N)
		    {
		    	j=0; //incase if the threads are lesser than the words in the paragraph
		    }
		  }
		}
		
		fclose(fp);
	}
	
	pthread_exit(NULL);
}
