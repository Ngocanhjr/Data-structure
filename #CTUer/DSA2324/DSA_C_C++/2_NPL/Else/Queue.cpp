#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
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

void enQueue(ElementType x, Queue *Q) // diff
{
    if (!isFull(*Q))
    {
        if (Q->rear == MAX_LENGTH)
        {
            shift(Q);
        }
        Q->elements[Q->rear++] = x; // diff
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
        return EMPTY_QUEUE_ERROR;
    }
}

// void print(Queue Q)
// {
//     if (!isEmpty(Q))
//     {
//         int front = Q.front, rear = Q.rear;
//         while (front != rear)
//         {
//             printf("%d ", Q.elements[front++]);
//         }

//         printf("%d\n", size(Q));
//     }
//     else
//     {
//         printf("-1 0\n");
//     }
// }

int main()
{
    int n;
    scanf("%d", &n);
    char c;
    Queue Q;
    makeNull(&Q);
    for (int i = 1; i <= 5; i++)
    {
        scanf(" %c", &c);
        if (c == 'E')
        {
            int x;
            scanf("%d", &x);
            enQueue(x, &Q);
            printf("%d\n", size(Q));
        }
        else if (c == 'D')
        {
            int value = deQueue(&Q);
            if (value == EMPTY_QUEUE_ERROR)
            {
                printf("-1 %d\n", size(Q));
            } else {
                printf("%d %d\n",value, size(Q));
            }   
        }
    }
    return 0;
}
int main() {
    int N;
    scanf("%d", &N);
    Queue Q;
    makeNull(&Q);

    for (int i = 0; i < N; ++i) {
        char command;
        scanf(" %c", &command);

        if (command == 'E') {
            int x;
            scanf("%d", &x);
            enQueue(x, &Q);
            printf("%d\n", size(Q));
        } else if (command == 'D') {
            ElementType removedElement = deQueue(&Q);
            if (removedElement == EMPTY_QUEUE_ERROR) {
                printf("-1 %d\n", size(Q));
            } else {
                printf("%d %d\n", removedElement, size(Q));
            }
        }
    }

    return 0;