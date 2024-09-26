// #include "astacklib.h"
// #include "dstacklib.h"
#include "pstacklib.h"

Stack convertBinary(ElementType n){
    if (n == 0){
        return 0;
    }
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

void fibo(int n){
    ElementType result = 0;
    Stack store;
    makeNull(&store);
    push (n, &store);
    while(!isEmpty(store)){
        n = pop(&store);
        if(n == 1 || n == 2){
            result += 1;
        } else {
            push(n - 1, &store);
            push(n - 2, &store);
        }
        // printf("%d ", n);
    }
    printf("Fibo: %d \n",result);
}

/*
result = 0;
khởi tạo stack rỗng

push (n, S)

while (!empty){
n = S;
 if = 1,2, ; resutl + 1 + 1
 else
 push(n - 1, S);
 push(n - 2, S);
}
*/

void combinatorics(ElementType n, ElementType k){
    Stack store;
    makeNull(&store);

    ElementType result = 0;
    push(k, &store);
    push(n, &store);

    while(!isEmpty(store)){
        n = pop(&store);
        k = pop(&store);
        if(k == 0 || k == n){
            result++;
        } else if (k == 1){
            result += n;
        } else {
            push(k - 1, &store);
            push(n - 1, &store);
            push(k, &store);
            push(n - 1, &store);
        }
        
    }
    printf("C: %d \n", result);
}
 /*
    Stack -> empty
    result - 0;
    S<-k;
    S <- n;
    while (!empty){
     n = pop (s);
     k = pop (s);
     if( k == 0 || k == n){
        result ++;
     } else{ k == 1;

     result + = n;
     } else 
     s <- k - 1
     s <- n - 1
    s <- k 
    s < n - 1   
    }
    
    
    */

int main (){
    // Stack s;
    // s = read();
    // print(s);
    // printf("Value of top: ");
    // printf("%d \n", top(s));
    // Stack result = convertBinary(45);
    // print(result);
    fibo(30);
    combinatorics(15,3);
}