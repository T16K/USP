#include <stdio.h>
#include <stdlib.h>

typedef struct aresta {
	struct aresta* prox;
	int v1;
	int v2;
	int custo;
} NO;

typedef struct {
	NO* inicio;
} VERTICE;

typedef struct {
	int v1;
	int v2;
	int custo;
} NO_registro;


NO* criar_NO() {
	NO* novo = (NO*)malloc(sizeof(NO));
	novo->v1 = 0;
	novo->v2 = 0;
	novo->custo = 0;
	novo->prox = NULL;
	return novo;
}

void instanciar_NO(NO_registro registro, NO* instanciar) {
	instanciar->v1 = registro.v1;
	instanciar->v2 = registro.v2;
	instanciar->custo = registro.custo;
}

void instanciar_NO_1(NO* registro, NO* instanciar) {
	instanciar->v1 = registro->v1;
	instanciar->v2 = registro->v2;
	instanciar->custo = registro->custo;
}

void adicionar_final(NO** lista, NO* novo) {
	if(*lista) {
		NO* andar = *lista;
		while(andar->prox) {
			andar = andar ->prox;
		}
		andar->prox = novo;
	} else {
		*lista = novo;
	}
}

void instanciar_grafo(VERTICE* grafo, NO* registros) {
	NO* temp = registros;
	if(temp) {
		NO* novo = criar_NO();
		instanciar_NO_1(temp, novo);
		adicionar_final(&grafo[temp->v1].inicio, novo);
		if(temp->prox) {
			temp = temp->prox;
			while(temp->prox) {
				novo = criar_NO ();
				instanciar_NO_1(temp, novo);
				adicionar_final(&grafo[temp->v1].inicio, novo);

				if(temp->prox)
					temp = temp->prox;
			}
			novo = criar_NO ();
			instanciar_NO_1(temp, novo);
			adicionar_final(&grafo[temp->v1].inicio, novo);
		}
	}
}

void profundidade(VERTICE* grafo, int i, int d, int custo_local, int* custo_saida) {
	if (*custo_saida != -1) 
		return;
	if (i == d) {
		*custo_saida = custo_local;
		return;
	}
	NO* p = grafo[i].inicio;
	if (p) {
		profundidade(grafo, p->v2, d, custo_local + p->custo, custo_saida);
		if (p->prox) {
			p = p->prox;
			while (p->prox) {
				profundidade(grafo, p->v2, d, custo_local + p->custo, custo_saida);
				p = p->prox;
			}
		}
	}
}

int main() {

	FILE *arquivo = fopen ("lista.txt", "rb");

	NO_registro entrada;
	NO* comeco = NULL;
	REGISTRO tabela_indice[100];
	int i = 0;

	while (0 != fread (&entrada, sizeof (NO_registro), 1, arquivo)) { 
		tabela_indice[i].v1 = entrada.v1
		tabela_indice[i].v2 = entrada.v2
		tabela_indice[i].custo = entrada.custo

		NO* novo = criar_NO();
		instanciar_NO(entrada, novo);
		adicionar_final(&comeco, novo);
		i++;
	}

	int n = 10;
	VERTICE* grafo = (VERTICE*) malloc(sizeof(VERTICE)*n);
	for (int i = 0; i < n; i++)
		grafo[i].inicio = NULL;

	instanciar_grafo (grafo, comeco);

	int* saida = (int*) malloc (sizeof (int));
	*saida = -1;
	int i = 0, d = 2;
	profundidade(grafo, i, d, 0, saida);
	printf("%d\n", *saida);

	fclose(arquivo);
	return 0;
}
