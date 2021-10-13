#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

// 11857215 
char* nroUSP() {
    return("11857215");
}

// Gustavo Tsuyoshi Ariga 
char* nome() {
    return("Gustavo Tsuyoshi Ariga");
}

// Elemento da lista
typedef struct estr {
        int valor;
        struct estr* prox;
} NO;

// Funcoes auxiliares
void iniciaNO (int n, NO* p){
	p->valor = n;
	p->prox = NULL;
}

void adicionaElementoNO (int n, NO* p) {
	NO* novo;
	NO* ant;
	while(p) {
		ant = p;
		p = p->prox;
	}
	novo = (NO*) malloc(sizeof(NO));
 	novo->valor = n;
 	novo->prox = NULL;
	if(!ant) p->prox = novo;
 	else ant->prox = novo;
}

void mostraLista (NO* p) {
	while(p) {
		printf("[%d]", p->valor);
		p = p->prox;
	}
}

// Funcao principal
NO* uniao (NO* p1, NO* p2);
NO* uniao (NO* p1, NO* p2) {
	NO* resp;
	resp = NULL;
	
	// Pelo menos uma lista existe, inicia lista resp
	resp = (NO*) malloc(sizeof(NO));
	NO* aux = resp;	
	
	// Uma lista existe, inicia aux->valor
	NO* listaSobra = p2;
	if(!p1 ^ !p2) {
		if(p1) listaSobra = p1;
		aux->valor = listaSobra->valor;
		resp->prox = NULL;
	}	
		
	// As duas listas existem, inicia lista resp
	if(p1 && p2)  {
		if(p1->valor > p2->valor) resp->valor = p1->valor;
		else resp->valor = p2->valor;
		resp->prox = NULL;
		
	// Coloca os elementos nas duas listas
		while (p1 && p2) {
			if(p1->valor < p2->valor){
				if(aux->valor != p1->valor) {
					adicionaElementoNO(p1->valor, resp);
					aux = aux->prox;
				}
				p1 = p1->prox;
			} 
			else {
				if(aux->valor != p2->valor) {
					adicionaElementoNO(p2->valor, resp);
					aux = aux->prox;
				}
				p2 = p2->prox;
			}
		}
		
	// Coloca lista de elementos proximos
	listaSobra = p2;
	if(p1) listaSobra = p1;
	}
	while (listaSobra) {
		if(aux->valor != listaSobra->valor) {
			adicionaElementoNO(listaSobra->valor, resp);
			aux = aux->prox;
		}
		listaSobra = listaSobra->prox;
	}
		while (listaSobra) {
		if(aux->valor != listaSobra->valor) {
			adicionaElementoNO(listaSobra->valor, resp);
			aux = aux->prox;
		}
		listaSobra = listaSobra->prox;
	}
		
	// Duas listas vazias
	if(!p1 && !p2) return resp;
	
	return resp;
}
	
int main() {
	NO* p1 = (NO*) malloc(sizeof(NO));
	NO* p2 = (NO*) malloc(sizeof(NO));
	
	// Inicia lista 1
	iniciaNO(1, p1);
	adicionaElementoNO(1, p1);
	adicionaElementoNO(2, p1);
	adicionaElementoNO(2, p1);
	adicionaElementoNO(3, p1);
	adicionaElementoNO(4, p1);
	adicionaElementoNO(4, p1);
	adicionaElementoNO(5, p1);
	adicionaElementoNO(6, p1);
	adicionaElementoNO(6, p1);
	adicionaElementoNO(7, p1);		

	// Inicia lista 2
	iniciaNO(1, p2);
	adicionaElementoNO(1, p2);
	adicionaElementoNO(3, p2);
	adicionaElementoNO(5, p2);
	adicionaElementoNO(7, p2);
	adicionaElementoNO(9, p2);
	adicionaElementoNO(11, p2);
	adicionaElementoNO(13, p2);
	adicionaElementoNO(15, p2);
	adicionaElementoNO(17, p2);
	adicionaElementoNO(51, p2);
	
	// Exibe as listas
	printf("lista 1:");
	mostraLista(p1);
	printf("\n");
	printf("lista 2:");
	mostraLista(p2);
	printf("\n");
	
	// Testa duas listas não vazias
	NO* padrao = uniao(p1,p2);
	printf("lista 1 e 2:");
	mostraLista(padrao);
	printf("\n");
	
	// Testa uma lista vazia 
	NO* listaVazia = NULL;
	listaVazia = uniao(listaVazia, p1);
	printf("lista 1 e lista vazia:");
	mostraLista(listaVazia);
	printf("\n");
	listaVazia = NULL;
	listaVazia = uniao(listaVazia, p2);
	printf("lista 2 e lista vazia:");
	mostraLista(listaVazia);
	printf("\n");
	
	// Testa duas listas vazias
	NO* listasVazias = NULL;
	listasVazias = uniao(listasVazias, listasVazias);
	printf("duas listas vazias:");
	mostraLista(listasVazias);
	printf("\n");
}
