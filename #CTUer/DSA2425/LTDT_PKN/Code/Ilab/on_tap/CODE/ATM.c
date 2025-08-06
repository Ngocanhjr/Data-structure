#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

//----------Graph--------------------
typedef struct {
    int A[MAX_SIZE][MAX_SIZE];
    int m, n;
} Graph;

// Khởi tạo đồ thị
void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

// Thêm cạnh (1 chiều)
void add_edge(Graph* pG, int u, int v, int w) {
    pG->A[u][v] = w;
    pG->A[v][u] = w;
    pG->m++;
}
// Cài đặt thuật toán phù hợp để giải bài toán này
int pi[MAX_SIZE];
int visited[MAX_SIZE];
int parent[MAX_SIZE];
int Prim(Graph* pG, int s, Graph* pR) {
    init_graph(pR, pG->n);
    int total = 0;
    // Khoi tao
    for (int i = 0; i <= pG->n; i++) {
        visited[i] = 0;
        pi[i] = 999999;
        parent[i] = -1;
    }
    pi[s] = 0;

    // duyet cac dinh
    for (int i = 1; i <= pG->n; i++) {
        // tim u co pi[u] nho nhat
        int u = -1, min_pi = 999999999;
        for (int v = 1; v <= pG->n; v++) {
            if (!visited[v] && pi[v] < min_pi) {
                u = v;
                min_pi = pi[v];
            }
        }

        if (u == -1) break;  // khong tim thay
        visited[u] = 1;

        // them vao cay khung
        if (parent[u] != -1) {
            add_edge(pR, u, parent[u], pG->A[u][parent[u]]);
        }
        // cap nhat cac dinh ke cua u
        for (int v = 1; v <= pG->n; v++) {
            if (!visited[v] && pG->A[u][v] > 0 && pG->A[u][v] < pi[v]) {
                pi[v] = pG->A[u][v];
                parent[v] = u;
            }
        }
    }

    //total
    for (int i = 1; i <= pR->n; i++) {
        for (int j = i + 1; j <= pR->n; j++) {
            if (pR->A[i][j] > 0) {

                total += pR->A[i][j];
            }
        }
    }
    return total;
}
int main() {
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int i = 0; i < m; i++) {
        int u, v, w, t;
        scanf("%d %d %d %d", &u, &v, &w, &t);
        add_edge(&G, u, v, w + t);
    }

    Graph R;
    int total = Prim(&G, 1, &R);
    printf("%d", (n - 1) + total);
    return 0;
}
