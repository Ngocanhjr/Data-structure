#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 5

typedef int ElementType;

typedef struct queue
{
    ElementType elements[MAX_LENGTH];
    int front, rear;
} Queue;

void makeNull(Queue *Q)
{
    Q->front = -1;
    Q->rear = Q->front;
}

int isEmpty(Queue Q)
{
    return Q.front == -1;
}

int len(Queue Q)
{
    if(isEmpty(Q))
        return 0;
    return (Q.rear + MAX_LENGTH - Q.front) % MAX_LENGTH + 1;
}

int isFull(Queue Q)
{
    return (Q.rear + 1) % MAX_LENGTH == Q.front;
}

void enQueue(ElementType x, Queue *Q)
{
    if (!isFull(*Q))
    {
        if (isEmpty(*Q))
        {
            Q->front = 0;
            ;
        }
        Q->rear = (Q->rear + 1) % MAX_LENGTH;
        Q->elements[Q->rear] = x;
    }
    else
    {
        printf("<!> Queue is full. Can't enQueue %d\n", x);
    }
}

ElementType deQueue(Queue *Q)
{
    if (!isEmpty(*Q))
    {
        ElementType value = Q->elements[Q->front];
        if (Q->front == Q->rear)
            makeNull(Q);
        else
            Q->front = (Q->front + 1) % MAX_LENGTH;
            return value;
    }
    else
    {
        printf("<!> Queue is empty. ");
        return -1;
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

void print(Queue Q)
{
    if (isEmpty(Q))
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