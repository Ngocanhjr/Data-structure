#include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>

/*
- O(2^N)
*/
using namespace std;

using ll = long long;

#define MAX 100  // con số lớn nhất có thể sinh ra

int n, k, final = 0;
int a[MAX];

/// @brief initialize first configuration
void init()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
    // create n bit 0
}

void generate()
{
    int i = k;
    /*
    => cấu hình tăng dần tối thiểu
    Mục tiêu tìm thằng chưa đạt giá trị max (từ bên phải) để tăng lên 1 đơn vị
    max = n - k + i; giá trị lớn nhất tại vị trí i có thể có
    -> đi tìm vị trí đầu tiên chưa đạt cực đại tại đầu tiên từ bên phải
    */
    while (i >= 1 && a[i] == (n - k + i))
    {
        i--;
    }
    if (i == 0)
    {
        final = 1;
    }
    else
    {
        a[i]++;
        int temp = a[i] + 1;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = temp;
            ++temp;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> k;
    init();
    while (!final)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << a[i];
        }
        cout << endl;
        generate();
    }
}
