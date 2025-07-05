#include <stdio.h>

#define MAX_SIZE 101

//------------------stack--------------
typedef struct {
    int top_idx;
    int data[MAX_SIZE];
} Stack;

void init_stack(Stack* pS) {
    pS->top_idx = -1;
}

void push(Stack* pS, int x) {
    pS->top_idx++;
    pS->data[pS->top_idx] = x;
}

void pop(Stack* pS) {
    pS->top_idx--;
}

int top(Stack* pS) {
    return pS->data[pS->top_idx];
}

int empty_stack(Stack* pS) {
    return pS->top_idx == -1;
}

//---------------------Graph----------------------------
typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

void add_edge(Graph* pG, int u, int v) {
    pG->m++;
    pG->A[u][v] = 1;
}

int adj(Graph* pG, int u, int v) {
    return pG->A[u][v] > 0;
}

//---------------------topo----------------
int visited[MAX_SIZE];
void topo_dfs(Graph* pG, Stack* pS, int u) {
    visited[u] = 1;
    for (int v = 1; v <= pG->n; v++) {
        if (adj(pG, u, v)) {
            if (visited[v] == 0) {
                topo_dfs(pG, pS, v);
            }
        }
    }
    push(pS, u);
}
int main() {
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    Stack S;
    init_stack(&S);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int u = 1; u <= n; u++)
        if (visited[u] == 0) topo_dfs(&G, &S, u);

    while (!empty_stack(&S)) {
        printf("%d ", top(&S));
        pop(&S);
    }
}