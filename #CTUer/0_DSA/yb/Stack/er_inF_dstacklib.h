/*
 Dynamic array 
*/

// ################### ERROR ###################################
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct
{
    ElementType *elements;
    int top;
    int capacity; // capacity of array
} Stack;

void makeNull(Stack *S)
{
    S->elements = (ElementType *)malloc(sizeof(ElementType));
    S->capacity = -1; //không dùng phần tử đầu tiên
    S->top = -1;
}

int isEmpty(Stack S)
{
    return S.top == -1;
}

void resize(Stack *S, int newCapacity)
{
    ElementType *temp = S->elements;
    S->capacity = newCapacity;
    S->elements = (ElementType *)malloc(sizeof(ElementType) * newCapacity);
    for (int i = 0; i < S->capacity - 1; i++)
    {
        S->elements[i] = temp[i];
    }
    free(temp);
}

void push(ElementType x, Stack *S)
{
    // if (isEmpty(*S))
    // {
    //     S->elements = (ElementType *)malloc(sizeof(ElementType));
    // }
    // else
    // {
    //     // S->elements = (ElementType*)realloc(S->elements, (S->top + 2)*sizeof(ElementType));
    //     // resize(S, S->capacity + 2);
    //     resize(S, S->capacity * 2);
    // }
    // S->top++;
    // S->elements[S->top] = x;

    if(S->top == S->capacity - 1){
        resize(S, S->capacity * 2);
    }
    S->top++;
    S->elements[S->top] = x;
}

ElementType pop(Stack *S)
{
    int value;
    if (!isEmpty(*S))
    {
        if (S->top == 0)
        {
            value = S->elements[S->top];
            free(S->elements);
        }
        else
        {
            value = S->elements[S->top];
            ElementType *temp;
            temp = (ElementType *)malloc(sizeof(ElementType) * (S->top));
            for (int i = 0; i < S->top; i++)
            {
                temp[i] = S->elements[i];
            }
            free(S->elements);
            S->elements = temp;
        }
        S->top--;
        return value;
    }
    else
    {
        printf("<!> Stack is empty");
    }
}

ElementType top(Stack S)
{
    return S.elements[S.top];
}

void print(Stack S)
{
    for (int i = 0; i <= S.top; i++)
    {
        printf("%d ", S.elements[i]);
    }
    printf("\n");
}
// void print(Stack S)
// {
//     while (!isEmpty(S))
//     {
//         printf("%d ", top(S));
//         pop(&S);
//     }
// }

Stack read()
{
    Stack newStack;
    makeNull(&newStack);
    int size;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(temp, &newStack);
    }
    return newStack;
}