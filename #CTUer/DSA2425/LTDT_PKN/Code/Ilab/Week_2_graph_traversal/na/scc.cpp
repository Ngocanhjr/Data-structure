#include <stdio.h>

#define MAX_SIZE 100

//---------------------Stack-------------------
typedef int ElementType;
typedef struct{
	int data[MAX_SIZE];
	int top_idx;
}Stack;

void init_stack(Stack* pS){
	pS->top_idx = -1;
}

int is_empty(Stack* pS){
	return pS->top_idx < 0;
}
void push(Stack* pS, ElementType x){
	pS->top_idx++;
	pS->data[pS->top_idx] = x;
}

void pop(Stack* pS){
	pS->top_idx--;
}

ElementType top(Stack* pS){
	return pS->data[pS->top_idx];
}

//---------------------Graph-------------------
typedef struct{
	int n,m;
	int A[MAX_SIZE][MAX_SIZE];
}Graph;

void init_graph(Graph* pG, int n){
	pG->n = n;
	pG->m = 0;
	for(int i=0; i<=n;i++){
		for(int j=0; j<=n;j++){
			pG->A[i][j] = 0;
		}
	}
}

void add_edge(Graph* pG, int u, int v){
	pG->A[u][v] = 1;
	if(u!=v){
		pG->A[v][u] = 1;
	}
	
	pG->m++;
}

int adj(Graph* pG, int u, int v){
	return pG->A[u][v] > 0;
}

//----------------SCC--------------
int num[MAX_SIZE];
int min_num[MAX_SIZE];
int on_stack[MAX_SIZE];
Stack S; 
int k;

void SCC(Graph* pG, int u){
	//1. Danh dau u dua vao ngan xep
	num[u] = k, min_num[u] = k;
	k++;
	push(&S,u);
	on_stack[u] = 1;
	
	//2. xet cac dinh ke cua u
	for(int v=1; v<=pG->n; v++){
		if(adj(pG,u,v)){
			//Chua duyet
			if(num[v] < 0){
				SCC(pG,v);
//				min_num[v] = min_num[v] < min_num[u] ? min_num[v] : num[u];
				if(min_num[v] < min_num[u]){
					min_num[u] = min_num[v];
				}
			}else if(on_stack[v]){
//				min_num[v] = min_num[v] < num[u] ? min_num[v] : num[u];
				if(num[v] < min_num[u]){
					min_num[u] = num[v];
				}
			}
		}
	}
	
	//3. Kiem tra co la lien thong manh
	if(num[u] == min_num[u]){
		int w;
		do{
			w = top(&S);
			pop(&S);
			on_stack[w] = 0;
		}while(w!=u);
	}
}

int main(){
	Graph G;
	int n, m;
	scanf("%d%d", &n,&m);
	
	init_graph(&G,n);
	
	for(int i = 0; i < m; i++){
		int u,v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);	
	}
	
	for(int i = 1 ; i <= G.n; i++){
		num[i] = -1;
	}
	
	k = 1;
	init_stack(&S);
	
	for(int u = 1; u <=  G.n; u++){
		if(num[u] == -1){
			SCC(&G,u);
		}
	}
	
	for(int i = 1; i <= G.n; i++){
		printf("%d %d\n", num[i], min_num[i]);
	}
	
}
