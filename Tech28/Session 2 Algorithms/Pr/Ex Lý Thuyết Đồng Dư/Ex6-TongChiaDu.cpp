#include <iostream>

#define MOD 1000000007  // 10^9 + 7

using namespace std;

using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int size;
    cin >> size;

    ll ans = 0;

    for (int i = 0; i < size; i++)
    {
        ll temp;
        cin >> temp;
        ans += temp;
        ans %= MOD;
        // ans = ((ans % MOD) + temp % MOD) % MAX;
    }
    cout << ans;
}