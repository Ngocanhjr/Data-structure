/*
 Cho số nguyên dương N, hãy đếm xem trong đoạn từ 0 tới N có bao nhiêu số
nguyên tố. Hướng dẫn :
 - Bước 1 : Sàng số nguyên tố
 - Bước 2 : Gọi F[i] là số lượng các số nguyên tố từ 0 tới i, xây dựng mảng F[i]
sau khi sàng
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// const ll max = 1e6;
const long long max 1e7;

ll prime[max];

// Sàng sô nguyên tố
void sieve()
{
    for (int i = 0; i <= max; i++)
    {
        prime[i] = i;
    }
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= sqrt(max); i++)
    {
        if (prime[i])
        {  // Nếu i là số nguyên tố
            // Đánh dấu tất cả các bộ số của i
            for (int j = i * i; j <= max; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

// mảng lưu trữ
int F[1000001];
int main()
{
    sieve();
    int cnt;
    for (int i = 0; i <= 1000000; i++)
    {
        if (prime[i])
        {
            ++cnt;
            F[i] = cnt;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n; cin>> n;
        cout << F[n];
    }
}