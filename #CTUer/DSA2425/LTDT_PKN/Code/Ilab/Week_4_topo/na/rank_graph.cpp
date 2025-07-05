#include <stdio.h>

#define MAX_SIZE 101

typedef struct {
    int data[MAX_SIZE];
    int size;
} List;

void init_list(List* pL) {
    pL->size = 0;
}

void push_back(List* pL, int x) {
    pL->data[pL->size] = x;
    pL->size++;
}

int size(List* pL) {
    return pL->size;
}

int element_at(List* pL, int i) {
    return pL->data[i - 1];
}

void copy_list(List* pL1, List* pL2) {
    pL1->size = pL2->size;
    for (int i = 0; i < pL2->size; i++) {
        pL1->data[i] = pL2->data[i];
    }
}

//------------------Graph-------------
typedef struct {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
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

int inDegree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 1; i <= pG->n; i++) {
        deg_u += pG->A[i][u];
    }

    return deg_u;
}

//-------------------rank---------------------
int r[MAX_SIZE];  // Luu hang cua do thi

void rank(Graph* pG) {
    int d[MAX_SIZE];  // Luu bac cua cac dinh

    // Tinh bac vao cua dinh u luu vao d[u]
    for (int u = 1; u <= pG->n; u++) {
        d[u] = inDegree(pG, u);
    }

    List L1, L2;
    init_list(&L1);

    // Tim goc dua vao L1
    for (int u = 1; u <= pG->n; u++) {
        if (d[u] == 0) {
            push_back(&L1, u);
        }
    }

    // Lap den khi L1 rong thi stop
    int k = 0;
    while (L1.size > 0) {
        init_list(&L2);
        for (int i = 1; i <= L1.size; i++) {
            int u = element_at(&L1, i);  // Lay cac goc trong l1 ra
            r[u] = k;

            // Xoa dinh u -> giam bac vao cua cac dinh ke v cua u
            for (int v = 1; v <= pG->n; v++) {
                // Neu v ke u thi giam bac vao
                if (adj(pG, u, v)) {
                    d[v]--;
                    if (d[v] == 0) {
                        if (d[v] == 0) {
                            push_back(&L2, v);
                        }
                    }
                }
            }
        }
        copy_list(&L1, &L2);  // Copy S2 vào S1
        k++;                  // Tăng hạng kế tiếp cho các gốc mới
    }
}

int main() {
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    rank(&G);
    for (int i = 1; i <= n; i++) {
        printf("r[%d] = %d\n", i, r[i]);
    }
}
