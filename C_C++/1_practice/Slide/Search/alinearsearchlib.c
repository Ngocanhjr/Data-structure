#include <stdio.h>

//#Find an item in an array A of n elements
typedef int Position;
typedef int ElementType;
typedef ElementType List;

Position linearSearch(ElementType x, List A[], int size)
{
    for(int pos = 0; pos < size; pos++){
        if(A[pos]== x){
            return ++pos;
        }
    }
    return -1; //Not found
}

int main (){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(A)/sizeof(A[0]);
    int x = 5;
    printf("Position of %d in A: %d\n", x, linearSearch(x, A, n));
    return 0;
}


