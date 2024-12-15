#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    set<string> se;
    string s;
    while (cin >> s)
    {
        se.insert(s);
    }
    // for(string s: se){
    //     cout << s <<"  " << endl;
    // }
    cout << se.size() << endl;
    cout << *se.begin() << " " << *se.rbegin();
}
