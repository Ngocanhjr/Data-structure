// /đồ thị vô hướng

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

// đơn đồ thị có hướng
void add_edge(Graph *pG, int u, int v) {
    for (int i = 0; i < pG->m; i++)
        if (pG->edges[i].u == u && pG->edges[i].v == v)
            return;
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

int adj (Graph* pG, int u, int v){
    for(int i = 0; i < pG->m; i++){
        if(pG->edges[i].u == u && pG->edges[i].v == v)
            return 1;
    }
    return 0;
}

void neighbours(Graph* pG, int u) {
    printf("neighbours(%d) = ", u);

    for(int v = 1; v <= pG->n; v++){
        
        if(adj(pG,u,v) != 0){
           printf("%d ", v);
       }
    }
    
        // if(pG->edges[i].u == u){
        //     printf("%d ", pG->edges[i].v);
        // }
    
    printf("\n");
}

int main() {
    Graph G;
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
}