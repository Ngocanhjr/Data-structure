#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;  //  vertices, edge
    cin >> n >> m;

    vector<int> dsKe[105];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        dsKe[x].push_back(y);
        dsKe[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(dsKe[i].begin(), dsKe[i].end());
        cout << i << " : ";
        for(int x: dsKe[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}