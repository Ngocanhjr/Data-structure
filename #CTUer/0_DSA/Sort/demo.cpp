#include <iostream>

int* selectionSort ( int a[], int n);
void swap(int *a, int *b);
void getArray (int a[], int x);
int main (){
    int a[] = { 1, 4, 0, 9 ,3};
    int sizeArray = sizeof(a)/sizeof(a[0]);
    getArray(a,sizeArray);
    printf("\n");
    selectionSort(a,sizeArray);
    getArray(a,sizeArray);
}

void getArray(int a[], int x){
    for (int i = 0; i < x; i++){
        printf("%d ", a[i]);
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int* selectionSort ( int a[],int n){
    printf("demo\n");
    for (int i = 0; i < n - 1; i++){
        int min=i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap (&a[min], &a[i]);
        getArray(a,n);
        printf("\n");
    }
    return a;
}
