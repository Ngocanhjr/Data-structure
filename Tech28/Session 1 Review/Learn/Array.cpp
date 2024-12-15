#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPrimeNumber(ll n);

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
    cout << "Address: ";
    cout << a << endl;
    for (int i = 0; i < n; i++)
    {
        cout << &a[i] << " ";
    }
    cout << endl;
    cout << "Dia chi phan tu thu 3:" << (a + 3) << endl;
    cout << "Value phan tu thu 3:" << *(a + 3) << endl;
    auto it = a + 3;
    cout << "Vi tri cua it: " << (it - a) << endl;
    cout << "Prime number in array a" << endl;
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
    cout << endl;

    sort(a, a + n);
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    //vector
    // sort(a.begin(), a.end());
    // for (int x : a)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
}


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
