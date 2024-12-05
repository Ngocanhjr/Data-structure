#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int start, int end) {
    int pivot = a[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    i++;
    swap(&a[i], &a[end]);
    return i;
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