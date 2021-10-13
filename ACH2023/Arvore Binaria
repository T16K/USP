// Gustavo Tsuyoshi Ariga
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11857215");
}


// no da arvore
typedef struct estr {
        int chave;
        struct estr *esq;
		struct estr *dir;
} NO;



void organizar(NO* *raiz);

// funcoes auxliares
void mostrarNivel (NO* raiz, int i, int j) {
	if( i == j) {
		printf("[%d] ", raiz->chave);
		return;
	}
	if (raiz->esq)
		mostrarNivel (raiz->esq, i + 1, j);
	if (raiz->dir)
		mostrarNivel (raiz->dir, i + 1, j);
}

void adicionar (NO* p, int ch) {
	while (p->esq || p->dir) {
		if (ch > p->chave)
			if (p->dir)
				p = p->dir;
			else break;
		if (ch < p->chave)
			if (p->esq)
				p = p->esq;
			else  break;
	}

	NO* novo;
	novo = NULL;
	novo = (NO*)(malloc (sizeof (NO*)));
	novo->esq = NULL;
	novo->dir = NULL;
	novo->chave = ch;

	if (ch > p->chave) p->dir = novo;
	else p->esq = novo;
}

NO* buscaDir (NO* raiz, NO* p) {
	if (p->esq) {
		if (p->esq->chave > p->chave || p->esq->chave < raiz->chave)
			return p->esq;
		if (buscaDir (raiz, p->esq))
			return buscaDir (raiz, p->esq);
	}
	if (p->dir) {
		if (p->dir->chave < p->chave || p->dir->chave < raiz->chave)
			return p->dir;
		if (buscaDir (raiz, p->dir))
			return buscaDir (raiz, p->dir);
	}
}

NO* buscaEsq (NO* raiz, NO* p) {
	if (p->esq) {
		if (p->esq->chave > p->chave || p->esq->chave > raiz->chave)
			return p->esq;
		if (buscaEsq (raiz, p->esq))
			return buscaEsq (raiz, p->esq);
	}
	if (p->dir) {
		if (p->dir->chave < p->chave || p->dir->chave > raiz->chave)
			return p->dir;
		if (buscaEsq (raiz, p->dir))
			return buscaEsq (raiz, p->dir);
	}
}

NO* procurarChave (NO* raiz, NO* p) {
	// checar a raiz
	if (p->esq)
		if (p->esq->chave > raiz->chave) {
			p = p->esq;
			if (p->esq)
				if (p->esq->chave > p->chave)
					return p;
			if (p->dir)
				if(p->dir->chave < p->chave)
					return p;
			if (!p->dir && !p->esq && raiz->dir)
				if (raiz->dir->chave < p->chave)
					return p;
			return raiz;
		}

	if (p->dir)
		if (p->dir->chave < raiz->chave) {
			p = p->dir;
			if (p->esq)
				if (p->esq->chave > p->chave)
					return p;
			if (p->dir)
				if(p->dir->chave < p->chave)
					return p;
			if (!p->dir && !p->esq && raiz->esq)
				if (raiz->esq->chave > p->chave)
					return p;
			return raiz;
		}

	// checar os dois filhos da raiz usando a raiz como comparativo
	if (p->dir)
		if (buscaDir (raiz, p->dir))
			return buscaDir (raiz, p->dir);
	if (p->esq)
		if (buscaEsq (raiz, p->esq))
			return buscaEsq (raiz, p->esq);
	return NULL;
}

NO* chaveSub (NO* p, NO* *pai) {
	NO* aux = *pai;
	if (p->dir)
		p = p->dir;
	while (p->dir) {
		p = p->dir;
		aux = aux->dir;
	}
	*pai = aux;
	return p;
}

NO* chaveSubDir (NO* p, NO* *pai) {
	NO* aux = *pai;
	if (p->esq)
		p = p->esq;
	while (p->esq) {
		p = p->esq;
		aux = aux->esq;
	}
	*pai = aux;
	return p;
}

//------------------------------------------
// O EP consiste em implementar esta funcao
//------------------------------------------

NO* paiErrado (NO* p, int ch) {
	if (p->chave == ch)
		return NULL;
	if (p->esq)	{
		if(p->esq->chave == ch)
			return p;
		if (paiErrado(p->esq, ch))
			return paiErrado(p->esq, ch);
	}
	if(p->dir) {
		if(p->dir->chave == ch)
			return p;
		if (paiErrado(p->dir, ch))
			return paiErrado(p->dir, ch);
	}
}

