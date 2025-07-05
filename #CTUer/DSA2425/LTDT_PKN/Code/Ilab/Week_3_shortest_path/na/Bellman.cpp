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

void Bellman_Ford(Graph* pG, int s) {
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
        }
    }

    // Kiem tra chu trinh am
    //  Kiểm tra chu trình âm bằng cách Duyệt qua các cung một lần nữa
    int negative_cycle = 0;
    for (int k = 0; k < pG->m; k++) {
        int u = pG->edges[k].u;
        int v = pG->edges[k].v;
        int w = pG->edges[k].w;
        if ((pi[u] != oo && pi[u] + w < pi[v])) {  // Nếu có đường đi mới đến v tốt hơn
            negative_cycle = 1;                    // Có chu trình âm
            break;
        }
    }

    if (negative_cycle) {
        printf("YES");
    } else {
        printf("NO");
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

    int s;
    scanf("%d", &s);
    Bellman_Ford(&G, s);
}

#if 0
#include <stdio.h>

#define MAX_N 1000
#define oo 999999

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

int pi[MAX_N];
int p[MAX_N];

void Bellman_Ford(Graph* pG, int s) {
    for (int u = 1; u <= pG->n; u++) {
        pi[u] = oo;
    }

    pi[s] = 0;
    p[s] = -1;

    for (int i = 1; i < pG->n; i++) {
        for (int k = 0; k < pG->m; k++) {
            int u = pG->edges[k].u;
            int v = pG->edges[k].v;
            int w = pG->edges[k].w;

            if (pi[u] == oo)
                continue;

            if (pi[u] + w < pi[v]) {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }

    // Kiểm tra chu trình âm xuất phát từ s
    int negative_cycle = 0;
    for (int k = 0; k < pG->m; k++) {
        int u = pG->edges[k].u;
        int v = pG->edges[k].v;
        int w = pG->edges[k].w;

        if (pi[u] != oo && pi[u] + w < pi[v]) {
            negative_cycle = 1;
            break;
        }
    }

    if (negative_cycle) {
        printf("YES\n");
    } else {
        printf("NO\n");
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

    int s;
    scanf("%d", &s);
    Bellman_Ford(&G, s);
}

#endif
