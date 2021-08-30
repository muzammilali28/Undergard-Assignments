void MergeArray(int A[],int sizeA,int B[],int sizeB,int C[],int sizeC)
{
    int a = 0, b = 0, c = 0, check1 = -1, tempA = 0, tempB = 0;
    int checkA = 0;
    bool flag = false;

    while (a < sizeA && b < sizeB)
    {
        if (A[a] == B[b])
        {
            flag = 0;

            while ((a < sizeA - 1 && A[a] == A[a + 1] && A[a] == B[b]) || (b < sizeB - 1 && B[b] == B[b + 1] && A[a] == A[a]))
            {
                if (A[a] == A[a + 1] && A[a] == B[b])
                {
                    if(check == -1)
                    {
                        tempB = b;
                        checkA = a;
                    }
                    check1 = 1;
                    a++;
                }
                
                if ((B[b] == B[b + 1]) && (B[b] == A[a]))
                {
                    if ((check1 == -1 || check1 == 1) && (flag == 0))
                    {
                        if(checkA == a - 1)
                        {
                            tempA = checkA;
                        }
                        else
                        {
                            tempA = a;
                        }

                        flag = 1;
                    }
                    check1 = 0;
                    b++;
                }
            }
            if (check1 == 1)
            {
                while (tempB <= b)
                {
                    C[c++] = B[tempB++];
                }
                b++;
            }
            else if (check1 == 0)
            {
                while(tempA <= a)
                {
                    C[c++] = B[tempA++];
                }
                a++;
            }
            
            if (check1 == -1)
            {
                if ((a < sizeA && A[a] == A[a - 1]) && (b < sizeB && B[b] == B[b - 1]))
                {
                    C[c++] = A[a++];
                }
                else
                {
                    C[c++] = A[a++];
                    C[c++] = B[b++];
                }
            }

            check1 = -1;
        }
        else
        {
            if (A[a] < B[b])
            {
                a++;
            }
            else
            {
                b++;
            }
        }
    }

    //Display Array
    cout << "\nArrayC[" << c << "] = {";
    for (int i = 0; i < c - 1; i++)
    {
        cout << C[i] << ",";
    }
    cout << C[c - 1] << "}\n";

    return;
}
