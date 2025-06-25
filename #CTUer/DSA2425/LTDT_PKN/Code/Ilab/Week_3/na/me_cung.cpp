#include <stdio.h>

#define MAX_SIZE 101
int A[MAX_SIZE][MAX_SIZE];  // Store maze
#define idx_o_ke 4
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};

//---------------------Graph----------------------
#if 0
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

    pG->m++;
}

int adj(Graph* pG, int u, int v) {
    return pG->A[u][v] > NO_EDGE;
}
#endif
//------------------Dijkstra path-----------------
#define NOT_SURE 0
#define SURE 1
#define oo 999999

// int parent[MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int pi[MAX_SIZE][MAX_SIZE];

void Dijkstra(int n, int m) {
    // 1. init
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            pi[i][j] = oo;
            visited[i][j] = NOT_SURE;
        }
    }

    pi[0][0] = 0;  // Tong chi phi tai vi tri bat dau

    while (1) {
        int ui = -1;  // Chi so i cua phan tu co tong chi phi thap nhat
        int uj = -1;  // Chi so j cua phan tu co tong chi phi thap nhat
        int min_u = oo;
        // Tim min
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (visited[i][j] == NOT_SURE && pi[i][j] < min_u) {
                    min_u = pi[i][j];
                    ui = i;
                    uj = j;
                }
            }
        }

        if (ui == -1) break;  // Không còn đỉnh nào để duyệt
        visited[ui][uj] = SURE;

        // Cập nhật các ô kề
        for (int k = 0; k < idx_o_ke; k++) {
            int vi = ui + di[k];
            int vj = uj + dj[k];

            if (vi >= 0 && vi < n && vj >= 0 && vj < m) {
                int cost = A[vi][vj];
                if (!visited[vi][vj] && pi[ui][uj] + cost < pi[vi][vj]) {
                    pi[vi][vj] = pi[ui][uj] + cost;
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    Dijkstra(n, m);
    printf("%d", pi[n - 1][m - 1]);
}
