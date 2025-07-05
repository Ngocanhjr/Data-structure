// Đồ thị vô hướng
#include <stdio.h>

#include "Queue.h"

#define MAX_N 100

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;

    // cho toan ma tran b?ng 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

// thêm vào d? th? vô hu?ng
void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

int degree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 1; i <= pG->n; i++) {
        for (int j = 1; j <= pG->n; j++) {
            printf("%d ", pG->A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= pG->n; i++) {
        deg_u += pG->A[u][i];
        // printf("%d ", deg_u);
    }

    return deg_u + pG->A[u][u];
}

int adj(Graph* pG, int u, int v) {
    return pG->A[u][v] > 0;
}

void neighbours(Graph* pG, int u) {
    printf("neighbours(%d) = ", u);

    for (int v = 1; v <= pG->n; v++)
        if (adj(pG, u, v) != 0) printf("%d ", v);

    printf("\n");
}

int mark[MAX_N];

void BFS(Graph* pG, int s) {
    // 1. Khai báo hàng đợi Q, khởi tạo rỗng
    Queue Q;
    make_null_queue(&Q);
    // 2. Đưa s vào Q, bắt đầu duyệt từ đỉnh s */
    enqueue(&Q, s);
    // 3. Vòng lặp chính dùng để duyệt
    while (!empty(&Q)) {
        // 3a. Lấy phần tử ở đầu hàng đợi
        int u = front(&Q);
        dequeue(&Q);
        if (mark[u] != 0)  // u đã duyệt rồi, bỏ qua
            continue;
        printf("%d\n", u);  // Làm gì đó trên u
        mark[u] = 1;        // Đánh dấu nó đã duyệt
        // 3b. Xét các đỉnh kề của u, đưa vào hàng đợi Q
        for (int v = 1; v <= pG->n; v++)
            if (adj(pG, u, v)) {
                enqueue(&Q, v);
            }
    }
}
// Hàm main()
int main() {
    Graph G;
    int n, m;

    // Ð?c s? d?nh, s? cung và kh?i t?o d? th? n d?nh, 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    // Ð?c m cung và thêm vào d? th?
    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    printf("Ma tran ke:\n");
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++) printf("%d ", G.A[u][v]);
        printf("\n");
    }

    // 3. Khởi tạo mảng mark[u] = 0, với mọi u = 1, 2, ..., n
    for (int u = 1; u <= G.n; u++) mark[u] = 0;
    // 4. Gọi hàm BFS duyệt theo chiều rộng từ đỉnh 1
    BFS(&G, 1);
    return 0;
}