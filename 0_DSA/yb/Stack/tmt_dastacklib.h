#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct
{
    ElementType *elements;
    int top;
    int capacity;
} Stack;

void makeNull(Stack *S)
{
    S->capacity = 1; // Initial capacity
    S->top = -1;     // Initial top
    S->elements = (ElementType *)malloc(sizeof(ElementType) * S->capacity);
}

int isEmpty(Stack S)
{
    return S.top == -1;
}

void resize(Stack *S, int newCapacity)
{
    ElementType *temp = (ElementType *)malloc(sizeof(ElementType) * newCapacity);
    if (temp == NULL)
    {
        printf("Malloc failed!\n");
        exit(1);
    }
    for (int i = 0; i <= S->top; i++)
    {
        temp[i] = S->elements[i];
    }
    free(S->elements);
    S->elements = temp;
    S->capacity = newCapacity;
}

void push(ElementType value, Stack *S)
{
    if (S->top == S->capacity - 1)
    {
        resize(S, S->capacity * 2);
    }
    S->elements[++S->top] = value;
}

ElementType pop(Stack *S)
{
    int value = -9999;
    if (!isEmpty(*S))
    {
        value = S->elements[S->top];
        S->top--;
        if (S->top < S->capacity / 4 && S->capacity > 1)
        {
            resize(S, S->capacity / 2);
        }
    }
    return value;
}

ElementType top(Stack S)
{
    if (isEmpty(S))
    {
        printf("Stack is empty!\n");
        return -9999; // Return an error value
    }
    return S.elements[S.top];
}

void print(Stack S)
{
    while (!isEmpty(S))
    {
        printf("%d ", pop(&S));
    }
    printf("\n");
}