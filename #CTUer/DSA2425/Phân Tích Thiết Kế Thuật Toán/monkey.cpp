#if 0
#include <algorithm>
#include <iostream>
#define MAX 105
using namespace std;

int A[MAX][MAX];
int B[MAX][MAX];
int m;

int main() {
    cin >> m;
    int rows = 2 * m + 1;

    // Nhập phần tam giác trên
    for (int i = 1; i <= m + 1; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> A[i][j];
            B[i][j] = -9999;  // Khởi tạo giá trị rất nhỏ
        }
    }

    // Nhập phần tam giác dưới
    for (int i = m + 2; i <= rows; i++) {
        int t = 2 * m + 2 - i;
        for (int j = 1; j <= t; j++) {
            cin >> A[i][j];
            B[i][j] = -9999;
        }
    }

    // Base case
    B[1][1] = A[1][1];

    // Tam giác trên
    // for (int i = 2; i <= m + 1; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         if (j == 1)
    //             B[i][j] = B[i - 1][j] + A[i][j];
    //         else if (j == i)
    //             B[i][j] = B[i - 1][j - 1] + A[i][j];
    //         else
    //             B[i][j] = max(B[i - 1][j - 1], B[i - 1][j]) + A[i][j];
    //     }
    // }

    // // Tam giác dưới
    // for (int i = m + 2; i <= rows; i++) {
    //     int t = 2 * m + 2 - i;
    //     for (int j = 1; j <= t; j++) {
    //         if (j == t) // Không được truy cập j + 1
    //             B[i][j] = B[i - 1][j] + A[i][j];
    //         else
    //             B[i][j] = max(B[i - 1][j], B[i - 1][j + 1]) + A[i][j];
    //     }
    // }
    // Tam giác trên
    for (int i = 2; i <= m + 1; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                B[i][j] = B[i - 1][j] + A[i][j];
            else if (j == i)
                B[i][j] = B[i - 1][j - 1] + A[i][j];
            else
                B[i][j] = max(B[i - 1][j - 1], B[i - 1][j]) + A[i][j];
        }
    }

    // Tam giác dưới
    for (int i = m + 2; i <= rows; i++) {
        int t = 2 * m + 2 - i;
        for (int j = 1; j <= t; j++) {
            B[i][j] = max(B[i - 1][j], B[i - 1][j + 1]) + A[i][j];
        }
    }

    // Kết quả là ô đầu tiên ở dòng cuối cùng
    // cout << B[rows][1] << endl;
    cout << B[rows][1] << endl;
    return 0;
}
#endif
#if 1
#include <iostream>
#include <algorithm>
#define MAX 105
using namespace std;

int A[MAX][MAX];
int B[MAX][MAX];

int main() {
    int m;
    cin >> m;
    int rows = 2 * m + 1;

    // Nhập phần tam giác trên (N+1 dòng)
    for (int i = 1; i <= m + 1; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> A[i][j];
            B[i][j] = -1e9; // khởi tạo giá trị nhỏ
        }
    }

    // Nhập phần tam giác dưới (N dòng)
    for (int i = m + 2; i <= rows; i++) {
        int t = 2 * m + 2 - i; // số lượng phần tử dòng đó
        for (int j = 1; j <= t; j++) {
            cin >> A[i][j];
            B[i][j] = -1e9;
        }
    }

    // Base case
    B[1][1] = A[1][1];

    // Tam giác trên
    for (int i = 2; i <= m + 1; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                B[i][j] = B[i - 1][j] + A[i][j];
            else if (j == i)
                B[i][j] = B[i - 1][j - 1] + A[i][j];
            else
                B[i][j] = max(B[i - 1][j - 1], B[i - 1][j]) + A[i][j];
        }
    }

    // Tam giác dưới
    for (int i = m + 2; i <= rows; i++) {
        int t = 2 * m + 2 - i;
        for (int j = 1; j <= t; j++) {
            B[i][j] = max(B[i - 1][j], B[i - 1][j + 1]) + A[i][j];
        }
    }

    // Kết quả nằm tại B[rows][1]
    cout << B[rows][1] << endl;
    for (int i = 1; i <= m + 1; i++) {
        for (int j = 1; j <= i; j++) {
            cout << B[i][j] << " ";
            // khởi tạo giá trị nhỏ
        }
        cout << endl;
    }

    // Nhập phần tam giác dưới (N dòng)
    for (int i = m + 2; i <= rows; i++) {
        int t = 2 * m + 2 - i; // số lượng phần tử dòng đó
        for (int j = 1; j <= t; j++) {
            cout << B[i][j] << " ";
            
        }
        cout << endl;
    }
    return 0;
}

#endif