#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <wait.h>
#include <semaphore.h>

#define Num_Sellers 4

int numTickets = 30;
sem_t lock;
int selling = 1;

void* SellTickets(void* ptr)
{
    long i = (long)ptr;

    while(selling == 1)
    {
        //entry section
        printf("Seller Num : %ld -> ", i+1);
        
        usleep(0.7*1000*1000); //To see the changes of remaining threads

        //Critical Section Entry
        sem_wait(&lock); //enter critical section

        if(numTickets == 0)
        {
            selling = 0;
        }
        else
        {
            numTickets--;
            printf("has sold a ticket (%d left)\n",numTickets);
        }
        
        //exit section
        sem_post(&lock);
    }
    
    printf("OUT OF TICKETS (SOLD OUT)!!!!\n");

    pthread_exit(0);

    return (void*)(NULL);
}

int main()
{
    //Initalize our Lock
    sem_init(&lock, 0, 1);

    pthread_t sellers[Num_Sellers];

    //Creating Threads for the Sellers
    for(long i = 0; i < Num_Sellers; i++)
    {
        pthread_create(&sellers[i], NULL, &SellTickets, (void*)i);
    }

    //Waiting for the Sellers to Finish their Job!
    for(int j = 0; j < Num_Sellers; j++)
    {
        pthread_join(sellers[j], NULL);
    }

    printf("\n\nAll Tickets Sold Out!\n");

    return 0;
}
