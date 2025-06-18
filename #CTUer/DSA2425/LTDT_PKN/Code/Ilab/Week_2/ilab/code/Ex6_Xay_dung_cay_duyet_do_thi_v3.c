#include <stdio.h>

#define MAX_SIZE 100
typedef int ElementType;

//--------------------Graph------------------------
typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

// init graph with n vertix
void init_graph(Graph* pG, ElementType n) {
    pG->n = n;
    pG->m = 0;

    // cho toan bo ma tran ke bang 0
    for (int i = 0; i <= pG->n; i++) {
        for (int j = 0; j <= pG->n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

// add edge (u,v) to graph
void add_edge(Graph* pG, ElementType u, ElementType v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

//--------------------DFS------------------------
int visited[MAX_SIZE];
int parent[MAX_SIZE];

void DFS(Graph* pG, int s, int p) {
    visited[s] = 1;
    // 	printf("%d \n", s);
    parent[s] = p;
    for (int u = 1; u <= pG->n; u++) {
        if (!visited[u] && pG->A[s][u] != 0) {
            DFS(pG, u, s);
        }
    }
}

int main() {
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 0; i <= G.n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    for (int i = 1; i <= G.n; i++) {
        if (!visited[i]) {
            DFS(&G, i, -1);
        }
    }

    for (int i = 1; i <= G.n; i++) {
        printf("%d %d\n", i, parent[i]);
    }
}