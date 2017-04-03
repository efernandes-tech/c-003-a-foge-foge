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
	// Só aceita estas teclas.
	if (
        direcao != 'a' && 
        direcao != 'w' &&
        direcao != 's' &&
        direcao != 'd'
    ) return;
    // O "return" sozinho geralmente é usado para terminar metodos void.
	
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
    if (proximox >= m.linhas) 
    	return;
	if (proximoy >= m.colunas) 
	    return;
	    
	// Verifica se a proxima posicao é vazia.
	if (m.matriz[proximox][proximoy] != '.') 
    	return;
    	
    // Aplica o movimento.
    m.matriz[proximox][proximoy] = '@';
	m.matriz[heroi.x][heroi.y] = '.';
	heroi.x = proximox;
	heroi.y = proximoy;
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
