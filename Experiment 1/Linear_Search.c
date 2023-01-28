#include <stdio.h>

int linearSearch(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
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

    printf("\nEnter the element to be searched : ");
    scanf("%d", &element);

    int output = linearSearch(arr, n, element);
    printOutput(output, element);

    return 0;
}
