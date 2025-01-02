#include <bits/stdc++.h>

#include <vector>
// #include <algorithm>
// #include <iostream>

/*
< Điều kiện dừng
- Duyệt bit thứ 2 từ cuối về (từ n - 1)
- Tìm a[i] < a[i + 1] -> tìm thằng đứng trước nhỏ hơn thằng đứng sau
>

- Cấu hình tiếp theo là: lớn hơn nhỏ nhất so với cấu hình hiện tại
Vd: 1269876543 => 12|6|9876543 => Hoán vị 6 và 7 (số lớn hơn nhỏ nhất so với vị trí i tới n - 1)
->1279876543
- sort lại đoạn sau: 1273456789 (cấu hình tiếp theo)
*/

using namespace std;

int n, a[100];  // save config

bool final = false;  // check is final config

vector<vector<int>> res;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}

void ReverseInit()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = n - i + 1;
    }
}
/// @brief Đi tìm vị trí i đầu tiên mà a[i] < a[i + 1]
void generate()
{
    int i = n - 1;

    while (i > 0 && a[i] > a[i + 1])
    {
        i--;
    }

    if (i == 0)
    {
        final = true;
    }
    else
    {
        // Đi tìm  a[j] > a[i]
        int j = n;
        while (a[i] > a[j])
        {
            --j;
        }
        swap(a[i], a[j]);
        /// Khoảng được đảo ngược là từ a[i + 1] đến a[n].
        reverse(a + i + 1, a + n + 1);
    }
}

void display()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void displayRes()
{
    for (int i = 0; i < res.size(); i++)
    {
        for (int x : res[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    cout << "Nhap vao so nguyen n: ";
    cin >> n;
    init();
#if 0
    while (!final)
    {
        vector<int> temp(a + 1, a + n + 1);
        res.push_back(temp);
        generate();
    }
    displayRes();
#endif

    int X[] = {1, 2, 6, 9, 8, 7, 6, 5, 4, 3};
    // Trả về true, false
    cout << "next_permutation: " << next_permutation(X, X + 9) << endl;
    for (int x : X)
    {
        cout << x << " ";
    }

#if 1
    cout << endl << "USE NEXT" << endl;
    do
    {
        display();
    } while (next_permutation(a + 1, a + n + 1));

    cout << endl
         << "=======================================================USE PREV==========================================="
         << endl;
    ReverseInit();
    do
    {
        display();
    } while (prev_permutation(a + 1, a + n + 1));
#endif
}
