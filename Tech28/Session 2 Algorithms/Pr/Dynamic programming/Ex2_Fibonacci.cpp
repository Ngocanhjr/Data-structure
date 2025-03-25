#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll F[1000001];

int main() {

    F[0] = 0;
    F[1] = 1;

    for(int i = 2; i<=1000000; i++){ //Tính từ số fibo thứ 2
        F[i] = F[i - 1] + F[i -2];
        F[i] %= MOD;
    }

}