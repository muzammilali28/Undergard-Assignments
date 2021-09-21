#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 16

int mainArr[SIZE] = {7, 12, 19, 3, 18, 16, 4, 2, 6, 9, 18, 38, 15, 8, 123, 72};
int mergeArr[SIZE] = {0};

int Partition(int *arr, int lowerb, int upperb)
{
    int temp = 0;
    int Pivot = arr[lowerb];
    int start = lowerb;
    int end = upperb;

    while(start < end)
    {
        while(arr[start] <= Pivot)
        {
            start++;
        }
        while(arr[end] > Pivot)
        {
            end--;
        }

        if(start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    
    temp = arr[lowerb];
    arr[lowerb] = arr[end];
    arr[end] = temp;

    return end;
}

void QuickSort(int *arr, int lowerb, int upperb)
{
    if(lowerb < upperb)
    {
        int NewStart = Partition(arr, lowerb, upperb);
        QuickSort(arr, lowerb, NewStart-1);
        QuickSort(arr, NewStart+1, upperb);
    }
}

void* SortLeftHalf(void* ptr)
{
    //Fetch the Array
    int *arr = (int*)ptr;

    //Sort the Array Left Side (0 , 7)
    QuickSort(arr, 0, (SIZE/2)-1);
    
    printf("Sorted Left Half : ");
    for(int i = 0; i < SIZE/2; i++)
    {
        printf("%d ",arr[i]);
    }

    pthread_exit(0);

    return (void*)(NULL);
}
void* SortRightHalf(void* ptr)
{
    //Fetch the Array
    int *arr = (int*)ptr;

    //Sort the Array Right Side (8 , 15)
    QuickSort(arr, SIZE/2, SIZE-2);
    
    printf("\nSorted Right Half : ");
    for(int i = SIZE/2; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    pthread_exit(0);

    return (void*)(NULL);
}
void* MergeAllSort(void* ptr)
{
    //Fetch The Array
    int *tempArr = (int*)ptr;

    //Merge (0 , 7) SubArray
    for(int i = 0; i < SIZE/2; i++)
    {
        mergeArr[i] = tempArr[i];
    }
    //Merge (8 , 15) SubArray
    for(int j = SIZE/2; j < SIZE; j++)
    {
        mergeArr[j] = tempArr[j];
    }

    //Sort the Merged Array (0 , 15)
    QuickSort(mergeArr, 0, SIZE-2);

    printf("\nMerge Array : ");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ",mergeArr[i]);
    }
    printf("\n");
    
    pthread_exit(0);

    return (void*)(NULL);
}

int main()
{
    pthread_t T0;
    pthread_t T1;
    pthread_t merge;
    
    printf("Main Array : ");
    for(int i = 0; i < SIZE; i++)
    {
    	printf("%d ",mainArr[i]);
    }
    printf("\n\n");

    pthread_create(&merge, NULL, &MergeAllSort, (void*)mainArr);
    pthread_create(&T1, NULL, &SortRightHalf, (void*)mainArr);
    pthread_create(&T0, NULL, &SortLeftHalf, (void*)mainArr);

    pthread_join(T0, NULL);
    pthread_join(T1, NULL);
    pthread_join(merge, NULL);

    return 0;
}
