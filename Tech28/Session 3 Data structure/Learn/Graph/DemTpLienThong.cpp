#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;  // vertix and edge

vector<int> adj[1001];

bool visited[1001];

void DFS1(int u);

void BFS(int u);

void read();

int cntTpLienThong();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read();
    BFS(1);
}

void read()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

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

void BFS(int u)
{
    // Step 1: init
    queue<int> q;       // create empty queue
    q.push(u);          // push u into queue
    visited[u] = true;  // marked u is visted

    // Step 2: loop when queue not empty
    while (!q.empty())
    {
        int x = q.front();  // Take out the vertex at the beginning of the queue
        q.pop();            // Erase vertex from queue
        // Visted vertex v
        cout << x << " ";

        // Browse vertices adjacent to v that have not been visited and push them in the queue
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

int cntTpLienThong()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS1(i);  // BFS(i)
        }
    }
    return cnt;
}

