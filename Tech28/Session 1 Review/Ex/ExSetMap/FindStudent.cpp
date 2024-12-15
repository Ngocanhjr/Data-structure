#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r", stdin);
        freopen ("output.txt" , "w", stdout);
    #endif

    map<string, string> mp;

    int numberOfStudent;
    cin >> numberOfStudent;
    cin.ignore();

    for (int i = 0; i < numberOfStudent; i++)
    {
        string code;
        getline(cin, code);
        // cin.ignore();
        string name;
        getline(cin, name);
        mp.insert({code, name});
    }

    // for (pair<string, string> p : mp)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }

    int numOfQuery;
    cin >> numOfQuery;
    cin.ignore();

    while (numOfQuery--)
    {
        string key;
        getline(cin, key);

        auto it = mp.find(key);
        if (it != mp.end())
        {
            cout << it->second << endl;
        }
        else
        {
            cout << "NOT FOUND" << endl;
        }
    }
    return 0;
}