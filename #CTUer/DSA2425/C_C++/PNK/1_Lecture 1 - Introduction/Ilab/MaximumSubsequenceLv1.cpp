#include <iostream>
#define MAX 100

using namespace std;

int A[MAX];
/*
Dãy sẽ được chia thành hai nửa, sau đó tìm:

Tổng lớn nhất ở nửa trái.
Tổng lớn nhất ở nửa phải.
Tổng lớn nhất đi qua điểm giữa.
*/

int maxSum(int i, int j) {
    // 1. Kiểm tra i == j
    if (i == j) return A[i];  // Dãy chỉ có 1 phần tử, trả về phần tử A[i]

    // Tính tiếp, sẽ có 3 phương án: left, right và xuyên qua điểm cắt (middle)
    // 2. Tìm vị trí cắt
    int m = (i + j) / 2;

    // 3. Gọi đệ quy tìm lời giải bên trái: từ i đến m
    int left = maxSum(i, m);

    // 4. Gọi đệ quy tìm lời giải bên phải: từ m+1 đến j
    int right = maxSum(m + 1, j);

    // 5. Tìm tổng của dãy lớn nhất đi xuyên qua điểm cắt
    // max_left là tổng dãy lớn nhất kết thúc tại A[m]
    // max_right là tổng dãy lớn nhất bắt đầu tại A[m + 1]
    int middle = max_left + max_right;

    // 6. Trả về phương án tốt nhất
    return max(max(left, right), middle);
}