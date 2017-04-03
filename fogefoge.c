#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

// Ponteiro de ponteiro.
char** mapa;
int linhas;
int colunas;

void lemapa() {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("Erro na leitura do mapa.");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    alocamapa();

	int i;
    for(i = 0; i < linhas; i++) {
        fscanf(f, "%s", mapa[i]);
    }

    fclose(f);
}

void alocamapa() {
	// O "malloc()" aloca uma quantidade de bytes e devolve um ponteiro.
	// O "sizeof()" retorna a qtd de bytes para o tipo char nessa maquina.
	// O "mapa" é um ponteiro de ponteiros, e esta alocando o tamanha de um
	// ponteiro de char "sizeof(char*)".
	mapa = malloc(sizeof(char*) * colunas);

	int i;
	for(i = 0; i < linhas; i++) {
		// Cada ponteiro esta alocando o tamanha de um char "sizeof(char)".
		mapa[i] = malloc(sizeof(char) * colunas + 1);
	}
}

void liberamapa() {
	int i;
    for(i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    // Cada "malloc()" deve ter um free, se não ninguem + usa o espaço alocado.
    free(mapa);
}

int main() {
	lemapa();
	
	int i;
	for(i = 0; i < 5; i++) {
	    printf("%s\n", mapa[i]);
	}
	
	liberamapa();
}
