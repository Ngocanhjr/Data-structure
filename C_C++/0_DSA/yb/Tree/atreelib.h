#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 5

#define NIL -1

typedef char DataType;

typedef int Node;

typedef struct tag
{
    DataType data[MAX_LENGTH];
    Node parent[MAX_LENGTH];
    int MaxNode;
} Tree;

Tree T;

void makeNull(Tree *T); // Make a tree empty

int isEmpty(Tree T); // Check if a tree is empty

Node parent(Node n, Tree T); // Return the parent node of a node on a tree

DataType Label(Node n, Tree T); // Return the label of a node

Node root(Tree T); // Return the root of a tree

Node leftMostChild(int n, Tree T); // Return the leftmost child of a node

Node rightSiblings(Node n, Tree T); // Return the right sibling of a node

void PreOrder(Node n, Tree T); // Preorder traversal

void readTree(Tree *T); // Read a tree from the keyboard

void makeNull(Tree *T)
{
    T->MaxNode = 0;
}

int isEmpty(Tree T)
{
    return T.MaxNode == 0;
}

Node parent(Node n, Tree T)
{
    if (isEmpty(T) || n > T.MaxNode - 1)
    {
        return NIL;
    }
    else
    {
        return T.parent[n];
    }
}

DataType Label(Node n, Tree T)
{
    if (!isEmpty(T) && n <= T.MaxNode - 1)
    {
        return T.data[n];
    }
}

Node root(Tree T)
{
    if (!isEmpty(T))
        return 0;
    else
        return NIL;
}

Node leftMostChild(int n, Tree T)
{
    Node i;
    int founded;

    if (n < 0)
        return NIL;

    i = n + 1;
    founded = 0;

    while (i <= T.MaxNode - 1 && !founded)
    {
        if (T.parent[i] == n)
            founded = 1;
        else
            i += 1;
    }

    if (founded)
        return i;
    else
        return NIL;
}

Node rightSiblings(Node n, Tree T)
{
    Node i, parent;
    int founded;
    if (n < 0)
        return NIL;

    parent = T.parent[n];
    i = n + 1;
    founded = 0;

    while (i <= T.MaxNode - 1 && !founded)
    {
        if (T.parent[i] == parent)
            founded = 1;
        else
            i += 1;
    }

    if (founded)
        return i;
    else
        return NIL;
}

void PreOrder(Node n, Tree T)
{
    if (n != NIL)
    {
        Node i;
        printf("Data: %c\n", Label(n, T));
        i = leftMostChild(n, T);

        while (i != NIL)
        {
            PreOrder(i, T);
            i = rightSiblings(i, T);
        }
    }
}

void readTree(Tree *T)
{
    makeNull(T);

    do
    {
        printf("Enter the number of nodes: ");
        scanf("%d", &(T->MaxNode));
    } while (T->MaxNode < 1 || T->MaxNode > MAX_LENGTH);

    printf("Enter label of the root: ");
    fflush(stdin);
    scanf("%c", &(T->data[0]));
    T->parent[0] = NIL;

    for (int i = 1; i <= T->MaxNode - 1; i++)
    {
        printf("Enter parent of  %d: ", i);
        scanf("%d", &T->parent[i]);

        printf("Enter label of %d: ", i);
        fflush(stdin);
        scanf("%c", &T->data[i]);
    }
}