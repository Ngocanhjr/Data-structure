#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct tag
{
    DataType data;
    struct tag *left;
    struct tag *right;
} Node;

typedef Node *Tree;

typedef Tree TTree;

void makeNull(Tree *T)
{
    (*T) = NULL;
}

int isEmpty(Tree T)
{
    return T == NULL;
}

Tree createEmptyTree(DataType x, Tree T)
{
    T = (Node *)malloc(sizeof(Node));
    T->data = x;
    T->left = NULL;
    T->right = NULL;
    return T;
}

Tree create(DataType v, Tree l, Tree r)
{
    Tree createTree;
    createTree = (Node *)malloc(sizeof(Node));
    createTree->data = v;
    createTree->left = l;
    createTree->right = r;
    return createTree;
}

TTree leftTree(Tree n)
{
    if (n != NULL)
        return n->left;
    return NULL;
}

TTree rightTree(Tree n)
{
    if (n != NULL)
        return n->right;
    return NULL;
}

int isLeaf(Tree n)
{
    if (n != NULL)
        return (leftTree(n) == NULL && rightTree(n) == NULL);
    return 0;
}

void NLR(Tree root)
{
    if (!isEmpty(root))
    {
        printf("data: %c\n", root->data);
        NLR(leftTree(root));
        NLR(rightTree(root));
    }
}

void LNR(Tree root)
{
    if (!isEmpty(root))
    {
        LNR(leftTree(root));
        printf("Data: %c\n", root->data);
        LNR(rightTree(root));
    }
}

void LRN(Tree root)
{
    if (!isEmpty(root))
    {
        LRN(leftTree(root));
        LRN(rightTree(root));
        printf("Data: %c\n", root->data);
    }
}

int nb_nodes(Tree T)
{
    if (isEmpty(T))
        return 0;
    else
    return 1 + nb_nodes(leftTree(T)) + nb_nodes(rightTree(T));
}

