#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

//------------------------Graph---------------------
typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_SIZE];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->m = 0;
    pG->n = n;
}

void add_edge(Graph* pG, int u, int v, int w) {
    if (u > v) {
        int temp = u;
        u = v;
        v = temp;
    }
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->edges[pG->m].w = w;
    pG->m++;
}

//-----------------------------Kruskal-----------------------
int parent[MAX_SIZE];

// find root using recursive
int findRoot(int u) {
    if (parent[u] == u) {
        return u;
    }
    return findRoot(parent[u]);
}
int find_root(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

// sort using for loop
void swap_edge(Edge* e1, Edge* e2) {
    Edge temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

void sort(Graph* pG) {
    for (int i = 0; i < pG->m - 1; i++) {
        for (int j = i + 1; j < pG->m; j++) {
            if (pG->edges[j].w < pG->edges[i].w) {
                swap_edge(&pG->edges[j], &pG->edges[i]);
            } else if (pG->edges[j].w == pG->edges[i].w) {
                if (pG->edges[j].u < pG->edges[i].u) {
                    swap_edge(&pG->edges[j], &pG->edges[i]);
                } else if (pG->edges[j].w == pG->edges[i].w && pG->edges[j].u == pG->edges[i].u) {
                    if (pG->edges[j].v < pG->edges[i].v) {
                        swap_edge(&pG->edges[j], &pG->edges[i]);
                    }
                }
            }
        }
    }
}

// sort using qsort
int cmp_edge(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;

    if (e1->w != e2->w) return e1->w - e2->w;  // Ưu tiên trọng số nhỏ
    if (e1->u != e2->u) return e1->u - e2->u;  // Sau đó theo u
    return e1->v - e2->v;                      // Cuối cùng theo v
}

int Kruskal(Graph* pG, Graph* pR) {
    // 1. sort w order by asc
    // sort(pG); // for loop
    qsort(pG->edges, pG->m, sizeof(Edge), cmp_edge); //function quicksort

    // // test sort
    // for (int i = 0; i < pG->m; i++) {
    //     printf("%d %d %d\n", pG->edges[i].u, pG->edges[i].v, pG->edges[i].w);
    // }

    // 2. Init pR and mange BPLT
    init_graph(pR, pG->n);
    for (int u = 1; u <= pG->n; u++) {
        parent[u] = u;  // each vertex is connected parts
    }

    int total_weight = 0;  // total minimum weight of spanning tree

    // 3. traverse spanning trees G (orderly)
    for (int i = 0; i < pG->m; i++) {
        int u = pG->edges[i].u;
        int v = pG->edges[i].v;
        int w = pG->edges[i].w;
        int root_u = find_root(u);    // find root u -> connected parts of u
        int root_v = find_root(v);    // find root u -> connected parts of v
        if (root_u != root_v) {       // u and v is diff connected parts
            add_edge(pR, u, v, w);    // add edge into pR
            parent[root_v] = root_u;  // merge 2 connected parts
            total_weight += w;
            // test
            //  printf("%d %d %d\n", pR->edges[i].u, pR->edges[i].v, pR->edges[i].w);
        }
    }

    return total_weight;
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

    Graph R;

    printf("%d\n", Kruskal(&G, &R));
    for (int i = 0; i < R.m; i++) {
        printf("%d %d %d\n", R.edges[i].u, R.edges[i].v, R.edges[i].w);
    }
}