#include <stdio.h>

#include <algorithm>  //for max() function
#include <iostream>
#include <stack>    //for stack class
#include <string>   // for string class
#include <utility>  //for pair struct

using namespace std;

#define MAX_SIZE 100

pair<int, int> P[MAX_SIZE][MAX_SIZE];
int C[MAX_SIZE][MAX_SIZE];

// Cài đặt thuật toán LCS tìm dãy con cung dài nhất của 2 chuỗi X, Y
// Trong C++, class string của std dùng để biểu diễn các chuỗi ký tự
// thay cho char[] hay char* trong ngông ngữ C
// Cách khai báo tham số kiểu const type& name thường dùng với
// dữ liệu có kích thước lớn (truyền tham chiếu bằng ký hiệu &)
// và ta không muốn hàm thay đổi nội dung của tham số (từ khoá const)

int LCS(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.size();  // length() hay size() được dùng để lấy chiều dài chuỗi

    // Khởi tạo:
    // Gán C[0, j] = 0 với mọi j
    // Gán C[i, 0] = 0 với mọi i

    for (int i = 0; i <= m; i++) C[i][0] = 0;
    for (int j = 0; j <= n; j++) C[0][j] = 0;

    // Lặp
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // Điền giá trị vào ô C[i, j]
            // Chú ý: i, j chạy từ 1 trong khi chỉ số của các chuỗi X và Y tính từ 0.
            // Do đó khi điền ô C[i,j] phải so sánh X[i-1] với Y[j-1]
            // Sử dụng make_pair(a, b) để tạo cặp (a,b)
            if (X[i - 1] == Y[j - 1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                P[i][j] = make_pair(i - 1, j - 1);
            } else {
                if (C[i - 1][j] >= C[i][j - 1]) {
                    C[i][j] = C[i - 1][j];
                    P[i][j] = make_pair(i - 1, j);
                } else {
                    C[i][j] = C[i][j - 1];
                    P[i][j] = make_pair(i, j - 1);
                }
            }
        }
    }

    // Trả về chiều dài của dãy con chung dài nhất của X và Y
    return C[m][n];
}

// Kiểm thử
int main() {
    string X, Y;

    getline(cin, X);  // Đọc chuỗi trên dòng 1
    getline(cin, Y);  // Đọc chuỗi trên dòng 2

    cout << "X = " << X << endl;
    cout << "Y = " << Y << endl;
    cout << "length of LCS(X, Y) = " << LCS(X, Y, P) << endl;

    // Truy vết
    int i = X.length();
    int j = Y.length();

    stack<char> S;  // Lưu dãy con chung dài nhất theo chiều từ phải sang trái
    while (i > 0 && j > 0) {
        int k = P[i][j].first;
        int l = P[i][j].second;        // (k, l) là ô trước ô (i, j)
        if (k == i - 1 && l == j - 1)  // trường hợp X[i] == Y[j]
            S.push(X[i - 1]);          // chỉ số của string tính từ 0
                                       // trong khi i đi từ 1
        i = k;
        j = l;
    }

    // In dãy con chung dài nhất theo chiều từ trái sáng phải
    while (!S.empty()) {
        cout << S.top() << ' ';
        S.pop();
    }

    return 0;
}
