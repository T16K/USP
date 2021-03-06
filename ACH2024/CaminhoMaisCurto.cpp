void instanciarFila(FILA* f) {
        f->inicio= NULL;
        f->fim = NULL;
}

int excluirDaFila(FILA* f) {
        if (f->inicio==NULL) return false;
        REGISTRO reg = f->inicio->reg;
        int aux = reg.chave;
        PONT apagar = f->inicio;
        f->inicio= f->inicio->prox;
        free(apagar);
        if (f->inicio==NULL) f->fim = NULL;
        return aux;
}

bool inserirNaFila(FILA* f, int reg) {
        PONT novo = (PONT)malloc(sizeof(ELEMENTO));
        REGISTRO* aux = (REGISTRO*)malloc(sizeof(REGISTRO*));
        aux->chave = reg;
        novo->reg = *aux;
        novo->prox = NULL;
        if (f->inicio==NULL) f->inicio= novo;
        else f->fim->prox = novo;
        f->fim = novo;
        return true;
}

int custoChaveMaisProxima(VERTICE* g, int i) {
        int custo;
        FILA f;
        instanciarFila(&f);
        g[i].flag = 1;
        inserirNaFila(&f, i);

        while (f.inicio) {
                custo = 0;
                i = excluirDaFila(&f);
                NO* p = g[i].cab;
                while (p) {
                        custo += p->peso;
                        if(g[p->v].flag==0) {
                                g[p->v].flag = 1;
                                inserirNaFila(&f, p->v);
                        }
                        if (g[i].temChave==true) break;
                        p = p->prox;
                }
                if (g[i].temChave==true)break;
                g[i].flag = 2;
        }
        return custo;
}
