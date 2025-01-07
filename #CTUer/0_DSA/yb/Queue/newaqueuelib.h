#include <stdio.h>

#define MAX_LENGTH 9

typedef int ElementType;
typedef int Position;

typedef struct queue {
    ElementType elements[MAX_LENGTH];
    Position front, rear;
} Queue;

void makeNull(Queue* Q) {
    Q->front = -1;
    Q->rear = -1;
}

int isEmpty(Queue Q) {
    return Q.front == -1;
}

int size(Queue Q) {
    return Q.rear - Q.front;
}

int isFull(Queue Q) {
    return Q.rear - Q.front == MAX_LENGTH;
}

ElementType front(Queue Q) {
    if (!isEmpty(Q)) {
        return Q.elements[Q.front];
    }
    printf(">>>>Empty<<<");
    return -99;
}

void shift(Queue* Q) {
    int lengthShift = Q->front;
    int size = Q->rear;
    int i;
    for (i = lengthShift; i < size; i++) {
        Q->elements[i - lengthShift] = Q->elements[i];
    }
    Q->rear = i - lengthShift;
    Q->front = 0;
}

void enQueue(ElementType x, Queue* Q) {
    if (isEmpty(*Q)) {
        Q->front = 0;
        Q->rear = 0;
    }
    if (!isFull(*Q)) {
        if (Q->rear == MAX_LENGTH) {
            shift(Q);
        }
        Q->elements[Q->rear] = x;
        Q->rear++;
    } else {
        printf(">>>>Full<<<<");
    }
}

ElementType deQueue(Queue* Q) {
    int value;
    if (!isEmpty(*Q)) {
        if (Q->front == Q->rear) {
            value = front(*Q);
            makeNull(Q);
        } else {
            value = front(*Q);
            Q->front++;
        }
        return value;
    } else {
        printf(">>>>Empty<<<<");
        return -99;
    }
}

void print(Queue Q) {
    int front = Q.front, rear = Q.rear;
    while (front != rear) {
        printf("%d ", Q.elements[front++]);
    }
}
