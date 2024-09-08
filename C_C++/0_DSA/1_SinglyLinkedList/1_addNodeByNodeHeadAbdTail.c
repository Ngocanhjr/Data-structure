#include <stdio.h>
#include <stdlib.h>
//Thêm node vào đầu DSLK quản lý bằng node head và tail
struct node{
    int data;
    struct node *next;
};

typedef struct node Node;

typedef struct {
    Node *head;
    Node *tail;
} List;

void print(List L){
    if(L.head == NULL){
        printf("Danh sach rong!");
    } else{
        Node* temp = L.head;
        while (temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void themDau(List *L, int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if(L->head == NULL){
        L->tail = newNode;
    } 
    newNode->next = L->head;
    L->head = newNode;
}

int main (){
    List L;
    L.head = NULL; L.tail = NULL;
    for (int i = 0; i < 10; i++){
        themDau(&L, i);
    }
    print(L);
}