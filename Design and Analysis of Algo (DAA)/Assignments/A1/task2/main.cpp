void MergeArray(int A[], int sizeA, int B[], int sizeB, int C[])
{
    int a = 0, b = 0, c = 0;
    while (a < sizeA && b < sizeB)
    {
        if (A[a] == B[b])
        {
            while (a < sizeA && A[a] == B[b])
            {
                a++;
            }
            while (b < sizeB && B[b] == A[a - 1])
            {
                b++;
            }
        }
        else
        {
            if (A[a] < B[b])
            {
                if (c > 0 && C[c - 1] != A[a])
                {
                    C[c++] = A[a];
                }
                else if (c == 0)
                {
                    C[c++] = A[a];
                }
                a++;
            }
            else
            {
                if (c > 0 && C[c - 1] != B[b])
                {
                    C[c++] = B[b];
                }
                else if (c == 0)
                {
                    C[c++] = B[b];
                }
                b++;
            }
        }
    }
    while (a < sizeA)
    {
        if(c > 0 && C[c - 1] != A[a])
        {
            C[c++] = A[a];
        }
        a++;
    }
    while (b < sizeB)
    {
        if (c > 0 && C[c - 1] != B[b])
        {
            C[c++] = B[b];
        }
        b++;
    }

    // Display Array
    cout << "\nArrayC[" << c << "] = {";
    for (int i = 0; i < c - 1; i++)
    {
        cout << C[i] << ",";
    }
    cout << C[c - 1] << "}\n";
    
    return;
}
