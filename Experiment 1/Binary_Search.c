#include <stdio.h>

int binarySearch(int arr[], int n, int element)
{
    int mid, start = 0, end = n - 1;

    mid = (start + end) / 2;
    while (start <= end)
    {

        if (arr[mid] > element)
        {

            end = mid - 1;
        }
        else if (arr[mid] < element)
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
        mid = (start + end) / 2;
    }

    return -1;
}

void printOutput(int returnValue, int element)
{
    if (returnValue == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("%d found at index %d", element, returnValue);
    }
}

int main()
{
    int n, element;
    printf("Size of the array:");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched : ");
    scanf("%d", &element);

    int output = binarySearch(arr, n, element);
    printOutput(output, element);

    return 0;
}
