#include <stdio.h>

#define MAX 500
typedef struct {
    int u, v;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->m = 0;
    pG->n = n;
}
// đơn đồ thị có hướng
void add_edge(Graph* pG, int u, int v) {
    // if (u < 1 || u > pG->n || v < 1 || v > pG->n) {
    //     return;
    // }

    // for (int i = 0; i < pG->m; i++) {
    //     if (pG->edges[i].u == u && pG->edges[i].v == v) return;
    // }
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

// đơn đồ thị vô hướng không khuyen
void add_edge(Graph* pG, int u, int v) {
    // kiem tra dieu kien
    if (u < 1 || u > pG->n || v < 1 || v > pG->n || u == v) {
        return;
    }

    // kiem tra cung đã tồn tại chưa
    for (int i = 0; i < pG->m; i++) {
        if ((pG->edges[i].u == u && pG->edges[i].v == v) ||
            (pG->edges[i].u == v && pG->edges[i].v == u))
            return;  // đơn đồ thị có hướng
    }

    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;

    pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
    for (int i = 0; i < pG->m; i++) {
        if ((pG->edges[i].u == u && pG->edges[i].v == v) ||
            (pG->edges[i].u == v && pG->edges[i].v == u))
            return 1;  // đơn đồ thị có hướng
    }
    return 0;
}

int degree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 0; i < pG->m; i++) {
        if (pG->edges[i].u == u) deg_u++;
        if (pG->edges[i].v == u) deg_u++;
    }
    return deg_u;
}

int main() {
    Graph G;

    init_graph(&G, 5);

    add_edge(&G, 1, 1);
    add_edge(&G, 1, 3);
    add_edge(&G, 5, 2);
    add_edge(&G, 2, 4);
    add_edge(&G, 3, 3);
    add_edge(&G, 5, 4);
    add_edge(&G, 3, 3);
    add_edge(&G, 3, 3);

    printf("Do thi co %d dinh va %d cung. ", G.n, G.m);

}