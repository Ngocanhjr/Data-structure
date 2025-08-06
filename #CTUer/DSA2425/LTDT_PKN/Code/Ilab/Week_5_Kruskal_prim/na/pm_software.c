#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1005

int n, m;
int duration[MAX];       // thời gian làm từng công việc
int indegree[MAX];       // số lượng phụ thuộc (bậc vào)
int adj[MAX][MAX];       // danh sách kề
int adj_size[MAX];       // số lượng đỉnh kề của từng đỉnh
int earliest[MAX];       // thời điểm sớm nhất có thể bắt đầu công việc

void topo_sort() {
    int queue[MAX], front = 0, rear = 0;

    // Khởi tạo các công việc không có phụ thuộc (indegree = 0)
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
            earliest[i] = 0;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        for (int i = 0; i < adj_size[u]; i++) {
            int v = adj[u][i];
            if (earliest[v] < earliest[u] + duration[u])
                earliest[v] = earliest[u] + duration[u];

            indegree[v]--;
            if (indegree[v] == 0)
                queue[rear++] = v;
        }
    }
}

int main() {
    scanf("%d", &n);  // số công việc

    for (int i = 1; i <= n; i++)
        scanf("%d", &duration[i]);

    scanf("%d", &m);  // số mối phụ thuộc

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adj_size[u]++] = v;
        indegree[v]++;
    }

    topo_sort();

    // tìm thời gian hoàn thành lớn nhất
    int total_time = 0;
    for (int i = 1; i <= n; i++) {
        int finish = earliest[i] + duration[i];
        if (finish > total_time)
            total_time = finish;
    }

    printf("%d\n", total_time);
    return 0;
}
