#include <bits/stdc++.h>

using namespace std;

/*
binary search, lower_bound, upper_bound
- logN
- Áp dụng có chuỗi đã sắp xếp
* lower_bound: >= x
- Áp dụng cho mảng, vector, set, map
- return con trỏ (array) or iterator(vector), not return value;
- return vị trí đầu tiên của phần tử lớn hơn hoặc bằng x
- nếu tất cả đều nhỏ hơn X, return last_ite
- Cú pháp tương tự binary_search

* upper_bound: > x
*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int size;
    cin >> size;
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

    // Use function in C++: binary search, lower_bound, upper_bound
    // binary_search: return true/false
    int num;
    cin >> num;
    cout << "Search num: ";
    if (binary_search(a, a + size, num))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    // lower_bound: phù hợp tìm phần tử xuất hiện đầu tiên
    auto it = lower_bound(a, a + size, num);
    // Nếu không thằng nào lớn hơn hoặc bằng num thì trả về a + size ( a.end())
    if (*it != num)
    {
        cout << "NOT FOUND\n";
    }
    else
    {
        cout << "Value >= num: " << *it << endl;
        cout << "Position >= num: " << (it - a) << endl;
    }

    // set, map
    cout << "SET MAP: \n";
    multiset<int> ms;
    for (int x : a)
    {
        ms.insert(x);
    }

    auto ite = ms.lower_bound(num);
    if (ite != ms.end())
    {
        cout << *ite << endl;
    }
    else
    {
        cout << "NOT FOUND\n";
    }
}
