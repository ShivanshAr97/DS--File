#include <stdio.h>
#define length 9
int hash[length];

void initialiseHash()
{
  for (int i = 0; i < length; i++)
    hash[i] = -1;
}

void insertHashValue(int value)
{
  int position = value % length;
  if (hash[position] != -1)
    printf("Unable to add value in hash table as collision occurs!!!!\n");
  else
  {
    hash[position] = value;
    printf("Successfully added %d in hash table\n", value);
  }
}

void deleteHashValue(int value)
{
  int position = value % length;
  if (hash[position] != -1)
  {
    hash[position] = -1;
    printf("Successfully deleted %d from hash table\n", value);
  }
  else

    printf("No such value exist in hash table!!!!!\n");
}

void searchHash(int value)
{
  int position = value % length;
  if (hash[position] != -1)
  {
    printf("%d is found in hash table with key %d\n", value, position);
  }
  else
  {
    printf("%d is not found in hash table\n", value);
  }
}

void traverse()
{
  printf("The hash table is : \n");
  for (int i = 0; i < length; i++)
  {
    if (hash[i] != -1)
    {
      printf("hash[%d]=%d\n", i, hash[i]);
    }
  }
}

int main()
{
  initialiseHash();
  insertHashValue(2);
  insertHashValue(4);
  insertHashValue(9);
  insertHashValue(5);
  insertHashValue(18);
  insertHashValue(8);
  traverse();
  deleteHashValue(5);
  printf("Hash table after deleting element\n");
  traverse();
  searchHash(11);
}