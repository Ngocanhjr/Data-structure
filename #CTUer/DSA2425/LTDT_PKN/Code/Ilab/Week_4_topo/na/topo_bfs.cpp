#include <stdio.h>

#define MAX_SIZE 101

//------------------------Queue-------------
typedef int ElementType;

typedef struct {
    int front, rear;
    ElementType data[MAX_SIZE];
} Queue;

void init_queue(Queue* pQ) {
    pQ->front = 0;
    pQ->rear = -1;
}

int empty_queue(Queue* pQ) {
    return pQ->rear < pQ->front;
}

void enqueue(Queue* pQ, int x) {
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

void dequeue(Queue* pQ) {
    pQ->front++;
}

ElementType front(Queue* pQ) {
    return pQ->data[pQ->front];
}

//-------------------------------------List------------------------
typedef struct {
    ElementType data[MAX_SIZE];
    int size;
} List;

void init_list(List* pL) {
    pL->size = 0;
}

int empty_list(List* pL) {
    return pL->size == 0;
}

void push_back(List* pL, int x) {
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List* pL, int i) {
    return pL->data[i - 1];
}

int size_list(List* pL) {
    return pL->size;
}

//---------------------------Graph-----------------------
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

//-----------------topo-----------------------
void topo_bfs(Graph* pG, List* pL) {
    int d[MAX_SIZE];

    // Tinh bac vao
    for (int u = 1; u <= pG->n; u++) {
        d[u] = inDegree(pG, u);
    }

    Queue Q;
    init_queue(&Q);

    // Dua cac dinh co bac vao = 0 vao hang doi
    for (int u = 1; u <= pG->n; u++) {
        if (d[u] == 0) {
            enqueue(&Q, u);
        }
    }

    while (!empty_queue(&Q)) {
        // Lay phan tu ra khoi hang doi
        int u = front(&Q);
        dequeue(&Q);
        push_back(pL, u);

        // xoa u va giam bac vao cua cac dinh ke v cua u
        for (int v = 1; v <= pG->n; v++) {
            if (pG->A[u][v] != 0) {
                d[v]--;
                // cap nhat them cac dinh co bac vao = 0 sau khi xoa u
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
    init_list(&L);
    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    topo_bfs(&G, &L);

    for(int i = 0; i < L.size; i++){
        printf("%d ", L.data[i]);
    }
}