// Based on divide and conquer method
// Complexity O(n*logn)(All Cases)
// Space requirment O(n);
// Large data
// External sorting
//

#include <stdio.h>

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (int i = 0; i < n2; i++)
    {
        M[i] = arr[q + 1 + i];
    }
    int i, j, k;
    i = j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] < M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {6, 2, 7, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("Array before merge sorting : \n");
    printArr(arr, length);
    mergeSort(arr, 0, length - 1);
    printf("Array after merge sorting : \n");
    printArr(arr, length);
    return 0;
}