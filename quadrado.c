#include <stdio.h>

struct quadrado {
    int x;
    int y;
};

typedef struct quadrado QUADRADO;

void dobra(QUADRADO q) {
    q.x = q.x * 2;
    q.y = q.y * 2;
}

int main() {
    QUADRADO q1;

    q1.x = 20;
    q1.y = 35;

    printf("%d %d\n", q1.x, q1.y);
    dobra(q1);
    printf("%d %d\n", q1.x, q1.y);
}
