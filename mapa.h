// Declaracao de uma struct para agrupar variaveis que sempre estao juntas.
struct mapa {
	char** matriz;
	int linhas;
	int colunas; 
};

struct posicao {
    int x;
    int y;
};

// Da um novo nome ao tipo, não sendo necessario usar "struct mapa m;".
typedef struct mapa MAPA;

typedef struct posicao POSICAO;

// Somente agora declarar as funcoes.
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);

void encontramapa(MAPA* m, POSICAO* p, char c);
