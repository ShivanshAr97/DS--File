#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct college
{
    char title[50];
    char value[50];
    struct college *link;
} * FIRST;

typedef struct college col;
int traverse()
{
    if (FIRST == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    col *temp = FIRST;

    do
    {
        printf("%s : ", temp->title);
        printf("%s\n", temp->value);
        temp = temp->link;
    } while (temp != FIRST);

    return 0;
}

int insertion()
{
    col *entity;
    entity = (col *)malloc(sizeof(col));
    if (entity == NULL)
    {
        printf("Unable to allocate space \n");
        return 0;
    }

    char title[50];
    char value[50];
    printf("Enter the title of node : ");

    scanf("%s", title);
    printf("Enter the value of node : ");

    scanf("%s", value);

    strcpy(entity->title, title);
    strcpy(entity->value, value);
    if (FIRST == NULL)
    {
        FIRST = entity;
        entity->link = FIRST;
    }
    else
    {
        entity->link = FIRST;
        col *temp = FIRST;

        while (temp->link != FIRST)
        {
            temp = temp->link;
        }
        temp->link = entity;
        FIRST = entity;
    }
    return 0;
}

int deletion()
{
    if (FIRST == NULL)
    {
        printf("No data avaialable\n");
        return 0;
    }
    if (FIRST->link == FIRST)
    {
        printf("Checked");
        col *temp = FIRST;
        free(temp);
        FIRST = NULL;

        return 0;
    }

    col *temp = FIRST;
    col *prev = NULL;
    do
    {
        prev = temp;
        temp = temp->link;
    } while (temp->link != FIRST);
    if (prev == temp)
    {

        FIRST = NULL;
    }
    else
    {
        prev->link = FIRST;
    }
    free(temp);
    return 0;
}

int main()
{
    FIRST = NULL;
    printf("1.Insertion at Front\n2.Deletion at end\n");
    char ch;
    do
    {
        int choice;
        printf("Enter the choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insertion();
            traverse();
        }
        else if (choice == 2)
        {
            deletion();
            traverse();
        }
        else
        {
            printf("Enter the valid choice \n");
        }

        printf("Do you want to continue or not : ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}