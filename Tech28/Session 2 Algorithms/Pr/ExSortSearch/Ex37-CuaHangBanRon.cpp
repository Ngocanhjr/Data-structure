#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;         // number of customer
    map<int, int> m;  // store time come and time out of customer
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        m.insert({a, b});
    }
    // for (auto p : m)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }


}
/*
input:
3
5 8
2 4
3 9
output: 2, max of customer in shop at the same time

input:
4
1 10
2 4
3 5
7 9
output: 3

*/