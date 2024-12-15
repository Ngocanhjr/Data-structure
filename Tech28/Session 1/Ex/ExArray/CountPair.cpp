#include <math.h>

#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
    {
        cin >> x;
    }
    int k;
    cin >> k;
    for (int x : a)
    {
        cout << x << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] + a[j]) == k)
            {
                cout << a[i] << ' ' << a[j] << endl;
            }
        }
    }
}
