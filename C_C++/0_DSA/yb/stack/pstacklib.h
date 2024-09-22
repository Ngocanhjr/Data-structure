#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct node{
    ElementType data;
    struct node *next;
}Node;

typedef Node *Stack;

void makeNull(Stack *S){
    Stack createEmpty  = (Node*)malloc(sizeof(Node));  
    createEmpty->next = NULL;
    (*S) = createEmpty;
}

void len(Stack S){
    int size = 0;
    while (S->next != NULL){
        size++;
        S = S->next;
    }
}

void push (ElementType x, Stack *S){
    Stack newNode = (Node*)malloc(sizeof(Node));
    makeNull(&newNode);
    newNode->data = x;
    newNode->next = (*S)->next;
    (*S)->next = newNode;
}

ElementType pop(Stack *S){
    ElementType value = (*S)->next->data;
    Stack del = (*S)->next;
    (*S)->next = del->next;
    free(del);
    return value;
}

ElementType top (Stack S){
    return S->next->data;
}

void print(Stack S){
    printf("Stack : ");
    while (S->next != NULL){
        printf("%d ", S->next->data);
        S= S->next;
    }
    printf("\n");
}

Stack read(){
    Stack newStack = (Node*)malloc(sizeof(Node));
    makeNull(&newStack);
    int size; 
    printf("Enter size of stack: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        // ElementType temp;
        // scanf("%d", temp);
        push(i, &newStack);
    }
    return newStack;
}
