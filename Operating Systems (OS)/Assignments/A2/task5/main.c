#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int numHydrogen = 0;
int numOxygen = 0;

sem_t BothydrogenAvail;
sem_t oxygenAvail;

void* Hydrogen_Available(void* ptr)
{
    //Entry Section
    numHydrogen++;

    if((numHydrogen % 2) == 0 && (numOxygen % 1) == 0)
    {
        sem_post(&BothydrogenAvail);
        printf("Both Hydrgen Atoms are Avaiable!!\n");
    }
    
    sem_wait(&oxygenAvail);
    printf("Hydrogen : Water is Made , Now I am free\n");

    numHydrogen--;

    pthread_exit(0);

    return (void*)(NULL);
}
void* Oxygen_Available(void* ptr)
{
    //Entry Section
    numOxygen++;
    
    sem_wait(&BothydrogenAvail);
    printf("Oxygen : I have both Hydrogen Atoms Available Now!\n");
    
    printf("Processing Water Making!!!\n");
    printf("WATER MADE!!\n");

    sem_post(&oxygenAvail);
    printf("Oxygen : Hydrogen Atom 1 you are free to go!\n");
    sem_post(&oxygenAvail);
    printf("Oxygen : Hydrogen Atom 2 you are free to go!\n");

    numOxygen--;

    pthread_exit(0);

    return (void*)(NULL);
}

int main()
{
    //Initalize Semaphore counters with values.
    sem_init(&BothydrogenAvail, 0, 0);
    sem_init(&oxygenAvail, 0, 0);

    pthread_t oxy;
    pthread_t h1;
    pthread_t h2;

    //Creating Threads
    pthread_create(&oxy, NULL, &Oxygen_Available, NULL);
    pthread_create(&h1, NULL, &Hydrogen_Available, NULL);
    pthread_create(&h2, NULL, &Hydrogen_Available, NULL);

    //wait for the threads to finish!
    pthread_join(h2, NULL);
    pthread_join(h1, NULL);
    pthread_join(oxy, NULL);

    return 0;
}
