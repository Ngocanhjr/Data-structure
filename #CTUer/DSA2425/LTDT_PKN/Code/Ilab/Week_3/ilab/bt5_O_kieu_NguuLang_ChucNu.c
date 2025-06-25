#include <stdio.h>

#define MAX_SIZE 101

//----------------------Graph---------------------
#define NO_EDGE -1

typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void init_graph(Graph* pG, int n) {
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

//---------------Moore Dijkstra--------------------
#define SURE 1
#define oo 999999

int visited[MAX_SIZE];
int pi[MAX_SIZE];

void Dijkstra(Graph* pG, int s) {
    for (int i = 0; i <= pG->n; i++) {
        pi[i] = oo;
        visited[i] = 0;
    }

    pi[s] = 0;

    for (int i = 1; i <= pG->n; i++) {
        int u = -1, min_u = oo;
        for (int v = 1; v <= pG->n; v++) {
            if (!visited[v] && pi[v] < min_u) {
                min_u = pi[v];
                u = v;
            }
        }

        if (u == -1) break;

        visited[u] = SURE;

        for (int v = 1; v <= pG->n; v++) {
            if (adj(pG, u, v) && (pi[u] + pG->A[u][v] < pi[v])) {
                pi[v] = pi[u] + pG->A[u][v];
            }
        }
    }
}

int main() {
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);

    init_graph(&G, n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    Dijkstra(&G, 1);

    printf("%d", pi[n]);
}