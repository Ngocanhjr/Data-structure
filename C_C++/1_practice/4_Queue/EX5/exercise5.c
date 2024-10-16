
#include "Ex.h"

int main (){
    Stack S;
    makeNullS(&S);

    Queue Q;
    makeNullQ(&Q);

    printf("--------------------------Test Stack------------------\n");
    for(int i = 0; i < 5; i++){
        push(i,&S);
    }
    printS(S);
    reverseStack(&S);
    printS(S);

    printf("--------------------------Test Queue------------------\n");
    for(int i = 0; i < 5; i++){
        enQueue(i,&Q);
    }
    printQ(Q);
    reverseQueue(&Q);
    printQ(Q);

    printf("--------------------------Test PnC------------------\n");
    Queue warehouse;
    makeNullQ(&warehouse);
    runPnC(&warehouse);
    return 0;
}