#include <iostream>

using namespace std;

int factorial(int n) {
    // 1 . Điều kiện dừng
    if (n == 0) {
        return 1;
    }

    // 2. Tính (n - 1)! và lưu tại n_1
    int n_1 = factorial(n - 1);
    return n*n_1;
}

int main() {
    int n; cin >> n;
    cout << factorial(n);
}