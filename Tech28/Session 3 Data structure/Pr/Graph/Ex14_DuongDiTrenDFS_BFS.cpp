#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, m;  // vertix and edge

vector<int> adj[1001];  // Adjacency list

bool visited[1001];

int parent[1001];  // parent[u] = cha cua dinh u

void read()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // sắp xếp danh sách kề lại
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            DFS(v);
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        // cout << x << " ";
        ID[x] = cnt;  // x thuộc thành phần liên thông thứ cnt
        for (int y : adj[x])
        {
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
                parent[y] = x;
            }
        }
    }
}

int main()
{
    read();

    int s, t;
    cin >> s >> t;  // đỉnh bắt đầu và đỉnh kết thúc

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    DFS(s);

    if (!visited[t])
    {
        cout << "-1\n";  // không có đường đi từ s đến t
    }
    else
    {
        // Truy vết đường đi
        vector<int> rs;  // Lưu đường đi từ s đến t
        while (t != s)
        {
            rs.push_back(t);
            t = parent[t];
        }

        rs.push_back(s);
        reverse(rs.begin(), rs.end());

        for (int x : rs) cout << x << " ";
    }
}
