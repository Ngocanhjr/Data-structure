#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    double c;  // coefficients
    int e;     // exponents
} ElementType;

typedef vector<ElementType> Polynomial;  // declares the data structure Polynomial

void printPolynomial(Polynomial* pL) {  // prints the Polynomial pL
    if (pL->size() == 0) return;

    cout << std::fixed << setprecision(2);  // sets the decimal precision to 2, e.g.: 5.23
    cout << '(' << (*pL)[0].c << ")x^" << (*pL)[0].e;

    for (int i = 1; i < pL->size(); i++)
        cout << setprecision(2) << " + " << '(' << (*pL)[i].c << ")x^" << (*pL)[i].e;

    cout << endl;
}