#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m, s, t;
set<int> adj[1001];
// vector<int> adj[1001];
bool visted[1005];
vector<pair<int, int> > edge;

void nhap()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
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

int tplt()
{
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (!visted[i])
        {
            count++;
            DFS(i);  // BFS(i)
        }
    }
    return count;
}

void canh_cau()
{
    int cc = tplt();
    for (pair<int, int> e : edge)
    {
        int s = e.first, t = e.second;
        memset(visted, false, sizeof(visted));
        if (cc < tptl())
        {
            cout << s << " " << t << endl;
        }
    }
}