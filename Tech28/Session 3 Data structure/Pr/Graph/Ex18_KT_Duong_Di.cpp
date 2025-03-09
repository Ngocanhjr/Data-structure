#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;  // vertix and edge

vector<int> adj[1001];

bool visited[1001];

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
        for (int y : adj[x])
        {
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main()
{
    read();
    // BFS(1);

    int n;
    cin >> n;

    while (n--)
    {
        int x, y;
        cin >> x >> y;
        memset(visited, false, sizeof(visited));
        BFS(x);
        if (visited[y])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}