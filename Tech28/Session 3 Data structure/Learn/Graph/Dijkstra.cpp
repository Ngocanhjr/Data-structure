#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct edge
{
    int x, y, w;
};

int n, m;

bool taken[100001];

vector<pair<int, int>> adj[100001];

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});  // đồ thị có hướng
        // adj[y].push_back({x, w});
    }
}

void Dijkstra(int s)
{
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        // Chọn ra đỉnh u có đường đi ngắn nhất => relaxation
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second, kc = top.first;
        if (kc > d[u])
        {
            continue;
        }

        // relaxation
        for (auto it : adj[u])
        {
            int v = it.first, w = it.second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << d[i] << ' '
        }
    }
}

int main() { nhap(); }

/*
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
*/