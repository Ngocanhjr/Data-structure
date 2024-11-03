#include "sort.h"

int main() {
    List L;
    makeNull(&L);
    int a[] = {1, 3, 2, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    readList(a, n, &L);
    printList(L);
    // bubbleSort(&L);
    // print(L);
    return 0;
}