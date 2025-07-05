#include <stdio.h>

#define MAX_SIZE 100
typedef int ElementType;

//--------------------Stack------------------------
typedef struct {
    ElementType data[MAX_SIZE];
    int top_idx;
} Stack;

// init empty stack
void make_null_stack(Stack* pS) {
    pS->top_idx = -1;
}

// Check stack is empty>
int is_empty_stack(Stack* pS) {
    return pS->top_idx == -1;
}
// add element x to stack
void push(Stack* pS, ElementType x) {
    pS->top_idx++;
    pS->data[pS->top_idx] = x;
}

// delete element x fromt stack
void pop(Stack* pS) {
    pS->top_idx--;
}

// Retrieve top element
ElementType top(Stack* pS) {
    return pS->data[pS->top_idx];
}

//--------------------Graph------------------------
typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

// init graph with n vertix
void init_graph(Graph* pG, ElementType n) {
    pG->n = n;
    pG->m = 0;

    // cho toan bo ma tran ke bang 0
    for (int i = 0; i <= pG->n; i++) {
        for (int j = 0; j <= pG->n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

// add edge (u,v) to graph
void add_edge(Graph* pG, ElementType u, ElementType v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

//--------------------DFS------------------------
int visited[MAX_SIZE];
void DFS(Graph* pG, int s) {
    visited[s] = 1;
    printf("%d \n", s);
    for (int u = 1; u <= pG->n; u++) {
        if (pG->A[s][u] != 0 && !visited[u]) {
            DFS(pG,u);
        }
    }
}

int main() {
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 0; i <= G.n; i++) {
        visited[i] = 0;
    }
	DFS(&G, 1);
}
