/*
    Cấp phát động một node mới
    Cho node mới lưu địa chỉ của node head (trỏ tới head)
    Cho node head trỏ ngược lại node mới (lưu địa chỉ node mới)
    Cập nhật head thành node mới tạo 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}Node;

Node *makeNode (int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int length (Node *head){
    int cnt;
    while(head != NULL){
        cnt ++;
        head = head->next;
    }
    return cnt;
}
void pushFront(Node **head, int x)
{
    Node *newNode = makeNode(x);
    if((*head) != NULL)
        (*head)->prev = newNode;
    newNode->next = (*head);
    (*head) = newNode;
}

void pushBack(Node **head, int x){
    Node *newNode = makeNode(x);
    if((*head) == NULL){
        (*head) = newNode;
        return;
    } else {
        Node *temp = (*head);
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
} 

/*
    Cấp phát động một node mới
    Duyệt tới node thứ K trong DSLK
    Cho node mới trỏ tới node thứ K 
    Cho node K - 1 trỏ vào node mới 
    Cho node mới trỏ ngược lại node K - 1
    Cho node K trỏ ngược lại node mới
*/
void insert(Node **head, int value, int idx){
    int len = length(*head);
    if(idx < 1 || idx > len){
        printf("Invalid position!");
        return;
    } else if(idx == 1){   
        pushFront(head, value);
        return ;
    } else {
        Node *newNode = makeNode(value);
        Node *temp= (*head);
        for(int i = 1 ; i <= idx - 1; i++){
            temp = temp->next;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode; //next of k - 1
        temp->prev = newNode;
    }
}
void print(Node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}


int main (){
    Node *head = NULL;
    for(int i = 10; i >= 1; i--){
       pushBack(&head, i);
    }
    print(head);
    insert(&head, 50 ,5);
    print(head);
}