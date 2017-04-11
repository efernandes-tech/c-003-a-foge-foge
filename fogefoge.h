// "if" em tempo de compilacao, assim evita incluir novamente um header.
#ifndef _FOGEFOGE_H_
	#define _FOGEFOGE_H_
	
	// Constantes.
	#define CIMA 'w'
	#define BAIXO 's'
	#define DIREITA 'd'
	#define ESQUERDA 'a'
	#define BOMBA 'b'
	
	int acabou();
	void move(char direcao);
	int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);
	int ehdirecao(char direcao);
	void fantasmas();
	void explodepilula();
	void explodepilula2(int x, int y, int somax, int somay, int qtd);
#endif
