// Lưu thời gian hoàn thành công việc
int d[MAX_N];
// Đọc danh sách các công việc và tạo đồ thị
int main() {
    Graph G;
    int n, u, x, v, j;
    // 1. Đọc đồ thị
    freopen(“tenfile”, “r”, stdin);
    scanf(“% d”, &n);
    // 1a. Tạo đồ thị có n + 2 đỉnh (alpha = n+1 và beta = n + 2)
    init_graph(&G, n + 2);
    int alpha = n + 1, beta = n + 2;
    d[alpha] = 0;  // thời gian hoàn thành alpha là 0.
    // 1b. Đọc danh sách các công việc
    for (u = 1; u <= n; u++) {
        scanf(“% d”, &d[u]);  // Thời gian hoàn thành công việc u
        do {
            scanf(“% d”, &x);  // Đọc công việc trước của u
            if (x > 0) add_edge(&G, x, u);
        } while (x > 0);  // Đọc đến khi gặp số 0 thì dừng
    }
    // 2. Thêm cung nối alpha với các đỉnh có bậc vào = 0
    for (u = 1; u <= n; u++) {
        int deg_neg = 0;
        for (x = 1; x <= n; x++) {
            if (G.A[x][u] > 0) deg_neg++;  // deg_neg là bậc vào của u
            if (deg_neg == 0) add_edge(&G, alpha, u);
        }
        // 3. Thêm cung nối các đỉnh có bậc ra = 0 vào beta
        for (u = 1; u <= n; u++) {
            int deg_pos = 0;
            for (v = 1; v <= n; v++)
                if (G.A[u][v] > 0) deg_pos++;  // deg_neg là bậc ra của u
            if (deg_pos == 0) add_edge(&G, u, beta);
        }
        // 4. Xếp thứ tự các đỉnh theo giải thuật sắp xếp topo.
        List L;
        topo_sort(&G, &L);
        // 5. Tính t[u]
        int t[MAX_N];
        t[alpha] = 0;
        // alpha chắc chắn nằm đầu danh sách, các đỉnh còn lại đi từ 2 đến L.size
        for (j = 2; j <= L.size; j++) {
            int u = element_at(&L, j);
            t[u] = -oo;  // vô cùng bé, ví dụ: -999999
            for (x = 1; x <= G.n; x++)
                if (G.A[x][u] > 0) t[u] = max(t[u], t[x] + d[x]);
        }
        // 6. tính T[u]
        int T[MAX_N];
        T[beta] = t[beta];
        // beta chắc chắn nằm cuối danh sách, đi ngược lại từ L.size – 1 về 1
        for (j = L.size - 1; j >= 1; j--) {
            int u = element_at(&L, j);
            T[u] = +oo;  // vô cùng lớn, ví dụ: 999999
            for (v = 1; v <= G.n; v++)
                if (G.A[u][v] > 0) T[u] = min(T[u], T[v] - d[u]);
        }
        // 7. In kết quả: in t[u] và T[u] ra màn hình
    }