#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node *makeNode (int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int size (Node *head){
    int cnt = 0;
    while (head != NULL){
        cnt ++;
        head = head->next;
    }
    return cnt;
}

void print(Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void pushFront(Node **head, int x){
    Node *newNode = makeNode(x);
    newNode->next = (*head);
    (*head) = newNode;
}

void pushBack(Node **head, int x){
    Node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    } else{
        Node *temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insert(Node **head, int k, int x){
    int n = size(*head);
    if(k < 1 || k > n + 1){
        printf("Invalid position!");
        return;
    }
    if(k == 1){
        pushFront(*head, x);
        return;
    }
    Node *temp = *head;
    for(int i = 1; i <= k - 2; i++){
        temp = temp->next;
    }
    //temp o vi tri k - 1
    Node *newNode = makeNode(x);
    newNode->next = temp->next;
    temp->next = newNode;  
}
    
int main(){
    Node *head = NULL;
    for(int i = 1; i <= 10; i++){
        pushFront(&head, i);
    }
    print(head);
    insert(&head, 5, 25);
    insert(&head, 9, 26);
    print(head);

}