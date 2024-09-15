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

ElementType getAt(Position p, List L); // return the element at position p

void setAt(Position p, ElementType x, List *L); // Update the element at position p by a new value x

void insertAt(Position p, ElementType x, List *L); // Insert a new element x

ElementType popAt(Position p, List *L); // Remove and return the element at position p

void insertFirst(ElementType x, List *L); // Inset x to the first element at position p

ElementType popFirst(List *L); // Remove and return the first element

void append(ElementType x, List *L); // Append a new element to the first

ElementType popLast(List *L); // Remove and return a last element

Position locate(ElementType x, List L); // Return the position of the first appearance of x in the list

Position first(List L); // return the first position of list

Position end(List L); // return the end position nof list

void makeNull(List *L){
    Node *header = (Node*)malloc(sizeof(Node));
    header->next = NULL;
    (*L) = header;
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

Position next (int pos, List L){
    List p = L;
    int count = 0;
    while (p->next != NULL && count < pos){
        count++;
        p = p->next;
    }
    return p->next;
}

Position end(List L){
    List p = L;
    while (p->next != NULL){
        p = p->next;
    }
    return p;
}


// endList()
// {
//     next = NULL;
// }
ElementType retrieve(Position p, List L){
    if(p->next != NULL){
        return p->next->data;
    }
}





