#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}Node;

void print(Node *head){
    if(head == NULL){
        printf("Empty linked list!");
        return;
    } 
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int length(Node *head){
    int cnt;
    while (head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *makeNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void pushBack (Node **head, int value){
    Node *newNode = makeNode(value);
    if((*head == NULL)){
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

void popFront(Node **head){
    if((*head) == NULL){
        printf("Empty linked list!");
        return;
    } else {
        Node *delNode = (*head);
        (*head) = (*head)->next;
        if((*head) != NULL)
            (*head)->prev = NULL;
        free(delNode); 
    }
}

void popBack(Node **head){
    if(*head == NULL){
        printf("Empty linked list!\n");
        return;
    } 
    else if((*head)->next == NULL){
        free(*head);
        (*head) = NULL;
        printf("Now linked list is empty!");
        return;
    }
    else{
        Node *temp = (*head);
        while (temp->next != NULL){
            temp = temp->next;
        }
        Node *delNode = temp;
        temp->prev->next = NULL;
        free(delNode);
    }
}

void erase(Node **head, int idx){
    if(idx < 1 || idx > len(*head)) {
        printf("Invalid position!");
        return; 
    }
    if(idx == 1){
        popFront(head);
        return;
    }
    else{
        Node *tmp = (*head);
        //Duyet den node idx 
        for(int i = 1; i <= idx - 1; i++){
            tmp = tmp->next;
        }
        //Luu lai node thu idx
        Node *delNode = tmp;
        //Cho idx - 1 => tro vao idx + 1
        tmp->prev->next = tmp->next;
        //Cho k + 1 => tro nguoc vao k - 1
        if(tmp->next != NULL){
            tmp->next->prev = tmp->prev;
        }
        //Giai phong node thu k
        free(delNode);
}

}

int main (){
    Node *head = NULL;
    // for(int i = 0; i >= 1; i--){
    //    pushBack(&head, i);
    // }
    print(head);
    printf("\n");
    popBack(&head);
    print(head);
    // print(head);
}
