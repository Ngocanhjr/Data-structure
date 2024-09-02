
#include "alistlib.h"

int main() {
    int temp;
    makeNull(&L);
    print(L);
    printf("\n----------------------------------------------------\n");

    append(10, &L);
    append(20, &L);
    append(30, &L);

    printf("APPEND\n");
    print(L);
    printf("\n");

    insertFirst(5, &L);
    printf("INSERT AT FIRST\n");
    print(L);
    printf("\n");
    
    temp = 2;
    insertAt(temp, 15, &L);
    printf("INSERT AT %d :\n", temp);
    print(L);
    printf("\n----------------------------------------------------\n");
    
    printf("DELETE FIRST ELEMENT\nValue at first: %d\n", popFirst(&L));
    print(L);
    printf("\n");

    temp = 2;
    printf("DELETE AT %d\n", temp);
    printf("Value: %d\n", popAt(temp,&L));
    print(L);
    printf("\n");

    printf("DELETE LAST ELEMENT\nValue at last: %d\n", popLast(&L));
    print(L);
    printf("\n----------------------------------------------------\n");

    temp = 48;
    printf("SET %d AT 5\n", temp);
    setAt(5,temp,&L);
    print(L);
    printf("\n----------------------------------------------------\n");

    append(5, &L);
    append(7, &L);
    append(2, &L);
    append(44, &L);
    append(52, &L);
    append(33, &L);
    printf("APPEND\n");
    print(L);
    printf("\n");

    printf("FOUND\n");
    temp = 20;
    printf("Found: %d\n", temp);
    Position pos = locate(temp, L);
    if (pos)
        printf("Element at: %d\n", pos);
    else
        printf("Not founded!.\n");
    
    temp = 44;
    printf("Found: %d\n", temp);
    pos = locate(temp, L);
    if (pos)
        printf("Element at: %d\n", pos);
    else
        printf("Not founded!.\n");
    printf("----------------------------------------------------\n");
    
    printf("SORT\n");
    sort(&L);
    print(L);
    printf("\nMAKE NULL\n");
    makeNull(&L);
    print(L);
    return 0;
}