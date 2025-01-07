#include "polynomialslib.h"

int main (){
    makeNullList(&L);
    L = readList();
    printList(L);

    Polynomial p1, p2;
    makeNullPoly(&p1);
    makeNullPoly(&p2);
    p1 = readPoly();
    printPoly(p1);
    
    p2 = readPoly();
    printPoly(p2);
    Polynomial result = addTwoPoly(p1, p2);
    printPoly(result);

    Polynomial d = derivative(p1);
    printPoly(d);
}