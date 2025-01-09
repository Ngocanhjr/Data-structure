#include "aliststudentlib.c"

int main (){
    List L;
    makeNull(&L);
    readList(&L);
    printList(L);
    sort(&L);
    printList(L);
    return 0;
}
