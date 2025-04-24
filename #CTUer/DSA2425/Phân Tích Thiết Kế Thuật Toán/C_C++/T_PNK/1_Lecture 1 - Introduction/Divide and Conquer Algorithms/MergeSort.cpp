#include <iostream>
#include <vector>

using namespace std;
vector<int> A = {2,1,3,9,8,7};

vector<int> mergeSort(vector<int> A) {
    int n = A.size();
    if (n <= 1) {
        return A;
    }

    int m = n / 2;
    vector<int> L = mergeSort(vector<int>(A.begin(), A.begin() + m));
    vector<int> R = mergeSort(vector<int>(A.begin() + m, A.end()));

    vector<int> K;

    auto l = L.begin();
    auto r = R.begin();

    // Dừng lại khi 1 trong 2 mảng hết
    while (l != L.end() && r != R.end()) {
        int temp;
        if (*l < *r) {
            temp = *l;
            K.push_back(temp);
            l++;
        } else {
            temp = *r;
            K.push_back(temp);
            r++;
        }
    }

    // Mảng bên trái còn phần tử
    while (l != L.end()) {
        int temp = *l;
        K.push_back(temp);
        l++;
    }

    // Mảng bên phải còn phần tử
    while (r != R.end()) {
        int temp = *r;
        K.push_back(temp);
        r++;
    }

    return K;
}

int main() {
    vector<int> rs = mergeSort(A);
    for (int x : rs) {
        cout << x << " ";
    }
    // sort(A.begin(), A.end());
    // if( rs != A){
    //     cout << ""
    // }
}