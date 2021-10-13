#include <stdio.h>

#define MAX 100

struct info_aluno {
    char nrousp[10];
    char nome[20];
    int idade;
};

int main() {
    int i;
    int proximo;
    FILE *arquivo;
    struct info_aluno vetor_alunos[MAX];

    if((arquivo=fopen("variavel.txt", "r"))==NULL)
	printf("Arquivo nao encontrado\n");
    else {
	i = 0;
	do {
	    fscanf(arquivo, "%[^/]%*c", vetor_alunos[i].nrousp);
	    fscanf(arquivo, "%[^/]%*c", vetor_alunos[i].nome);
	    proximo = fscanf(arquivo, "%d", &vetor_alunos[i].idade);
	    fflush(arquivo);
	    if(proximo >= 1) i++;
	} while(proximo >= 1);
	fclose(arquivo);
    }

    arquivo = fopen("fixo.txt", "w");
	
    fprintf(arquivo, "\n--------------------------------------\n");
    fprintf(arquivo, "Ha %d alunos cadastrados.\n", i);
    for(int j = 0; j < i; j++) {
	fprintf(arquivo, "\n%7s ", vetor_alunos[j].nrousp);
	fprintf(arquivo, "%20s ", vetor_alunos[j].nome);
	fprintf(arquivo, "%d", vetor_alunos[j].idade);
    }
    fprintf(arquivo, "\n--------------------------------------\n");

    fclose(arquivo);
    return 0;
}
