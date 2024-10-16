#include <stdio.h>
#include<stdlib.h>

#define EMPTY_ERROR -99
typedef int ElementType;

typedef struct tg{
	int data;
	struct tg *next;
}Node;

typedef struct queue{
	Node *front;
	Node *rear;
}Queue;

void makeNull(Queue *Q){
	Node *header = (Node*)malloc(sizeof(Node));
	header->next = NULL;
	Q->front = header;
	Q->rear = Q->front;
}

int isEmpty(Queue Q){
	return Q.front == Q.rear;
}

void enQueue(ElementType x, Queue *Q){
	Node *createNewNode = (Node*)malloc(sizeof(Node));
	createNewNode->data = x;
	createNewNode->next = NULL;
	Q->rear->next = createNewNode;
	Q->rear = createNewNode;
}

ElementType deQueue(Queue *Q){
	ElementType value = EMPTY_ERROR;
	if(!isEmpty(*Q)){
		value = Q->front->next->data;
		Node *del = Q->front;
		Q->front = del->next;
		free(del);
	}
	return value;
}

void print(Queue Q)
{
    Node *temp = Q.front;
    while (temp->next)
    {
        printf("%d ", temp->next->data);
        temp = temp->next;
    }
    printf("\n");
}
