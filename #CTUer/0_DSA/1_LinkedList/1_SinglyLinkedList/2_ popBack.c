#include <stdio.h>
#include <stdlib.h>
/*
    Duyệt đến node thứ 2 từ cuối về
    Lưu lại node cuối trong DSLK
    Cho node thứ 2 trong DSLK trỏ vào NULL
    Giải phóng vùng nhớ node cuối đã lưu ở bước 2
*/
typedef struct node {
    int data;
    struct node *next;
}Node;

Node *makdeNode (int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void print(Node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
} 

void pushFront(Node **head, int x){
    Node *newNode = makdeNode(x);
    newNode->next = (*head);
    (*head) = newNode;
}  

void popBack (Node **head){
    if((*head) == NULL){
        printf("Empty linked list!");
        return;
    }
    else if((*head)->next == NULL){
        free(*head); //gỉa phóng vùng nhớ
        (*head) == NULL;
    } else {
        Node *temp = *head;
        while (temp->next->next != NULL){
            temp = temp->next;
        }
        Node *last = temp->next;
        temp->next = NULL;
        free(last);
    }
}
int main (){
    Node *head = NULL;
    for(int i = 1; i <= 10; i++){
        pushFront(&head, i);
    }
    print(head);
    popBack(&head);
    printf("\n");
    print(head);
}