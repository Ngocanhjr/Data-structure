#include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>

using namespace std;

void init(char a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 'B';
        // cout <<a[i];
    }
}

void generate(char a[], int n, bool &final)
{
    int i = n;

    while (i >= 1 && a[i] == 'A')
    {
        a[i] = 'B';
        i--;
    }

    if (i == 0)
    {
        final = true;
    }
    else
    {
        a[i] = 'A';
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;  // number of bit

    bool final = false;
    char res[n];
    init(res, n);
    while (!final)
    {
        for (int i = 1; i <= n; i++)
        {
            cout <<res[i];
        }
        cout << endl;
        generate(res, n, final);
    }
}
