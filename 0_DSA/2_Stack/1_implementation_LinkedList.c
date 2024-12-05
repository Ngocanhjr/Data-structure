#include <stdio.h>
#include <stdlib.h>

//Linked list
typedef struct node{
    int data;
    struct node *next;
}Node;

Node *makeNode (int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int length (Node *top){
    int cnt;
    while (top != NULL){
        cnt++;
        (top) = (top)->next;
    }
}
void pushStack(Node **top, int value){
    Node *newNode = makeNode(value);
    if(*top == NULL){
        newNode->data = value;
        return;
    } 
    newNode->next = (*top);
    (*top) = newNode;
}

void popStack(Node **top){
    //xử lý trường stack = 0, và stack = 1
    if(*top == NULL)
        printf("stack is empty");
    else if((*top)->next == NULL){
        Node *delNode = (*top);
        (*top) = NULL;
        free(delNode);
    } else 
    {
        Node *temp = (*top);
        while (temp->next->next != NULL){
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        free(delNode);
    }
}

int main (){





}