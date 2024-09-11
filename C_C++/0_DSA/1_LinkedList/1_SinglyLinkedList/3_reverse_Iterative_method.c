#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;

Node *makeNode(int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next  = NULL;
    return newNode;
}

Node *reverse(Node *head){
    Node *current = head;
    Node *next = NULL;
    Node *previous = NULL;
    while (current!= NULL)
    {
        next = current->next; // giữ tạm địa chỉ thằng thứ 2, 
        current->next = previous; //giữ địa chỉ của tk trước đó, ban đầu là NULL
        previous->next = current; // trỏ tới địa chỉ của current, ban đầu là head
        current = next; // cập nhật head
    }
    head = previous;
    return head;
    
}
int main (){

}