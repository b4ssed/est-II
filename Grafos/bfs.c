void buscaLargura(tipo_grafo *g, int ini, int visit) {
    int i, cor[visit], dist[visit], ant[visit];
    fila q;
	inicializa(&q);
	enfilera(&q, ini); 
	for(i = 0; i < visit; i++) {
	    cor[i] = 0;
	}
    while(!filaVazia(q)) {
        int u = desenfilera(&q);
        tipo_no *p = g->VETOR_list_adj[u].prox;
        while(p) {
            if (cor[p->vertice] == 0) {
        		cor[p->vertice] = 1;
        		dist[p->vertice] = dist[u]+1;
        		ant[p->vertice] = u;
        		enfilera(&q, p->vertice);
        		p = p->prox;
            } else {
                p = p->prox;
            }
        }
    cor[u] = 2;
    }
}