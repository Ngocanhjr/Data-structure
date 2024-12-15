#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size;
    cin >> size;
    int a[size];
    map<int, int> mp;

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
        auto it = mp.find(a[i]);
        if (it != mp.end())
        {
            mp[a[i]]++;
        }
        else
        {
            mp[a[i]] = 1;
        }
    }
    // for (auto p : mp)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    for(int i = 0; i< size; i++){
        auto it = mp.find(a[i]);
        if (it != mp.end())
        {
            cout << it->first << " " << it->second << endl;
        }
        mp.erase(a[i]);
    }
}