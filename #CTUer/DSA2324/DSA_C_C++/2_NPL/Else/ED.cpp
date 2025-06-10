

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define EMPTY_QUEUE_ERROR -99

typedef int ElementType;

typedef struct {
    ElementType elements[MAX_LENGTH];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

int isEmpty(Queue Q) {
    return Q.front == Q.rear;
}

int size(Queue Q) {
    return Q.rear - Q.front;
}

int isFull(Queue Q) {
    return Q.rear - Q.front == MAX_LENGTH;
}

void enqueue(Queue *Q, ElementType x) {
    if (!isFull(*Q)) {
        Q->elements[Q->rear % MAX_LENGTH] = x;
        Q->rear++;
    }
}

ElementType dequeue(Queue *Q) {
    if (!isEmpty(*Q)) {
        ElementType frontElement = Q->elements[Q->front % MAX_LENGTH];
        Q->front++;
        return frontElement;
    } else {
        return EMPTY_QUEUE_ERROR;
    }
}

ElementType front(Queue Q) {
    if (!isEmpty(Q)) {
        return Q.elements[Q.front % MAX_LENGTH];
    } else {
        return EMPTY_QUEUE_ERROR;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Queue Q;
    initializeQueue(&Q);

    for (int i = 0; i < N; ++i) {
        char command;
        scanf(" %c", &command);

        if (command == 'E') {
            int x;
            scanf("%d", &x);
            enqueue(&Q, x);
            printf("%d\n", size(Q));
        } else if (command == 'D') {
            ElementType removedElement = dequeue(&Q);
            if (removedElement == EMPTY_QUEUE_ERROR) {
                printf("-1 %d\n", size(Q));
            } else {
                printf("%d %d\n", removedElement, size(Q));
            }
        }
    }

    return 0;
}