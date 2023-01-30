#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the length of the expression : ");
    scanf("%d", &n);
    char test[n];
    printf("Enter the infix expression : ");
    scanf("%s", test);
    int topExpr = -1;
    char expression[n];
    char stack[n / 2];
    int topStack = -1;
    for (int i = 0; i < n; i++)
    {
        if ((test[i] >= 'a' && test[i] <= 'z') || (test[i] >= 'A' && test[i] <= 'Z'))
        {
            topExpr++;
            expression[topExpr] = test[i];
        }
        else if (test[i] == '(')
        {
            topStack++;
            stack[topStack] = '(';
        }
        else if (test[i] == ')')
        {
            while (stack[topStack] != '(')
            {
                topExpr++;
                expression[topExpr] = stack[topStack];
                topStack--;
            }
            topStack--;
        }
        else
        {
            if (test[i] == '+' || test[i] == '-')
            {
                while (stack[topStack] != '(')
                {
                    topExpr++;
                    expression[topExpr] = stack[topStack];
                    topStack--;
                }
                topStack++;
                stack[topStack] = test[i];
            }
            else if (test[i] == '*' || test[i] == '/')
            {
                while (stack[topStack] == '^')
                {
                    topExpr++;
                    expression[topExpr] = stack[topStack];
                    topStack--;
                }
                topStack++;
                stack[topStack] = test[i];
            }
            else
            {
                topStack++;
                stack[topStack] = test[i];
            }
        }
    }
    for (int i = 0; i <= topExpr; i++)
    {
        printf("%c", expression[i]);
    }

    return 0;
}