#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

// struct mapa m;
MAPA m;
POSICAO heroi;

int acabou() {
    return 0;
}

void move(char direcao) {
	m.matriz[heroi.x][heroi.y] = '.';
    // Determina o movimento do pj.
    switch(direcao) {
        case 'a': // esq
            m.matriz[heroi.x][heroi.y-1] = '@';
            heroi.y--;
            break;
        case 'w': // cima
            m.matriz[heroi.x-1][heroi.y] = '@';
            heroi.x--;
            break;
        case 's': // baixo
            m.matriz[heroi.x+1][heroi.y] = '@';
            heroi.x++;
            break;
        case 'd': // dir
            m.matriz[heroi.x][heroi.y+1] = '@';
            heroi.y++;
            break;
    }
}

int main() {
	lemapa(&m);
	
	encontramapa(&m, &heroi, '@');
	
	do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        move(comando);
    } while (!acabou());
	
	liberamapa(&m);
}
