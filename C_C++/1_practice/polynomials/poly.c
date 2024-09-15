#include "polylib.h"
int main (){
    Polynomial a, b;
    makeNull(&a);
    makeNull(&b);
    a = read();
    print(a);

    Polynomial d = derivative(a);
    print(d);
    // b = read(); 
    // print(b);
    // Polynomial sum = add(a,b);
    // print(sum);
}