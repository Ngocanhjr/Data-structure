#include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>

using namespace std;

// Complete search

int X[100];  // Save config

int n;  // Length of bit

void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << X[i];
    }
}
/// @brief
/// @param i : bit thứ i mà mình muốn xây dựng
void Try(int i)
{
    // Thử gán các giá trị có thể cho phần tử X[i]: Vì là xâu nhị phân nên chỉ có thể nhận các giá trị 0 & 1
    for (int j = 0; j <= 1; j++)
    {
        X[i] = j;

        if (i == n)
        {
            print();
            cout << endl;
        }
        else
        {
            Try(i + 1);
        }
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    cout << "Nhap vao n: ";
    cin >> n;
    Try(1);
}
