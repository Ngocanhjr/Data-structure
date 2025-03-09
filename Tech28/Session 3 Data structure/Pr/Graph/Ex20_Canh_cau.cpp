#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

int n, m, s ,t;
set<int> adj[1001];
// vector<int> adj[1001];
bool visted[1005];
vector<pair<int, int>> edge;  // Danh sach canh

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge.push_back({x,y});
        adj[x].insert(y);
        adj[y].insert(x);
    }
}
void DFS(int u, int s, int t)
{
    visted[u] = true;
    for (int v : adj[u])
    {
        // Nếu xét phải cạnh muốn loại bỏ thì không xét
        if ((u == s && v == t) || (u == t && v == s))
        {
            continue;
        }
        if (!visted[v])
        {
            DFS(v, s, t);
        }
    }
}

void DFS1(int u)
{
    visted[u] = true;
    for (int v : adj[u])
    {
        if (!visted[v])
        {
            DFS1(v);
        }
    }
}

int tplt()
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visted[i])
        {
            count++;
            DFS1(i);  // BFS(i)
        }
    }
    return count;
}

void canh_cau()
{
    int cc = tplt();
    int count = 0;
    for (auto e : edge)
    {
        int x = e.first, y = e.second;
        adj[x].erase(y);
        adj[y].erase(x);

        memset(visted, false, sizeof(visted));
        if (cc < tplt())
        {
            ++count;
        }
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cout << count;
}

int main()
{
    nhap();
    canh_cau();
}