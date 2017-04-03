#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

// struct mapa m;
MAPA m;

void lemapa() {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("Erro na leitura do mapa.");
        exit(1);
    }

    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));
    alocamapa();

	int i;
    for(i = 0; i < m.linhas; i++) {
        fscanf(f, "%s", m.matriz[i]);
    }

    fclose(f);
}

void alocamapa() {
	// O "malloc()" aloca uma quantidade de bytes e devolve um ponteiro.
	// O "sizeof()" retorna a qtd de bytes para o tipo char nessa maquina.
	// O "m.matriz" é um ponteiro de ponteiros, e esta alocando o tamanha de um
	// ponteiro de char "sizeof(char*)".
	m.matriz = malloc(sizeof(char*) * m.linhas);

	int i;
	for(i = 0; i < m.linhas; i++) {
		// Cada ponteiro esta alocando o tamanha de um char "sizeof(char)".
		m.matriz[i] = malloc(sizeof(char) * m.colunas + 1);
	}
}

void liberamapa() {
	int i;
    for(i = 0; i < m.linhas; i++) {
        free(m.matriz[i]);
    }
    // Cada "malloc()" deve ter um free, se não ninguem + usa o espaço alocado.
    free(m.matriz);
}

int acabou() {
    return 0;
}

void imprimemapa() {
	int i;
    for(i = 0; i < m.linhas; i++) {
        printf("%s\n", m.matriz[i]);
    }
}

void move(char direcao) {
    int x;
    int y;
    int i, j;
    
    // Determina a posicao atual do pj.
    for(i = 0; i < m.linhas; i++) {
        for(j = 0; j < m.colunas; j++) {
            if (m.matriz[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }
    
    // Determina o movimento do pj.
    switch(direcao) {
        case 'a': // esq
            m.matriz[x][y-1] = '@';
            break;
        case 'w': // cima
            m.matriz[x-1][y] = '@';
            break;
        case 's': // baixo
            m.matriz[x+1][y] = '@';
            break;
        case 'd': // dir
            m.matriz[x][y+1] = '@';
            break;
    }

	// Onde ele estava fica vazio.
    m.matriz[x][y] = '.';
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
