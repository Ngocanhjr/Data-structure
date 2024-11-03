#include <stdio.h>
#include <stdlib.h>
// void merge(int left[], int right[], int a[]){

// }

// void mergeSort(int a[]){
//     int n = sizeof(a)/sizeof(int);
//     printf("%d\n", n);
// }

void merge(int a[], int left, int middle, int right) {  /// m = l + (r - l)/2: to avoid overflow
    int leftSize = middle - left + 1;                   // First sub array is a[l..m]
    int rightSize = right - middle;                     // Second sub array is a[m+1..r]
    int length = left + right + 1;

    int* leftArray = (int*)malloc(leftSize * sizeof(int));
    int* rightArray = (int*)malloc(rightSize * sizeof(int));

    // Copy data to temp arrays left[] and right[]
    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = a[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = a[middle + 1 + j];
    }

    // err
    //  for (; i < length; i++) {
    //      if (i < middle) {
    //          leftArray[i] = a[i];
    //      } else {
    //          rightArray[j] = a[i];
    //          j++;
    //      }
    //  }

    int l = 0, r = 0;  // Initial index of left and right sub arrays
    int k = left;      // Index for merged array

    // Check condition and merge the temp arrays back into a[l..r]
    while (l < leftSize && r < rightSize) {
        if (leftArray[l] <= rightArray[r]) {
            a[k] = leftArray[l];  // Copy leftArray to a
            l++;
        } else {
            a[k] = rightArray[r];  // Copy rightArray to a
            r++;
        }
        k++;
    }

    while (l < leftSize) {
        a[k] = leftArray[l];
        l++;
        k++;
    }

    while (r < rightSize) {
        a[k] = rightArray[r];
        r++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // Same as (l + r) / 2, but avoids overflow for large l and r
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {3, 7, 8, 5, 4, 2, 6, 1};
    int len = sizeof(a) / sizeof(int);

    printf("Before sort: ");
    printArray(a, len);
    mergeSort(a, 0, len - 1);
    printf("After sort: ");
    printArray(a, len);
    printf("DONE!\n");
    return 0;
}