#include <stdio.h>

#define MAX 100

typedef struct {
    int n, m;
    int A[MAX][MAX];
} Graph;

void init_graph(Graph* pG, int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
    pG->n = n;
    pG->m = 0;
}

// /đơn đồ thị vô hướng
void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

// đồ thị vô hướng (có thể chứa đa cung và chứa khuyên)
void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v]++;
    if (u != v) {
        pG->A[v][u]++;
    }
    pG->m++;
}

// đồ thị có hướng (có thể chứa đa cung và chứa khuyên)
void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v]++;
    // if (u != v) {
    //     pG->A[v][u]++;
    // }
    pG->m++;
}
int main() {
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    // In ma trận kề của đồ thị
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++) printf("%d \n", G.A[u][v]);
        printf("\n");
    }
}