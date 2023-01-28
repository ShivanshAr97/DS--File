#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
} * HEAD;

typedef struct node node;
int insertionStart()
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Overflow\n");
        return 0;
    }
    else
    {
        int data;
        printf("Enter the value to be added : ");
        scanf("%d", &data);
        n->data = data;

        if (HEAD->rlink == NULL)
        {
            n->rlink = HEAD;
            HEAD->llink = n;
        }
        else
        {
            n->rlink = HEAD->rlink;
            (n->rlink)->llink = n;
        }
        n->llink = HEAD;
        HEAD->rlink = n;
    }
    return 0;
}

int insertionEnd()
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Overflow\n");
        return 0;
    }
    else
    {
        int data;
        printf("Enter the value to be added : ");
        scanf("%d", &data);
        n->data = data;
        if (HEAD->rlink == NULL)
        {
            HEAD->rlink = n;
            n->llink = HEAD;
        }
        else
        {
            node *temp = HEAD->llink;
            temp->rlink = n;
            n->llink = temp;
        }
        n->rlink = HEAD;
        HEAD->llink = n;
    }
    return 0;
}

int insertionSpecified()
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Overflow\n");
        return 0;
    }
    else
    {

        if (HEAD->rlink == NULL)
        {
            printf("No element was there\n");
            return 0;
        }
        else
        {
            int item;
            printf("Enter the value after which the insertion should take place : ");
            scanf("%d", &item);
            node *temp = HEAD->rlink;
            while (temp->data != item && temp != HEAD)
            {
                temp = temp->rlink;
            }
            if (temp == HEAD)
            {
                printf("Unable to find element!\n");
                return 0;
            }
            else
            {
                int data;
                printf("Enter the value to be added : ");
                scanf("%d", &data);
                n->data = data;
                if (temp->rlink == HEAD)
                {
                    HEAD->llink = n;
                }
                n->rlink = temp->rlink;
                temp->rlink = n;
                n->llink = temp;
            }
        }
    }
    return 0;
}

int deletionStart()
{
    if (HEAD->rlink == NULL)
    {
        printf("Underflow!\n");
        return 0;
    }
    else
    {
        node *temp = HEAD->rlink;
        printf("Deleted element is : %d\n", temp->data);
        if (temp->rlink == HEAD)
        {
            HEAD->rlink = NULL;
            HEAD->llink = NULL;
        }
        else
        {
            HEAD->rlink = (temp)->rlink;
        }
        free(temp);
    }
    return 0;
}

int deletionEnd()
{
    if (HEAD->rlink == NULL)
    {
        printf("Underflow\n");
        return 0;
    }
    else
    {
        node *temp = HEAD->llink;
        if (temp->llink == HEAD)
        {
            HEAD->llink = NULL;
            HEAD->rlink = NULL;
        }
        else
        {
            (temp->llink)->rlink = HEAD;
            HEAD->llink = temp->llink;
        }
        printf("Deleted element : %d\n", temp->data);
        free(temp);
    }
}

int deletionSpecified()
{
    if (HEAD->rlink == NULL)
    {
        printf("Underlow\n");
        return 0;
    }
    else
    {
        int item;
        printf("Enter the value for which the element is to be deleted : ");
        scanf("%d", &item);
        node *temp = HEAD->rlink;
        while (temp->data != item && temp != HEAD)
        {
            temp = temp->rlink;
        }
        if (temp == HEAD)
        {
            printf("Element was not found!\n");
            return 0;
        }
        else
        {
            if (temp->llink == HEAD)
            {
                HEAD->llink = temp->llink;
                (temp->llink)->rlink = HEAD;
            }
            else
            {
                (temp->llink)->rlink = temp->rlink;
                (temp->rlink)->llink = temp->llink;
            }
        }
        printf("Deleted element is : %d\n", temp->data);
        free(temp);
    }
}

int traverse()
{
    if (HEAD->rlink == NULL)
    {
        printf("No element was there \n");
        return 0;
    }
    else
    {
        node *temp = HEAD->rlink;
        while (temp != HEAD)
        {
            printf("%d\t", temp->data);
            temp = temp->rlink;
        }
    }
    printf("\n");
    return 0;
}

int main()
{
    HEAD = (node *)malloc(sizeof(node));
    HEAD->llink = NULL;
    HEAD->rlink = NULL;
    int choice;
    printf("1.Insertion at start\n2.Insertion at end\n3.Insertion at specified position\n4.Deletion at start\n5.Deletion at end\n6.Deletion at specified position\n");

    do
    {
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case (1):
            insertionStart();
            traverse();
            break;
        case (2):
            insertionEnd();
            traverse();
            break;
        case (3):
            insertionSpecified();
            traverse();
            break;
        case (4):
            deletionStart();
            traverse();
            break;
        case (5):
            deletionEnd();
            traverse();
            break;
        case (6):
            deletionSpecified();
            traverse();
            break;
        }
    } while (choice >= 1 && choice <= 6);
    return 0;
}