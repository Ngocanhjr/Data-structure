/*
Dạng: a^b
Bài toán con nhỏ nhất:
 = 1 khi b = 0; Vì a^0 = 1;

Divided: chia đôi số mũ
 - a^(b/2).a^(b/2): nếu b chẵn
 - a.a^(b/2).a^(b/2): nếu b lẻ


Đề bài: tính N^K, sao đó lấy kq chia dư cho 10^9 + 9
*/

#include <iostream>

using namespace std;

long long mod = 10e9 + 7;

long long binpow(int a, int b)
{
    if (b == 0) return 1;
    long long temp = binpow(a,b/2);
    if(b%2 == 0){
        return temp*temp;
    } else {
        return temp*temp*a;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << binpow(n, k);
}