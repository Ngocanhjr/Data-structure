#include <iostream>
#include <set>

using namespace std;

using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a[] = {3, 1, 2, 2, 1, 4, 6, 8, 9};
    set<int> s;
    for (int x : a)
    {
        s.insert(x);
    }
    cout << s.size() << endl;

    for (int x : s)
    {
        cout << x << " ";
    }

    cout << endl << "Iterator: " << endl;

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl << "Reverse printing : " << endl;

    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << "Max and min: ";
    cout << *s.begin() << " " << *s.rbegin();
    cout << endl << "End: " << *s.end();
    cout << endl << "Find: ";
    auto i = s.find(9);
    if (i != s.end())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl << "\t  "; 
    cout << (s.find(5) != s.end() ? "YES" : "NO");

    //Ham find, erase: O(LogN)
    //Nếu trong set không có trong set mà erase thì sẽ gây ra lỗi

}