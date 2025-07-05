//Khai báo thu vi?n và h?ng
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
    pG->m = 0;

    // cho toan ma tran b?ng 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pG->A[i][j] = 0;
        }
    }
}

// thêm vào d? th? vô hu?ng
void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

int degree(Graph *pG, int u) {
    int deg_u = 0;
    for(int i = 1; i <= pG->n; i++){
            deg_u += pG->A[u][i];
            // printf("%d ", deg_u);
    }
   
    return deg_u + pG->A[u][u];
}

void neighbours(Graph* pG, int u) {
    printf("neighbours(%d) = ", u);
    
    int v;
    for (v = 1; v <= pG->n; v++){
        // printf("1");
        if (pG->A[u][v] != 0)
        {
            printf("%d ", v);
        }
    }

    printf("\n");
}
//Hàm main()
int main() {
    Graph G;
    int n, m;
    
    //Ð?c s? d?nh, s? cung và kh?i t?o d? th? n d?nh, 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    //Ð?c m cung và thêm vào d? th?
    for (int e = 0; e < m; e++) {
        int u,v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    //In ma tr?n k? c?a d? th?
    for (int u = 1; u <= G.n; u++) {
//        for (int v = 1; v <= G.n; v++)
//            printf("%d \n", G.A[u][v]);
//        printf("\n");
	    neighbours(&G,u);	
    }
    
    return 0;
}