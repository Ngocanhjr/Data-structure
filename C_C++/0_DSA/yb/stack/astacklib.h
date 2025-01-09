#include <stdio.h>

#define MAX_LENGTH 100

typedef int ElementType;

typedef struct
{
    ElementType elements[MAX_LENGTH];
    int top;
} Stack;

void makeNull(Stack *S)
{
    S->top = -1;
}

int isEmpty(Stack S)
{
    return S.top == -1;
}

int isFull(Stack S)
{
    return S.top == MAX_LENGTH - 1;
}

/*
similarly insertLast(), popLast() of array based list
*/
// T(n) = O(1)
void push(ElementType x, Stack *S)
{
    if (isFull(*S))
    {
        printf("<!> Stack is full");
    }
    else
    {
        S->top += 1;
        S->elements[S->top] = x;
    }
}

ElementType pop(Stack *S)
{
    if (isEmpty(*S))
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

void print(Stack S)
{
    while (!isEmpty(S))
    {
        printf("%d ", top(S));
        pop(&S);
    }
}

Stack read()
{
    Stack createNew;
    makeNull(&createNew);
    int size;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(temp, &createNew);
    }
    return createNew;
}
