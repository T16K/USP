#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11857215");
}


// ######### ESCREVA SEU NOME AQUI
const char* nome() {
    return("Gustavo Tsuyoshi Ariga");
}

// elemento da pilha
typedef struct estrutura {
	struct estrutura *prox;
	int tipo; // 1=char e 2=float
	union {
		char simbolo;
        	float valor;
	};
} NO;

// funcoes auxiliares
typedef struct {
	NO* topo;
} PDINAM;

// Inicialização da pilha dinâmica
void inicializarPdinam (PDINAM* p) {
	p->topo = NULL;
}

// Inserir item no topo
void push (int ch, PDINAM* p) {
	NO* novo = (NO*) malloc(sizeof(NO));
	if (ch < '0' || ch > '9') {
 		novo->tipo = 1;
		novo->simbolo = ch;
	} 
	else {	
		novo->tipo = 2;
 		novo->valor = ch-48;
	}
	novo->prox = p->topo;
	p->topo = novo;
}

void pushAux (float ch, PDINAM* p) {
	NO* novo = (NO*) malloc(sizeof(NO));
	novo->tipo = 2;
 	novo->valor = ch;
	novo->prox = p->topo;
	p->topo = novo;
}

// Retirar a chave do topo ou -1
float pop (PDINAM* p) {
	NO* aux;
	float ch;
	if (!p->topo) return(-1);
	aux = p->topo;
	if (p->topo->tipo == 1) ch = aux->simbolo;
	else ch = aux->valor;	
	p->topo = p->topo->prox;
	free (aux);
	return (ch);
}


// funcao principal (retorna float e int)
float calcular (char* expressao, int* codigo);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
float calcular (char* expressao, int* codigo) {

	float resp = 0.0;
	*codigo = 1;

	// seu codigo AQUI
	PDINAM pilha;
	inicializarPdinam (&pilha);
	
	int i=0;
	while (expressao[i] != 0) {
		push (expressao[i], &pilha);
		if (expressao[i] == ')') {
			pop (&pilha);
			float numero_2 = pop (&pilha), resultado;
			char simbol_operacao = pop (&pilha);
			float numero_1 = pop (&pilha);
			if(simbol_operacao == '+') resultado = numero_1+numero_2;
			else if(simbol_operacao == '-') resultado = numero_1-numero_2;
			else if(simbol_operacao == '*') resultado = numero_1*numero_2;
			else if(simbol_operacao == '/') resultado = numero_1/numero_2;
			else {
				*codigo = -1;
				return 0;
			}
			if (numero_2 == 0 && simbol_operacao == '/') {
				*codigo = 0;
				return 0;
			}
			char parenteses = pop (&pilha);
			if(parenteses != '(') {
				*codigo = -1;
				return 0;
			}
			pushAux (resultado, &pilha);
		}
		i++;
	}
	resp = pop (&pilha);
	if (*codigo != 0 && pilha.topo) *codigo = -1;
	return resp;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {
	
	// o EP sera testado com chamadas deste tipo

	char exp[200];
	strcpy(exp, "(7*5)");

	int codigo;

	float resp = calcular(exp,&codigo);
	
	
}

// por favor nao inclua nenhum código abaixo da função main()
