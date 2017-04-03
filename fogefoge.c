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

int acabou() {
    return 0;
}

void imprimemapa() {
	int i;
    for(i = 0; i < linhas; i++) {
        printf("%s\n", mapa[i]);
    }
}

void move(char direcao) {
    int x;
    int y;
    int i, j;
    
    // Determina a posicao atual do pj.
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            if (mapa[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }
    
    // Determina o movimento do pj.
    switch(direcao) {
        case 'a': // esq
            mapa[x][y-1] = '@';
            break;
        case 'w': // cima
            mapa[x-1][y] = '@';
            break;
        case 's': // baixo
            mapa[x+1][y] = '@';
            break;
        case 'd': // dir
            mapa[x][y+1] = '@';
            break;
    }

	// Onde ele estava fica vazio.
    mapa[x][y] = '.';
}

int main() {
	lemapa();
	
	do {
        imprimemapa();

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());
	
	liberamapa();
}
