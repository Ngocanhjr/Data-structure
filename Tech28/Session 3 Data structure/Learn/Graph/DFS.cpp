#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> dsKe[1005];

vector<pair<int, int>> dsCanh;

int mtKe[1005][1005];

int n, m;  //  vertices, edge

bool visited[1001];

/// @brief duyet danh sach ke
/// @param u :vertices
void DFS1(int u)
{
    cout << u << " ";
    visited[u] = true;
    // Duyet danh sach ke
    for (int v : dsKe[u])
    {
        if (!visited[v])
        {
            DFS1(v);
        }
    }
}

/// @brief ma tran ke
/// @param u :vertices
void DFS2(int u)
{
    cout << u << " ";
    visited[u] = true;
    // Duyet dong thu u trong ma tran
    for (int v = 1; v <= n; v++)
    {
        if (mtKe[u][v] == 1)
        {
            // kiem tra visited
            if (!visited[v])
            {
                DFS2(v);
            }
        }
    }
}

/// @brief danh sach canh
/// @param u :vertices
void DFS3(int u)
{
    cout << u << " ";
    visited[u] = true;
    // Duyet ds ke cua dinh u: duyet tat ca cac canh trong ds canh
    for (auto it : dsCanh)
    {
        if (it.first == u)
        {
            if (!visited[it.second])
            {
                DFS3(it.second);
            }
        }
        if (it.second == u)
        {
            if (!visited[it.first])
            {
                DFS3(it.first);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

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
        for (int x : dsKe[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    DFS1(1);
    /*
    input:  9 8
            1 2
            1 6
            2 3
            2 4 
            3 5
            6 7
            7 8
            7 9
*/
}