#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tag
{
    ElementType data;
    struct tag *next;
} Node;

typedef Node *List;
typedef Node *PNode;

void makeNull(List *L)
{
    (*L) = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
}

PNode next(PNode pos)
{
    return pos->next;
}

ElementType retrieve(PNode pos)
{
    return pos->next->data;
}

PNode linearSearch(ElementType x, List L)
{
    PNode pos = L;
    while (pos->next != NULL)
    {
        if (retrieve(pos) == x)
        {
            return pos;
        }
        pos = next(pos);
    }
    return pos; // the position of the last node;
}

void insert(ElementType x, List *L){
    List newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = (*L)->next;
    (*L)->next = newNode;
}

int main()
{
    List L;
    makeNull(&L);
    for (int i = 5; i < 10; i++)
    {
        insert(i, &L);
    }

    PNode pos = linearSearch(5, L);
    if (pos->next == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found\n");
        printf("Data: %d\n", retrieve(pos));
    }
    return 0;
}