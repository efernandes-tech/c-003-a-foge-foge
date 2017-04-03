// Constantes.
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
int ehdirecao(char direcao);
void move(char direcao);
int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);
void fantasmas();
