#include <stdio.h>

#define MAX_LENGTH 100

typedef int ElementType;

typedef struct queue {
    ElementType elements[MAX_LENGTH];
    int front, rear;
} Queue;

void makeNull(Queue* Q) {
    Q->front = -1;
    Q->rear = -1;
}

int isEmpty(Queue Q) {
    return Q.front == -1;
}

int isFull(Queue Q) {
    return (Q.rear - Q.front + 1) == MAX_LENGTH;
}

ElementType front(Queue Q) {
    if (!isEmpty(Q)) {
        return Q.elements[Q.front];
    } else {
        printf("<!> Queue is empty.");
    }
}

void deQueue(Queue* Q) {
    if (isEmpty(*Q)) {
        printf("<!> Queue is empty.");
    } else if (Q->front == Q->rear) {
        makeNull(Q);
    } else {
        Q->front++;
    }
}

void enQueue(ElementType x, Queue* Q) {
    if (!isFull(*Q)) {
        if (isEmpty(*Q)) {
            Q->front = 0;
        }
        if (Q->rear == MAX_LENGTH - 1) {  // row overflow
            // move row forward front positions
            for (int i = Q->front; i <= Q->rear; i++) {
                Q->elements[i - Q->front] = Q->elements[i];
            }
            Q->rear -= Q->front;
            Q->front = 0;
        }

        Q->rear++;
        Q->elements[Q->rear] = x;
    } else {
        printf("<!> Queue is full.");
    }
}