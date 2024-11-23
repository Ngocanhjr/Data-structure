#include <stdio.h>
#define Maxlength 100
typedef int Position;
typedef int ElementType;
typedef struct {
    ElementType Elements[Maxlength];
    Position Last;
} List;
void insertSet(ElementType x, List *pL) {
     if (pL->Last==Maxlength)
 		printf("Danh sach day\n");
 	else {
	    pL->Elements[pL->Last]=x;
	    pL->Last=pL->Last+1;
 	}
} 
void deleteList(ElementType X,List *L) {
    Position p= locate(x,*L);
    if (p!= L->Last+1) {
        int i;
        for ( i=p-1;i<L->Last-1;i++) {
            L->Elements[p]=L->Elements[p+1];
        }
        L->Last--;
    }
}
void makenullList(List *pL) {
pL->Last= 0;
}
int member (ElementType x, List L) {
    int found=0;
    Position p=1;
    while(p!=L.Last+1 &&!found) {
if (L.Elements[p-1]==x) found=1;
    }
    return found;
}
void insertList(ElementType x, Position p,List *pL){
if (pL->Last== Maxlength) printf("Danh sach day");
else if ((p<1) || (p>pL->Last+1)) {
     printf("Vi tri khong hop le");
} else {
    int i;
    for ( i=pL->Last;i>p-1;i--) {
        pL->Elements[p] = pL->Elements[p-1]; 
    }
    pL->Elements[p-1]=x;
    pL->Last++;
}
    
}
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

void sort(List *pL) {
    int i,j;
    for ( i=0;i<pL->Last;i++) {
        for ( j=i+1;j<pL->Last;j++) {
            if (pL->Elements[i]> pL->Elements[j]) {
                int temp= pL->Elements[i];
                pL->Elements[i] =pL->Elements[j];
                pL->Elements[j] =temp;
            }
        }
    }
}

void printList(List L) {
    Position P=1;
    while (P!=L.Last+1) {
        printf("%d ",L.Elements[P-1]);
        P++;
    }
    printf("\n");
}

void difference(List L1,List L2,List *L) {
    Position p =1;
    while (p!=L1.Last) {
if (!member(L1.Elements[p-1],L2)) {
insertSet(L1.Elements[p-1],L);
}

p++;
    }
}

int main()
{
    List L1,L2,L;
    makenullList(&L);
    readList(&L1);
printList(L1);
    readList(&L2);
    printList(L2);
     difference(L1,L2,&L);
   printList(L);
    return 0;
}