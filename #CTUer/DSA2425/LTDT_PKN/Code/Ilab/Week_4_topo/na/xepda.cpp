#include <stdio.h>

#define MAX_SIZE 101

typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void init_graph(Graph* pG, int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }

    pG->n = n;
}

void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v] = 1;
    // pG->A[v][u] = 1;
}

typedef struct {
    int top_idx;
    int data[MAX_SIZE];
} Stack;

void init_stack(Stack* pS) {
    pS->top_idx = -1;
}

int empty_stack(Stack* pS) {
    return pS->top_idx == -1;
}

void push(Stack* pS, int x) {
    pS->top_idx++;
    pS->data[pS->top_idx] = x;
}

int pop(Stack* pS) {
    int x = pS->data[pS->top_idx];
    pS->top_idx--;
    return x;
}

int visited[MAX_SIZE];
void dfs(Graph* pG, int u, Stack* pS) {
    visited[u] = 1;
    for (int v = 1; v <= pG->n; v++) {
        if (pG->A[u][v] > 0 && !visited[v]) dfs(pG, v, pS);
    }
    push(pS, u);
}

void topo(Graph* pG, Stack* pS) {
    // 1. init
    for (int i = 1; i <= pG->n; i++) {
        visited[i] = 0;
    }
    init_stack(pS);
    // traversal graph
    for (int i = 1; i <= pG->n; i++) {
        if (!visited[i]) {
            dfs(pG, i, pS);
        }
    }
}

int main() {
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    Stack S;
    topo(&G, &S);

    while (!empty_stack(&S)) {
        printf("%d\n", pop(&S));
    }
}