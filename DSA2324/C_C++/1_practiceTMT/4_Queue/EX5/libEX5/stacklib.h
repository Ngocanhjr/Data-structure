#include <stdio.h>

#define MAX_LENGTH 5

typedef int ElementType;

typedef struct stack
{
    ElementType elements[MAX_LENGTH];
    int top;
}Stack;

void makeNullS(Stack *S)
{
    S->top = -1;
}

int isEmptyS(Stack S)
{
    return S.top == -1;
}

int isFullS(Stack S)
{
    return S.top == MAX_LENGTH - 1;
}

/*
similarly insertLast(), popLast() of array based list
*/
// T(n) = O(1)
void push(ElementType x, Stack *S)
{
    if (isFullS(*S))
    {
        printf("<!> Stack is full. Can't push %d\n", x);
    }
    else
    {
        S->top += 1;
        S->elements[S->top] = x;
    }
}

ElementType pop(Stack *S)
{
    if (isEmptyS(*S))
    {
        printf("<!> Stack is empty");
    }
    else
    {
        ElementType value = S->elements[S->top];
        S->top -= 1;
        return value;
    }
}

ElementType top(Stack S)
{
    return S.elements[S.top];
}

void printS(Stack S)
{
    while (!isEmptyS(S))
    {
        printf("%d ", top(S));
        pop(&S);
    }
    printf("\n");
}

