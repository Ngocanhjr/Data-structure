// Danh sách cung
#include <stdio.h>
#define MAX_M 500
typedef struct {
    int u, v;
} Edge;
typedef struct {
    int n, m;
    Edge edges[MAX_M];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
}

#if 0
void add_edge(Graph* pG, int u, int v) {
    if (u <= pG->n && v <= pG->n && u > 0 && v > 0) {
        pG->edges[pG->m].u = u;
        pG->edges[pG->m].v = v;
        pG->m++;
    }
}
#endif

#if 0  // đơn đồ thị có hướng

int isExisted(Graph* pG, int u, int v) {
    for (int i = 0; i < pG->m; i++) {
        if (pG->edges[i].u == u && pG->edges[i].v == v) {
            return 1;
        }
    }
    return 0;
}
void add_edge(Graph* pG, int u, int v) {
    if (!isExisted(pG, u, v)) {
        if (u <= pG->n && v <= pG->n && u > 0 && v > 0) {
            pG->edges[pG->m].u = u;
            pG->edges[pG->m].v = v;
            pG->m++;
        }
    }
}
#endif

#if 1  // đơn đồ thị vô hướng
void add_edge(Graph* pG, int u, int v) {
    for (int i = 0; i < pG->m; i++) {
        if ((pG->edges[i].u == u && pG->edges[i].v == v) ||
            (pG->edges[i].u == v && pG->edges[i].v == u)) {
            return;
        }
    }

    if (u <= pG->n && v <= pG->n && u > 0 && v > 0) {
        pG->edges[pG->m].u = u;
        pG->edges[pG->m].v = v;
        pG->m++;
    }
}
#endif

int main() {
    Graph G;
    init_graph(&G, 5);
    add_edge(&G, 1, 3);
    add_edge(&G, 2, 3);
    add_edge(&G, 1, 3);
    add_edge(&G, 3, 1);
    add_edge(&G, 1, 3);

    printf("n = %d, m = %d\n", G.n, G.m);
    for (int i = 0; i < G.m; i++) {
        printf("%d %d\n", G.edges[i].u, G.edges[i].v);
    }

    return 0;
}