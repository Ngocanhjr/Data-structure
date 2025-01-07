#include "sort.h"

int main() {
    printf("Hello, world!\n");
    List L;

    makeNull(&L);

    int a[] = {3, 7, 8, 5, 4, 2, 6, 1};
    int b[] = {100, 3, 2, 5, 44, 12, 9, 8, 10, 6, 10, 11};
    int c[] = {110};
    int d[] = {0};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int o = sizeof(c) / sizeof(c[0]);
    int p = 0;
    printf("##################################################\n");
    printf("Test 1:\n");
    readList(a, n, &L);
    printList(L);
    printf("Length of list: %d\n", len(L));
    // bubbleSort(&L);
    // selectionSort(&L);
    // insertionSort(&L);
    shellSort(&L);
    printList(L);

    printf("##################################################\n");
    makeNull(&L);
    printf("Test 2:\n");
    readList(b, m, &L);
    printList(L);
    printf("Length of list: %d\n", len(L));
    // bubbleSort(&L);
    // selectionSort(&L);
    // insertionSort(&L);
    shellSort(&L);
    printList(L);

    printf("##################################################\n");
    makeNull(&L);
    printf("Test 3:\n");
    readList(c, o, &L);
    printList(L);
    printf("Length of list: %d\n", len(L));
    // bubbleSort(&L);
    // selectionSort(&L);
    // insertionSort(&L);
    shellSort(&L);
    printList(L);

    printf("##################################################\n");
    makeNull(&L);
    printf("Test 4:\n");
    readList(d, p, &L);
    printList(L);
    printf("Length of list: %d\n", len(L));
    // bubbleSort(&L);
    // selectionSort(&L);
    // insertionSort(&L);
    shellSort(&L);
    printList(L);

    return 0;
}