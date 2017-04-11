#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

// struct mapa m;
MAPA m;
POSICAO heroi;

int tempilula = 0;

int acabou() {
    POSICAO pos;

    int perdeu = !encontramapa(&m, &pos, HEROI);
    int ganhou = !encontramapa(&m, &pos, FANTASMA);

    return ganhou || perdeu;
}

int ehdirecao(char direcao) {
	// Só aceita estas teclas.
    return
        direcao == ESQUERDA || 
        direcao == CIMA ||
        direcao == BAIXO ||
        direcao == DIREITA;
}

void move(char direcao) {
    // O "return" sozinho geralmente é usado para finalizar metodos void.
	if (!ehdirecao(direcao))
        return;
	
	int proximox = heroi.x;
    int proximoy = heroi.y;

	// Determina o movimento do pj.
    switch(direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }
	    
    
    if (!podeandar(&m, HEROI, proximox, proximoy))
        return;
        
    if (ehpersonagem(&m, PILULA, proximox, proximoy)) {
        tempilula = 1;
    }
    	
    // Aplica o movimento.
    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;
}

int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino) {
    int opcoes[4][2] = {
        { xatual   , yatual+1 },
        { xatual+1 , yatual   },
        { xatual   , yatual-1 },
        { xatual-1 , yatual   }
    };
    
    srand(time(0));
    int i;
    for(i = 0; i < 10; i++) {
        int posicao = rand() % 4;
        
        if (podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }

    return 0;
}

void fantasmas() {
	MAPA copia;

    copiamapa(&copia, &m);
    
	int i, j;
    for(i = 0; i < copia.linhas; i++) {
        for(j = 0; j < copia.colunas; j++) {
            if (copia.matriz[i][j] == FANTASMA) {
            	int xdestino;
                int ydestino;

                int encontrou = praondefantasmavai(i, j, &xdestino, &ydestino);

                if (encontrou) {
                    andanomapa(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }

    liberamapa(&copia);
}

void explodepilula() {

}

int main() {
	lemapa(&m);
	
	encontramapa(&m, &heroi, HEROI);
	
	do {
        printf("Pilula: %s\n", (tempilula ? "SIM" : "NAO"));
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        if (ehdirecao(comando)) move(comando);
    	if (comando == BOMBA) explodepilula();
        
        fantasmas();
    } while (!acabou());
	
	liberamapa(&m);
}
