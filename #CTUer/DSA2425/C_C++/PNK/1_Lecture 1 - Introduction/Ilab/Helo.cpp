#include <climits>  // Để dùng INT_MIN
#include <iostream>
using namespace std;

// Khai báo mảng toàn cục
int A[100] = {20, 64, 64, -45, 70, 46, -22, -47, -83, 84, -39, -5};

// Hàm tìm tổng dãy con lớn nhất sử dụng thuật toán Chia để trị
int maxSum(int i, int j) {
    // Trường hợp cơ sở: nếu chỉ có 1 phần tử
    if (i == j) return A[i];

    // Tìm vị trí cắt giữa
    int m = (i + j) / 2;

    // Tìm tổng lớn nhất ở nửa trái
    int left = maxSum(i, m);

    // Tìm tổng lớn nhất ở nửa phải
    int right = maxSum(m + 1, j);

    // Tính tổng lớn nhất đi qua điểm giữa
    int sum = 0, max_left = INT_MIN;
    for (int k = m; k >= i; k--) {
        sum += A[k];
        max_left = max(max_left, sum);
    }

    sum = 0;
    int max_right = INT_MIN;
    for (int k = m + 1; k <= j; k++) {
        sum += A[k];
        max_right = max(max_right, sum);
    }

    // Tổng lớn nhất đi qua điểm giữa
    int middle = max_left + max_right;

    // Trả về tổng lớn nhất trong 3 phương án
    return max(max(left, right), middle);
}

int main() {
    int n = 4;  // Số phần tử của mảng
    // Gán giá trị mảng như yêu cầu: 38, 67, -3, 38
    // Gọi hàm maxSum để tìm tổng dãy con lớn nhất
    int result = maxSum(0, n - 1);

    // In ra kết quả
    cout << "Tong day con lien tiep lon nhat la: " << result << endl;

    return 0;
}
