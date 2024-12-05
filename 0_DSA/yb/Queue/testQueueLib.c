/*
################# FIFO ##################
*/
// #include "aqueulib.h"
#include "acirclequeuelib.h"
// #include ""E:\RHNA\Visual\2_Data structure\CTUer\C_C++\1_practice\4_Queue\EX5\Circularqueuelib.h""
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
    
}