#include <stdio.h>

#define MAX_LENGTH 10
#define EMPTY_QUEUE_ERROR -99

typedef int ElementType;

typedef struct tag
{
	ElementType elements[MAX_LENGTH];
	int front, rear;
} Queue;

void makeNull(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
}

int isEmpty(Queue Q)
{
	return Q.front == Q.rear;
}

int size(Queue Q)
{
	return Q.rear - Q.front;
}

int isFull(Queue Q)
{
	return Q.rear - Q.front == MAX_LENGTH;
}

ElementType front(Queue Q)
{
	if (!isEmpty(Q))
	{
		return Q.elements[Q.front];
	}
	printf(">>>>Empty<<<");
	return EMPTY_QUEUE_ERROR;
}

void shift(Queue *Q)
{
	int front = Q->front;
    int rear = Q->rear;
    int i;
	for (i = front; i < rear; i++)
	{
		Q->elements[i - front] = Q->elements[i];
	}
	Q->rear = i - front;
	Q->front = 0;
}

void enQueue(ElementType x, Queue *Q) //diff
{
    if (!isFull(*Q))
    {
        if (Q->rear == MAX_LENGTH)
        {
            shift(Q);
        }
        Q->elements[Q->rear++] = x; // diff
    }
    else
    {
        printf(">>>>Full<<<<");
    }
}

ElementType deQueue(Queue *Q)
{
    int value;
    if (!isEmpty(*Q))
    {
        value = front(*Q);
        if (Q->front == Q->rear - 1)
        {
            makeNull(Q);
        }
        else
        {
            Q->front++;
        }
        return value;
    }
    else
    {
        printf(">>>>Empty<<<<");
        return EMPTY_QUEUE_ERROR;
    }
}

void print(Queue Q)
{
    if (!isEmpty(Q))
    {
        int front = Q.front, rear = Q.rear;
        while (front != rear)
        {
            printf("%d ", Q.elements[front++]);
        }
    }
    else
    {
        printf(">>>>Empty<<<<");
    }
}