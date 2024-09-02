#include <stdio.h>
#include <stdlib.h>
// Maximum size of list
#define MAXSIZE 1000

typedef int Position;
typedef int ElementType;

typedef struct
{
    ElementType element[MAXSIZE]; // Array of elements
    int size;                     // current number of elements
} List;

List L;

void makeNull(List *L); // Initialize an empty list

int len(List L); // Return the number of elements

int empty(List L); // check whether the list is empty

int fullList(List L); // check whether the list is full

void print(List L); // Traverse the list to print out all elements

ElementType getAt(Position p, List L); // return the element at position p

ElementType first(List L); // return the first position of list

ElementType end(List L); // return the end position nof list

void setAt(Position p, ElementType x, List *L); // Update the element at position p by a new value x

void insertAt(Position p, ElementType x, List *L); // Insert a new element x

ElementType popAt(Position p, List *L); // Remove and return the element at position p

void insertFirst(ElementType x, List *L); // Inset x to the first element at position p

ElementType popFirst(List *L); // Remove and return the first element

void append(ElementType x, List *L); // Append a new element to the first

ElementType popLast(List *L); // Remove and return a last element

Position locate(ElementType x, List L); // Return the position of the first appearance of x in the list

Position next(Position p, List L); // return the next position of p in list

Position previous(Position p, List L); // return the previous position of p in list

void swap(ElementType *x, ElementType *y);

void sort(List *L);

void build(ElementType A[], int n, List *L);

void makeNull(List *L)
{
    L->size = 0;
}

int len(List L)
{
    return L.size;
}

int empty(List L)
{
    return L.size == 0;
}

int fullList(List L)
{
    return L.size == MAXSIZE;
}

void print(List L)
{
    if (empty(L))
    {
        printf("List is empty!\n");
        printf("List of element: null!\n");
        return;
    }
    if (fullList(L))
    {
        printf("List is full!\n");
    }
    printf("List of element: ");
    for (int i = 1; i < end(L); i++)
    {
        printf("%d ", getAt(i, L));
    }
}

ElementType getAt(Position p, List L)
{
    return L.element[p - 1];
}

ElementType first(List L)
{
    return 1;
}

ElementType end(List L)
{
    return L.size + 1;
}

void setAt(Position p, ElementType x, List *L)
{
    if (p < 1 || p > len(*L))
    {
        printf("invalid position!\n");
        return;
    }
    L->element[p - 1] = x;
}

void insertAt(Position p, ElementType x, List *L)
{
    if (p < 1 || p > len(*L))
    {
        printf("invalid position!\n");
        return;
    }
    else if (fullList(*L))
    {
        printf("List is full!\n");
        return;
    }
    else
    {
        for (int i = L->size; i >= p; i--)
        {
            L->element[i] = L->element[i - 1];
        }
        L->element[p - 1] = x;
        L->size++;
    }
}

ElementType popAt(Position p, List *L)
{
    if (p < 1 || p > len(*L))
    {
        printf("invalid position!\n");
        exit(EXIT_FAILURE);;
    }
    else if (empty(*L))
    {
        printf("List is empty!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (int i = p; i < L->size; i++)
        {
            L->element[i - 1] = L->element[i];
        }
        L->size--;
        return getAt(p, *L);
    }
}

void insertFirst(ElementType x, List *L)
{
    insertAt(first(*L), x, L);
}

ElementType popFirst(List *L)
{
    popAt(1, L);
    return getAt(first(*L), *L);
}

void append(ElementType x, List *L)
{
    if (fullList(*L))
    {
        printf("List is full!\n");
        exit(EXIT_FAILURE);;
    }
    else
    {
        L->element[L->size] = x;
        L->size++;
    }
}

ElementType popLast(List *L)
{
    L->size--;
    return getAt(L->size, *L);
}

Position locate(ElementType x, List L)
{
    int found = 0;
    Position p = first(L), q = end(L);
    while (p != q && !found)
    {
        if (getAt(p, L) == x)
        {
            found = p;
        }
        else
        {
            p = next(p, L);
        }
    }
    return found;
}

Position next(Position p, List L)
{
    return p + 1;
}

Position previous(Position p, List L)
{
    return p - 1;
}

void swap(ElementType *x, ElementType *y)
{
    ElementType tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(List *L)
{
    Position p = first(*L), e = end(*L), q;
    while (p != e)
    {
        q = next(p, *L);
        while (q != e)
        {
            if (getAt(p, *L) > getAt(q, *L)) // dua thang nho nhat ve dau
            {
                swap(&L->element[p - 1],&L->element[q - 1]);
            }
            q = next(q, *L);
        }
        p = next(p, *L);
    }
}

void build(ElementType A[], int n, List *L)
{
    for (int i = 0; i < n; i++)
    {
        L->element[i] = A[i];
    }
    L->size = n;
}