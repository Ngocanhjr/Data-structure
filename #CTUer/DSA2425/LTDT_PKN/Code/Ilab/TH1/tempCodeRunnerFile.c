void add_edge(Graph* pG, int u, int v) {
    if (u > pG->n && v > pG->n && u < 1 && v < 1) {
        pG->edges[pG->m].u = u;
        pG->edges[pG->m].v = v;
        pG->m++;
    }
}