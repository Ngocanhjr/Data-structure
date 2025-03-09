#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1001];
int color[1001];

bool DFS(int u)
{
    color[u] = 1;
    for (int v : adj[u])
    {
        if (color[v] == 0)
        {
            if (DFS(v)) return true;
        }
        else if (color[v] == 1)
        {
            return true;
        }
    }
    color[u] = 2;
    return false;
}

// Thuat toan kahn
int degree[1005];
bool kahn()
{
    for (int i = 1; i <= n; i++)
    {
        for (int x : adj[i])
        {
            degree[x]++;  // ban bac vao
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ++cnt;
        for (int v : adj[u])
        {
            --degree[v];
            if (degree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    if (cnt != n)
        return true;
    else
        return false;
}
int main() {}