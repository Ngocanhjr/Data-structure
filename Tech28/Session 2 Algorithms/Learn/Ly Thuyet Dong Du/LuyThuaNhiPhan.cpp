#include <iostream>

using namespace std;
using ll = long long;

ll binPow(ll a, ll b)
{
    cout << a << " " << b/2 << endl;

    // Case stop Recursion
    if (b == 0)
    {
        return 1;
    }
    ll X = binPow(a, b / 2);

    if (b % 2 == 0)
    {
        return X * X;
    }
    else
    {
        return X * X * a;
    }
    // return (b % 2 == 0) ? X * X : X * X * a;
}
ll binPowMod(ll a, ll b, ll c)
{
    cout << a << " " << b/2 << endl;
    // Case stop Recursion
    if (b == 0)
    {
        return 1;
    }
    ll X = binPowMod(a, b / 2,c);

    if (b % 2 == 0)
    {
        return ((X % c) * (X % c) % c);
    }
    else
    {
        return ((X % c) * (X % c) % c) * (a % c) % c;
    }
    // return (b % 2 == 0) ? X * X : X * X * a;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll a, b, c;
    cin >> a >> b >> c;

    cout << binPow(a, b) << endl;
    // cout << binPowMod(a, b, c) << endl;
}