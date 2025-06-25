#include <stdio.h>

#define MAX_SIZE 100

//--------------------Graph------------
#define NO_EDGE -1  // Vi la ma tran trong so
typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

int init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = NO_EDGE;
        }
    }
}

void add_edge(Graph* pG, int u, int v, int w) {
    pG->A[u][v] = w;
    pG->A[v][u] = w;
    pG->m++;
}

int adj(Graph* pG, int u, int v) {
    return pG->A[u][v] > NO_EDGE;
}

//--------------------------Moore Dijkstra-----------------------
#define oo 999999
#define NOT_SURE 0
#define SURE 1
int parent[MAX_SIZE];
int visited[MAX_SIZE];
int d[MAX_SIZE];  // Store length of path

void Moore_Dijkstra(Graph* pG, int s) {
    for (int i = 0; i <= n; i++) {
        d[i] = oo;
        visited[i] = NOT_SURE;
    }

    parent[s] = -1;
    d[s] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        int min_u = oo;
        for (int v = 1; v <= pG->n; v++) {
            if (visited[v] == NOT_SURE && d[v] < min_u) {
                min_u = d[v];
                u = v;
            }
        }
    }

    if (u == -1)  // Không tìm được u
        break;

    visited[u] = SURE;

    for (int v = 1; v <= pG->n; v++) {
        int w = pG->W[u][v];
        if (adj(pG, u, v) && d[u] + w < d[v]) {
            d[v] = d[u] + w;
            parent[v] = u;
        }
    }
}

int main() {
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    MooreDijkstra(&G, 1);
    if (pi[n] < oo)
        printf("%d\n", pi[n]);
    else
        printf("-1\n");
}
