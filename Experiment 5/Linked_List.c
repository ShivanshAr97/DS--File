#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int rollNo;
    char name[20];
    char grade;
    struct student *link;
} * FIRST;

typedef struct student stu;
int newNode()
{

    stu *student1;
    student1 = (stu *)malloc(sizeof(stu));
    if (student1 == NULL)
    {
        printf("There is no availabe space \n");
        return 0;
    }
    else
    {
        int rollNo;
        char name[20];
        char grade;

        printf("Enter Roll No.: ");
        scanf("%d", &rollNo);
        printf("Enter Grade: ");
        scanf(" %c", &grade);

        printf("Enter Name: ");
        scanf("%s", name);

        student1->rollNo = rollNo;
        strcpy(student1->name, name);
        student1->grade = grade;
        if (FIRST == NULL)
        {

            FIRST = student1;
            student1->link = NULL;
        }
        else
        {
            stu *temp = FIRST;
            stu *prev = NULL;

            while ((temp != NULL) && (temp->rollNo < rollNo) && (temp->rollNo != rollNo))
            {
                prev = temp;
                temp = temp->link;
            }

            if (temp == NULL)
            {

                prev->link = student1;
                student1->link = NULL;
            }
            else if (temp->rollNo == rollNo)
            {
                printf("This Roll No. already exists!");
                char existChoice;

                printf("Do you want to append it (Y) or (N):");
                scanf(" %c", &existChoice);
                if (existChoice == 'Y')
                {
                    temp->grade = grade;
                }
            }
            else
            {

                if (prev == NULL)
                {

                    FIRST = student1;
                    temp->link = NULL;
                }
                else
                {
                    prev->link = student1;
                }
                student1->link = temp;
            }
        }
    }
    return 0;
}

int deletion(int rollNo)
{

    if (FIRST == NULL)
    {
        printf("No element currently exists \n");
        return 0;
    }
    else
    {
        stu *temp = FIRST;
        stu *prev = NULL;
        while (temp->rollNo != rollNo && temp != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL)
        {
            printf("Element not found\n");
        }
        else
        {
            if (prev == NULL)
            {
                FIRST = NULL;
            }
            else
            {
                prev->link = (temp->link);
            }
            free(temp);
        }
    }
    return 0;
}

void traverse()
{
    stu *temp = FIRST;
    while (temp != NULL)
    {

        printf("\nRoll no. %d\n", temp->rollNo);
        printf("Name : %s\n", temp->name);
        printf("Grade : %c\n", temp->grade);
        temp = temp->link;
    }
}

void reversal()
{
    stu *cur = FIRST;
    stu *prev = NULL;
    stu *next = NULL;
    while (cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    FIRST = prev;
}

int main()
{
    FIRST = NULL;
    char ch;
    printf("1.Insert new node at specified position\n2.Deletion of elements with roll no\n3.Reversal of the linked list\n");
    do
    {
        int choice;
        printf("Enter the choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {

            newNode();
            traverse();
        }
        else if (choice == 2)
        {
            int rollNo;
            printf("Enter the roll no of the student : ");
            scanf("%d", &rollNo);
            deletion(rollNo);
            traverse();
        }
        else if (choice == 3)
        {
            reversal();
            traverse();
        }

        printf("Do you want to continue or not : ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');
}