#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next; // cho head chuyen sang node ke tiep
    }
}

void themdau(node **head, int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->next = (*head);
    (*head) = newNode;
}

int len(node *head){
    int dem = 0;
    while(head != NULL){
        ++dem;
        head = head->next; // cho head chuyen sang node ke tiep
    }
    return dem;
}

void xoadau(node **head){
    if(*head == NULL) return; // DSLK rong
    node *deleteNode = *head;
    //Cho node head thanh node thu 2 trong DSLK
    (*head) = (*head)->next; 
    //Giai phong vung nho
    free(deleteNode);
}

void xoagiua(node **head, int k){
    if(k < 1 || k > len(*head)) return; // vi tri xoa ko hop le
    if(k == 1){
        xoadau(head);
    }
    else{
        node *tmp = (*head);
        //Duyet den node k - 1
        for(int i = 1; i <= k - 2; i++){
            tmp = tmp->next;
        }
        //Luu lai node thu k
        node *delNode = tmp->next;
        //Cho k - 1 => tro vao k + 1
        tmp->next = delNode->next;
        //Giai phong node thu k
        free(delNode);
    }
}

int main(){
    node *head = NULL;
    for(int i = 1; i <= 10; i++){
        themdau(&head, i);
    }
    duyet(head);
    xoagiua(&head, 4);
    printf("\n");
    duyet(head);
}