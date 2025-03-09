// #include <bits/stdc++.h>
// // #include <algorithm>
#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // n: Vertices
    // m: edge
    int n, m;
    int mtKe[105][105];  // nếu quá lớn sẽ gây tràn bộ nhớ stack vd 1005
    // Vì mtKe[1005][1005] chiếm khoảng ~4MB (1005 * 1005 * 4 byte với int 4 byte)
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;  // 2 đỉnh của cạnh
        mtKe[x][y] = 1;
        mtKe[y][x] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mtKe[i][j] << " ";
        }
        cout << endl;
    }
}
