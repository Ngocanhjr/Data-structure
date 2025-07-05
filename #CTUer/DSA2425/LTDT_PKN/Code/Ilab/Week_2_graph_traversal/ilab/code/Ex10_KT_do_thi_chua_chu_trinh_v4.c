#include <stdio.h>

#define MAX_SIZE 100
typedef int ElementType;

//----------------Graph------------------
typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v]++;
    if (u != v) pG->A[v][u]++;

    pG->m++;
}

int adj(Graph* pG, int u, int v) {
    return pG->A[u][v] > 0;
}
//-------------------------------Cycle------------------
#define NO_COLOR 0
#define GRAY 1
#define BLACK 2

int color[MAX_SIZE];
int has_cycle;
int parent[MAX_SIZE];

int start, end;

void cycle(Graph* pG, int u, int p) {
    color[u] = GRAY;

    for (int v = 1; v <= pG->n; v++) {
        if (adj(pG, u, v)) {
            if(p==v) continue;
            if (color[v] == NO_COLOR) {
                parent[v] = u;
                cycle(pG, v, u);
                if (has_cycle) return;
            } else if (color[v] == GRAY) {
                has_cycle = 1;
                start = v;
                end = u;
                return;
            }
        }
    }
    color[u] = BLACK;
}

void print_path() {
    int path[MAX_SIZE];
    int count = 0;

    path[count++] = start;
    int u = end;
    while (u != start) {
        path[count++] = u;
        u = parent[u];
    }
    path[count++] = start;

    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph G;
    init_graph(&G, n);

    // Read graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = NO_COLOR;
        parent[i] = -1;
    }

    for (int i = 1; i <= G.n; i++) {
        if (color[i] == NO_COLOR) {
            start = i;
            cycle(&G, i, -1);
            if (has_cycle) break;
        }
    }

    if (has_cycle) {
        print_path();
    } else {
        printf("-1");
    }
    // for (int i = 1; i <= G.n; i++) {
    //     printf("%d: %d\n", i, parent[i]);
    // }
}
