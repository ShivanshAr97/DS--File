// Works on principle - in each pass put the biggest element at the end of the list
// Complexity Best Case O(N)
// Worst Case and average case O(N^2)
// Advantages
// Works well on partially sorted array

#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int swapOccured = 0;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swapOccured = 1;
        swap(&arr[j], &arr[j + 1]);
      }
    }
    if (!swapOccured)
      return;
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
  printf("Array before bubble sorting : \n");
  printArr(arr, length);
  bubbleSort(arr, length);
  printf("Array after bubble sorting : \n");
  printArr(arr, length);
}