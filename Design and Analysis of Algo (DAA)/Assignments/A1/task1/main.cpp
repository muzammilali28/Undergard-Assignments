int BinarySearch(int A[], int key)
{
    int start = 1, end = 1, middle;
    while (A[end] < key)
    {
        if (A[end] == key)
        {
            return end;
        }
        end = end * 2;
    }
    start = end / 2;
    while (A[end] >= 1000)
    {
        middle = start + (end - start) / 2;
        if (A[middle] < 1000 && A[middle] > A[start])
        {
            end = middle;
        }
        else if (A[middle] > A[start])
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    start = 1;
    while (start <= end)
    {
        middle = start + (end - start) / 2;
        if (A[middle] == key)
        {
            return middle;
        }
        else if (A[middle] > key)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    return -1;
}
