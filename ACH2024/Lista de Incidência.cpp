#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int TIPOPESO;

typedef struct adjacencia{
	int vertice;
	TIPOPESO peso;
	struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice{
	ADJACENCIA *cab;
} VERTICE;

typedef struct grafo{
	int vertices;
	int arestas;
 	VERTICE *adj;
} GRAFO;

GRAFO *criaGrafo(int v) {
	GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
	g->vertices = v;
	g->arestas = 0;
	g->adj = (VERTICE *) malloc(v*sizeof(VERTICE));
	int i;
	for(i=0; i<v; i++) g->adj[i].cab = NULL;
	return(g);
}

ADJACENCIA *criaAdj(int v, int peso) {
	ADJACENCIA *temp = (ADJACENCIA *) malloc(sizeof(ADJACENCIA));
	temp->vertice = v;
	temp->peso = peso;
	temp->prox = NULL;
	return(temp);
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
	if(!gr) return(false);
	if((vf<0) || (vi >= gr->vertices)) return(false);
	if((vi<0) || (vi >= gr->vertices)) return(false);
	ADJACENCIA *novo = criaAdj(vf,p);
	novo->prox = gr->adj[vi].cab;;
	gr->adj[vi].cab = novo;
	gr->arestas++;
	return(true);
} 

void adjacencia2incidencia(VERTICE* g, int n) {
    ADJACENCIA* incidencia[n][n];
    ADJACENCIA* temp;
    ADJACENCIA* seg;
    int i=0;
    int j=0;

    while (i < n) {
        j=0;
        while (j < n) {
            incidencia[i][j] = NULL;
            j++;
        }
        i++;
    }

    i=0;
    while (i < n) {
        if(g[i].cab) {
            temp = g[i].cab;
            while(temp) {;
                incidencia[temp->vertice-1][i] = temp;
                incidencia[temp->vertice-1][i]->vertice = i;
                if(temp->prox)
                    seg = temp->prox;
                else
                    seg = NULL;
                temp->prox = NULL;
                temp = seg;
            }
            g[i].cab = NULL;
        }
        i++;
    }

    j=0;
    while (j < n) {
        i=0;
        while (i < n) {
            if (incidencia[j][i]) {
                    if (!g[j].cab) {
                        g[j].cab = incidencia[j][i];
                     } else {
                        temp = g[j].cab;
                        if (temp->prox) {
                            while (temp->prox)
                                temp = temp->prox;
                        }
                        temp->prox = incidencia[j][i];
                    }
                }
            ++i;
        }
        ++j;
    }
}

void imprime(GRAFO *gr){
	printf("Vértices: %d. Arestas: %d. \n", gr->vertices,gr->arestas);
	int i;
	for(i=0; i<gr->vertices; i++){
		printf("v%d:  ",i);
		ADJACENCIA *ad = gr->adj[i].cab;
		while(ad){
			printf("v%d(%d) ",ad->vertice, ad->peso);
			ad = ad->prox;
		}
		printf("\n");
	}
}

void segundalista(VERTICE* vetor, int array[], int n, int size) {
	ADJACENCIA *temp = criaAdj(array[0], 0);
	vetor[n].cab = temp;
	for(int i=1; i<size; i++){
		ADJACENCIA * novo = criaAdj(array[i], 0);
		temp->prox = novo;
		temp = temp->prox;
	}
}

int main(void){
		
	GRAFO * gr = criaGrafo(5);
	

	criaAresta(gr,0,1,2);
	criaAresta(gr,1,2,4);
	criaAresta(gr,2,0,12);
	criaAresta(gr,2,4,40);
	criaAresta(gr,3,1,3);
	criaAresta(gr,4,3,8);

	imprime(gr);	
	
	printf("\n");		
			
	int lista0[] = {2}; 
	segundalista(gr->adj, lista0, 0, 1);
	int lista1[] = {3}; 
	segundalista(gr->adj, lista1, 1, 1);
	int lista2[] = {1, 5}; 
	segundalista(gr->adj, lista2, 2, 2);
	int lista3[] = {2}; 
	segundalista(gr->adj, lista3, 3, 1);
	int lista4[] = {4}; 
	segundalista(gr->adj, lista4, 4, 1);
	
	adjacencia2incidencia(gr->adj, 5);
	
	imprime(gr);
}

