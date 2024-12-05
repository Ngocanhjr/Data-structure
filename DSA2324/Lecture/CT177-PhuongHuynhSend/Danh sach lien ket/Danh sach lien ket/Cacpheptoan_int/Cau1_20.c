// Cau 1
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
    (*pL)=(struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next=NULL;
}
// Cau 3
void insertList(ElementType X, Position P, List *pL){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    //Position t=(struct Node*)malloc(sizeof(struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
}
// Cau 4
void deleteList(Position p, List *pL)
{
	if (p->Next!=NULL)		
	{
		Position t=p->Next;
		p->Next = t->Next;
		free(t);
	}
}
// Cau 5
Position locate(ElementType X, List L){
    Position P=L;
    int Found = 0;
    while ((P->Next!=NULL) && (!Found)){
        if (P->Next->Element==X)
            Found=1;
        else
            P=P->Next;
    }
    return P;
}
// Cau 6
void append(ElementType X, List *pL){
    Position P=(*pL);
    while (P->Next!=NULL)
        P=P->Next;
    insertList(X,P,pL);
//    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
//	t->Element=X;
//	t->Next=P->Next;
//	P->Next=t;    
}
// Cau 7
void addFirst(ElementType X, List *pL){
    Position P=(*pL);
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
	(*pL)=P;
}
// Cau 8
void readList(List *pL){
    int n;
    ElementType X;
    scanf("%d", &n);
    makenullList(pL);
    for(int i=1; i<=n; i++){
        scanf("%d", &X);
        append(X,pL);
    }
}
// Cau 9
void erase(ElementType X, List *pL){
    Position P=locate(X,*pL);
    if (P->Next!=NULL)
        deleteList(P, pL);
    else
        printf("Not found %d\n",X);
}
// Cau 10
void removeAll(ElementType X, List *pL){
    Position P=locate(X,*pL);
    while (P->Next!=NULL){
        deleteList(P, pL);
        P=locate(X,*pL);
    }
}
// Cau 11
void normalize(List *pL){
    Position P, Q;
    P=(*pL);
    while (P->Next != NULL){
        Q=P->Next;
        while (Q->Next != NULL){
            if (P->Next->Element == Q->Next->Element)
                deleteList(Q,pL);
            else
                Q=Q->Next;
        }
        P=P->Next;
    }
}
// Cau 12
void printOddNumbers(List L){
    Position P=L;
    while (P->Next!=NULL){
        if (P->Next->Element%2==1)
            printf("%d ", P->Next->Element);
        P=P->Next;
    }
}
// Cau 13
void copyEvenNumbers(List L1, List *pL){
    makenullList(pL);
    Position P=L1;
    while (P->Next!=NULL){
        if(P->Next->Element%2==0)
            append(P->Next->Element,pL);
        P=P->Next;
    }
}
// Cau 14
double getAvg(List L){
    Position P=L;
    if (P->Next==NULL)
        return -10000.000;
    else {
        double S=0;
        int count=0;
        while (P->Next!=NULL){
            S += P->Next->Element;
            P=P->Next;
            count++;
        }
        return S/count;
    }
}
// Cau 15
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
// Cau 16
List readSet(){
    List L;
    int n;
    ElementType X;
    makenullList(&L);
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&X);
        if (!member(X,L))
            addFirst(X,&L);
    }
    return L;
}
// Cau 17
List unionSet(List L1, List L2){
    List L;
    makenullList(&L);
    Position P=L1;
    while (P->Next!=NULL){
        append(P->Next->Element,&L);
        P=P->Next;
    }
    P=L2;
    while (P->Next!=NULL){
        if (!member(P->Next->Element,L))
            append(P->Next->Element,&L);
        P=P->Next;
    }
    return L;
}
// Cau 18
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
// Cau 19
List difference(List L1, List L2){
    List L;
    makenullList(&L);
    Position P=L1;
    while (P->Next!=NULL){
        if (!member(P->Next->Element,L2))
            append(P->Next->Element,&L);
        P=P->Next;
    }
    return L;
}
// Cau 20
void sort(List *pL){
    Position P,Q;
    ElementType temp;
    P=(*pL);
    while (P->Next!=NULL){
        Q=P->Next;
        while(Q->Next!=NULL){
            if (P->Next->Element>Q->Next->Element){
                temp=P->Next->Element;
                P->Next->Element=Q->Next->Element;
                Q->Next->Element=temp;
            }
            Q=Q->Next;
        }
        P=P->Next;
    }
}
