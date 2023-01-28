#include <stdio.h>

int main()
{
    int n, m, top = 0;
    printf("Enter Rows and Columns of the Sparse Matrix: ");
    scanf("%d %d", &n, &m);
    int sparseMatrix[n][m];
    int nonZeroElement[n * m];

    printf("Enter Elements of the Sparse Matix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Elements of Row %d: ", i + 1);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &sparseMatrix[i][j]);
            if (sparseMatrix[i][j])
            {
                nonZeroElement[top] = sparseMatrix[i][j];
                top++;
            }
        }
    }

    printf("The Non-zero elements in the sparse matrix:\n");
    for (int i = 0; i < top; i++)
    {
        printf("%d \t", nonZeroElement[i]);
    }
    return 0;
}