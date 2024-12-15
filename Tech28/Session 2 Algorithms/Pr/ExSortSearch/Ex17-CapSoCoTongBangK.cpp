// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int size;
    cin >> size;
    int key;
    cin >> key;
    int a[size];
    for (int &x : a)
    {
        cin >> x;
    }
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    sort(a, a + size);
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    long long ans = 0;
    for (int i = 0; i < size; i++)
    {
        // count : k - a[i] nếu có
    }
}