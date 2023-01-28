#include <stdio.h>
#include <stdlib.h>

struct automobile
{
    char type[20];
    char company[50];
    int year;
    struct automobile *lchild, *rchild;
} *root, *par, *loc, *save, *ptr;

typedef struct automobile autom;
void findLocation(int year)
{
    if (root == NULL)
    {
        par = loc = NULL;
        return;
    }
    else if (root->year == year)
    {
        par = NULL;
        loc = root;
        return;
    }
    else
    {
        save = root;
        if (year > root->year)
            ptr = root->rchild;

        else
            ptr = root->lchild;
        while (ptr != NULL)
        {
            if (ptr->year == year)
            {
                loc = ptr;
                par = save;
                return;
            }
            else if (ptr->year > year)
            {
                save = ptr;
                ptr = ptr->lchild;
            }
            else
            {
                save = ptr;
                ptr = ptr->rchild;
            }
        }
        loc = NULL;
        par = save;
    }
}

void insertion()
{
    autom *node;
    node = (autom *)malloc(sizeof(autom));
    if (node == NULL)
        printf("Unable to allocate memory !\n");
    else
    {
        int year;
        char type[20];
        char company[100];
        printf("Enter the year : ");
        scanf(" %d", &(node->year));
        printf("Enter the type : ");
        scanf("%s", node->type);
        printf("Enter the company : ");
        scanf("%s", node->company);
        node->lchild = node->rchild = NULL;

        findLocation(node->year);
        if (loc != NULL)
            printf("Item already exists!\n");
        else
        {
            if (par != NULL)
            {
                if (par->year > node->year)

                    par->lchild = node;

                else

                    par->rchild = node;
            }
            else
                root = node;
        }
    }
}

void inOrder(autom *node)
{
    if (node == NULL)
        return;

    inOrder(node->lchild);
    printf("%d ", node->year);
    printf("%s", node->type);
    printf("%s\n", node->company);

    inOrder(node->rchild);
}

void preOrder(autom *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->year);
    printf("%s", node->type);
    printf("%s\n", node->company);
    preOrder(node->lchild);
    preOrder(node->rchild);
}

void postOrder(autom *node)
{
    if (node == NULL)
        return;
    postOrder(node->lchild);
    postOrder(node->rchild);
    printf("%d ", node->year);
    printf("%s ", node->type);
    printf("%s\n", node->company);
}

void traversal()
{
    printf("1.Inorder\n2.Preorder\n3.Postorder\n");
    int orderChoice;
    printf("Enter the order choice : ");
    scanf("%d", &orderChoice);
    switch (orderChoice)
    {
    case 1:
        printf("Inorder\n");
        inOrder(root);
        break;
    case 2:
        printf("Preorder\n");
        preOrder(root);
        break;
    case 3:
        printf("Postorder\n");
        postOrder(root);
        break;
    default:
        printf("Enter the valid order choice \n");
    }
}
void deletionZeroOrSingle(autom *loc, autom *par)
{
    autom *child = (autom *)malloc(sizeof(autom));
    if (loc->lchild != NULL)

        child = loc->lchild;

    else if (loc->rchild != NULL)

        child = loc->rchild;

    else

        child = NULL;

    if (par != NULL)
    {
        if (par->lchild == loc)

            par->lchild = child;

        else if (par->rchild == loc)

            par->rchild = child;
    }
    else

        root = child;
}

void deletionTwo()
{
    ptr = loc->rchild;
    save = loc;
    while (ptr->lchild != NULL)
    {
        save = ptr;
        ptr = ptr->lchild;
    }
    autom *suc = ptr;
    autom *parsuc = save;
    deletionZeroOrSingle(suc, parsuc);
    if (par != NULL)
    {
        if (loc == par->lchild)

            par->lchild = suc;

        else

            par->rchild = suc;
    }
    else
    {
        suc->lchild = loc->lchild;
        suc->rchild = loc->rchild;
        root = suc;
    }
}

void deletion()
{
    int year;
    printf("Enter the year of the element to be deleted : ");
    scanf("%d", &year);
    findLocation(year);
    if (loc == NULL)
    {
        printf("Item not found!\n");
        return;
    }
    else
    {

        if (loc->lchild != NULL && loc->rchild != NULL)
            deletionTwo();

        else

            deletionZeroOrSingle(loc, par);
    }
}

int main()
{
    root = NULL;
    printf("1.Insertion\n2.Deletion\n3.Traversal\n4.Exit....\n");
    int choice;
    do
    {
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            traversal();
            break;
        default:
            printf("Exiting ....\n");
        }
    } while (choice == 1 || choice == 2 || choice == 3);
    return 0;
}