#include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>

/*
- O(2^N): sinh ra 2^n xâu nhị phân
- đi tìm bit 0 đầu tiên tính từ bên phải -> 1, sau đó giữ nguyên phía trước
- gặp bit 1 sẽ chuyển thành 0
*/
using namespace std;

using ll = long long;

#define MAX 100  // con số lớn nhất có thể sinh ra

int n, final = 0;
int a[MAX];
// n là số bit của xâu nhị phân
// mảng a lưu trữ xâu nhị phân
// final là biến kiểm tra xem đã sinh hết xâu chưa

/// @brief initialize first configuration
void init()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
    // create n bit 0
}

void generate()
{
    int i = n;  // bắt đầu từ bit cuối cùng
    while (a[i] == 1 && i >= 1)
    {
        a[i] = 0;
        i--;
    }
    if (i == 0)
    {
        final = 1;
    }
    else
    {
        a[i] = 1;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    init();
    while (!final)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        generate();
    }
}
