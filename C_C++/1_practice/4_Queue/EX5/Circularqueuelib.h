//################################# USING ##################################

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 5

typedef int ElementType;

typedef struct queue
{
    ElementType elements[MAX_LENGTH];
    int front, rear;
} Queue;

void makeNullQ(Queue *Q)
{
    Q->front = 0;
    Q->rear = Q->front;
}

int isEmptyQ(Queue Q)
{
    return Q.front == Q.rear;
}

int lenQ(Queue Q)
{
    return (Q.rear + MAX_LENGTH - Q.front) % MAX_LENGTH;
}

int isFullQ(Queue Q)
{
    // return (Q.rear + MAX_LENGTH - Q.front) % MAX_LENGTH == MAX_LENGTH ;

    return (Q.rear + 1) % MAX_LENGTH == Q.front ;
}

void enQueue(ElementType x, Queue *Q)
{
    if (!isFullQ(*Q))
    {
        Q->elements[Q->rear] = x;
        Q->rear = (Q->rear + 1) % MAX_LENGTH;
    }
    else
    {
        printf("<!> Queue is full. Can't enQueue %d\n", x);
    }
}

ElementType deQueue(Queue *Q)
{
    int value = -1;
    if (!isEmptyQ(*Q))
    {
        value = Q->elements[Q->front];
        Q->front = (Q->front + 1) % MAX_LENGTH;
    }
    else
    {
        printf("<!> Queue is empty.");
    }
    return value;
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
    if (!isEmptyQ(Q))
    {
        int sz = lenQ(Q);
        for (int i = 0; i < sz; i++)
            printf("%d ", Q.elements[(i + Q.front) % MAX_LENGTH]);
        printf("\n");
    }
    else
    {
        printf("Hang doi rong!\n");
    }
}
