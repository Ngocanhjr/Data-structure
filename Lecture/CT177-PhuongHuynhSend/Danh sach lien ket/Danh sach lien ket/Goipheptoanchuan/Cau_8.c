#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElementType;
struct Node
{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
    (*pL)=(struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next=NULL;
}
void append(ElementType X, List *pL){
    Position P=(*pL);
    while (P->Next!=NULL)
        P=P->Next;
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;    
}
int member(ElementType X, List L){
    int Found=0;
    Position P=L;
    while (P->Next!=NULL && !Found){
        if (P->Next->Element==X)
            Found=1;
        else
            P=P->Next;
    }
    return Found;
}
void addFirst(ElementType X, List *pL){
    Position P=(*pL);
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
	(*pL)=P;
}
List readSet(){
    List L;
    int n;
    ElementType X;
    makenullList(&L);
    scanf("%d",&n);
    int i;
    for( i=1; i<=n; i++){
        scanf("%d",&X);
        if (!member(X,L))
            addFirst(X,&L);
    }
    return L;
}
void printList(List L){
	Position P=L;
	while (P->Next!=NULL){
		printf("%d ",P->Next->Element);
		P=P->Next;
	}
	printf("\n");
}
List intersection(List L1, List L2){
    List L;
    makenullList(&L);
    Position P=L1;
    while (P->Next!=NULL){
        if (member(P->Next->Element,L2))
            append(P->Next->Element,&L);
        P=P->Next;
    }
    return L;
}
void printOddNumbers(List L) {
Position P= L;
while (P->Next!=NULL) {
    if (P->Next->Element %2!=0)
    printf("%d ",P->Next->Element);
    P =P->Next;
} 

}


void copyEvenNumbers(List L, List *pL) {
    Position P= L;
    makenullList(pL);
    while( P->Next !=NULL) {
        if (P->Next->Element %2==0) {
           append(P->Next->Element,pL);
        }
        P=P->Next;
    }
}

int main(){
	List L1, L2, L;
	L1=readSet();
	L2=readSet();
	printList(L1);
	printList(L2);
	L=intersection(L1,L2);
	printList(L);
	return 0;
}
