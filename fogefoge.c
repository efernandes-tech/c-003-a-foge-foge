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
    // O "return" sozinho geralmente é usado para finalizar metodos void.
	if (!ehdirecao(direcao))
        return;
	
	int proximox = heroi.x;
    int proximoy = heroi.y;

	// Determina o movimento do pj.
    switch(direcao) {
        case 'a':
            proximoy--;
            break;
        case 'w':
            proximox--;
            break;
        case 's':
            proximox++;
            break;
        case 'd':
            proximoy++;
            break;
    }
	    
    // Verifica se vai sair da matriz e nao deixa.
    if (!ehvalida(&m, proximox, proximoy))
    	return;

	// Verifica se a proxima posicao é vazia.
	if (!ehvazia(&m, proximox, proximoy))
    	return; 
    	
    // Aplica o movimento.
    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;
}

int ehdirecao(char direcao) {
	// Só aceita estas teclas.
    return
        direcao == 'a' || 
        direcao == 'w' ||
        direcao == 's' ||
        direcao == 'd';
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
