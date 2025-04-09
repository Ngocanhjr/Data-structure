#include <iostream>
using namespace std;

// Đổi nội dung hai biến a và b
void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

// Chọn phần tử pivot
int choosePivot(int A[], int low, int high) {
    int mid = (low + high) / 2;
    return A[mid];  // Trả về giá trị làm pivot
}

// Phân hoạch A[low] ... A[high] thành L pivotVal R
int partition(int A[], int low, int high, int pivotVal) {
    int pivotIndex = low;
    for (int i = low; i <= high; i++) {
        if (A[i] == pivotVal) {
            pivotIndex = i;
            break;
        }
    }

    swap(A[pivotIndex], A[high]);  // Đưa pivot về cuối

    int i = low;
    for (int j = low; j < high; j++) {
        if (A[j] <= pivotVal) {
            swap(A[i], A[j]);
            i++;
        }
    }

    swap(A[i], A[high]);  // Đưa pivot về vị trí đúng
    return i;
}

// Cài đặt thuật toán sắp xếp nhanh
void quickSort(int A[], int low, int high) {
    if (low >= high) return;

    int pivotVal = choosePivot(A, low, high);
    cout << "pivotVal = " << pivotVal << endl;

    int cut = partition(A, low, high, pivotVal);
    //       L         pivotVal          R
    // [low ... cut-1]    cut   [cut+1 ... high]

    cout << "After partition: ";
    for (int i = low; i <= high; i++) cout << A[i] << ' ';
    cout << endl;
    cout << "cut = " << cut << endl;

    quickSort(A, low, cut - 1);   // sắp xếp đoạn L: [low   ... cut-1]
    quickSort(A, cut + 1, high);  // sắp xếp đoạn R: [cut+1 ... high]
}

int main() {
    int A[] = {4, 1, 5, 8, 9, 0, 7};
    quickSort(A, 0, 6);

    cout << "Sorted: ";
    for (int i = 0; i < 7; i++) cout << A[i] << ' ';
    cout << endl;
}