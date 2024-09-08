#include <stdio.h>
#include <stdlib.h>

/*
    Duyệt đến node k - 1 trong DSLK
    Lưu lại địa chỉ node thứ k
    Cho node k - 1 trỏ vào node k + 1
    Giải phóng vùng nhớ node thứ k đã lưu ở bước 2
*/
typedef struct node {
    int data;
    struct node *next;
}Node;

void print(Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int length(Node *head){
    int cnt = 0;
    while(head != NULL){
        cnt ++;
        head = head->next;
    }
    return cnt;
}
Node *makeNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void pushFront(Node **head, int value){
    Node *newNode = makeNode(value);
    newNode->next = (*head);
    (*head) = newNode;
}

void pushBack(Node **head, int value){
    Node *newNode = makeNode(value);

    if ((*head) == NULL){
        (*head) == newNode;
        return;
    } else {
        Node *temp = (*head);
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp = newNode;
    }
}

void popFront(Node **head){
    if((*head) == NULL)
    {
        printf("Empty linked list!");
        return;
    } else {
        Node *delNode = (*head);
        (*head) = (*head)->next;
        // (*head) = NULL;
        free(delNode);
    }
}
void eraseNode(Node **head, int index){
    if(index < 1 || index > length((*head))){
        printf("Invalid position!");
        return; 
    } 
    /*
    Chú ý : Nếu DSLK đơn chỉ có 1 node thì bạn cần xử lý riêng
    vì với việc xóa trong DSLK đơn nếu bạn xóa node thứ k ta cần tới được node thứ k - 1
    và tìm cách kết nối node này với node k + 1.
    */
    else if (index == 1){
        popFront(head);
    }
    else 
    {
        Node *previous = (*head);
        for (int i = 1; i <= index - 2; i++){
            previous = previous->next;
        }
        Node *current = previous->next;
        //Cho k - 1 => tro vao k + 1
        previous->next = current->next;
        free(current);
    }

}

int main (){
    Node *head = NULL;
    for(int i = 1; i <= 10; i++){
        pushFront(&head, i);
    }
    print(head);
    eraseNode(&head, 4);
    printf("\n");
    print(head);
    
}