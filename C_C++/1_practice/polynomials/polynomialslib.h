#include <stdio.h>
#include<stdlib.h>

#define MAX_LENGTH_LIST 100
#define MAX_EXPONENT 10
typedef int Position;

typedef struct Polynomial {
    float factor[MAX_EXPONENT];
    int exponent;
}Polynomial;

typedef struct ListPolynomial{
    Polynomial list[MAX_LENGTH_LIST];
    int size;
}ListPoly;

Polynomial P;

ListPoly L;

void makeNullPoly(Polynomial *P){
    P->factor[0] = 0;
    P->exponent = 0;
}

void makeNullList( ListPoly *L){
    L->size = 0;
}

int len(ListPoly *L){
    return L->size;
}

int emptyList(ListPoly L){
    return L.size == 0;
}

int fullList(ListPoly L){
    return L.size == MAX_LENGTH_LIST;
}

// Polynomial getAt(Position idx, ListPoly);

void addPolyInList(Polynomial p, ListPoly *L){
    int len = L->size;
    L->list[len] = p;
    L->size++;
}

Polynomial readPoly(){
    int maxExponent;
    Polynomial newPoly;
    makeNullPoly(&newPoly);
    printf("Enter number of monomaial: ");
    scanf("%d", &maxExponent);
    newPoly.exponent = maxExponent;
    for(int i = 0; i <= maxExponent; i++){
        printf("Enter the coefficient at %d: ", i + 1);
        scanf("%f", &newPoly.factor[i]);
    }
    return newPoly;
}

ListPoly readList(){
    int sizeList;
    ListPoly newList;
    makeNullList(&newList);
    printf("Enter number of polynomial: ");
    scanf("%d", &sizeList);
    for(int i = 0; i < sizeList; i++){
        printf("---------------------------------------\n");
        Polynomial initPoly = readPoly();
        addPolyInList(initPoly, &newList);
    }
    return newList;
}

void printPoly(Polynomial p){
    int length = p.exponent;
    int exp = p.exponent;
    for(int i = 0; i <= length; i++){
        float coef = p.factor[i];
        int temp;
        if(coef == 0){
            exp--;
            temp = 0;
            continue;
        }  
        else {
            if(i > 1 && temp != 0){
                printf(" + ");
            }
            if(exp == 1){
                printf("%1.fX", coef);
            } else if( exp == 0){
                printf("%1.f", coef);
            } else{
                printf("%1.fX^%d", coef, exp);
            }
            exp--;
            temp = coef;
            if(i == 0 && exp != 0){
                printf(" + ");
            }
        }
    }
    printf("\n---------------------------------------\n");
}

void printList(ListPoly L){
    int length = L.size;
    for (int i = 0; i < length; i++){
        printf("Polynomial %d: ", i + 1);
        printPoly(L.list[i]);
    }
    printf("\n");
}

Polynomial addTwoPoly(Polynomial p1, Polynomial p2){
    int exp1 = p1.exponent, exp2 = p2.exponent;
    int maxExponent = exp1 >=  exp2 ? exp1 : exp2;

    Polynomial newPoly;
    newPoly.exponent = maxExponent;
    
    int flag1 = 0, flag2= 0;
    for(int i = 0; i <= maxExponent; i++){
        if(exp1 == exp2)
        {
            int coef1 = p1.factor[flag1] ;
            int coef2 = p2.factor[flag2];
            newPoly.factor[i] = coef1 + coef2;
            exp1--;
            exp2--;
            flag1++;
            flag2++;
        } else if( exp1 > exp2){
            newPoly.factor[i] =p1.factor[i];
            exp1--;
            flag1 ++;
        } else {
            newPoly.factor[i] =p2.factor[i];
            exp2--;
            flag2 ++;
        }
        
    }
    return newPoly;
}

 Polynomial derivative(Polynomial p){
    Polynomial newPoly;
    int newExp = p.exponent;
    newPoly.exponent = newExp - 1;

    
    for(int i = 0; i <= p.exponent; i++){
        if(newExp == 0){
            newPoly.factor[i] = 0;
        }
        else{
            newPoly.factor[i] = newExp*(p.factor[i]);
            newExp--;
        }
    }
    return newPoly;
}