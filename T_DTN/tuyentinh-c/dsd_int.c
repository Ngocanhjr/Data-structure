#include <stdio.h>
#include <stdlib.h>

#define MaxLength 50
typedef int ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List; 

List L;

void MakeNullList(List *L) {
	L->Last=0;
}

int EmptyList(List L) { 
	return (L.Last==0);
}

void InsertList(ElementType X,Position P, List *L) {
	if (L->Last==MaxLength)
		printf("Danh sach day");	
	else if ((P<1) || (P>L->Last+1))
	    printf("Vi tri khong hop le");
		else {
			Position Q;
			for(Q=(L->Last-1)+1;Q>=P;Q--)
				L->Elements[Q]=L->Elements[Q-1];
			L->Elements[P-1]=X;
			L->Last++;
		}
} 

void DeleteList(Position P,List *L) { 
	if ((P<1) || (P>L->Last))
		printf("Vi tri khong hop le");
	else if (EmptyList(*L))
	    printf("Danh sach rong!");
		else {
			Position Q;
			for(Q=P-1;Q<L->Last-1;Q++)
				L->Elements[Q]=L->Elements[Q+1];
			L->Last--;
		}
} 

Position Locate(ElementType X, List L) {
	Position P;
	int Found = 0;
	P = First(L);

	while ((P != EndList(L)) && (Found == 0))
		if (Retrieve(P,L) == X) Found = 1;
		else P = Next(P, L);
	return P;
} 
 
ElementType Retrieve(Position P, List L) {
	return L.Elements[P-1];
} 

Position First(List L) {	
	return 1; 
} 

Position EndList(List L) {
	return L.Last+1;
}
 
Position Next(Position P, List L) {	
	return P+1;
}

void PrintList(List L) {
	Position P;
	P = First(L);
	while (P != EndList(L)) {
		printf("%d ",Retrieve(P,L));
		P = Next(P, L);
	}
	printf("\n");
}

void ReadList(List *L) {	
	int i,N;
	ElementType X;
	MakeNullList(L);
	printf("So phan tu danh sach N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		InsertList(X,EndList(*L),L);
	}
}

int count(List L) {
	return L.Last;
}

int count1(List L) {
	int sophtu = 0;
	Position P = First(L);
	while(P != EndList(L)) {
		sophtu++;
		P = Next(P, L);
	}
	return sophtu;
}

main() {
	List L;
	ElementType X;
	Position P;
	ReadList(&L);
	printf("Danh sach vua nhap: ");
	PrintList(L); 
	printf("Phan tu can them vao danh sach: ");scanf("%d",&X);
	printf("Vi tri can them: ");scanf("%d",&P);
	InsertList(X,P,&L);
	printf("Dsach sau khi them phan tu la: ");
	PrintList(L);
	printf("Noi dung phan tu can xoa: ");
	scanf("%d",&X);
	P=Locate(X,L);
	DeleteList(P,&L);
	printf("Danh sach sau khi xoa %d la: ",X);
	PrintList(L);
	printf("So phan tu trong danh sach: %d\n", count(L));
	return 0;
} 
