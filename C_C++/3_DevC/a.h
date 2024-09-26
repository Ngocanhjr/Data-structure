#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef int Position;

typedef struct NodeTag{
	ElementType data;
	struct NodeTag *next;
}Node;

typedef Node *List;

typedef Node *PNode;

void makeNull(List *L){
	List init = (Node*)malloc(sizeof(Node));
	init->next = NULL;
	(*L)  = init;
}

int len(List L){
	int size = 0;
	while (L->next != NULL){
		size++;
		L = L->next;
	}
	return size;
}

int empty(List L){
	return L->next == NULL;
}

PNode getPosition (Position p, List L){
	int flag = 0;
	PNode pos = L;
	while (pos->next != NULL && flag < p){
		flag++;
		pos = pos->next;
	}
	return pos;
}

void setAt(ElementType x, Position p, List (*L)){	
    List temp = getPosition(p, *L);
    temp->next->data = x;
}

ElementType getAt(Position p, List L){
	PNode pos = getPosition(p, L);
	return pos->next->data;
}

void append(Position p,ElementType x, List *L){
	List newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    // newNode->next = NULL;
    List current = getPosition(p, *L);
    newNode->next = current->next;
    current->next = newNode;
}

void print(List L){
	while (L->next != NULL)
    {
      printf("%d ", L->next->data);
      L = L->next;
    }
    printf("\n");
}

List bubbleSort(List L){
	int size = len(L);
	List sort = L;
	for (int i = 0; i < size; i++)
	{
		int isSorted = 1;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (getAt(j, sort) > getAt(j + 1, sort))
			{
				isSorted = 0;
				int temp = getAt(j, sort);
				setAt(getAt(j + 1, sort),j, &sort);
				setAt(temp,j + 1, &sort);
			}
		}
		if (isSorted)
		{
			break;
		}
	}
//	int isSorted = 1, size = len(L);
//	List sort = L;
//	
//	for(int i = 0; i < size; i++){
//		isSorted = 1;
//		for(int j = 0; j < size - i - 1; j++){
//			if(getAt(j, L) > getAt(j + 1, L)){
//				isSorted = 0;
//				int temp = getAt(j, L);
//				setAt(getAt(j + 1, L),j,&sort);
//				setAt(temp, j + 1, &sort);
//			}
//		}
//		if(isSorted){
//			break;
//		}
//	}
	
	return sort;
}

