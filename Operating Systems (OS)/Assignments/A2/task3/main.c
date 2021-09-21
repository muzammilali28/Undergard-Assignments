#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define BSIZE 10

typedef struct{
    int buffer[BSIZE];
    int occupied;
    int nextin;
    int nextout;
    pthread_mutex_t mutex;
    sem_t empty;
    sem_t full;
}buffer_t;

buffer_t buffer;
int data = 1;

void* Producer(void* obj)
{
    buffer_t *buff = (buffer_t*)obj;

    sem_wait(&buff->empty);
    pthread_mutex_lock(&buff->mutex);
        
    if(buff->occupied == BSIZE)
    {
        printf("Buffer is Full !!!\n");
    }
    else
    {
        buff->buffer[buff->nextin] = data;
        printf("Produced = %d\n", data);
        data++;
        buff->nextin = (buff->nextin + 1) % BSIZE;
        buff->occupied++;
        usleep(1*1000*1000);
    }

    pthread_mutex_unlock(&buff->mutex);
    sem_post(&buff->full);
    
    pthread_exit(0);

    return (void*)(NULL);
}
void* Consumer(void* obj)
{
    buffer_t *buff = (buffer_t*)obj;

    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    sem_wait(&buff->full);
    pthread_mutex_lock(&buff->mutex);
        
    if(buff->occupied == 0)
    {
        printf("Buffer is Empty !!!\n");
    }
    else
    {
        printf("Consumed = %d\n",buff->buffer[buff->nextout]);
        buff->nextout = (buff->nextout + 1) % BSIZE;
        buff->occupied--;
        usleep(1*1000*1000);
    }
    
    pthread_mutex_unlock(&buff->mutex);
    sem_post(&buff->empty);
    
    pthread_exit(0);

    return (void*)(NULL);
}

int main()
{
    pthread_mutex_init(&buffer.mutex, NULL);
    sem_init(&buffer.empty, 0, 10);
    sem_init(&buffer.full, 0, 0);
    buffer.occupied = 0;
    buffer.nextin = 0;
    buffer.nextout = 0;

    pthread_t produce;
    pthread_t consume;
    
    for(int i = 0; i < BSIZE; i++)
    {
    	pthread_create(&consume, NULL, &Consumer, (void*)&buffer);
    	pthread_create(&produce, NULL, &Producer, (void*)&buffer);

    	pthread_join(produce, NULL);
    	pthread_join(consume, NULL);
    }

    return 0;
}
