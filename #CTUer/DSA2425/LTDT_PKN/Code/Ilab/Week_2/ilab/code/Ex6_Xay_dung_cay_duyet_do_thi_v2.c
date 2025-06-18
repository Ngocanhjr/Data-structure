#include <stdio.h>

#define MAX_SIZE 100

//--------------Queue--------------
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void make_null_queue(Queue* pQ) {
    pQ->rear = -1;
    pQ->front = 0;
}

int is_empty(Queue* pQ) {
    return pQ->front > pQ->rear;
}

void enqueue(Queue* pQ, int x) {
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

void dequeue(Queue* pQ) {
    pQ->front++;
}

int front(Queue* pQ) {
    return pQ->data[pQ->front];
}

//--------------Graph-------------
typedef struct {
    int A[MAX_SIZE][MAX_SIZE];
    int n, m;
} Graph;

// Create empty graph
void init_graph(Graph* pG, int n) {
    pG->n = n;
    for (int i = 0; i <= pG->n; i++) {
        for (int j = 0; j <= pG->n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

// Add new edge to graph
void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v] = 1;
    // pG->A[v][u] = 1;
    pG->m++;
}

//----------------BFS------------
int visited[MAX_SIZE];
int parent[MAX_SIZE];

void BFS(Graph* pG, int s) {
    Queue Q;
    make_null_queue(&Q);
    enqueue(&Q, s);
    visited[s] = 1;
    parent[s] = -1;
    while (!is_empty(&Q)) {
        int u = front(&Q);
        dequeue(&Q);
        // printf("%d\n", u);
        for (int v = 1; v <= pG->n; v++) {
            if (pG->A[u][v] > 0 && !visited[v]) {
                enqueue(&Q, v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
}

int main() {
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int e = 0; e <= n; e++) {
        visited[e] = 0;
        parent[e] = 99;
    }

    for (int e = 1; e <= n; e++) {
        if (!visited[e]) {
            BFS(&G, e);
        }
    }

    for (int e = 1; e <= n; e++) {
        printf("%d %d\n", e, parent[e]);
    }
}
