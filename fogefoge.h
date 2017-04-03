void lemapa();
void alocamapa();
void liberamapa();
int acabou();
void imprimemapa();
void move(char direcao);

// Declaracao de uma struct para agrupar variaveis que sempre estao juntas.
struct mapa {
	char** matriz;
	int linhas;
	int colunas; 
};

// Da um novo nome ao tipo, não sendo necessario usar "struct mapa m;".
typedef struct mapa MAPA;
