#include <stdio.h>

/*
    Chạy từ đầu đến cuối mảng
    Tại vòng lặp i, coi như dãy từ [0, i - 1] đã được sắp xếp, chèn phần tử a[i] vào vị trí thích hợp
    Sau vòng lặp thứ i thì dãy [0, i] đã được sắp xếp
*/
void display (int a[], int n);
void insertionSort(int a[], int n);
int main (){
    int a[] = { 9, 7, 5, 8, 3, 5};
    int n = sizeof(a)/sizeof(int);
    insertionSort(a, n);
    display(a,n);
}
void insertionSort (int a[], int n){
    for (int i = 1; i < n; i++){
        //chen a[i] vào dãy 0 -> i - 1
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && (a[j] > temp))
        {
            a[j + 1] = a[j];
            j--;
            display(a, n);
            printf("\n");
        }

        a[j + 1] = temp; //a[0]
        printf("Step %d: ", i);
        display(a, n);
        printf("\n");
    }
}
void display (int a[], int n)
{
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}