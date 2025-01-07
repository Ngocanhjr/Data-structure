#include <iostream>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << ' ' << a[i].second << endl;
    }
}