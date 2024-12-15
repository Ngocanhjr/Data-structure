#include <iostream>
#include <set>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    set<int> s;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    // for (int x : s)
    // {
    //     cout << x << " ";
    // }
    int quantitySearch;
    cin >> quantitySearch;
    for (int i = 0; i < quantitySearch; i++)
    {
        int temp;
        cin >> temp;
        auto founded = s.find(temp);
        if (founded != s.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO";
        }
    }
}