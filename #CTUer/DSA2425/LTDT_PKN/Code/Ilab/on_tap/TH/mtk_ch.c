#include <stdio.h>

#define MAX 100

typedef struct {
    int n, m;
    int A[MAX][MAX];
} Graph;

void init_graph(Graph* pG, int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
    pG->n = n;
    pG->m = 0;
}

// đồ thị vô hướng (có thể chứa đa cung và chứa khuyên)
void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v]++;
    pG->m++;
}

//đồ thị vô hướng (có thể chứa đa cung và chứa khuyên).
int degree(Graph *pG, int u) {
    int deg_in = 0, deg_out = 0;
    for(int i = 1; i <= pG->n; i++){
            deg_out += pG->A[u][i] ;
    }
   
    for(int i = 1; i <= pG->n; i++){
            deg_in += pG->A[i][u] ;
    }
   
    return deg_in + deg_out;
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

    // In ma trận kề của đồ thị
    printf("Ma tran ke:\n");
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++) printf("%d ", G.A[u][v]);
        printf("\n");
    }

    // In bậc
    for (int i = 1; i <= n; i++) {
        printf("deg(%d) = %d\n", i, degree(&G, i));
    }
}