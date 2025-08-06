#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005

int n, m;
int graph[MAXN][MAXN];  // Ma trận kề
int in_deg[MAXN];       // Bán bậc vào
int candy[MAXN];        // Số kẹo mỗi bé
int queue[MAXN];        // Hàng đợi cho Topo Sort
int front = 0, rear = 0;

// Thêm phần tử vào hàng đợi
void push(int x) {
    queue[rear++] = x;
}

// Lấy phần tử ra khỏi hàng đợi
int pop() {
    return queue[front++];
}

int main() {
    scanf("%d %d", &n, &m);

    // Khởi tạo
    for (int i = 1; i <= n; i++) {
        candy[i] = 1;
        in_deg[i] = 0;
    }

    // Nhập các ràng buộc
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (!graph[b][a]) {
            graph[b][a] = 1;
            in_deg[a]++;
        }
    }

    // Thêm các đỉnh có bậc vào bằng 0 vào hàng đợi
    for (int i = 1; i <= n; i++) {
        if (in_deg[i] == 0) push(i);
    }

    // Topological Sort + cập nhật số kẹo
    while (front < rear) {
        int u = pop();
        for (int v = 1; v <= n; v++) {
            if (graph[u][v]) {
                if (candy[v] <= candy[u]) {
                    candy[v] = candy[u] + 1;
                }
                in_deg[v]--;
                if (in_deg[v] == 0) {
                    push(v);
                }
            }
        }
    }

    // In kết quả
    int total = 0;
    for (int i = 1; i <= n; i++) {
        printf("%d\n", candy[i]);
        total += candy[i];
    }
    printf("%d\n", total);

    return 0;
}
