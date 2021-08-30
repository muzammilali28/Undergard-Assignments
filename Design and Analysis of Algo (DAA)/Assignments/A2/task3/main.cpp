void sort_values(int A[],int N)
{
    //Insertion Sort Algorithm

    int temp=0;
    int j=0;

    for(int i=1; i<N; i++)
    {
        temp = A[i];
        j=i-1;

        while(j >= 0 && A[j] > temp)
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = temp;
    }

    cout<<"Array Sorted : ";
    for(int i=0; i<N; i++)
    {
        cout<<A[i]<<" ";
    }
}
