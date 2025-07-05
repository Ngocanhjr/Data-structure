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
int cnt_edge;
int visited[MAX_SIZE];
void DFS(Graph* pG, int s) {
    cnt_edge++;
    visited[s] = 1;
    // printf("%d \n", s);
    for (int u = 1; u <= pG->n; u++) {
        if (pG->A[s][u] > 0 && !visited[u]) {
            DFS(pG, u);
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
    }

    cnt_edge = 0;
    int s;
    scanf("%d", &s);
    DFS(&G, s);

    // for (int i = 1; i <= G.n; i++) {
    //     if (!visited[i]) {
    //         cnt++;
    //         DFS(&G, i);
    //     }
    // }
    printf("%d", cnt_edge);
}
