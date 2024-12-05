// Cau 1
#define Maxlength 100
typedef int ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[Maxlength];
	Position    Last;
} List; 
// Cau 2
void makenullList(List *pL) {
	pL->Last=0;
}
// Cau 3
void insertList(ElementType X,Position P, List *pL) {
	if (pL->Last==Maxlength)
		printf("Danh sach day");	
	else if ((P<1) || (P>pL->Last+1))
	    printf("Vi tri khong hop le");
	else {
			Position Q;
			for(Q=pL->Last;Q>P-1;Q--)
				pL->Elements[Q]=pL->Elements[Q-1];
			pL->Elements[P-1]=X;
			pL->Last++;
		}
} 
// Cau 4
void deleteList(Position P,List *pL) { 
	if ((P<1) || (P>pL->Last))
		printf("Vi tri khong hop le\n");
	else if (pL->Last==0)
	    printf("Danh sach rong!\n");
	else {
			Position Q;
// 			for(Q=P;Q<pL->Last;Q++)
// 				pL->Elements[Q-1]=pL->Elements[Q];
            for(Q=P-1;Q<pL->Last-1;Q++)
				pL->Elements[Q]=pL->Elements[Q+1];
			pL->Last--;
		}
} 
// Cau 5
Position locate(ElementType X, List L) {
	Position P;
	int Found = 0;
	P = 1;
	while ((P != L.Last+1) && (Found == 0))
		if (L.Elements[P-1] == X) Found = 1;
		else P = P+1;
	return P;
} 
// Cau 6
void erase(ElementType x,List *pL) { 
	Position P;
	P=locate(x,*pL);
	if (P!=pL->Last+1)
	    deleteList(P,pL);
} 
// Cau 7
void removeAll(ElementType x,List *pL) { 
	Position P;
	do {
	    P=locate(x,*pL);
	    if (P!=pL->Last+1)
	        deleteList(P,pL);
	} while (P!=pL->Last+1);        
} 
// Cau 8
void printList(List L) {
	Position P;
	P = 1;
	while (P != L.Last+1) {
		printf("%d ",L.Elements[P-1]);
		P = P+1;
	}
	printf("\n");
}
// Cau 9
void readList(List *pL) {	
	int i,N;
	ElementType X;
	makenullList(pL);
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		scanf("%d",&X);
		insertList(X,pL->Last+1,pL);
	}
}
// Cau 10
int member(ElementType x, List L){
    Position P=1;
    int Found=0;
    while (P!=L.Last+1 && !Found)
        if(L.Elements[P-1]==x)
            Found=1;
        else P=P+1;   
    return Found;
}
// Cau 11
void insertSet(ElementType x, List *pL) {
     if (pL->Last==Maxlength)
 		printf("Danh sach day\n");
 	else {
	    pL->Elements[pL->Last]=x;
	    pL->Last=pL->Last+1;
 	}
} 
// Cau 12
float  getAvg(List L){
    int S=0;
    Position P=1;
    while (P!=L.Last+1){
        S += L.Elements[P-1];
        P++;
    }
    return (float)S/L.Last;
}
// Cau 13
void unionSet(List L1, List L2, List *pL){
    makenullList(pL);
    Position P;
    P=1;
    while (P!=L1.Last+1){
        insertSet(L1.Elements[P-1], pL);
        P++;
    }
    P=1;
    while (P!=L2.Last+1){
        if (!member(L2.Elements[P-1],*pL))
            insertSet(L2.Elements[P-1], pL);
        P++;
    }
}
// Cau 14
void difference(List L1, List L2, List *pL){
    makenullList(pL);
    Position P;
    P=1;
    while (P!=L1.Last+1){
        if (!member(L1.Elements[P-1],L2))
            insertSet(L1.Elements[P-1], pL);
        P++;
    }
}
// Cau 15
void sort(List *pL){
    Position p,q;
    ElementType temp;
    for(p=1;p<pL->Last;p++)
        for(q=p+1;q<=pL->Last;q++)
            if(pL->Elements[p-1]>pL->Elements[q-1]){
                temp=pL->Elements[p-1];
                pL->Elements[p-1]=pL->Elements[q-1];
                pL->Elements[q-1]=temp;
            }
}
// Cau 16
void normalize(List *pL){
    Position p,q;
    p=1;
    while (p!=pL->Last+1){
        q=p+1;
        while (q!=pL->Last+1){
            if (pL->Elements[p-1]==pL->Elements[q-1])
                deleteList(q,pL);
            else
                q++;
        }
        p++;
    }
}
// Cau 17
void printOddNumbers(List L){
    Position p=1;
    while (p!=L.Last+1){
        if (L.Elements[p-1]%2!=0)
            printf("%d ",L.Elements[p-1]);
        p++;    
    }
}
// Cau 18
void copyEvenNumbers(List L1, List *pL2){
    makenullList(pL2);
    ElementType x;
    Position p=1;
    while (p!=L1.Last+1){
        x=L1.Elements[p-1];
        if (x%2==0)
            insertList(x,pL2->Last+1,pL2);
        p++;    
    }
}
// Cau 19
void readSet(List *pL) {	
	int i,N;
	ElementType X;
	makenullList(pL);
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		scanf("%d",&X);
		if (!member(X,*pL))
		    insertSet(X,pL);
	}
}
// Cau 20
void intersection(List L1, List L2, List *pL){
    makenullList(pL);
    Position p=1;
    while (p!=L1.Last+1){
        if (member(L1.Elements[p-1],L2)){
            insertSet(L1.Elements[p-1],pL);
        }
        p++;
    }
}

