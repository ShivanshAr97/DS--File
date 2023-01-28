#include <stdio.h>
#include <stdlib.h>

struct element
{
    char data;
    struct element *lchild, *rchild;
} *root;

typedef struct element element;
element *initialise(char ch)
{
    element *node;
    node = (element *)malloc(sizeof(element));
    if (node == NULL)
        return NULL;
    else
    {
        node->data = ch;
        node->lchild = NULL;
        node->rchild = NULL;
        return node;
    }
}

void inOrder(element *node)
{
    if (node == NULL)
        return;
    inOrder(node->lchild);
    printf("%c ", node->data);
    inOrder(node->rchild);
}

void preOrder(element *node)
{
    if (node == NULL)
        return;
    printf("%c ", node->data);
    preOrder(node->lchild);
    preOrder(node->rchild);
}

void postOrder(element *node)
{
    if (node == NULL)
        return;
    postOrder(node->lchild);
    postOrder(node->rchild);
    printf("%c ", node->data);
}

int main()
{
    root = initialise('A');
    root->lchild = initialise('B');
    root->rchild = initialise('C');
    root->lchild->lchild = initialise('D');
    root->lchild->rchild = initialise('E');
    root->rchild->lchild = initialise('F');
    root->rchild->rchild = initialise('G');
    printf("Inorder:");
    inOrder(root);
    printf("\n");
    printf("Preorder:");
    preOrder(root);
    printf("\n");
    printf("Postorder:");
    postOrder(root);
    printf("\n");
    return 0;
}