#include <stdio.h>

/*
Nguyên lý:
    Chạy từ đầu đến cuối mảng
    Nếu phần tử đứng  trước mà lớn hơn phần tử đứng sau thì đổi chỗ
    Sau mỗi vòng lặp thì phần tử lớn nhất sẽ trôi xuống dưới ( phần tử lớn nhất nằm cuối cùng)
    1 4 5 6 2 7 
    1 4 5 2 6 7 
    1 4 2 5 6 7 
    1 2 4 5 6 7
     for ( int i = 0; i < n  ; i++){
        for ( int j = 0; j < n - i - j; j ++ ){
            if (a[j] > a [j + 1]){

*/
void bubbleSort (int a[], int n);
void  swap (int &a ,int &b);
void disPlay(int a[], int n);
int main (){
    int n = 10;
    int a[] = { 1, 2, 4, 6, 5};
    n = sizeof(a)/sizeof(int);
   // int a[n] = { 1, 5, 4, 6, 7, 2, 0};
    disPlay(a,n);
    printf("\n");
    bubbleSort(a,n);    
    disPlay(a,n);
}
void disPlay (int a[], int n){
     for ( int i = 0; i < n; i++){
        printf ("%d ", a[i]);
    }
}
void  swap (int &a ,int &b){
    int t = a;
    a = b;
    b = t;
}
void bubbleSort (int a[], int n){
    for ( int i = 0; i < n  ; i++){
        int isSorted = 1;
        for ( int j = 0; j < n - i - 1; j ++ ){ //j - 1 < n - i => j < n - i - 1
            if (a[j] > a [j + 1]){ // đưa số lớn ra sau
                isSorted = 0;
                swap ( a[j], a[j + 1]);
                disPlay(a,n);
                printf("\n");
            }
        }
        if(isSorted)
        {
            break;
        }
    }
}