#include <iostream>

using namespace std;

#define INF 99999

int main() {
    // define: số mệnh giá và tổng số tiền
    int n, m;
    cout << "Nhap vao n menh gia va tong so tien: ";
    cin >> n >> m;

    // define: V[]: mang luu tru menh gia, K[x]: số tờ tiền của cách chọn tối ưu với tổng mệnh giá
    // là x
    int V[n], K[m + 1];

    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }

    for (int t : V) {
        cout << t << " ";
    }

    cout << endl;
    // Init
    K[0] = 0;

    for (int i = 1; i <= m; i++) {
        K[i] = INF;
        for (int j = 0; j < n; j++) {
            if (V[j] <= i) {
                if (K[i] > K[i - V[j]] + 1) {
                    K[i] = K[i - V[j]] + 1;
                    // T[i] = make_pair(i - V[j], K[i]);
                }
            }
        }
        // cout << T.first << " :" << T.second << endl;
    }
    cout << K[m];
}