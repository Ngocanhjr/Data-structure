#include <iostream>

using namespace std;

int A[] = {20, 64, 64, -45, 70, 46, -22, -47, -83, 84, -39, -5};
int n = sizeof(A) / sizeof(int);

void insertionSort() {
    for (int i = 1; i < n; i++) {
        int current = A[i];

        int j = i - 1;
        while (j >= 0 && A[j] > current) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = current;
    }
}

int main() {
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;
    insertionSort();
    for (int x : A) {
        cout << x << " ";
    }
}