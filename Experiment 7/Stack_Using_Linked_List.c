#include <stdio.h>
#include <stdlib.h>

struct node
{
    int no;
    struct node *prev;
    struct node *next;
} * TOP;

typedef struct node n;
int insertion()
{
    n *entity;
    entity = (n *)malloc(sizeof(n));
    if (entity == NULL)
    {
        printf("Unable to allocate space\n");
        return 0;
    }
    else
    {
        int data;
        printf("Enter the value : ");
        scanf("%d", &data);
        entity->no = data;
        if (TOP == NULL)
        {
            entity->next = NULL;
            entity->prev = NULL;
            TOP = entity;
        }
        else
        {
            n *temp = TOP;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = entity;
            entity->prev = temp;
            entity->next = NULL;
        }
    }
    return 0;
}

int deletion()
{
    if (TOP == NULL)
    {
        printf("There is no elements in the stack ");
        return 0;
    }
    else
    {
        n *temp = TOP;
        if (temp->next == NULL)
        {
            TOP = NULL;
        }
        else
        {

            while (temp->next != NULL)
            {

                temp = temp->next;
            }
            (temp->prev)->next = NULL;
        }
        printf("Deleted element is : %d\n", temp->no);
        free(temp);
    }
    return 0;
}

int traverse()
{
    n *temp = TOP;
    if (TOP == NULL)
    {
        printf("Nothing to print\n");
        return 0;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        int count = 1;
        while (temp != NULL)
        {
            printf("The %d element is : %d\n", count, temp->no);
            temp = temp->prev;
            count++;
        }
    }
}

int peek()
{
    n *temp = TOP;
    if (TOP == NULL)
    {
        printf("No element was there!\n");
        return 0;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Peek element is %d\n", temp->no);
    return 0;
}

void main()
{
    printf("1.Insertion\n2.Deletion\n3.Peek\n4.Traverse\nPress any other key to exit...\n");
    int choice;
    do
    {
        printf("Enter the choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insertion();
        }
        else if (choice == 2)
        {
            deletion();
        }
        else if (choice == 3)
        {
            peek();
        }
        else if (choice == 4)
        {
            traverse();
        }
        else
        {
            break;
        }
    } while (1);
}