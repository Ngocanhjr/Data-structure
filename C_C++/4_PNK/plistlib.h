#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;

typedef struct CellTag {
    ElementType element;
    struct CellTag* next;
} Cell;

typedef Cell* Position;
typedef Position List;

void printList(List* L) {
    Position p = (*L)->next;
    while (p != NULL) {
        printf("%.2f", p->element);
        p = p->next;
        if (p != NULL) {
            printf(", ");
        }
    }
    if ((*L)->next == NULL) {
        printf("empty");
    }
}

Position makeNull(List* L) {
    List newList = (Cell*)malloc(sizeof(Cell));
    newList->next = NULL;
    newList->element = 10960;  // Dummy value
    (*L) = newList;
    return (*L);
}

ElementType retrieve(Position p, List* L) {
    ElementType value = 0;
    if (p->next != NULL) {
        value = p->next->element;
    }
    return value;
}

Position first(List* L) {
    return (*L);
}

Position previous(Position p, List* L) {
    Position pos = (*L);
    while (pos->next != NULL && pos->next != p) {
        pos = pos->next;
    }
    return pos;
}

Position next(Position p, List* L) {
    return p->next;
}

Position end(List* L) {
    Position last = (*L);
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
}

ElementType popAt(Position p, List* L) {
    List cur = p;
    ElementType value = cur->next->element;
    List del = cur->next;
    cur->next = del->next;
    free(del);
    return value;
}

void insert(ElementType x, Position p, List* L) {
    List newNode = (Cell*)malloc(sizeof(Cell));
    newNode->element = x;
    // newNode->next = NULL;
    List current = p;
    newNode->next = current->next;
    current->next = newNode;
}

Position locate(ElementType x, List* L) {
    Position header = (*L);
    int found = 0;
    while (header->next != NULL && !found) {
        if (header->next->element == x) {
            found = 1;
        } else {
            header = header->next;
        }
    }
    return header;
}