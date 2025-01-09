#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef int ElementType;

typedef struct queue
{
    ElementType elements[MAX_LENGTH];
    int front, rear;
} Queue;

void makeNull(Queue *Q)
{
    Q->front = 0;
    Q->rear == Q->front;
}

int isEmpty(Queue Q)
{
    return Q.front == Q.rear;
}

int len(Queue Q)
{
    return (Q.rear + MAX_LENGTH - Q.front) % MAX_LENGTH;
}

int isFull(Queue Q)
{
    return (Q.rear + 1) % MAX_LENGTH == Q.front;
}

void enQueue(ElementType x, Queue *Q)
{
    if (!isFull(*Q))
    {
        Q->elements[Q->rear] = x;
        Q->rear = (Q->rear + 1) % MAX_LENGTH;
    }
    else
    {
        printf("<!> Queue is full.");
    }
}

void deQueue(Queue *Q)
{
    if (!isEmpty(*Q))
    {
        Q->front = (Q->front + 1) % MAX_LENGTH;
    }
    else
    {
        printf("<!> Queue is empty.");
    }
}

ElementType front(Queue Q)
{
    if (!isEmpty(Q))
    {
        return Q.elements[Q.front];
    }
    else
    {
        return -1;
    }
}