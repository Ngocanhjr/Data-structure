// đồ thị vô hướng (có thể chứa đa cung và chứa khuyên)

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
    pG->A[u][v]++;
    if(u != v){
        pG->A[v][u]++;
    }
    pG->m++;
}

//Hàm main()
int main() {
    Graph G;
    int n, m;

    //Ð?c s? d?nh, s? cung và kh?i t?o d? th? n d?nh, 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    //Ð?c m cung và thêm vào d? th?
    for (int e = 0; e < m; e++) 
    {
        int u ,v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    //In ma tr?n k? c?a d? th?
    printf("Ma tran ke:\n");
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");	
    }
    
    return 0;
}