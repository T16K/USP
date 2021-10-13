#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct aresta {
    int v1;
    int v2;
    int custo;
    struct aresta* prox;
} NO;

typedef struct {
    int v1;
    int v2;
    int custo;
} NO_registro;

void adicionar_final(NO** lista, NO* novo) {
    if (*lista) {
	NO* andar = *lista;
	while (andar->prox) {
	    andar = andar ->prox;
	}
	andar->prox = novo;
    } else {
	*lista = novo;
    }
}

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

int main () {

    FILE *arquivo;
    arquivo = fopen ("lista.txt", "rb");

    NO_registro entrada;
    NO* comeco = NULL;

    while (0 != fread (&entrada, sizeof (NO_registro), 1, arquivo)) { 
	NO* novo = criar_NO();
	instanciar_NO(entrada, novo);
	adicionar_final(&comeco, novo);
    }

    fclose (arquivo);
    return 0;
}
