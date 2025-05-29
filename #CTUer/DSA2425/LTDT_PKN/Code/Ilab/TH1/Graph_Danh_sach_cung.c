#include <stdio.h>

#define MAX_M 500

typedef struct {
    int u, v;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_M];
} Graph;

// Ham init_graph(Graph *pG, int n)
void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
}

/// @brief thêm vào đồ thị, không kiểm tra điều kiện
/// @param pG
/// @param u
/// @param v
void add_edge_cb(Graph* pG, int u, int v) {
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    // printf("%d %d\n", pG->edges[pG->m].u, pG->edges[pG->m].v);
    pG->m++;
}

// Thêm vào đồ thị có kiểm tra điều kiện
void add_edge_nc(Graph* pG, int u, int v) {
    if (u < 1 || v < 1 || u > pG->n || v > pG->n) return;
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    // printf("%d %d\n", pG->edges[pG->m].u, pG->edges[pG->m].v);
    pG->m++;
}

/// @brief Vì pG là "đơn đồ thị" có hướng nên nếu cung (u, v) đã có trong đồ thị rồi thì bỏ qua,
/// không thêm vào nữa. Thêm vào đơn đồ thị có hướng
/// @param pG
/// @param u
/// @param v

int exist1(Graph* pG, int u, int v) {
    for (int i = 0; i < pG->m; i++) {
        if (pG->edges[i].u == u && pG->edges[i].v == v) return 1;
    }
    return 0;
}

void add_edge_don_co_huong(Graph* pG, int u, int v) {
    if (u < 1 || v < 1 || u > pG->n || v > pG->n) return;
    if (exist1(pG, u, v)) return;
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    // printf("%d %d\n", pG->edges[pG->m].u, pG->edges[pG->m].v);
    pG->m++;
}

// Thêm vào đơn đồ thị vô hướng
int exist2(Graph* pG, int u, int v) {
    for (int i = 0; i < pG->m; i++) {
        if ((pG->edges[i].u == u && pG->edges[i].v == v) ||
            (pG->edges[i].u == v && pG->edges[i].v == u))
            return 1;
    }
    return 0;
}

void add_edge_don_vo_huong(Graph* pG, int u, int v) {
    if (u < 1 || v < 1 || u > pG->n || v > pG->n) return;
    if (exist2(pG, u, v)) return;
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    // printf("%d %d\n", pG->edges[pG->m].u, pG->edges[pG->m].v);
    pG->m++;
}

/// @brief Trong đồ thị vô hướng G, u kề với v khi G có cung (u, v) hoặc cung (v, u)
/// @param pG
/// @param u
/// @param v
/// @return Trả về 1, nếu u kề với v, ngược lại trả về 0.
int adjacent_vo_huong(Graph* pG, int u, int v) {
    for (int i = 0; i < pG->m; i++) {
        Edge edge = pG->edges[i];
        if ((edge.u == u && edge.v == v) || (edge.u == v && edge.v == u)) return 1;
    }
    return 0;
}

int adjacent_co_huong(Graph* pG, int u, int v) {
    for (int i = 0; i < pG->m; i++) {
        Edge edge = pG->edges[i];
        if (edge.u == u && edge.v == v) return 1;
    }
    return 0;
}

int main() {
    Graph G;
#if 0
    init_graph(&G, 5);
    printf("Do thi co %d dinh va %d cung.", G.n, G.m);
#endif
#if 1
    init_graph(&G, 5);
    add_edge(&G, 1, 1);
    add_edge(&G, 1, 3);
    add_edge(&G, 5, 2);
    add_edge(&G, 5, 2);
    add_edge(&G, 2, 4);
    add_edge(&G, 3, 6);
    add_edge(&G, 5, 4);
    add_edge(&G, 3, 3);
    add_edge(&G, 3, 9);
    printf("n = %d, m = %d\n", G.n, G.m);
    for (int i = 0; i < G.m; i++) {
        printf("%d %d\n", G.edges[i].u, G.edges[i].v);
    }
#endif
    return 0;
}
