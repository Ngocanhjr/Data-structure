#include <stdio.h>

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Bước 1: Biểu diễn bằng phương pháp danh sách các cung (list of edges)
// Sử dụng cấu trúc Edge để lưu cung (u, v, w)
typedef struct {
    int u, v;
    int w;
} Edge;

// Với mỗi cung u --w--> v, ta lưu (u, v, w)

#define MAX_N 101       // Tối đa 100 đỉnh, đánh số đỉnh từ 1
struct Graph {          // Khai báo struct kiểu C++, không cần dùng typedef
    int n, m;           // n: số đỉnh, m: số cung
    Edge edges[MAX_N];  // danh sách cung, lưu từ 0
};

// Bước 2: Khai báo các hằng và biến hỗ trợ (biến toàn cục):
#define oo 999999999  // Xem như vô cùng

int mark[MAX_N];  // Trạng thái đánh dấu của các đỉnh
int d[MAX_N];     // Chiều dài đường đi ngắn nhất

// Bước 3: Cài đặt thuật toán Bellman-Ford tìm đường đi ngắn nhất từ đỉnh s
void Bellman_Ford(Graph* pG, int s) {
    // Gán d[v] = oo với mọi v trong V
    for (int v = 1; v <= pG->n; v++) d[v] = oo;

    // Gán d[s] = 0
    d[s] = 0;

    // Lặp n-1 lần từ 0 đến n - 2
    for (int it = 0; it <= pG->n - 2; it++) {
        // Duyệt qua tất cả các cung (u, v, w) và xem xét cập nhật d[v]
        for (int e = 0; e < pG->m; e++) {
            int u, v, w;
            // Gán (u, v, w) = phần tử thứ e của danh sách các cung edges
            u = pG->edges[e].u;
            v = pG->edges[e].v;
            w = pG->edges[e].w;

            // Nếu d[v] lớn hơn d[u] + edgeWeight(u, v), chú ý d[u] phải khác vô cùng
            if (d[v] > d[u] + w)
                // Cập nhật d[v] = d[u] + edgeWeight(u, v)
                d[v] = d[u] + w;
        }
    }
}

// Bước 4: Kiểm thử
int main() {
    Graph G;

    cin >> G.n >> G.m;

    // Đọc các cung và thêm vào đồ thị
    for (int e = 0; e < G.m; e++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Gán edges[e] = (u, v, w)
        G.edges[e].u = u;
        G.edges[e].v = v;
        G.edges[e].w = w;
    }

    Bellman_Ford(&G, 1);

    for (int u = 1; u <= G.n; u++) cout << "d[" << u << "] = " << d[u] << endl;

    return 0;
}
