void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
    if (u != v)
        pG->A[v][u] += 1;
}

========================
void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] = 1;
    //pG->A[v][u] = 1;
    pG->m++;
}


void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
}


=============================
void add_edge(Graph *pG, int u, int v) {
    // if(u == V){
    // }
    // if(pG->A[u][v] == 1){
    //     pG->A[u][v]++;
    //     pG->A[v][u]++;
    // }else{
    //     pG->A[u][v] = 1;
    //     pG->A[v][u] = 1;
    // }
    
    if(u == v){
        pG->A[u][v]++;
    }else{
        pG->A[u][v]++;
        pG->A[v][u]++;
         
    }
    pG->m++;
}


void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
    if (u != v)
        pG->A[v][u] += 1;
}


===================================
void add_edge(Graph *pG, int u, int v) {
    // if(u == v){
    //     pG->A[u][v]++;
    // }else{
       
    //     // pG->A[v][u]++;
         
    // }
     pG->A[u][v]++;
    pG->m++;
}



void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
}


