// Principle of division of array in two parts sorted array and unsorted array
// Complexity O(n^2) (All the cases)
// Advantages
// Only 1 bit extra space is required for storage of temporary varibale(minIndex)
// Works well on small no of elements
// Disadvantages
// Complexity is O(n2) which is very bad for large no of elements

#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    if (minIndex != i)
      swap(&arr[i], &arr[minIndex]);
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
  printf("Array before selection sorting : \n");
  printArr(arr, length);
  selectionSort(arr, length);
  printf("Array after selection sorting : \n");
  printArr(arr, length);
}