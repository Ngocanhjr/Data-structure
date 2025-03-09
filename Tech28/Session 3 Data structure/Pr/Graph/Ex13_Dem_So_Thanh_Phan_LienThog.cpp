#include <iostream>
#include <vector>

using namespace std;

vector<int> dsKe[1005];

/// @brief n : vertices, m: edge
int n, m;

bool visited[1005];

void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;

    for (int v : dsKe[u])
    {
        if (!visited[v])
        {
            DFS(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        dsKe[x].push_back(y);
        dsKe[y].push_back(x);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout<< endl;

            DFS(i);
            ++cnt;
        }
    }
    cout << "\nSo thanh phan lien thong: ";
    cout << cnt << endl;
}