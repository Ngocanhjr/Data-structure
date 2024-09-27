#include <stdio.h>

#define MAX_LENGTH 100

typedef int ElementType;

typedef struct queue{
    ElementType elements[MAX_LENGTH];
    int front, rear;
}Queue;

void makeNull (Queue *Q){
    Q->front = -1;
    Q->rear = -1;
}

int isEmpty (Queue Q){
    return Q.front == -1;   
}

int isFull(Queue Q){
    return (Q.rear - Q.front + 1) == MAX_LENGTH;
}