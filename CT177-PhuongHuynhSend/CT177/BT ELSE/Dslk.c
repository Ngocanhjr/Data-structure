#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef int ElementType;
struct Node
{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;
// Cau 2
void makenullList(List *pL){
    (*pL)=(struct Node*) malloc(sizeof(struct Node));
    (*pL)->Next=NULL;
}


void append(ElementType X, List *pL ) {
    Position P = (*pL) ;
    while (P-> Next!=NULL) P=P->Next;
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t-> Element = X;
    t->Next = NULL;
    P-> Next=t;
}

int member (ElementType X, List L) {
int Found=0;
Position P=L;
while ( P-> Next != NULL && !Found)  {
    if (P -> Next ->Element ==X) Found=1;
    else  P = P ->Next;
}
return Found;

}
void addFirst (ElementType X, List *pL )  {
    Position P = (*pL);
    struct Node *t = (struct Node*) malloc (sizeof(struct Node));
    t->Element=X;
    t->Next = P-> Next;
    P-> Next =t;
    (*pL) = P;
}



void readList(List *pL){ 
    int n;
    ElementType X;
    scanf("%d", &n);
    makenullList(pL);

    
    
    // while
    int i; 
    for( i=1; i<=n; i++){
        scanf("%d", &X);
        List t= (struct Node*)malloc(sizeof(struct Node));
        Position P = (*pL) ;
        while (P-> Next !=NULL) P=P->Next;
        t->Element =X;
        t->Next = NULL;
        P->Next = t;

    }
}

List readSet() {
    List L ;
    int n;
    ElementType X;
    makenullList(&L);
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++)
 {
    scanf("%d",&X);
    if (!member(X,L)) addFirst(X,&L);
 }
 return L;
}

void printList(List L) {
    Position P= L;
    while (P -> Next !=NULL) {
        printf("%d ", P -> Next -> Element);
        P= P-> Next;

    }
    printf("\n");
}


 void printOddNumbers(List L) {
Position P =L ;
while (P->Next !=NULL) {
    if (P-> Next ->Element %2==1) printf("%d ",P->Next->Element); 
    P =  P->Next;
}
 }


void deleteList(Position p, List *pL) {

    if (p->Next !=NULL) {
        Position t=p->Next;
        p->Next = t->Next;
        free(t); 
    }

}

void insertList (ElementType x, Position p, List *pL) {
    struct Node* t =(struct Node*)malloc (sizeof(struct Node));
    t->Element =x;
    t->Next =p ->Next;
    p->Next =t;
}

List intersection(List L1, List L2) {
    List L;
    makenullList(&L);
Position P=L1;
while ( P-> Next !=NULL) {
    if (member(P->Next->Element,L2 ) ) append(P->Next->Element,&L) ;
    P = P ->Next;
}
return L;
}

void sort(List *pL) {
Position P=(*pL);
Position Q;
ElementType temp;
while (P->Next!=NULL ) {
    Q = P-> Next;
    while (Q->Next !=NULL) {
if (P->Next->Element > Q->Next->Element) {
       
temp = P->Next->Element;
P->Next->Element = Q->Next->Element;
Q->Next->Element = temp;
    }
Q= Q->Next;
    }
    
    P = P->Next;
    
}

}

float getAvg(List L) {
float sum=0;
Position P=L;
int n=0;
if (P->Next==NULL) 
{
    /* code */
    return -10000.000;
}
else {

while (P->Next !=NULL) {
    sum+= P->Next->Element;
    
    P= P->Next;
    n++;
}
return sum/n; 
}

}

int main() {
List L;
readList(&L);
printList(L);
printf("%.3f", getAvg(L));

	return 0;
}