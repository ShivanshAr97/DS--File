// Principle of taking the key out and placing it at correct place before it
// Complexity O(n) (Best Case)
// O(n^2) (Worst and average case)

// Auxillary Space 1 bit(for key variable)
// Advantages
// List is partially sorted
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

void insertionSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    for (; j >= 0 && key < arr[j]; j--)
    {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = key;
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
  printf("Array before insertion sorting : \n");
  printArr(arr, length);
  insertionSort(arr, length);
  printf("Array after insertion sorting : \n");
  printArr(arr, length);
}