// Khai báo thư viện và hằng
#include <stdio.h>
#define MAX_N 100

/// @brief đơn đồ thị vô hướng, chỉ số ma trận bắt đầu từ 1 đến n

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;

    // cho toan ma tran bằng 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
}



// thêm vào đồ thị vô hướng, có thể chứa đa cung và chưa khuyên
void add_edge(Graph* pG, int u, int v) {
    if(u == v) { // trường hợp (u, u)
        pG->A[u][v]++;
    }else if (pG->A[u][v] == 1) { //đa cung
        pG->A[u][v]++;
        pG->A[v][u]++;
    }  else { //cung chưa tồn tại
        pG->A[u][v] = 1;
        pG->A[v][u] = 1;
    }
    pG->m++;
}

// Hàm main()
int main() {
    Graph G;
    int n, m;

    // Đọc số đỉnh, số cung và khởi tạo đồ thị n đỉnh, 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    // Đọc m cung và thêm vào đồ thị
    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    // In ma trận kề của đồ thị
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++) printf("%d ", G.A[u][v]);
        printf("\n");
    }
    return 0;
}

#if 0

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
    if (u != v)
        pG->A[v][u] += 1;
    
    pG->m++;
}

#endif