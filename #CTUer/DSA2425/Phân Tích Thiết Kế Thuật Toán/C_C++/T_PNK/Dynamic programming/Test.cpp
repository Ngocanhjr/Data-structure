#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_LENGTH 50

int C[MAX_LENGTH][MAX_LENGTH] = {0};  // Bảng lưu độ dài chuỗi con chung
pair<int, int> T[MAX_LENGTH][MAX_LENGTH];  // Bảng lưu truy vết

int main() {
    // Nhập hai chuỗi
    string X, Y;
    cin >> X >> Y;
    
    int m = X.length(), n = Y.length();

    // Tạo bảng C và bảng truy vết T
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (X[i - 1] == Y[j - 1]) {  // Lưu ý: Chỉ số X[i-1], Y[j-1] vì chuỗi bắt đầu từ 0
                C[i][j] = C[i - 1][j - 1] + 1;
                T[i][j] = {i - 1, j - 1};  // Lưu vị trí trước đó
            } else {
                if (C[i - 1][j] > C[i][j - 1]) {
                    C[i][j] = C[i - 1][j];
                    T[i][j] = {i - 1, j};  // Truy vết từ trên xuống
                } else {
                    C[i][j] = C[i][j - 1];
                    T[i][j] = {i, j - 1};  // Truy vết từ trái sang
                }
            }
        }
    }

    // In ra độ dài chuỗi con chung dài nhất
    cout << C[m][n] << endl;

    // Truy vết lại để tìm chuỗi con chung
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;  // Lấy ký tự chung
        }
        auto prev = T[i][j];
        i = prev.first;
        j = prev.second;
    }

    cout << "LCS: " << lcs << endl;

    return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_LENGTH 50

int main() {
    // Define: Chiều dài của chuỗi con chung dài nhất của x và y
    int C[MAX_LENGTH][MAX_LENGTH] = {0};  // C[m][n] = độ dài

    // Vector lưu các cặp tọa độ (i, j) để truy vết
    vector<pair<int, int>> T;

    // Chuỗi X và Y
    string X, Y;
    cin >> X >> Y;
    int m = X.length(), n = Y.length();

    // Init
    for (int i = 0; i <= m; i++) {
        C[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        C[0][j] = 0;
    }

    // CT truy hồi - > đệ quy cắt đuôi
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                // Không lưu truy vết ở đây
            } else {
                C[i][j] = max(C[i][j - 1], C[i - 1][j]);
            }
        }
    }

    // In độ dài chuỗi con chung dài nhất
    cout << "Độ dài LCS: " << C[m][n] << endl;

    // Truy vết bằng cách đi từ C[m][n] ngược về C[0][0]
    int i = m, j = n;
    string lcs = "";
    
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            // Nếu ký tự giống nhau, lưu tọa độ và đi chéo
            T.push_back(make_pair(i, j));
            lcs = X[i-1] + lcs;
            i--; j--;
        } else if (C[i-1][j] >= C[i][j-1]) {
            // Đi lên trên
            i--;
        } else {
            // Đi sang trái
            j--;
        }
    }

    // In chuỗi con chung
    cout << "LCS: " << lcs << endl;
    
    // In ra các tọa độ truy vết (theo thứ tự ngược)
    cout << "Đường đi (i, j): " << endl;
    for (int k = T.size() - 1; k >= 0; k--) {
        cout << "(" << T[k].first << "," << T[k].second << ") - " 
             << X[T[k].first-1] << endl;
    }
    
    return 0;
}