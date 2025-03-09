#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
vector<pair<int, int>> edge;

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge.push_back({x, y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void DFS(int u, int s, int t)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if ((u == s && v == t) || (u == t && v == s))  // u, v giong voi canh can bo
        {
            continue;
        } 
        if (!visited[v])
        {
            DFS(v, s, t);
        }
    }
}

int tplt(int s, int t)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ++ans;
            DFS(i, s, t);
        }
    }
    return ans;
}

void canh_cau()
{
    // Dem thanh phan lien thong ban dau
    int cc = tplt(0, 0);
    int cnt = 0;  // so canh cau
    for (auto it : edge)
    {
        int x = it.first, y = it.second;

        memset(visited, false, sizeof(visited));
        if (cc < tplt(x, y))
        {
            ++cnt;
        }
    }

    cout << cnt;
}

int main()
{
    nhap();
    canh_cau();
}