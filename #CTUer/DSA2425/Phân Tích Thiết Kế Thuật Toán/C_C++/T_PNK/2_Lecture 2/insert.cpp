#include <iostream>

using namespace std;

// void demo(int arr[]) {
//     // int arr[] = {14, 3, 6, 27, 12};
//     for (int item : arr) {
//         // biến item đại diện cho phần tử mảng ở mỗi vòng lặp
//         cout << item << " ";
//     }
//     cout << endl;
// }
// void print(int A[], int n) {
//     //	for(int i = 0; i < n; i++){
//     //		cout << A[i] << " ";
//     //	}
//     for (int x : A) {
//         cout << x << " ";
//     }
//     cout << endl;
// }

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int current = A[i];
        int j = i - 1;
        // So sanh current va cac gia tri truoc do
        while (j >= 0 && A[j] > current) {
            // Neu thoa thi tinh tien sang phai
            A[j + 1] = A[j];
            j--;
            // tiep tuc so sanh cac gia tri con lai
        }
        // Cap nhat gia tri sau khi tinh tien sang phai
        A[j + 1] = current;
        for(int k = 0; k < n; k++){
            cout << A[k] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int A[] = {6, 4, 3, 5, 8};

    int n = sizeof(A) / sizeof(int);

    //	print(A,n);
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;

    insertionSort(A, n);
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;
}