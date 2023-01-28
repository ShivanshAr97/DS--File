#include <stdio.h>

void singleSource(int distance[], int sourceVertex, int noVertex)
{
  for (int i = 0; i < noVertex; i++)
  {
    if (i == sourceVertex)
      distance[i] = 0;
    else
      distance[i] = -1;
  }
}

int extractMin(int distance[], int relaxedVertex[], int noVertex)
{
  int min_vertex;
  for (int i = 0; i < 5; i++)
    if (!relaxedVertex[i])
    {
      min_vertex = i;
      break;
    }

  for (int i = 0; i < noVertex; i++)
  {
    if (distance[i] == -1 || relaxedVertex[i])
      continue;
    else
    {
      if (distance[i] < distance[min_vertex])
        min_vertex = i;
    }
  }

  return min_vertex;
}

int main()
{
  int graph[5][5] = {{0, 10, 5, -1, -1}, {-1, 0, 2, 1, -1}, {-1, 3, 0, 9, 2}, {-1, -1, -1, 0, 4}, {-1, -1, -1, 6, 0}};
  int distances[5] = {0};
  int relaxedVertex[5] = {0};
  singleSource(distances, 0, 5);
  for (int j = 0; j < 5; j++)
  {
    int minVertex = extractMin(distances, relaxedVertex, 5);
    relaxedVertex[minVertex] = 1;
    printf("Relaxed vertex %d :  ", j);
    for (int i = 0; i < 5; i++)
    {
      if (relaxedVertex[i] == 1)
        continue;

      if (graph[minVertex][i] != -1)
      {
        if (distances[i] == -1)
          distances[i] = graph[minVertex][i] + distances[minVertex];

        else
        {
          if (distances[minVertex] + graph[minVertex][i] < distances[i])
            distances[i] = distances[minVertex] + graph[minVertex][i];
        }
      }
    }
    for (int i = 0; i < 5; i++)
      printf("%d\t", distances[i]);

    printf("\n");
  }

  return 0;
}