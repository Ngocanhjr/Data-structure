/*
Static array: độ dài n  cố định, chứa n elements indextable
    -> được lưu vào vùng nhớ stack
Dynamic array -> được lưu vào vùng nhớ heap

Cú pháp : ptr = (cast_type*)malloc(byte_size)

Cú pháp : ptr = (cast_type*) calloc(n, element_size)

*/

#include <stdio.h>
#include<stdlib.h>

int main (){
    int *a = (int* )malloc(sizeof(int)*5);
    free(a);
}
