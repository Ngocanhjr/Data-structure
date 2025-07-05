#include <stdio.h>

#define MAX_SIZE 101

//-------------------Graph------------------------
#define NO_EDGE -1
typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = NO_EDGE;
        }
    }
}

void add_edge(Graph* pG, int u, int v, int w) {
    pG->A[u][v] = w;
    // pG->A[v][u] = w;
    pG->m++;
}

int adj(Graph* pG, int u, int v) {
    return pG->A[u][v] > NO_EDGE;
}

//--------------------------Dijkstra----------------------------
#define NOT_SURE 0
#define SURE 1
#define oo 999999

int parent[MAX_SIZE];
int visited[MAX_SIZE];
int d[MAX_SIZE];  // Luu lai chieu dai duong di tai dinh u

void Dijkstra(Graph* pG, int s, int t) {
    // 1. init
    for (int i = 1; i <= pG->n; i++) {
        d[i] = oo;
        visited[i] = NOT_SURE;
    }

    d[s] = 0;
    parent[s] = -1;

    int u = -1;

    // duyet cac dinh
    for (int i = 1; i <= pG->n; i++) {
        int min_u = oo;
        // 2. tim nho nhat trong cac dinh chua duyet
        for (int v = 1; v <= pG->n; v++) {
            if (visited[v] == NOT_SURE && d[v] < min_u) {
                min_u = d[v];
                u = v;
            }
        }

        if (u == -1) break;
        visited[u] = SURE;

        if (u == t) break;
        // 3. Cap nhap cac dinh ke
        for (int v = 1; v <= pG->n; v++) {
            int w = pG->A[u][v];
            if (adj(pG, u, v) && (d[u] + w < d[v])) {
                d[v] = d[u] + w;
                parent[v] = u;
            }
        }
    }

    // 4. print path
    int path[MAX_SIZE];
    int k = 0;

    int current = u;

    while (current != s) {
        //    	printf("%d ", current);
        path[k] = current;
        k++;
        current = parent[current];
    }

    path[k] = s;

    printf("%d ", path[k]);

    for (int i = k - 1; i >= 0; i--) {
        printf("-> %d ", path[i]);
    }
    //
    //	printf("%d: ", k);
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
    scanf("%d %d", &s, &t);
    Dijkstra(&G, s, t);

    //	for (int u = 1; u <= G.n; u++){
    //        printf("pi[%d] = %d, p[%d] = %d\n", u, d[u], u, parent[u]);
    //    }

    //	if (d[n] < oo)
    //        printf("%d\n", d[n]);
    //    else
    //        printf("-1\n");
}
