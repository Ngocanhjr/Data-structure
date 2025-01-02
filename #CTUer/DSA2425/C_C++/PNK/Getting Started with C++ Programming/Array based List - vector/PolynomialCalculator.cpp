/*
Please write a function insert(c, e, pL) to add the monomial cx^e to pL.

Prototype

Name: insert
Parameter(s):
c: double
e: int
pL: Polynomial pointer
Return value: void
Body: insert the monomial cx^e to the polynomial *pL at the suitable position.
    If the exponent e has already existed in *pL, replace the coefficient by c.
Please note that after this operation, exponents in *pL must be in decreasing order.

Hint
Find the position p in *pL where the exponent ≤e
Using insert() function of the vector class.


Test
Polynomial L;
insert(5, 3, &L);
insert(4, 4, &L);
insert(7, 0, &L);
insert(-3, 2, &L);
printPolynomial(&L);

Result
(4.00)x^4 + (5.00)x^3 + (-3.00)x^2 + (7.00)x^0
*/
#include <math.h>

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

// void insert(double c, int e, Polynomial* pL) {
//     int i = 0;
//     for (i; i < (*pL).size(); i++) {
//         if ((*pL)[i].e == e) {
//             (*pL)[i].c = c;
//             return;
//         }

//         if ((*pL)[i].e < e) {
//             break;
//         }
//     }

//     pL->insert(pL->begin() + i, {c, e});
// }

void insert(double c, int e, Polynomial* pL) {
    auto it = pL->begin();
    for (it; it != pL->end(); ++it) {
        if (it->e == e) {
            it->c = c;
            return;
        }

        if (it->e < e) {
            break;
        }
    }

    pL->insert(it, {c, e});
}

void delete_e(int e, Polynomial* pL) {
    auto it = pL->begin();
    for (it; it != pL->end(); ++it) {
        if (it->e == e) {
            pL->erase(it);
            return;
        }
    }

    if (it == pL->end()) {
        cout << "The exponent does not appear.\n";
    }
}

Polynomial differentiate(Polynomial* pL) {
    Polynomial derivative;
    for (auto it = pL->begin(); it != pL->end(); ++it) {
        int e = it->e;
        if (e != 0) {
            ElementType mono = {(it->c) * e, (e - 1)};
            derivative.push_back(mono);
        }
    }
    return derivative;
}

double evaluate(double val, Polynomial* pL) {
    double sum = 0;
    for (auto it = pL->begin(); it != pL->end(); ++it) {
        sum += (it->c) * pow(val, it->e);
    }
    return sum;
}

double coefficient(int e, Polynomial* pL) {
    double coef = 0;
    for (auto it = pL->begin(); it != pL->end(); ++it) {
        if (it->e == e) {
            coef = it->c;
            break;
        }
    }
    return coef;
}
int main() {
    Polynomial L;
    insert(5, 3, &L);
    insert(5, 4, &L);
    insert(7, 0, &L);
    insert(-3, 2, &L);
    printPolynomial(&L);
    for (int e = 10; e >= 0; e--)
        printf("The coefficient of x^%d is: %.2f\n", e, coefficient(e, &L));
}