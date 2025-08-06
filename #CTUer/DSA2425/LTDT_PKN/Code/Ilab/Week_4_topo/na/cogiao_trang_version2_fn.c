#include <stdio.h>

#define MAX_SIZE 101

//-----------------Graph-------------------
typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

void add_edge(Graph* pG, int u, int v) {
    if (pG->A[u][v] == 0) {
        pG->m++;
        pG->A[u][v] = 1;
    }
}

int rev_adj(Graph* pG, int u, int v) {
    return pG->A[u][v] > 0;
}

//-------------------rank----------- (u -> v)
int visited[MAX_SIZE];
int rank[MAX_SIZE];  // Luu lai xep hang cua cac dinh

int max(int a, int b) {
    return a > b ? a : b;
}

void rank_topo(Graph* pG, int u) {
    // duỵet dfs
    visited[u] = 1;
    int m = 0;

    for (int v = 1; v <= pG->n; v++) {
        if (rev_adj(pG, u, v)) {
            if (!visited[v]) {
                rank_topo(pG, v);
            }
            m = max(m, rank[v] + 1);
        }
    }
    rank[u] = m;
}

int main() {
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    // khoi tao
    for (int i = 1; i <= G.n; i++) {
        visited[i] = 0;
        rank[i] = 0;
    }

    // duyet topo
    for (int i = 1; i <= G.n; i++) {
        if (!visited[i]) rank_topo(&G, i);
    }

    // in
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        printf("%d\n", rank[i] + 1);  // vì ban đầu bé nào cũng có ít nhất 1 viên
        sum += rank[i] + 1;
    }
    printf("%d\n", sum);
}