#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r) {
    int pivot = a[l];
    int start = l;
    int end = r;
    while(start < end){
        while(a[start] <= pivot){
            start++;
        }

        while(a[end] > pivot){
            end--;
        }
        if(start < end){
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[l], &a[end]);
    return end;
}

void quickSort(int a[], int start, int end) {
    if (end > start) {
        int pivot = partition(a, start, end);
        quickSort(a, start, pivot - 1);
        quickSort(a, pivot + 1, end);
    } else {
        return;
    }
}

int main() {
    int a[] = {3, 7, 8, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}