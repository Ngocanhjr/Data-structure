/*
################# FIFO ##################
*/
// #include "aqueulib.h"
#include "acirclequeuelib.h"
// #include "pqueulib.h"

void readQueue(Queue *Q)
{
    int size;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    for (int i = 1; i <= size; i++)
    {
        enQueue(i, Q);
    }
}

void print(Queue Q)
{
    printf("Queue: ");
    while (!isEmpty(Q))
    {
        printf("%d ", front(Q));
        deQueue(&Q);
    }
}

int main()
{
    Queue Q;
    makeNull(&Q);
    readQueue(&Q);
    print(Q);
    return 0;
}