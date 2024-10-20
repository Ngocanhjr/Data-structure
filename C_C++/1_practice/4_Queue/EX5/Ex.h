#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 5

typedef int ElementType;

typedef struct queue
{
    ElementType elements[MAX_LENGTH];
    int front, rear;
    int identityProduct;
} Queue;

typedef struct stack
{
    ElementType elements[MAX_LENGTH];
    int top;
} Stack;

void makeNullQ(Queue *Q);

int isEmptyQ(Queue Q);

int lenQ(Queue Q);

int isFullQ(Queue Q);

void enQueue(ElementType x, Queue *Q);

ElementType deQueue(Queue *Q);

ElementType front(Queue Q);

void printQ(Queue Q);

void makeNullS(Stack *S);

int isEmptyS(Stack S);

int isFullS(Stack S);

void push(ElementType x, Stack *S);

ElementType pop(Stack *S);

ElementType top(Stack S);

void reverseStack(Stack *S);

void reverseQueue(Queue *Q);

void PnC(Queue *warehouse);

void runPnC(Queue *warehouse);

void printS(Stack S);

void makeNullQ(Queue *Q)
{
    Q->front = -1;
    Q->rear = Q->front;
    Q->identityProduct = 0;
}

int isEmptyQ(Queue Q)
{
    return Q.front == -1;
}

int lenQ(Queue Q)
{
    if(isEmptyQ(Q))
        return 0;
    return (Q.rear + MAX_LENGTH - Q.front) % MAX_LENGTH + 1;
}

int isFullQ(Queue Q)
{
    return (Q.rear + 1) % MAX_LENGTH == Q.front;
}

void enQueue(ElementType x, Queue *Q)
{
    if (!isFullQ(*Q))
    {
        if (isEmptyQ(*Q))
        {
            Q->front = 0;
            ;
        }
        Q->rear = (Q->rear + 1) % MAX_LENGTH;
        Q->elements[Q->rear] = x;
    }
    else
    {
        printf("<!> Queue is full.");
    }
}

ElementType deQueue(Queue *Q)
{
    if (!isEmptyQ(*Q))
    {
        ElementType value = Q->elements[Q->front];
        if (Q->front == Q->rear)
            makeNullQ(Q);
        else
            Q->front = (Q->front + 1) % MAX_LENGTH;
            return value;
    }
    else
    {
        printf("<!> Queue is empty.");
        return -1;
    }
}

ElementType front(Queue Q)
{
    if (!isEmptyQ(Q))
    {
        return Q.elements[Q.front];
    }
    else
    {
        return -1;
    }
}

void printQ(Queue Q)
{
    if (isEmptyQ(Q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = Q.front;
    while (i != Q.rear)
    {
        printf("%d ", Q.elements[i]);
        i = (i + 1) % MAX_LENGTH;
    }
    printf("%d\n", Q.elements[Q.rear]); // In phần tử cuối cùng
}

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

void push(ElementType x, Stack *S)
{
    if (isFullS(*S))
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
    printf("Stack elements: ");
    while (!isEmptyS(S))
    {
        printf("%d ", top(S));
        pop(&S);
    }
    printf("\n");
}

void reverseStack(Stack *S)
{
    Queue Q;
    makeNullQ(&Q);
    while (!(isEmptyS(*S)))
    {
        enQueue(pop(S), &Q);
    }

    while (!isEmptyQ(Q))
    {
        push(deQueue(&Q), S);
    }
}

void reverseQueue(Queue *Q)
{
    Stack S;
    makeNullS(&S);

    while (!isEmptyQ(*Q))
    {
        push(deQueue(Q), &S);
    }

    while (!(isEmptyS(S)))
    {
        enQueue(pop(&S), Q);
    }
}

void PnC(Queue *warehouse)
{
    // int random = rand() % 10 + 1;
    srand(time(NULL));
    int random = rand() % 100 + 1;
    printf("Random number: %d\n", random);

    if (random % 2 == 0)
    {
        // Call Consumer
        if (!isEmptyQ(*warehouse))
        {
            printf("Consumer product #%d\n", deQueue(warehouse));
        }
        else
        {
            printf("<!> The warehouse is out of stock and temporarily suspends sales!\n");
        }
    }
    else
    {
        // call Producer
        if (!isFullQ(*warehouse))
        {
            enQueue(++(warehouse->identityProduct), warehouse);
            printf("Producer product #%d\n", warehouse->identityProduct);
        }
        else
        {
            printf("<!> The warehouse is full and stopped production!\n");
        }
    }
}

void runPnC(Queue *warehouse)
{
    int bool = 1;
    printf("Do you want to begin PnC? (1/0): ");
    scanf("%d", &bool);

    while (bool)
    {
        PnC(warehouse);
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &bool);
    }

    printf("End of PnC\n");
}
