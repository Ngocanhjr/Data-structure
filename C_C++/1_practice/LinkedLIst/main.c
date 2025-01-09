#include "listlib.h"
// #include "demo.h"
int main()
{
    int temp;
    List L;
    makeNull(&L);
    // DONE
    //  printf("\n------------------CHECK EMPTY FUNCTION----------------------\n");
    //  print(L);

    printf("--------------------APPEND FUNCTION-------------------------\n");
    for (int i = 15; i > 7; i--)
    {
        append(i, &L);
    }
    print(L);

    // DONE
    //  printf("\n--------------------LENGTH FUNCTION-------------------------\n");
    //  printf("Length: %d", len(L));

    printf("\n-------------GET AT POSITION FUNCTION-------------------------\n");
    temp = 1;
    printf("At %d value is: %d", temp, getAt(temp, L));

    printf("\n-------------FIRST END NEXT PREVIOUS--------------------------\n");
    temp = 3;
    printf("Current: %d\t", retrieve(getPosition(temp, L), L));
    printf("First: %d\t", retrieve(first(L), L));
    printf("End: %d\t", retrieve(end(L), L));
    printf("Next: %d\t", retrieve(next(temp, L), L));
    printf("Previous: %d\n", retrieve(previous(temp, L), L));

    printf("---------------------POP--------------------------------------\n");
    print(L);
    temp = 4;
    printf("\nCurrent: %d\n", popFirst(&L));
    printf("New value at first: %d\n", retrieve(first(L), L));
    printf("Current: %d\n", popLast(&L));
    printf("New value at last: %d\n", retrieve(end(L), L));
    print(L);
    temp = 3;
    printf("\nCurrent: %d\n", popAt(temp, &L));
    printf("New value at %d: %d\n", temp, retrieve(getPosition(temp, L), L));

    printf("---------------------INSERT--------------------------------------\n");
    print(L);
    temp = 5;
    insertFirst(55, &L);
    printf("\nInsert first: %d\n", getAt(0, L));
    print(L);
    insertAt(temp, 60, &L);
    printf("\nInsert at %d: %d\n", temp, getAt(temp, L));
    print(L);
    setAt(temp, 70, &L);
    // print(L);
    printf("\nSet at %d: %d\n", temp, getAt(temp, L));
    print(L);

    printf("\n---------------------LOCATE--------------------------------------\n");
    temp = 9;
    printf("Locate %d: %d\n", temp, locate(temp, L));
    printf("value: %d\n", getAt(locate(temp, L), L));
}