// Danh sách cung
#include <stdio.h>

#define MAX_N 1000

typedef struct {
    int u, v;
    int w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_N];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph* pG, int u, int v, int w) {
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->edges[pG->m].w = w;
    pG->m++;
}

//---------------Bellman----------------
#define oo 999999

int pi[MAX_N];
int p[MAX_N];

void Bellman_Ford(Graph* pG, int s, int t) {
    for (int u = 1; u <= pG->n; u++) {
        pi[u] = oo;
    }

    pi[s] = 0;
    p[s] = -1;

    for (int i = 1; i < pG->n; i++) {
        // Duyet qua tat cac cung va cap nhat neu thoi man
        for (int k = 0; k < pG->m; k++) {
            int u, v, w;
            u = pG->edges[k].u;
            v = pG->edges[k].v;
            w = pG->edges[k].w;
            if (pi[u] == oo)  // chua co duong di den u
                continue;

            if (pi[u] + w < pi[v]) {
                pi[v] = pi[u] + w;
                p[v] = u;
            }

            // if (v == t) return;
        }
    }

    // 4. in duong di
    int k = 0;
    int path[MAX_N];

    int current = t;

    while (current != p[s]) {
        path[k] = current;
        current = p[current];
        k++;
    }

    printf("%d ", path[k - 1]);

    for (int i = k - 2; i >= 0; i--) {
        printf("-> %d ", path[i]);
    }
}

int main() {
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);

    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    int s, t;
    scanf("%d  %d", &s, &t);
    Bellman_Ford(&G, s, t);

}