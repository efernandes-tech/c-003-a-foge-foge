#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void lemapa(MAPA* m) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("Erro na leitura do mapa.");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    alocamapa(m);

	int i;
    for(i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

// Usado ponteiro no parametro pq se não a passagem é por copia.
void alocamapa(MAPA* m) {
	// O "malloc()" aloca uma quantidade de bytes e devolve um ponteiro.
	// O "sizeof()" retorna a qtd de bytes para o tipo char nessa maquina.
	// O "m.matriz" é um ponteiro de ponteiros, e esta alocando o tamanha de um
	// ponteiro de char "sizeof(char*)".
	// "(*m)." é igual a "m->"
	// (*m).matriz = malloc(sizeof(char*) * (*m).linhas);
	m->matriz = malloc(sizeof(char*) * m->linhas);

	int i;
	for(i = 0; i < m->linhas; i++) {
		// Cada ponteiro esta alocando o tamanha de um char "sizeof(char)".
		m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
	}
}

void liberamapa(MAPA* m) {
	int i;
    for(i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    // Cada "malloc()" deve ter um free, se não ninguem + usa o espaço alocado.
    free(m->matriz);
}

void imprimemapa(MAPA* m) {
	int i;
    for(i = 0; i < m->linhas; i++) {
        printf("%s\n", m->matriz[i]);
    }
}

void encontramapa(MAPA* m, POSICAO* p, char c) {
	int i, j;
    for(i = 0; i < m->linhas; i++) {
        for(j = 0; j < m->colunas; j++) {
            if (m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return;
            }
        }
    }
}

int ehvalida(MAPA* m, int x, int y) {
	// Verifica se vai sair da matriz e nao deixa.
    if (x >= m->linhas) 
        return 0;
    if (y >= m->colunas) 
        return 0;

    return 1;    
}

int ehvazia(MAPA* m, int x, int y) {
	// Verifica se a proxima posicao é vazia.
    return m->matriz[x][y] == VAZIO;
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino) {
    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;
}

void copiamapa(MAPA* destino, MAPA* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    alocamapa(destino);
    int i;
    for(i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

int podeandar(MAPA* m, int x, int y) {
    return 
        ehvalida(m, x, y) && 
        ehvazia(m, x, y);
}
