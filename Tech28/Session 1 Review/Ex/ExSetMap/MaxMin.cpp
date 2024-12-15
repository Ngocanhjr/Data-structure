#include <iostream>
#include <set>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // output: in ra kq voi thao tac 3 4

    int size;
    cin >> size;
    set<int> s;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    // for (int x : s)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    int numberOfAction;
    cin >> numberOfAction;
    while (--numberOfAction)
    {
        int action;
        cin >> action;

        switch (action)
        {
            case 1:
            {
                int x;
                cin >> x;
                // cout << "case 1:" << endl;
                s.insert(x);
                // for (int x : s)
                // {
                //     cout << x << " ";
                // }
                // cout << endl;
                break;
            }
            case 2:
            {
                                int x;
                cin >> x;
                // cout << "case 2:" << endl;
                if (s.find(x) != s.end())
                {
                    s.erase(x);
                }
                // for (int x : s)
                // {
                //     cout << x << " ";
                // }
                // cout << endl;
                break;
            }
            case 3:
                cout << *s.begin() << endl;
                break;
            case 4:
                cout << *s.rbegin() << endl;
                break;
            default:
                cout << "Error!";
                break;
        }
    }
}