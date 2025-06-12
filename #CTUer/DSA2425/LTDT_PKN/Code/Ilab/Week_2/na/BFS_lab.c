#include <stdio.h>

#define MAX_SIZE 100
//#define MAX_N 100

typedef int ElementType;

//--------------Queue-------------
typedef struct {
	ElementType data[MAX_SIZE];
	int front, rear;
}Queue;

//init null queue
void make_null_queue(Queue* pQ){
	pQ->front = 0;
	pQ->rear = -1;
}

//check queue is empty
int is_empty(Queue* pQ){
	return pQ->front > pQ->rear;
}

//add element x to queue
void enqueue(Queue* pQ, ElementType x){
	pQ->rear++;
	pQ->data[pQ->rear] = x;
}

//delete element x from queue
void dequeue(Queue* pQ){
	pQ->front++;
}

//Retrieve first element in queue
ElementType front(Queue* pQ){
	return pQ->data[pQ->front];
}

//-----------Graph---------
typedef struct{
	int n,m;
	int A[MAX_SIZE][MAX_SIZE];
}Graph;

//init graph with n vertix
void init_graph(Graph* pG, ElementType n){
	pG->n = n;
	pG->m = 0;
	
	//cho toan bo ma tran ke bang 0
	for(int i = 0; i <= pG->n; i++){
		for(int j = 0; j <= pG->n; j++){
			pG->A[i][j] = 0;
		}
	}
}

//add edge (u,v) to graph
void add_edge(Graph* pG, ElementType u, ElementType v){
	pG->A[u][v] = 1;
//	pG->A[v][u] = 1; //co huong don
	pG->m++;
}

//Kiem tra u, v co ke nhau hay khong
int adjacent(Graph* pG, ElementType u, ElementType v){
	return pG->A[u][v] > 0;
}

void neighbours(Graph* pG, ElementType u){
	for(int v = 1; v <= pG->n; v++){
		if(adjacent(pG,u, v) > 0){ //u,v ke nhau
			//do something
		}
	}
}

ElementType degree(Graph* pG, ElementType u){
	int deg_u = 0;
	for(int v = 1; v <= pG->n; v++){
		deg_u += pG->A[u][v];
	}
	
	return deg_u + pG->A[u][u]; //truong hop co chua khuuyen
}

//----------------BFS------------
int visited[MAX_SIZE];

void BFS(Graph*pG, ElementType s){
	Queue Q;
	make_null_queue(&Q);
	enqueue(&Q,s);
	while(!is_empty(&Q)){
		ElementType u =  front(&Q);
		dequeue(&Q);
		
		if(visited[u] != 0){
			continue;
		}
		
		visited[u] = 1;
		printf("%d\n", u);
		for(int v = 1; v <= pG->n ; v++){
			if(adjacent(pG,u,v) > 0){
				enqueue(&Q,v);
			}
		}
			
		/* Ngâm cuu them
		if(!visited[u]){
			visited[u] = 1;
			printf("%d\n", u);
			for(int v = 1; v <= pG->n ; v++){
				if(adjacent(pG,u,v) > 0){
					enqueue(&Q,v);
				}
			}
		}
		*/
	}
}

#if 1
void BFS(Graph*pG, ElementType s){
	Queue Q;
	make_null_queue(&Q);
	enqueue(&Q,s);
	while(!is_empty(&Q)){
		ElementType u =  front(&Q);
		dequeue(&Q);
		
		/*
		if(visited[u] != 0){
			continue;
		}

		visited[u] = 1;
		printf("%d\n", u);
		for(int v = 1; v <= pG->n ; v++){
			if(adjacent(pG,u,v) > 0){
				enqueue(&Q,v);
			}
		}
		*/	
		if(!visited[u]){
			visited[u] = 1;
			printf("%d\n", u);
			for(int v = 1; v <= pG->n ; v++){
				if(adjacent(pG,u,v) > 0){
					enqueue(&Q,v);
				}
			}
		}
		
	}
}

#endif
int main(){
	Graph G;
	ElementType n, m;
	scanf("%d%d", &n, &m);
	
	init_graph(&G, n);
	
	for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    ElementType s; scanf("%d", &s);
    for (int u = 1; u <= G.n; u++) visited[u] = 0;
    BFS(&G, s);
}
