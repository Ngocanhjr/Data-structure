#include <iostream>
using namespace std;

//Đổi nội dung hai biến a và b
void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

//Chọn phần tử pivot
int choosePivot(int A[], int low, int high) {
    return -1; // Tất cả phần tử giống nhau


}

//Phân hoạch A[low] ... A[high] thành L pivotVal R
int partition(int A[], int low, int high, int pivotVal) {
 
}

//Cài đặt thuật toán sắp xếp nhanh
void quickSort(int A[], int low, int high) {
    if (low >= high)
        return;
        
    int index = choosePivot(A, low, high);
    if (index == -1) //Các phần từ đều giống nhau, không có pivot
        return;
    
    int pivotVal = A[index];
    cout << "pivotVal = " << pivotVal << endl;
    
    int cut = partition(A, low, high, pivotVal);
    // [     L     ] [       R      ]
    // [low ... cut] [cut+1 ... high]

    cout << "After partition: ";
    for (int i = low; i <= high; i++)
        cout << A[i] << ' ';
    cout << endl;
    cout << "cut = " << cut << endl;
    
    quickSort(A, low, cut);      //sắp xếp đoạn L: [low   ... cut]
    quickSort(A, cut + 1, high); //sắp xếp đoạn R: [cut+1 ... high]
}

int main() {
    int A[] = {4, 1, 5, 8, 9, 0, 7};
    quickSort(A, 0, 6);
    
    cout << "Sorted: ";
    for (int i = 0; i < 7; i++)
        cout << A[i] << ' ';
    cout << endl;
}