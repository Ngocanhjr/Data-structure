#include <stdio.h>

#define MAX 100

int n;
int d[MAX];         // thời gian thực hiện công việc
int earliest[MAX];  // thời gian sớm nhất bắt đầu
int latest[MAX];    // thời gian trễ nhất bắt đầu
int mark[MAX];

typedef struct {
    int n;
    int A[MAX][MAX];  // ma trận kề: A[u][v] = 1 nếu u → v
} Graph;

int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}

void dfs_earliest(Graph* G, int u) {
    mark[u] = 1;
    int maxVal = 0;
    for (int i = 1; i <= G->n; i++) {
        if (G->A[i][u]) {
            if (!mark[i]) dfs_earliest(G, i);
            maxVal = max(maxVal, earliest[i] + d[i]);
        }
    }
    earliest[u] = maxVal;
}

void dfs_latest(Graph* G, int u) {
    mark[u] = 1;
    int minVal = 1e9;
    int hasChild = 0;

    for (int v = 1; v <= G->n; v++) {
        if (G->A[u][v]) {
            hasChild = 1;
            if (!mark[v]) dfs_latest(G, v);
            minVal = min(minVal, latest[v] - d[u]);
        }
    }

    if (!hasChild)
        ;  // giữ nguyên latest[u] nếu là đỉnh cuối
    else
        latest[u] = minVal;
}

int main() {
    Graph G;
    scanf("%d", &n);
    G.n = n;

    // Khởi tạo
    for (int i = 1; i <= n; i++) {
        earliest[i] = 0;
        latest[i] = 0;
        mark[i] = 0;
        for (int j = 1; j <= n; j++) G.A[i][j] = 0;
    }

    // Nhập dữ liệu
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        int v;
        while (scanf("%d", &v) && v != 0) {
            G.A[v][i] = 1;  // cạnh v → i (phải làm v trước i)
        }
    }

    // Tính thời điểm sớm nhất
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) dfs_earliest(&G, i);
    }

    // Tìm thời gian kết thúc dự án
    int endTime = 0;
    for (int i = 1; i <= n; i++) {
        if (endTime < earliest[i] + d[i]) endTime = earliest[i] + d[i];
    }

    // Gán latest ban đầu = endTime - d[u]
    for (int i = 1; i <= n; i++) {
        latest[i] = endTime - d[i];
        mark[i] = 0;
    }

    // Tính thời điểm trễ nhất
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) dfs_latest(&G, i);
    }

    // In kết quả
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", earliest[i], latest[i]);
    }

    return 0;
}
 