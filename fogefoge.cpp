#include <stdio.h>
#include <stdlib.h>

int main() {
	// Matriz de 5 linhas e 10 colunas, e uma coluna extra para o enter.
	char mapa[5][10+1];
	
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0) {
	    printf("Erro na leitura do mapa.");
	    exit(1);
	}
}