// foi utilizado como base o código do professor Norton T. Roman

void salasComChaves (VERTICE* g, int i, ADJACENCIA** lista) {
	g[i].flag = 1;
	if (g[i].temChave == 1) 
		if (*lista) {
			NO* tmp = (*lista);
			while (tmp -> prox)
				tmp = tmp -> prox;
			tmp -> prox = (ADJACENCIA*) malloc (sizeof (ADJACENCIA*));
			tmp -> prox -> v = g[i].cab -> v;
		} else {
			(*lista) = (ADJACENCIA*) malloc (sizeof (ADJACENCIA*));
			(*lista) -> v = g[i].cab -> v;
		}
	ADJACENCIA* p = g[i].cab;
	while (p) {
		if(g[p -> v].flag == 0)
			salasComChaves(g, p -> v, lista);
		p = p -> prox;
	}
	g[i].flag = 2;
}
