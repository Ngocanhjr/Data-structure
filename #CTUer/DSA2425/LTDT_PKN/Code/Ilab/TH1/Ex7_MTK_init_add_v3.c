#if 1

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
    if (u == v) {  // trường hợp (u, u)
        pG->A[u][v]++;
    } else if (pG->A[u][v] == 1) {  // đa cung
        pG->A[u][v]++;

    } else {  // cung chưa tồn tại
        pG->A[u][v] = 1;
    }
    pG->m++;
}

#endif

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

    pG->m++;
}
#endif