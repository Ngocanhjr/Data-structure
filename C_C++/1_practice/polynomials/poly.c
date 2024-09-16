#include "polylib.h"
int main (){
    Polynomial a, b;
    makeNull(&a);
    makeNull(&b);
    a = read();
    print(a);

    b = read(); 
    print(b);
    Polynomial sum = add(a,b);
    printf("ADD: \n");
    print(sum);

    Polynomial d = derivative(b);
    printf("DERIVATIVE: \n");
    print(d);
}