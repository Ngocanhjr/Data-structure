#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

typedef char ElementType;
typedef int Position;
typedef struct node
{
    ElementType elements;
    struct node *next;
} Node;

typedef Node *List;
typedef Node *PNode;

void makeNull(List *L)
{
    List createEmpty = (Node *)malloc(sizeof(Node));
    createEmpty->next = NULL;
    (*L) = createEmpty;
}

int isEmpty(List L)
{
    return L->next == NULL;
}

int length(List L)
{
    int size = 0;
    while (L->next != NULL)
    {
        size++;
        L = L->next;
    }
    return size;
}

void print(List L)
{
    if (!isEmpty(L))
    {
        while (L->next != NULL)
        {
            printf("%c", L->next->elements);
            L = L->next;
        }
        printf("\n");
    }
    else
    {
        printf("<!> List is empty");
    }
}

void insertFirst(ElementType x, List *L)
{
    List new = (Node *)malloc(sizeof(Node));
    new->elements = x;
    new->next = (*L)->next;
    (*L)->next = new;
}

List read()
{
    List init = (Node *)malloc(sizeof(Node));
    makeNull(&init);
    printf("Enter string: ");

    char source[MAX_LENGTH];
    fgets(source, MAX_LENGTH, stdin);
    source[strlen(source) - 1] = '\0';

    int size = strlen(source);
    for (int i = size - 1; i >= 0; i--) // skip '\0'
    {
        insertFirst(source[i], &init);
    }
    return init;
}

List reverse(List L)
{
    PNode cur = L->next;
    PNode next = NULL;
    PNode prev = NULL;
    while (cur != NULL)
    {
        next = cur->next; // store pointer referring the next position
        cur->next = prev; // store pointer referring the previous position
        prev = cur;
        cur = next;
    }
    L->next = prev;
    return L;
}

List coder(List source, List key)
{
    List destination = (Node *)sizeof(Node);
    makeNull(&destination);
    PNode posKey = key;
    while (source->next != NULL)
    {
        if (posKey->next == NULL)
        {
            posKey = key;
        }
        ElementType data = source->next->elements + (posKey->next->elements - '0');
        insertFirst(data, &destination);
        source = source->next;
        posKey = posKey->next;
    }
    // print(destination);
    destination = reverse(destination);
    return destination;
}

List deCoder(List source, List key)
{
    List destination = (Node *)malloc(sizeof(Node));
    makeNull(&destination);
    PNode posKey = key;
    while (source->next != NULL)
    {
        if (posKey->next == NULL)
        {
            posKey = key;
        }
        ElementType data = source->next->elements - (posKey->next->elements - '0');
        insertFirst(data, &destination);
        posKey = posKey->next;
        source = source->next;
    }
    destination = reverse(destination);
    return destination;
}