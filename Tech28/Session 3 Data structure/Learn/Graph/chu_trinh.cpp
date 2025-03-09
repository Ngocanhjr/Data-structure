// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int n, m, ok;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
}
// Vo huong
bool DFS(int u)
{
    visited[u];
    for (int v : adj[u])
    {
        if (!visited(v))
        {
            parent[v] = u;
            // DFS(v); ok
            if (DFS(v)) return true;
            // return DFS(v); laf sai
        }
        else if (v != parent[u])
        {
            return true;
            // ok = 1;
        }
    }
    return false;
}

bool BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : adj[x])
        {
            if (!visited[y])
            {
                q.push(y);
                parent[y] = x;
                visited[y] = true;
            }
            else if (y != parent[x])
            {
                return true;
            }
        }
    }
    return false;
}

//Co huong

int main() {}