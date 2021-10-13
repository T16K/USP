//--------------------------------------------------------------
// NOME : Gustavo Tsuyoshi Ariga
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
int nroUSP() { return 11857215; }

//-------------------------------------------

// nos das listas de adjacencias
typedef struct adj {
  int v;
  struct adj *prox;
} NO;

// vertices
typedef struct {
  NO *inicio;
} VERTICE;

// funcao principal
NO *caminhos_max_d(VERTICE *g, int n, int x, int y, int d);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------

void colocar_na_lista(NO **vetor, int v) {
  NO *elemento = (NO *)malloc(sizeof(NO));
  elemento->prox = NULL;
  elemento->v = v;
  NO *andar = *vetor;
  if (andar) {
    while (andar->prox)
      andar = andar->prox;
    andar->prox = elemento;
  } else {
    *vetor = elemento;
  }
}

void remover_ultimo(NO **vetor) {
  NO *remover = (*vetor);
  NO *ultimo = NULL;
  if (remover) {
    while (remover->prox) {
      ultimo = remover;
      remover = remover->prox;
    }
    if (ultimo)
      ultimo->prox = NULL;
    free(remover);
  }
}

int verificar_caminho_simples(NO **lista_temp, int v) {
  NO *andar = *lista_temp;
  while (andar) {
    if (andar->v == v)
      return 1;
    andar = andar->prox;
  }
  return 0;
}

int verificar_repitido(NO **lista_temp, NO **saida, int distancia,
                       int destino) {
  NO *saida_local = *saida;
  NO *lista_temp_local = *lista_temp;
  int elementos_iguais, valor;

  if (!lista_temp_local)
    return 1;

  valor = lista_temp_local->v;

  while (saida_local) {
    lista_temp_local = *lista_temp;
    while (saida_local->v == lista_temp_local->v) {
      elementos_iguais = 0;

      while (saida_local && lista_temp_local) {

        if (lista_temp_local->v == saida_local->v)
          elementos_iguais++;

        if (saida_local->v == destino)
          break;

        saida_local = saida_local->prox;
        lista_temp_local = lista_temp_local->prox;
      }

      if (elementos_iguais >= distancia + 1)
        return 1;

      if (saida_local && lista_temp_local) {
        if (!saida_local->prox || !lista_temp_local->prox)
          return 0;
        saida_local = saida_local->prox;
        lista_temp_local = lista_temp_local->prox;
      } else
        return 0;
    }

    if (saida_local)
      saida_local = saida_local->prox;
  }
  return 0;
}

void adicionar_lista(NO **lista_temp, NO **saida) {
  NO *saida_local = *saida;
  NO *lista_temp_local = *lista_temp;
  while (lista_temp_local->prox) {
    colocar_na_lista(&saida_local, lista_temp_local->v);
    lista_temp_local = lista_temp_local->prox;
  }
  colocar_na_lista(&saida_local, lista_temp_local->v);
}

void profundidade(VERTICE *g, NO **lista_temp, NO **saida, int n, int x, int y, int d,
                  int d_contador) {
  if (x < 1 || x > n)
    return;
  NO *lista_temp_local = *lista_temp;
  NO *saida_local = *saida;
  NO *entrar = g[x].inicio;

  if (verificar_caminho_simples(&lista_temp_local, x) || d_contador > d)
    return;

  colocar_na_lista(&lista_temp_local, x);

  if (x == y) {
    if (!verificar_repitido(&lista_temp_local, &saida_local, d_contador, y)) {
      adicionar_lista(&lista_temp_local, &saida_local);
      remover_ultimo(&lista_temp_local);
    }
    return;
  }

  while (entrar) {
    profundidade(g, &lista_temp_local, &saida_local, n, entrar->v, y, d,
                 d_contador + 1);
    if (entrar->prox)
      entrar = entrar->prox;
    else
      break;
  }

  remover_ultimo(&lista_temp_local);
}

NO *caminhos_max_d(VERTICE *g, int n, int x, int y, int d) {
  if (x < 1 || x > n || y < 1 || y > n)
    return NULL;

  NO *lista_temp = NULL;
  NO *saida = (NO *)malloc(sizeof(NO));
  saida->prox = NULL;
  saida->v = 0;

  profundidade(g, &lista_temp, &saida, n, x, y, d, 0);
  lista_temp = saida;
  saida = saida->prox;
  free(lista_temp);
  return saida;
}
