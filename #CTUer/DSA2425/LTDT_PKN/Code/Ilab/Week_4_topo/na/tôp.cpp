#include <stdio.h>

#define MAX_SIZE 101
//-----------------------------Queue----------------
typedef int ElementType;

typedef struct {
    ElementType data[MAX_SIZE];
    int front, rear;
} Queue;

void init_queue(Queue* pQ) {
    pQ->front = 0;
    pQ->rear = -1;
}

int is_empty_queue(Queue* pQ) {
    return pQ->rear < pQ->front;
}

void enqueue(Queue* pQ, int x) {
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

void dequeue(Queue* pQ) {
    pQ->front++;
}

int front(Queue* pQ) {
    return pQ->front;
}

//-----------------------List-----------------------
typedef struct {
    ElementType data[MAX_SIZE];
    int size;
} List;

void init_list(List* pL) {
    pL->size = 0;
}

void push_back(List* pL, int x) {
    pL->data[pL->size] = x;
    pL->size++;
}

// L?y ph?n t? th? i, ph?n t? b?t d?u có v? trí 1
ElementType element_at(List* pL, int i) {
    return pL->data[i - 1];
}

// Tr? v? s? ph?n t? c?a danh sách
int size_list(List* pL) {
    return pL->size;
}
//-----------------------Graph----------------------
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
    pG->A[u][v] = 1;
    pG->m++;
}

int adj(Graph* pG, int u, int v) {
    return pG->A[u][v] > 0;
}

int inDegree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 1; i <= pG->n; i++) {
        deg_u += pG->A[i][u];
    }
    return deg_u;
}

//---------------------------------------------Topo---------------------

void topo(Graph* pG, List* pL) {
    // 1. init
    int d[MAX_SIZE];
    Queue Q;
    init_queue(&Q);
    List L;
    init_list(&L);
    // 1.1 Tinh bac vao cua cac dinh d[u]
    for (int u = 1; u <= pG->n; u++) {
        d[u] = inDegree(pG, u);
    }
    // 1.2 Q chua cac dinh co bac vao = 0;
    for (int u = 1; u <= pG->n; u++) {
        if (d[u] == 0) {
            enqueue(&Q, u);
        }
    }

    // 2 lap
    while (!is_empty_queue(&Q)) {
        int u = front(&Q);
        // xoa u
        dequeue(&Q);
        // Them u vao danh sach topo
        push_back(&L, u);
        for (int v = 1; v <= pG->n; v++) {
            if (adj(pG, u, v)) {
                d[v]--;
                if (d[v] == 0) {
                    enqueue(&Q, v);
                }
            }
        }
    }
}
int main() {
    Graph G;
    int n, m;
    List L;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    topo(&G, &L);
}
