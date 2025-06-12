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

void add_edge(Graph* pG, int u, int v) {
    if (u <= pG->n && v <= pG->n && u > 0 && v > 0) {
        pG->edges[pG->m].u = u;
        pG->edges[pG->m].v = v;
        pG->m++;
    }
}

int degree(Graph* pG, int u) {
    int deg = 0;
    for (int i = 0; i < pG->m; i++) {
        Edge edge = pG->edges[i];
        if (edge.u == u && edge.v == u) {  // kiểm tra khuyên
            deg += 2;
        } else if (edge.u == u || edge.v == u) {
            deg++;
        }
    }
    return deg;
}
