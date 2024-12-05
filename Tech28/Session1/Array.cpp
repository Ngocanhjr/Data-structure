#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPrimeNumber(ll n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return n > 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    // Method 1:
#if 0
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
#endif
    // Method 2:
#if 1
    for (int &x : a)
    {
        cin >> x;
    }
#endif
    for (int i = 0; i < n; i++)
    {
        if (isPrimeNumber(a[i]))
        {
            cout << a[i] << ' ';
        }
    }

    cout << endl;
    for (int x : a)
    {
        if (isPrimeNumber(x))
        {
            cout << x << ' ';
        }
    }
}