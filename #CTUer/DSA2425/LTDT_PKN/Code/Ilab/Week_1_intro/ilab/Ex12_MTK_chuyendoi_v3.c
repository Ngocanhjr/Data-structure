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
            scanf("%d", &pG->A[i][j]);
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
    int n;
    scanf("%d", &n);
    init_graph(&G, n);

    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
        {  
            int w = G.A[u][v];
            while(w > 0){
                printf("%d ", v);
                w--;
            }
        }
        printf("0\n");
    }
    
    return 0;
}