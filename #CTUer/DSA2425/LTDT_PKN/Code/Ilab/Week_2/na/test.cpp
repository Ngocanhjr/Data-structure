#include <stdio.h>
#define MAX_N 500

typedef struct {
    int n, m;     
    int A[MAX_N][MAX_N];
} Graph;

//Kh?i t?o d? th?
void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}
//Thêm cung (u, v)
void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v]++;
    pG->m++;
}
//Tính b?c vào c?a u
int indegree(Graph* pG, int u){
    int deg = 0;
    for(int i = 1; i <= pG->n; i++){
        deg+=pG->A[i][u];
    }
    
    return deg;
}


//Chuong trình chính
int main() {
    Graph G;
    //Ð?c d? li?u vào d? th? G
    int n, m, e, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    //In b?c vào c?a các d?nh
    for(int i = 1; i <=G.n; i++){
    	printf("deg-in[%d] = %d\n",i, indegree(&G,i));
}


    return 0;
}
