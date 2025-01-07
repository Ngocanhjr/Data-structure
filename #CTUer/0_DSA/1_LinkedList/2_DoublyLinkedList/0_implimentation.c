#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *previous;
}Node;

Node *makeNode (int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void print(Node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void pushFront(Node **head, int x){
    Node *newNode = makeNode(x);
    newNode->next = (*head);
    if((*head) != NULL)
        (*head)->previous = newNode;
    (*head) = newNode; // UPDATE HEAD
}

int main (){
    Node *head = NULL;
    for(int i = 10; i >= 1; i--){
       pushFront(&head, i);
    }
    print(head);
}