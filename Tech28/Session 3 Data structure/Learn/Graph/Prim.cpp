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
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void Prim(int s)
{
    memset(taken, 0, sizeof(taken));  // Đặt tất cả giá trị của taken về false
    taken[s] = true;
    riority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
    for (auto it : adj[s])
    {
        int t = it.first;
        if (!taken[t])
        {
            Q.push({it.second, t});
        }
    }

    long long d = 0, cnt = 0;
    while (!Q.empty())
    {
        // lấy ra cạnh ngắn nhất
        pair<int, int> e = Q.top();
        Q.pop();
        int u = e.second, w = e.first;
        if (!taken[u])  // QUAN TRỌNG
        {
            d += w;
            ++cnt;
            taken[u] = true;
            for (auto it : adj[u])
            {
                  if (!taken[it.first])
                {
                    Q.push({it.second, it.first});
                }
            }
        }
    }

    if (cnt == n - 1)
    {
        cout << d << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int main()
{
    nhap();
    Prim(1);
}

/*
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
*/