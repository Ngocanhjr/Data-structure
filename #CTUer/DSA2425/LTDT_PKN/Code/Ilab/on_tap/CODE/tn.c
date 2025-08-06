
// Cài đặt thuật toán phù hợp để giải bài toán này
int pi[MAX_SIZE];
int visited[MAX_SIZE];
int parent[MAX_SIZE];
int Prim(Graph* pG, int s, Graph* pR) {
    init_graph(pR, pG->n);
    int total = 0;
    // Khoi tao
    for (int i = 0; i <= pG->n; i++) {
        visited[i] = 0;
        pi[i] = 999999;
        parent[i] = -1;
    }
    pi[s] = 0;

    // duyet cac dinh
    for (int i = 1; i <= pG->n; i++) {
        // tim u co pi[u] nho nhat
        int u = -1, min_pi = 999999999;
        for (int v = 1; v <= pG->n; v++) {
            if (!visited[v] && pi[v] < min_pi) {
                u = v;
                min_pi = pi[v];
            }
        }

        if (u == -1) break;  // khong tim thay
        visited[u] = 1;

        // them vao cay khung
        if (parent[u] != -1) {
            add_edge(pR, u, parent[u], pG->A[u][parent[u]]);
        }
        // cap nhat cac dinh ke cua u
        for (int v = 1; v <= pG->n; v++) {
            if (!visited[v] && pG->A[u][v] > 0 && pG->A[u][v] < pi[v]) {
                pi[v] = pG->A[u][v];
                parent[v] = u;
            }
        }
    }

    //total
    for (int i = 1; i <= pR->n; i++) {
        for (int j = i + 1; j <= pR->n; j++) {
            if (pR->A[i][j] > 0) {

                total += pR->A[i][j];
            }
        }
    }
    return total;
}



void DFS(Graph* pG, int s) {

    visited[s] = 1;
    // printf("%d \n", s);
    for (int u = 1; u <= pG->n; u++) {
        if (pG->A[s][u] > 0 && !visited[u]) {
            DFS(pG, u);
        }
    }
}

 cnt = 0;
    for (int i = 1; i <= G.n; i++) {
        if (!visited[i]) {
            cnt++;
            DFS(&G, i);
        }
    }



    void rank(Graph *pG) {
	int d[MAX_N]; //Lưu bậc các đỉnh
	//Tính bậc vào của các đỉnh d[u]
	for (int u = 1; u <= pG->n; u++) {
		d[u] = 0;
		for (int x = 1; x <= pG->n; x++)
			if (pG->A[x][u] != 0)
				d[u]++;
	}
	//Sử dụng 2 danh sách S1, S2
	List S1, S2;
	//Tìm gốc, đưa vào S1
	make_null_list(&S1);
	for (int u = 1; u <= pG->n; u++)
		if (d[u] == 0)
			push_back(&S1, u);

	//Vòng lặp chính, lặp đến khi S1 rỗng thì dừng
	int k = 0; //hạng tính từ 0. Tùy theo bài toán có thể cho k = 1
	while (S1.size > 0) {
		make_null_list(&S2);
		for (int i = 1; i <= S1.size; i++) {
			int u = element_at(&S1, i); 	//Lấy các gốc u trong S1 ra
			r[u] = k; 			            //Xếp hạng cho u
			//Xoá đỉnh u <=> giảm bậc vào của các đỉnh kề v của u
			for (int v = 1; v <= pG->n; v++)
				if (pG->A[u][v] != 0) {
					d[v]--;
					if (d[v] == 0)
						push_back(&S2, v);
				}
		}
		copy_list(&S1, &S2); 	//Copy S2 vào S1
		k++; 				//Tăng hạng kế tiếp cho các gốc mới
	}
}