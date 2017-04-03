#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

// struct mapa m;
MAPA m;

int acabou() {
    return 0;
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
	lemapa(&m);
	
	do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        move(comando);
    } while (!acabou());
	
	liberamapa(&m);
}
