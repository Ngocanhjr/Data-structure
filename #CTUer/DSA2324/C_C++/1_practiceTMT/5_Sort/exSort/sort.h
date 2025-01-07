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
    printf("List of element: ");
    for (int i = 1; i <= len(L); i++) {
        printf("%d ", getAt(i, L));
    }

    printf("\n");
}

void swap(Position a, Position b, List* L) {
    ElementType temp = getAt(a, *L);
    setAt(a, getAt(b, *L), L);
    setAt(b, temp, L);
}
// // #########################Bubble sort###########################
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
void selectionSort(List * L){
    int length = len(*L);
    for(int i = 1; i < length; i ++){
        int minPos = i;
        for(int j = i + 1; j < length + 1; j++){
            if(getAt(minPos, (*L)) > getAt(j, (*L))){
                minPos = j; 
            }
        }
        swap(i, minPos, L);
    }
}
// #########################Insertion sort########################
void insertionSort(List *L){
    int length = len (*L);
    for(int i = 1; i <= length; i++){
        ElementType temp = getAt(i,(*L));
        int pos = i;
        ///compare a[i] va a[i - 1]
        while(pos > 1 && getAt(pos - 1, *L) > temp){
            setAt(pos,getAt(pos - 1, *L), L);
            pos-=1; 
        }
        setAt(pos,temp, L);
    }
}
// #########################Shell sort############################
void shellSort(List *L){
    int length = len(*L);
    for(int gap = length / 2; gap >= 1; gap /= 2){
        for(int i = gap; i <= length; i++){
            for(int j = i - gap; j >= 0; j -= gap){
                if(getAt(j, *L) > getAt(j + gap, *L)){
                    swap(j, j + gap, L);
                } else {
                    break;
                }
            }
        }
    }
}