#include <bits/stdc++.h>

#include <vector>

using namespace std;

struct edge
{
    int x, y, w;
};

int n, m;

int sz[100001], parent[100001];
vector<edge> adj;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        sz[i] = 1;
        parent[i] = i;  // cho parent của i bằng chính nó
    }
}

int Find(int u)
{
    if (u == parent[u])
    {  // Đại diện cho chính nó
        return u;
    }
    else
    {
        return parent[u] = Find(parent[u]);
    }
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    // U và v cùng một tập hợp
    if (u == v)
    {
        return false;
    }

    if (sz[u] > sz[v])
    {
        parent[v] = u;
        sz[u] += sz[v];
    }
    else
    {
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;  // có thể gộp lại
}

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edge e{x, y, w};
        adj.push_back(e);
    }
}

void Kruskal()
{
    // Buoc 1: sắp xếp các cạnh theo trọng số tăng dần
    sort(adj.begin(), adj.end(), [](edge a, edge b) -> bool { return a.w < b.w; });  // sắp xếp tăng dần

    // Bước 2: lặp
    int d = 0;  // lưu lại trọng số
    vector<edge> MST;
    for (int i = 0; i < m; i++)
    {
        if (MST.size() == n - 1) break;  // cây khung đã đủ n - 1 cạnh
        edge e = adj[i];
        // Kiểm tra cạnh e thêm vào có tạo thành chu trình không
        if (Union(e.x, e.y))
        {
            MST.push_back(e);
            d += e.w;
        }
    }

    cout << d << endl;

    for (auto it : MST)
    {
        cout << it.x << " " << it.y << ' ' << it.w << endl;
    }
}
int main()
{
    nhap();
    init();
    Kruskal();
}
/*
6 9
1 2 1
1 3 2
3 2 3
2 4 4
2 5 7
3 5 5
4 5 3
4 6 2
5 6 2
output: 
11
1 2 1
1 3 2
4 6 2
5 6 2
2 4 4
*/