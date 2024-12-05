/*
    LIFO: last in first out
    ứng dụng: đảo ngược xâu kí tự, biểu thức trung tố, tiền tố, hậu tố
*/
#include <stdio.h>
#include <stdlib.h>
//Mảng 1 Chiều
int size = 0, stack[10001];

void push(int value){
    stack[size] = value;
    ++size;
}

void pop(){
    if(size >= 1)
        --size;
}

void top(){
    if(size < 1){
        printf("empty stack!");
        return;
    }
    return stack[size - 1];
}

int main (){
    
}