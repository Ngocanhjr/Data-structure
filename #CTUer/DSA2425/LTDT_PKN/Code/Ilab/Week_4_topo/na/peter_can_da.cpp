#include <stdio.h>

#define MAXN 1005

typedef struct {
    int n;
    int A[MAXN][MAXN];
} Graph;

int visited[MAXN];
int rank[MAXN];

// Kiểm tra có cạnh v → u không
int rev_adj(Graph* pG, int u, int v) {
    return pG->A[v][u];  // ngược chiều
}

void rank_topo(Graph* pG, int u) {
    visited[u] = 1;
    int m = 0;
    for (int v = 1; v <= pG->n; v++) {
        if (rev_adj(pG, u, v)) {
            if (!visited[v]) {
                rank_topo(pG, v);
            }
            if (rank[v] + 1 > m) m = rank[v] + 1;
        }
    }
    rank[u] = m;
}

int main() {
    Graph G;
    int m;
    scanf("%d%d", &G.n, &m);

    // Khởi tạo
    for (int i = 1; i <= G.n; i++)
        for (int j = 1; j <= G.n; j++) G.A[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G.A[u][v] = 1;  // u nhẹ hơn v → cạnh u → v
    }

    // Tính rank bằng DFS
    for (int u = 1; u <= G.n; u++) {
        if (!visited[u]) rank_topo(&G, u);
    }

    // Sắp xếp theo rank tăng dần
    int order[MAXN];
    for (int i = 1; i <= G.n; i++) order[i] = i;

    for (int i = 1; i < G.n; i++) {
        for (int j = i + 1; j <= G.n; j++) {
            if (rank[order[i]] > rank[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    // In kết quả
    for (int i = 1; i <= G.n; i++) {
        printf("%d\n", order[i]);
    }

    return 0;
}
