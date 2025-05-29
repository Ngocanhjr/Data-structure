#if 1
#include <stdio.h>

#define MAX_N 100

typedef struct {
    int u, v, w;  // đỉnh đầu , đỉnh cuối, trọng số
} Edge;

typedef struct {
    int n, m;           // vertix, edge
    Edge edges[MAX_N];  // Danh sach cung
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
}

// đa đồ thị vô hướng
void add_edge(Graph* pG, int u, int v) {
    // for (int i = 0; i < pG->m; i++) {
    //     if (pG->edges[i].u == u && pG->edges[i].v == v) return;
    // }
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
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

int main() {
    Graph G;
    freopen("dt.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 1; i <= n; i++) {
        printf("deg(%d) = %d\n", i, degree(&G, i));
    }
}
#endif

#if 0
#include <stdio.h>

#define MAX_N 100

typedef struct {
    int u, v, w;  // đỉnh đầu , đỉnh cuối, trọng số
} Edge;

typedef struct {
    int n, m;           // vertix, edge
    Edge edges[MAX_N];  // Danh sach cung
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
}

// đa đồ thị vô hướng
void add_edge(Graph* pG, int u, int v) {
    // for (int i = 0; i < pG->m; i++) {
    //     if (pG->edges[i].u == u && pG->edges[i].v == v) return;
    // }
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
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

/// @brief In ra n dòng, dòng thứ i in các đỉnh kề của đỉnh i,
/// cách nhau 1 khoảng trắng, theo thứ tự tăng dần (không lặp lại)
/// @param u
void neighbours(Graph* pG, int u) {
    printf("neighbours(%d) =", u);

    for (int i = 0; i < pG->m; i++) {
        Edge edge = pG->edges[i];   // lấy cạnh ra
        if (edge.u == u)            // có dạng (u,v)
            printf(" %d", edge.v);  // liệt kê v
        else if (edge.v == u)
            printf(" %d", edge.u);
    }
    printf("\n");
}

int main() {
    Graph G;
#if 0
    // chuyển hướng nhập sang file
    // freopen("dt.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    // In bậc của các đỉnh
    for (int u = 1; u <= n; u++) printf("deg(%d) = %d\n", u, degree(&G, u));
    return 0;

#endif

#if 1
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 1; i <= n; i++) {
        neighbours(&G, i);
    }

#endif
}

#endif