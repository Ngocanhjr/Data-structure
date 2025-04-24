/*
- Sâu con chung dài nhất, không liên tiếp
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_LENGTH 50

int main() {
    // Define: Chiều dài của chuỗi con chung dài nhất của x và y
    int C[MAX_LENGTH][MAX_LENGTH] = {0};  // C[m][n] = độ dài

    // Define: Bảng truy vết
    pair<int, int> T[MAX_LENGTH][MAX_LENGTH];
    // vector<pair<int, int>> T;


    // Chuỗi dài nhất
    string lcs = "";

    // Chuỗi X và Y
    string X, Y;
    cin >> X >> Y;
    int m = X.length(), n = Y.length();  // C[m][n] = độ dài

    X = "0" + X;
    Y = "0" + Y;

    // Init
    C[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        C[i][0] = 0;
    }
    for (int j = 1; j <= n; j++) {
        C[0][j] = 0;
    }

    // CT truy hồi - > đệ quy cắt đuôi
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                // Truy vết
                T[i][j] = {i - 1, j - 1};
                lcs = X[i - 1] + lcs;
            } else {
                C[i][j] = max(C[i][j - 1], C[i - 1][j]);
            }
        }
    }

    cout << C[m][n] << endl;
    cout << "LCS: " << lcs << endl;
    for (int k = T.size() - 1; k >= 0; k--) {
        cout << "(" << T[k].first << "," << T[k].second << ") - " << X[T[k].first - 1] << endl;
    }
}

/*
- input:ZHFTDFHF
TFISHROV
- output: 3
 */