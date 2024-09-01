#include <stdio.h>
#include "alistlib.h"

void makeNull( List *pL){
    pL->size = 0;
}

void build(ElementType A[], int n,List *pL){
    for (int i = 0; i < n; i++){
        pL->element[i] = A[i];
    }
    pL->size = n;
}

int len(List L){
    return L.size;
}

int empty(List L){
    return L.size == 0;
}

int fullList(List L){
    return L.size == MAXSIZE;
}

void print(List L){
    printf("List of element: ");
    for (int i = 0; i < len(L); i++){
        printf("%d ", getAt(i, L));
    }
}

ElementType getAt(Position p, List L){
    return L.element[p];
}

void setAt(Position p, ElementType x, List *pL){
    pL->element[p] = x;
}

void insertAt(Position p, ElementType x, List *pL){
    if(p < 0 || p > len(*pL)){
        printf("invalid position!");
        return;
    } else if (fullList(*pL)){
        printf("List is full!");
        return;
    } else{
        for ( int i = pL->size; i > p; i--){
            pL->element[i] = pL->element[i - 1];
        }
        pL->element[p] = x;
        pL->size++;
    }
}

ElementType popAt(Position p, List *pL){
    if(p < 0 || p > len(*pL)){
        printf("invalid position!");
    return;
    } else {
        for(int i = p; i < pL->size; i++){
            pL->element[p] = pL->element[p + 1];
        }
        pL->size--;
        return pL->element[p];
    }
}

void insertFirst(ElementType x, List *pL){
    insertAt(0,x,pL);
}

ElementType popFirst(List *pL){
    popAt(0,pL);
    return pL->element[0];
}

void append(ElementType x, List *pL){
    pL->size++;
    pL->element[len(*pL) - 1] = x;
}

ElementType popLast(List *pL){
    pL->size--;
    return pL->element[pL->size];
}

Position locate(ElementType x, List L){
    int found = 0;
    for ( int i = 0; i < len(L); i++){
        if(getAt(i, L) == x)
        {
            found = i;
        }
    }
    return found;
}
