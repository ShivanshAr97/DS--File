#include <stdio.h>
int vertices;

void bfs(int source, int dest, int graph[vertices][vertices])
{
    int queue[9] = {0};
    int origin[9] = {0};
    origin[source] = -1;
    queue[source] = 1;
    int tempQueue[9];
    tempQueue[0] = source;
    int temp = 0;
    int top = 0;
    while (temp != -1)
    {
        for (int i = 0; i < 9; i++)
        {
            if (graph[tempQueue[temp]][i] == 1 && queue[i] == 0)
            {
                top++;
                queue[i] = 1;
                origin[i] = tempQueue[temp];

                tempQueue[top] = i;
                if (i == dest)
                    temp = -2;
            }
        }
        ++temp;
    }
    printf("BFS Path : %d", dest);
    temp = origin[dest];
    while (temp != -1)
    {
        printf("\t%d", temp);
        temp = origin[temp];
    }
    printf("\n");
}

void dfs(int source, int dest, int graph[vertices][vertices])
{
    int stack[9] = {0};
    int origin[9] = {
        0};
    origin[source] = -1;
    stack[source] = 1;
    int tempStack[9];
    int top = -1;
    int temp = source;
    while (top != -2)
    {
        for (int i = 0; i < 9; i++)
        {
            if (graph[temp][i] == 1 && stack[i] == 0)
            {
                top++;
                tempStack[top] = i;
                stack[i] = 1;
                origin[i] = temp;
                if (i == dest)
                {

                    top = -1;
                }
            }
        }
        temp = tempStack[top];
        top--;
    }
    printf("DFS path : %d", dest);
    temp = origin[dest];
    while (temp != -1)
    {
        printf("\t%d", temp);
        temp = origin[temp];
    }
}

void main()
{
    printf("Enter the no of vertices : ");
    scanf("%d", &vertices);
    int graph[vertices][vertices];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            graph[i][j] = -1;
        graph[i][i] = 0;
        int no;
        printf("Enter the no of vertices %d vertice connect : ", i);
        scanf("%d", &no);
        printf("Enter the vertice : ");
        for (int j = 0; j < no; j++)
        {
            int data;
            scanf("%d", &data);
            graph[i][data] = 1;
        }
    }
    bfs(0, 8, graph);
    dfs(0, 8, graph);
}