void organizar(NO* *raiz) {

	NO* p;
	p = *raiz;
	NO* chErrada;
	NO* paiErr;

	// procurar pela chave errada
	chErrada = procurarChave (p, p);
	if (!chErrada)
		return;

	// buscar pelo pai errado
	paiErr = paiErrado (p, chErrada->chave);

	// achar uma chave substituta se existir
	NO* subst;
	NO* pai;
	pai = chErrada->esq;
	int dir;
	dir = -1;

	if (chErrada->esq) {
		pai = chErrada->esq;
		subst = chaveSub (chErrada->esq, &pai);
		dir = 0;
	}
	else if (chErrada->dir) {
		pai = chErrada->dir;
		subst = chaveSubDir (chErrada->dir, &pai);
		dir = 1;
	}
	else
		subst = NULL;

	if (pai != subst && pai!= NULL)	{
		if (pai->esq == subst) {
			if(subst->esq)
				pai->esq = subst->esq;
			else
				pai->esq = NULL;
		}
		else
			if (pai->dir == subst) {
				if(subst->esq)
					pai->dir = subst->esq;
				else
					pai->dir = NULL;
		}
	}

	if (!paiErr)
		*raiz = subst;
	else
		if (paiErr->esq == chErrada) {
			if (subst != NULL)
				paiErr->esq = subst;
			else
				paiErr->esq = NULL;
		}
		else {
			if (subst != NULL)
				paiErr->dir = subst;
			else
				paiErr->dir = NULL;
		}

	if (chErrada->esq)
		if (chErrada->esq != subst)
			subst->esq = chErrada->esq;
	if (chErrada->dir)
	  	if (chErrada->dir != subst)
			subst->dir = chErrada->dir;

	free (chErrada);

	// sugestao: faca NO* p = *raiz para percorrer a arvore com p

	// nao use *raiz para mais nada, exceto quando precisar modificar este ponteiro (tipicamente quando exclur o no apontado por ele)


}

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------

int main() {
	
	// inicializar a arvore
	/*
	NO* arv = NULL;
	arv = (NO*)(malloc(sizeof(NO*)));
	arv->chave = 10;
	arv->esq = NULL;
	arv->dir = NULL;
	*/
	
	// arvore de 3 niveis
	/*
	adicionar(arv, 4);
	adicionar(arv, 16);
  	adicionar(arv, 3);
	adicionar(arv, 6);
	adicionar(arv, 15);
	adicionar(arv, 17);
	
	
	// erro na raiz
	// arv->chave = 100;
	// arv->chave = -100;

	// erro nos filhos da raiz
	// arv->esq->chave = 20;
	// arv->dir->chave = 0;

	// erro nas folhas
	// arv->esq->esq->chave = 12;
	// arv->dir->dir->chave = 1;
	// arv->esq->dir->chave = 12;
	// arv->dir->esq->chave = 0;
	*/


	// arvore de 2 niveis
	/*
	adicionar(arv, 4);
	adicionar(arv, 11);
	adicionar(arv, 3);
	*/
	// erro na raiz
	// arv->chave = 100;
	// arv->chave = -100;
	// arv->esq->chave = 100;

	// erro nas folhas
	// arv->dir->chave = 0;
	// arv->esq->chave = 400;
	// arv->esq->esq->chave = 411;


	// arvore de 1 galho

	// esq
	/*
	adicionar(arv, 4);
	adicionar(arv, 3);
	*/
	// dir
	/*
	adicionar(arv, 12);
	adicionar(arv, 13);
	*/
	// erro na raiz
	// arv->chave = 0;
	// arv->esq->chave = 0;
	// arv->chave = 20;
	// arv->dir->chave = 100;



	// mostrar a arvore

	/*
	mostrarNivel(arv, 1, 1);
	printf("\n");
	mostrarNivel(arv, 1, 2);
	printf("\n");
	mostrarNivel(arv, 1, 3);
	printf("\n");
	printf("\n");

	organizar(&arv);

	mostrarNivel(arv, 1, 1);
	printf("\n");
	mostrarNivel(arv, 1, 2);
	printf("\n");
	mostrarNivel(arv, 1, 3);
	printf("\n");
	*/


	// serao realizadas chamadas como esta:
	// organizar(&arv);

}

// por favor nao inclua nenhum código abaixo da função main()
