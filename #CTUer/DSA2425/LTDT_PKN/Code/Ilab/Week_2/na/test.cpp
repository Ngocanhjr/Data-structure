#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;  // vertix and edge

vector<int> adj[1001];  // Adjacency list

bool visited[1001];

int parent[1001];  // parent[u] = cha cua dinh u

int ID[1001];

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // sáº¯p xáº¿p danh sÃ¡ch ká» láº¡i
    // for (int i = 1; i <= n; i++) {
    //     sort(adj[i].begin(), adj[i].end());
    // }
}

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS(v);
        }
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // cout << x << " ";
        // ID[x] = cnt;  // x thuá»™c thÃ nh pháº§n liÃªn thÃ´ng thá»© cnt
        for (int y : adj[x]) {
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
                parent[y] = x;
            }
        }
    }
}

int main() {
    read();

    // int s, t;
    // cin >> s >> t;  // Ä‘á»‰nh báº¯t Ä‘áº§u vÃ  Ä‘á»‰nh káº¿t thÃºc

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    // DFS(s);

    for (int i = 1; i <= 4; i++) {
        if (!visited[i]) {
            BFS(i);
        }
    }

    for (int i = 1; i <= 4; i++) {
        cout << i << " " << parent[i] << endl;
    }

#if 0
    if (!visited[t])
    {
        cout << "-1\n";  // khÃ´ng cÃ³ Ä‘Æ°á»ng Ä‘i tá»« s Ä‘áº¿n t
    }
    else
    {
        // Truy váº¿t Ä‘Æ°á»ng Ä‘i
        vector<int> rs;  // LÆ°u Ä‘Æ°á»ng Ä‘i tá»« s Ä‘áº¿n t
        while (t != s)
        {
            rs.push_back(t);
            t = parent[t];
        }

        rs.push_back(s);
        reverse(rs.begin(), rs.end());

        for (int x : rs) cout << x << " ";
    }
#endif
}