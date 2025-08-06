#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
#define oo 99999
#define NO_EDGE -1

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
            pG->A[i][j] = NO_EDGE;
        }
    }
}

// Thêm cạnh (1 chiều)
void add_edge(Graph* pG, int u, int v, int w) {
    pG->A[u][v] = w;
    pG->A[v][u] = w;
    pG->m++;
}

//-------------Prim------------------
int pi[MAX_SIZE];
int p[MAX_SIZE];
int mark[MAX_SIZE];

void Prim(Graph* pG, int s, Graph* pR) {
    init_graph(pR, pG->n);  // Khởi tạo cây khung rỗng
    int total = 0;          // tong trọng số của cây
    for (int u = 1; u <= pG->n; u++) {
        mark[u] = 0;
        pi[u] = oo;
        p[u] = -1;
    }
    pi[s] = 0;

    for (int i = 1; i <= pG->n; i++) {
        // Tìm u gần với S nhất (tìm u có pi[u] nhỏ nhất)
        int u = -1, min_pi = oo;
        for (int j = 1; j <= pG->n; j++) {
            if (!mark[j] && pi[j] < min_pi) {
                min_pi = pi[j];
                u = j;
            }
        }
        printf("%d\n", u);
        if (u == -1) break;
        mark[u] = 1;  // đánh dấu u

        // Nếu u có cha thì thêm cạnh (u,p[u]) vào cây khung
        // nếu nó không phải là gốc thì nó có một cha (p[u])
        if (p[u] != -1) {
            add_edge(pR, u, p[u], pG->A[u][p[u]]);
        }

        // cập nhật lại pi và các đỉnh kề của u
        for (int v = 1; v <= pG->n; v++) {
            if (pG->A[u][v] != NO_EDGE && !mark[v] && pG->A[u][v] < pi[v]) {
                pi[v] = pG->A[u][v];
                p[v] = u;
            }
        }
    }
    // total
    for (int i = 1; i <= pG->n; i++) {
        for (int j = i + 1; j <= pG->n; j++) {  // chỉ duyệt 1 chiều
            if (pR->A[i][j] != NO_EDGE) {
                // printf("%d %d %d\n", i, j, pR->A[i][j]);
                total += pR->A[i][j];
            }
        }
    }

    // return total;
}

//-------------Main------------------
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
    // int total = Prim(&G, 1, &R);  // bắt đầu từ đỉnh 1
    Prim(&G, 1, &R);
    // In cây khung và tính tổng trọng số

    // printf("%d\n", total);
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i + 1; j <= n; j++) {  // chỉ duyệt 1 chiều
    //         if (R.A[i][j] != NO_EDGE) {
    //             printf("%d %d %d\n", i, j, R.A[i][j]);
    //         }
    //     }
    // }

    return 0;
}
