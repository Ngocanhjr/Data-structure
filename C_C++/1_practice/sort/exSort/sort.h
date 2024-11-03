// #include "../../2_LinkedList/D_EX3/alistlib.h"
// #include "C_C++/1_practice/2_LinkedList/D_EX3/plistlib.h"
#include "alistlib.h"
// #include "plistlib.h"

void readList(int a[], int sizeArray, List* L) {
    // int sizeArray = sizeof(a) / sizeof(a[0]);
    while (sizeArray > 0) {
        insertFirst(a[sizeArray - 1], L);
        sizeArray--;
    }
}

void printList(List L) {
    if (empty(L)) {
        printf("List is empty!\n"); 
        return;
    }
    if (fullList(L)) {
        printf("List is full!\n");
    }
    printf("List of element: ");
    // for (int i = first(L); i < endList(L); i++) {
    //     printf("%d ", getAt(i, L));
    // }
    int i = first(L);
    while (i <=  len(L)) {
        printf("%d ", getAt(i, L));
        i = next(i, L);
    }
    printf("\n");
}

void swap(Position a, Position b, List* L) {
    int temp = getAt(a, *L);
    setAt(a, getAt(b, *L), L);
    setAt(b, temp, L);
}
// #########################Bubble sort###########################
void bubbleSort(List* L) {
    int length = len(*L);
    for (int i = 1; i < length; i++) {
        for (int j = 1; j <= length - i; j++) {
            if (getAt(j, *L) > getAt(j + 1, *L)) {
                swap(j, j + 1, L);
            }
        }
    }
}
// ########################Selection sort#########################
// #########################Insertion sort########################
// #########################Shell sort############################
