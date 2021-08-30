void find_value_count(int A[],int N)
{
    int Rli = 0;
    int Rri = N-1;
    int Lli = 0;
    int Lri = N-1;

    int right = -1;
    int left = N;

    int mid = 0;

    int value1 = A[0];
    int value2 = A[N-1];
    int midVal = 0;

    while(Rli < Rri)
    {
        mid = (Rli + Rri)/2;

        if(A[mid] != value1 && A[mid] != value2)
        {
            midVal = A[mid];
            
            if(mid > right)
            {
                right = mid;
            }

            if(A[Rri - 1] == midVal)
            {
                Rli = mid + 1;
            }
            else
            {
                Rli = mid;
            }
        }
        else if(A[mid] == value1)
        {
            Rli = mid;
        }
        else if(A[mid] == value2)
        {
            Rri = mid;
        }
    }

    Lli = 0;
    Lri = N-1;

    while(Lri > Lli)
    {
        mid = (Lli + Lri)/2;

        if(A[mid] == midVal)
        {
            if(mid < left)
            {
                left = mid;
            }

            if(A[Lli + 1] == midVal)
            {
                Lri = mid - 1;
            }
            else
            {
                Lri = mid;
            }
        }
        else if(A[mid] == value1)
        {
            Lli = mid;
        }
        else if (A[mid] == value2)
        {
            Lri = mid;
        }

        if(Lli == Lri-1)
        {
            break;
        }
    }

    cout<<"Mid Value : "<<midVal<<endl;
    cout<<"Its Count is : "<<((right - left) + 1)<<endl;

}
