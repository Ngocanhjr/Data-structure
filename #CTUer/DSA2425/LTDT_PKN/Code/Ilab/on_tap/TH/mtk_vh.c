#include <stdio.h>

#define MAX 100
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
    ElementType data[MAX_ELEMENTS];
    int size;
} List;
/* Tao danh sach rong */
void make_null(List* L) {
    L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
    L->data[L->size] = x;
    L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List* L, int i) {
    return L->data[i - 1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
    return L->size;
}

typedef struct {
    int n, m;
    int A[MAX][MAX];
} Graph;

void init_graph(Graph* pG, int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
    pG->n = n;
    pG->m = 0;
}

// đồ thị vô hướng (có thể chứa đa cung và chứa khuyên)
void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v]++;
    if (u != v) {
        pG->A[v][u]++;
    }
    pG->m++;
}

// đồ thị vô hướng (có thể chứa đa cung và chứa khuyên).
int degree(Graph* pG, int u) {
    int deg_u = 0;
    for (int i = 1; i <= pG->n; i++) {
        deg_u += pG->A[u][i];
    }

    return deg_u + pG->A[u][u];
}

void neighbours(Graph* pG, int u) {
    printf("neighbours(%d) =", u);
    for (int i = 1; i <= pG->n; i++) {
        if (pG->A[u][i] > 0) {
            printf(" %d", i);
        }
    }
    printf("\n");
}

List neighbors(Graph* G, int x) {
    List pL;
    make_null(&pL);
    for (int i = 1; i <= G->n; i++) {
        if (G->A[x][i] > 0) {
            push_back(&pL, i);
            printf("%d ", i);
        }
    }
    return pL;
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

    // In ma trận kề của đồ thị
    // printf("Ma tran ke:\n");
    // for (int u = 1; u <= G.n; u++) {
    //     for (int v = 1; v <= G.n; v++) printf("%d ", G.A[u][v]);
    //     printf("\n");
    // }

    // In bậc
    // int max = 0;
    // int idx = 0;
    // for (int i = 1; i <= n; i++) {
    //     int deg = degree(&G, i);
    //     // printf("deg(%d) = %d\n", i, );
    //     if (deg > max) {
    //         max = deg;
    //         idx = i;
    //     }
    // }
    // printf("%d %d", idx, max);
    // neighbours
    //   for (int i = 1; i <= n; i++) {
    //      neighbours(&G, i);
    //  }
    List L = neighbors(&G, 1);
    for(int i = 1; i <= L.size; i++){
        printf("%d\n", element_at(&L, i));
    }
}