void find_values(int A[],int N)
{
    //No restriction on using a Temp Array!

    int C[4]={0};
    int c=0;

    int prevVal = A[0];
    
    C[c++] = A[0];

    for(int i=1; i < N; i++)
    {
        if(A[i] != prevVal)
        {
            C[c++] = A[i];
            prevVal = A[i];
        }
    }

    cout<<"Values are : ";
    for(int i=0; i<c; i++)
    {
        cout<<C[i]<<" ";
    }
}
