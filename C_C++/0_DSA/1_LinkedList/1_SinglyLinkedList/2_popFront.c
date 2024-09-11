#include <stdio.h>
#include <stdlib.h>

/*
    Lưu lại node đầu trong DSLK để giải phóng
    Cho node head trỏ sang node thứ 2 trong DSLK
    Giải phóng vùng nhớ node đầu trong DSLK đã lưu ở bước 1
*/
typedef struct node{
    int data;
    struct node *next;
}Node;

Node *makeNode (int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushFront(Node **head, int x){
    Node *newNode = makeNode(x);
    newNode->next = (*head);
    (*head) = newNode;
}
void popFront(Node **head){
    // check empty linked list
    if(head == NULL){
        printf("Empty linked list!");
        return;
    }
    Node *delNode = *head;
    *head = (*head)->next;
    free(delNode);
}

void print(Node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main (){
    Node *head = NULL;
    for(int i = 1; i <= 10; i++){
        pushFront(&head, i);
    }
    print(head);
    popFront(&head);
    printf("\n");
    print(head);
}