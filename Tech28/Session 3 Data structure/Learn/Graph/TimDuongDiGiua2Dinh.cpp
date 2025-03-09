#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;  // vertix and edge

vector<int> adj[1001];

bool visited[1001];

// Chứa thành phần liên thong
int ID[1001];  // chứa x thuộc thành phần liên thông thứ mấy

int cnt = 0;  // sô thứ tự thành phần liên thông

// Truy vết đường đi
int parent[1001];  // parent[u]: đỉnh cha của đỉnh u

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
        ID[x] = cnt;  // x thuộc thành phần liên thông thứ cnt
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

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v);
            parent[v] = u;
        }
    }
}
void ktDuongDi(int n)
{
    // Đếm thành phần liên thông
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])  // chưa thăm -> khác thành phần liên thông, tiếp tục duyệt
        {
            cnt++;
            BFS(i);
        }
    }
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (ID[x] == ID[y])  // cùng thành phần liên thông
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
int main()
{
    read();
    // BFS(1);

    int n;
    cin >> n;
    ktDuongDi(n);  // n là số lần kiểm tra
}