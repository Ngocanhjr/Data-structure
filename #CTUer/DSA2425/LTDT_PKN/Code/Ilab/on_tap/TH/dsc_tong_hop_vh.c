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

void neighbour(Graph *pG, int u){
    printf("neighbours(%d) =", u);
    for(int i = 1; i <= pG->n; i++){
        if(adjacent(pG, i , u)){
            printf(" %d", i);
        }
    }
    printf("\n");
}

int main() {
    Graph G;
    int n, m;
    // freopen("dt.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 1; i <= n; i++) {
        // printf("deg(%d) = %d\n", i, degree(&G, i));
        neighbour(&G, i);
    }

}