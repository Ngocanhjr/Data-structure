int degree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 1; i <= pG->n; i++) {
        deg_u += pG->A[u][i];
        // printf("%d ", deg_u);
    }

    return deg_u + pG->A[u][u];
}

int degree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 1; i <= pG->n; i++) {
        deg_u += pG->A[u][i] + pG->A[i][u];
        // printf("%d ", deg_u);
    }

    return deg_u;
}

int indegree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 1; i <= pG->n; i++) {
        deg_u += pG->A[i][u];
        // printf("%d ", deg_u);
    }

    return deg_u;
}

int outdegree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 1; i <= pG->n; i++) {
        deg_u += pG->A[u][i];
        // printf("%d ", deg_u);
    }

    return deg_u;
}