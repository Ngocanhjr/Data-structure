 max = cnt = 0;
    for (int i = 1; i <= G.n; i++) {
        if (!visited[i]) {
            cnt = 0;
            DFS(&G,i);
            if (cnt > max) {
                max = cnt;
            }
        }
    }
    printf("%d", max);