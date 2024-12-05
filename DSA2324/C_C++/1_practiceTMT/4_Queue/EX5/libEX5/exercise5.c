#include "Circularqueuelib.h"
#include "stacklib.h"
#include <time.h>

int code = 0;

void reverseStack(Stack *S)
{
    Queue Q;
    makeNull(&Q);
    while (!(isEmptyS(*S)))
    {
        enQueue(pop(S), &Q);
    }
    while (!isEmpty(Q))
    {
        push(deQueue(&Q), S);
    }
}

void reverseQueue(Queue *Q)
{
    Stack S;
    makeNullS(&S);

    while (!isEmpty(*Q))
    {
        push(deQueue(Q), &S);
    }
    while (!(isEmptyS(S)))
    {
        enQueue(pop(&S), Q);
    }
}

void PnC(Queue *warehouse)
{
    int random = rand() % 100 + 1;
    // srand(time(NULL));
    // int random = rand() % 100 + 1;
    printf("Random number: %d\n", random%2);

    if (random % 2 == 0)
    {
        // Call Consumer
        if (!isEmpty(*warehouse))
        {
            printf(">>Consumer product #%d\n", deQueue(warehouse));
        }
        else
        {
            printf("<!> The warehouse is out of stock and temporarily suspends sales!\n");
        }
    }
    else
    {
        // call Producer
        if (!isFull(*warehouse))
        {
            enQueue(++code, warehouse);
            printf("Product #%d was successfully produced !\n", code);
        }
        else
        {
            printf("<!> The warehouse is full and stopped production!\n");
        }
    }
}

void runAutoPnC(Queue *warehouse)
{
    for(int i = 0; i < 15; i++){
        PnC(warehouse);
        print(*warehouse);
        printf("--------------------------\n");
    }
    printf("End of PnC\n");
}

void runPnC(Queue *warehouse)
{
    int bool = 1;
    printf("Do you want to begin PnC? (1/0): ");
    scanf("%d", &bool);

    while (bool)
    {
        PnC(warehouse);
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &bool);
        print(*warehouse);
        printf("--------------------------\n");
    }
    printf("End of PnC\n");
}

int main (){
    Stack S;
    makeNullS(&S);

    Queue Q;
    makeNull(&Q);

    printf("--------------------------Test Stack------------------\n");
    for(int i = 0; i < 6; i++){
        push(i,&S);
    }
    printS(S);
    reverseStack(&S);
    printS(S);

    printf("--------------------------Test Queue------------------\n");
    for(int i = 7; i < 15; i++){
        enQueue(i,&Q);
    }
    print(Q);
    reverseQueue(&Q);
    print(Q);

    printf("--------------------------Test PnC------------------\n");
    Queue warehouse;
    makeNull(&warehouse);
    code = 0;
    // runPnC(&warehouse);
    runAutoPnC(&warehouse);
    return 0;
}