#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tag
{
    ElementType data;
    struct tag *next;
} Node;

typedef struct queueTag
{
    Node *front;
    Node *rear;
} Queue;

void makeNull(Queue *Q)
{
    Node *header = (Node *)malloc(sizeof(Node));
    header->next == NULL;
    Q->front = header;
    Q->rear = Q->front;
}

int isEmpty(Queue Q)
{
    return Q.front == Q.rear;
}

void enQueue(ElementType x, Queue *Q)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
}

ElementType deQueue(Queue *Q)
{
    if (isEmpty(*Q))
    {
        printf("<!> Queue is empty.");
    }
    else
    {
        int value = Q->front->next->data;
        Node *del = Q->front;
        Q->front = del->next;
        free(del);
        return value;
    }
}

ElementType front(Queue Q)
{
    return Q.front->next->data;
}