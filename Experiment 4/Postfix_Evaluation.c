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

    int expression[n];
    for (int i = 0; i < n; i++)
    {
        if (test[i] >= '0' && test[i] <= '9')
        {
            topExpr++;
            int temp = test[i] - 48;
            expression[topExpr] = temp;
        }
        else
        {
            if (test[i] == '+')
            {
                expression[topExpr - 1] = expression[topExpr - 1] + expression[topExpr];
            }
            else if (test[i] == '-')
            {
                expression[topExpr - 1] = expression[topExpr - 1] - expression[topExpr];
            }
            else if (test[i] == '/')
            {
                expression[topExpr - 1] = expression[topExpr - 1] / expression[topExpr];
            }
            else if (test[i] == '*')
            {
                expression[topExpr - 1] = expression[topExpr - 1] * expression[topExpr];
            }
            else
            {
                expression[topExpr - 1] = pow(expression[topExpr - 1], expression[topExpr]);
            }

            topExpr--;
        }
    }
    printf("%d", expression[topExpr]);

    return 0;
}