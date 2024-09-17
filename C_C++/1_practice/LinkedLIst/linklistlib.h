#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct NodeTag{
    ElementType data;
    struct NodeTag *next;
}Node;

typedef Node* List;
typedef Node* Position;

void makeNull(List *L); //Initialize an empty list

int len(List L); //Number of elements

int empty(List L); //Check whether the list is empty?

void print(List L); //Traverse the list to print out all elements

ElementType getAt(int idx, List L); // return the element at position idx

Position getPosition(int idx, List L); //return the pointer referring to the pos_th element 

Position first(List L); // return the pointer referring tho the first element of L

Position end(List L); // return the pointet to the last element of L

void setAt(int idx, ElementType x, List *L); // Update the element at position p by a new value x

void insertAt(int idx, ElementType x, List *L); // Insert a new element x at position p

ElementType popAt(int idx, List *L); // Remove and return the element at position p

void insertFirst(ElementType x, List *L); // Inset x to the first element at position p

ElementType popFirst(List *L); // Remove and return the first element

void append(ElementType x, List *L); // Append a new element to the first

ElementType popLast(List *L); // Remove and return a last element

Position locate(ElementType x, List L); // Return the position of the first appearance of x in the list

Position next(int idx, List L); //return the pointer referring to the next position of pos in L

Position previous(int idx, List L);   

ElementType retrieve(Position p, List L);

void makeNull(List *L){
    Node *header = (Node*)malloc(sizeof(Node));
    header->next = NULL;
    (*L) = header;
}

int len(List L){
    int count = 0;
    while (L->next != NULL){
        count++;
        L = L->next;
    }
    return count;
}

int empty(List L){
    return L->next == NULL;
}

void print(List L){
    List header = L;
    while (header->next != NULL)
    {
       printf("%d ", header->data);
       header = header->next;
    }
}

ElementType getAt(int idx, List L){
    Position p = getPosition(idx, L);
    return retrieve(p, L);
}

Position getPosition(int pos, List L){
    List p = L;
    int count = 0;
    while(p->next != NULL && count < pos){
        count++;
        p = p->next;
    }
    return p;
}

Position first(List L){
    return L;
    // List p = L;
    // return p;
}

Position end(List L)
{
    Position p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

void setAt(int idx, ElementType x, List *L){
    List p = getPosition(idx, *L);
    p->next->data = x;
}

void insertAt(int idx, ElementType x, List *L){
    List source = getPosition(idx, *L);
    List temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = source->next;
    source->next = temp; 
}

ElementType popAt(int idx, List *L){
    if(idx > 0 && idx <= len(*L)){
        List p = getPosition(idx, *L);
        ElementType value = retrieve(p, *L);
        List delNode = p->next;
        p->next = delNode->next;
        free(delNode);
        return value;
    } else {
        printf("invalid position!");
    }
}

void insertFirst(ElementType x, List *L){
    List newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = (*L)->next;
    (*L)->next = newNode;
}

ElementType popFirst(List *L){
    if(empty){
        return;
    } else {
        List delNode = getPosition(1, *L);
        delNode = next(1, *L);
        free(delNode);
    }
}

Position next (int pos, List L){
    List p = L;
    int count = 0;
    while (p->next != NULL && count < pos){
        count++;
        p = p->next;
    }
    return p->next;
}

Position previous(int idx, List L){
    List header = L;
    if(empty){
        return;
    } else{
        int count = 0;
        while (header->next != NULL && count < idx - 1){
            count++;
            header = header->next;
        }
    return header->next;
    }
}

void append(ElementType x, List *L){
    insertAt(len(*L), x, L);
}

ElementType popLast(List *L){
    Position end = getPosition(len(*L), *L) ;
    int value = retrieve(end, *L);
    popAt(len(*L), L);
    return value;
}

Position locate(ElementType x, List L){
    List p = L;
    while(p->next != NULL){
        if(x == retrieve(p, L));
            return p;
        p = p->next;
    }
    return p;
}

ElementType retrieve(Position p, List L){
    if(p->next != NULL){
        return p->next->data;
    }
}





