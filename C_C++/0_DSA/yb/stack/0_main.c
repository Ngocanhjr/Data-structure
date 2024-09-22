// #include "astacklib.h"
// #include "dstacklib.h"
#include "pstacklib.h"

Stack convertBinary(int n){
    Stack binary = (Node*)malloc(sizeof(Node));
    makeNull(&binary);
    while(n != 0){
        ElementType temp;
        temp = n % 2;
        push(temp,&binary);
        n/=2;
    }
    return binary;
}
int main (){
    Stack s;
    s = read();
    print(s);
    printf("Value of top: ");
    printf("%d \n", top(s));
    Stack result = convertBinary(45);
    print(result);
}