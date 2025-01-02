#include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>

/*
In ra các cách phân tích N dưới dạng tổng các tự nhiên nhỏ hơn hoặc bằng N
không xét thú tự
-> in ra theo thứ tự giảm dần

Giải thuật:
- Đi tìm số hạn đầu tiên có thể giảm xuống được -> giảm xuống 1 đơn vị
- Thông qua thằng vừa giảm xuống, tìm phần bù cho các số hạn ở sau
*/
using namespace std;

int n, a[100];  // lưu cấu hình

int cnt;  // Lưu sl số hạng trong phân tích

bool final = false;  // check cấu hình cuối

void init()
{
    cnt = 1;
    a[1] = n;
}

void generate()
{
    // Bắt đầu từ số hạng cuối cùng và tìm số hạng đầu tiên != 1
    int i = cnt;
    while (i > 0 && a[i] == 1)
    {
        i--;
    }

    if (i == 0)
    {
        final = true;
    }
    else
    {
        a[i]--;
        int d = cnt - i +1;
        cnt = i;
        int q = d / a[i];  // phần còn thiếu gấp mấy lần a[i]
        int r = d % a[i];
        for (int j = 1; j <= q; j++)
        {
            a[i + j] = a[i];
            ++cnt;
        }

        if (r != 0)
        {
            ++cnt;
            a[cnt] = r;
        }
    }
}

void display()
{
    for (int i = 1; i <= cnt; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    cout << "Nhap vao n: ";
    cin >> n;
    init();
    while (!final)
    {
        display();
        generate();
    }
}
