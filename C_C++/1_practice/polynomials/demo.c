#include<stdio.h>
#include<math.h>
#define MaxLength 100
typedef int Position;
typedef struct {
	 float Coefficient;
	 int Exponent;
}ElementType;

typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
}List;


void makenullList(List *pL){
	pL->Last =0; 
}
int emptyList(List L){
	return L.Last == 0;
}
int fullList(List L){
	return L.Last == MaxLength;
	
}
Position first (List L){
	return 1;
}
Position endList(List L){
	return L.Last +1;
}


Position next(Position P, List L){
	return P+1;
}
Position previous(Position P, List L){
	return P-1;
}
void insertSorted(float Coefficient, int Exponent, List *pL ){
	Position   i = pL->Last-1;
	while ( i >= first(*pL)-1  && Exponent > pL->Elements[i].Exponent){
		pL->Elements[i+1].Exponent=pL->Elements[i].Exponent;
		pL->Elements[i+1].Coefficient=pL->Elements[i].Coefficient;
		i--;
	}
	pL->Elements[i+1].Coefficient=Coefficient;
	pL->Elements[i+1].Exponent=Exponent;
	pL->Last++;
	}
void deleteList(Position P, List *pL){
	if (emptyList (*pL)) 
		printf ("List is empty");
	else if (P < first(*pL) || P > endList(*pL))
		printf ("Error !");
	else {
		Position Q;
		for (Q= P;Q<pL->Last;Q++){
			pL->Elements[Q-1]= pL->Elements[Q];
		}
		pL->Last--;
	}
}
Position locate(ElementType x, List L){
	Position Q;
	Q = first(L);
	int found =0;
	while ((Q != endList (L) )&& (found ==0)){
		if (x.Coefficient==L.Elements[Q-1].Coefficient&& x.Exponent==L.Elements[Q-1].Exponent) 
			found =1;
		else 
			Q= next (Q,L);
	}
	return Q;
}

void readList(List *pL){
	makenullList(pL);
	int n,b,i;
	float a;
	printf("Enter the number of monomials:");
	scanf("%d",&n);
	if (n>MaxLength|| n<0){
		printf("Error !");
		return;
	}
	else if(n==0) return ;
	 
	for( i=0;i<n;i++){
			printf("don thuc thu %d:",i+1);
			scanf("%f%d",&a,&b);
			insertSorted(a,b,pL);
		}
}

void printList1(List L){
	Position i;
	int term= 1;
	if (emptyList (L)){
		printf("0\n");
		return; 
	}
	else{
	for(i =first(L)-1; i<endList(L)-1; i = next (i,L) ){
		if (L.Elements[i].Coefficient!=0 ){
			if (!term){
				if (L.Elements[i].Coefficient>0)
					printf(" + ");
				else{
					printf(" - ");
				}
				
			}
			else {
				
				if (L.Elements[i].Coefficient<0){
					printf(" - ");
			}
			term =0;}
			
			if (fabs(L.Elements[i].Coefficient )!= 1 || L.Elements[i].Exponent ==0 )
				printf("%.1f",fabs(L.Elements[i].Coefficient));
			if (L.Elements[i].Exponent != 0) 
				printf("x");
			if(L.Elements[i].Exponent >1 ) 
				printf("^%d",L.Elements[i].Exponent);}
	}
	}
	

printf("\n");}

List addPolynomials(List L1, List L2){
	List L;
	makenullList(&L);
	Position i,j,k;
	i= first(L1)-1;
	j=first(L2) -1;
	k = 0;
	
	
		while ( i < endList(L1)-1 && j< endList(L2)-1){
			if (L1.Elements[i].Exponent == L2.Elements[j].Exponent){
				L.Elements[k].Coefficient= L1.Elements[i].Coefficient + L2.Elements[j].Coefficient;
				L.Elements[k].Exponent=L1.Elements[i].Exponent;
				i++;
				j++;
			}
			else if(L1.Elements[i].Exponent > L2.Elements[j].Exponent){
				L.Elements[k]= L1.Elements[i] ;
				
				i++;
			}
			else {
				L.Elements[k]= L2.Elements[j] ;
				j++;
			}
			k++;	
			}
		while (i<endList(L1)-1){
			L.Elements[k]=L1.Elements[i];
			i++;
			k++;
		}
			while (j<endList(L2)-1){
			L.Elements[k]=L2.Elements[j];
			j++;
			k++;
		}
		L.Last= k;
	return L;	
} 

void printList(List L){
	Position i;
	i= first(L)-1;
	while ( i!= endList(L) && L.Last != 0){
		if (L.Elements[i].Coefficient!=0 ){
			if (L.Elements[i].Coefficient>0 && i> 0) 
				printf("+");
			if (L.Elements[i].Exponent ==0)
				printf(" %.1f ",L.Elements[i].Coefficient);
			else if (L.Elements[i].Exponent ==1) 
				printf(" %.1fx ",L.Elements[i].Coefficient);
			else 
				printf(" %.1fx^%d ",L.Elements[i].Coefficient,L.Elements[i].Exponent);}
			
		
		i++;
	}
	printf("\n");
}

float calculate( List L){
	float result=0,x;
	printf("Enter x :");
	scanf("%f",&x);
	Position i;
	i = first(L) ;
	while ( L.Last != 0 && i != endList(L)){
		result += (L.Elements[i-1].Coefficient * pow(x,L.Elements[i-1].Exponent));
		i++;
	}
	return result;
} 
void multiply ( List * pL ){
	float constant;
	Position i;
	i = first(*pL);
	printf("Enter a constant:");
	scanf("%f",&constant);
	while ( pL->Last !=0 && i != endList(*pL)){
		pL->Elements[i-1]. Coefficient*= constant;
		i++;
	}
}	
void derivative(List *pL){
	Position i;
	i = first(*pL);
	while ( pL->Last !=0 && i != endList(*pL)){
		if (pL->Elements[i-1].Exponent ==0) {
			deleteList(locate(pL->Elements[i-1],*pL),pL);
		}
		else{pL->Elements[i-1].Coefficient*= pL->Elements[i-1].Exponent;
		pL->Elements[i-1].Exponent--;
		i++;
	}}
	printf(" the derivative of the polynomial is : ");
	printList(*pL);
}

int main (){
    List a, b;
    readList(&a);
    printList1(a);

    
    readList(&b);
    printList1(b);
    List r = addPolynomials(a,b);
    printList1(r);
    derivative(&r);
    printList1(r);
}