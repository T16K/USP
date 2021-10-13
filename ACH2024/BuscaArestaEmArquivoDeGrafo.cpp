TÇÙ
#2283

HTsuyoshi — Hoje às 11:35
ate la da pra terminar a tarefa de aed
krl os kra n aceita
TÇÙ — Hoje às 11:35
so de tarde
ent ta safe
HTsuyoshi — Hoje às 11:35
GODD
TÇÙ — Hoje às 11:35
nice
TÇÙ — Hoje às 11:56
era a primeira do dia
n conta
HTsuyoshi — Hoje às 11:56
heuhueu
TÇÙ — Hoje às 11:56
volto mais tarde
HTsuyoshi — Hoje às 11:56
bom almoço
safee
vou de AED jaja mando
TÇÙ — Hoje às 11:56
nice
boa sorte ae bro
HTsuyoshi — Hoje às 11:56
duess
TÇÙ — Hoje às 13:15
opa to on
HTsuyoshi — Hoje às 13:20
OPA
mds  eu n vi
tocolando
TÇÙ — Hoje às 13:21
hm?
ta safe
HTsuyoshi — Hoje às 13:21
acabei a tarefa so preciso converter
acho q ss
posso converter dps
TÇÙ — Hoje às 13:21
opa nice
HTsuyoshi — Hoje às 13:21
ou terminar agr tu escolhe hue
TÇÙ — Hoje às 13:21
mas faz tranquilo
eu to de boa
tem bastante tempo
HTsuyoshi — Hoje às 13:21
safe
heuieh
to colando ent
TÇÙ — Hoje às 13:22
calma
onde?
HTsuyoshi — Hoje às 13:22
opa
lolzao
to aq na liga heuhe
tao vendo videdo da E3 acho
TÇÙ — Hoje às 13:22
man pode terminar tranquilo
ta safe
eu espero
HTsuyoshi — Hoje às 13:22
opa
safe
ent ja jacolo
to aq na sala
TÇÙ — Hoje às 13:23
hahaha
safe
HTsuyoshi — Hoje às 13:23
hueuh
HTsuyoshi — Hoje às 14:06
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
... (27 linhas)
Recolher
tarefa_nro_8.cpp
3 KB
acho q ta safe
TÇÙ — Hoje às 14:06
opa arigatso
?
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

    while (0 != fread (&entrada, sizeof (NO_registro), 1, arquivo)) { 
	NO* novo = criar_NO();
	instanciar_NO(entrada, novo);
	adicionar_final(&comeco, novo);
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
tarefa_nro_8.cpp
3 KB
