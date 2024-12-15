#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    map<int, int> mp;
    mp.insert({1, 2});
    mp.insert({3, 2});
    mp.insert({4, 5});
    mp.insert({4, 6});
    // insert (2,6)
    // map[key] = value;  O(longN)
    // Key: maybe all datatype in c++
    // Neu key da ton tai thi change value
    mp[2] = 6;
    cout << mp.size() << endl;
    for (pair<int, int> p : mp)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << "use auto :" << endl;
    for (auto p : mp)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << "use iterator: " << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        // cout<< (*it).first << " " << (*it).second << endl;
        cout << it->first << " " << it->second << endl;
    }
}