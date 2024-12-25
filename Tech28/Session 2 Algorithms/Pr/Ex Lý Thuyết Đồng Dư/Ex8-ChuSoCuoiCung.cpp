#include <math.h>

#include <iostream>
using ll = long long;

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    int mod = pow(10, k);
    ll res = 1;
    for (int i = 1; i <= m; i++)
    {
        res *= n;
        // cout << res << " ";
        res %= mod;
    }
    cout << endl;
    cout << res;
}