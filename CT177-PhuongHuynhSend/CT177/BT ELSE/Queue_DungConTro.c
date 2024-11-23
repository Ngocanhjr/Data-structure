#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElementType;
struct Node {
    ElementType Element ;
    struct Node *Next;
};
typedef struct Node* Position;
typedef struct {
    Position Front,Rear;
}Queue;

void makenullQueue (Queue *pQ) {
    Position Header;
    Header = (struct Node*) malloc(sizeof(struct Node));
    Header ->Next =NULL;
    pQ->Front = Header;
    pQ->Rear =Header;
} 
int emptyQueue(Queue Q) {
    return (Q.Front ==Q.Rear);
}
