#include <stdio.h>

int choice()
{
    int choice;
    printf("Enter the operation you want to perform:\n");
    printf("1.Push\n2.Pop\n3.Traversal\n");
    scanf("%d", &choice);
    return choice;
}

void push(int arr[], int *top, int stack, int element)
{
    if ((stack == 1 && *top == 4) || (stack == 2 && *top == 5))
    {
        printf("Overflow\n");
    }
    else
    {
        arr[*top] = element;
        if (stack == 1)
        {
            *top = *top + 1;
        }
        else if (stack == 2)
        {
            *top = *top - 1;
        }
    }
}

void pop(int arr[], int *top, int stack)
{
    if ((stack == 1 && *top == 0) || (stack == 2 && *top == 9))
    {
        printf("Underflow\n");
    }
    else
    {

        if (stack == 1)
        {
            *top = *top - 1;
        }
        else if (stack == 2)
        {
            *top = *top + 1;
        }
        printf("Deleted element is %d\n", arr[*top]);
    }
}

void traverse(int arr[], int *top, int stack)
{
    if ((stack == 1 && *top == 0) || (stack == 2 && *top == 9))
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("Elements of stack : ");
        if (stack == 1)
        {
            for (int i = *top - 1; i >= 0; i--)
            {
                printf("%d\t", arr[i]);
            }
        }
        else if (stack == 2)
        {
            for (int i = *top + 1; i <= 9; i++)
            {
                printf("%d\t", arr[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int arr[10];
    int top1 = 0;
    int top2 = 9;
    int stack;
    char c;
    do
    {
        printf("Enter the stack in which you want to do operation : ");
        scanf("%d", &stack);
        if (stack == 1)
        {
            int option = choice();
            if (option == 1)
            {
                int element;
                printf("Enter the element to be added : ");
                scanf("%d", &element);
                push(arr, &top1, 1, element);
            }
            else if (option == 2)
            {
                pop(arr, &top1, 1);
            }
            else if (option == 3)
            {
                traverse(arr, &top1, 1);
            }
            else
            {
                printf("Invald choice!\n");
            }
        }
        else if (stack == 2)
        {
            int option = choice();
            if (option == 1)
            {
                int element;
                printf("Enter element to be added : ");
                scanf("%d", &element);
                push(arr, &top2, 1, element);
            }
            else if (option == 2)
            {
                pop(arr, &top2, 2);
            }
            else if (option == 3)
            {
                traverse(arr, &top2, 1);
            }
            else
            {
                printf("Invald choice!\n");
            }
        }
        else
        {
            printf("Invalid stack!\n");
        }

        printf("Do you want to continue (Y) or (N) : ");
        scanf(" %c", &c);

    } while (c == 'Y' || c == 'y');
}
