#include <stdio.h>

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d\t ", A[i]);
  }
  printf("\n");
}

int partition(int A[], int low, int high)
{
  int pivot = A[low];
  int i = low + 1;
  int j = high;
  int temp;
  do
  {
    while (A[i] <= pivot)
    {
      i++;
    }
    while (A[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  } while (i < j);
  temp = A[low];
  A[low] = A[j];
  A[j] = temp;
  return j;
}

void quickSort(int A[], int low, int high)
{
  int partitionIndex;
  if (low < high)
  {
    partitionIndex = partition(A, low, high);
    quickSort(A, low, partitionIndex - 1);
    quickSort(A, partitionIndex + 1, high);
  }
}

int main()
{
  int arr[] = {6, 2, 7, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Array before quick sort\n");
  printArray(arr, n);
  quickSort(arr, 0, n - 1);
  printf("Array after quick sort\n");
  printArray(arr, n);
  return 0;
}