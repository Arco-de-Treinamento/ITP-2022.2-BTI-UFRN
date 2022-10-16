#include <stdio.h>

int main() {
    int ded[4];
    scanf("%d %d %d %d", &ded[0], &ded[1], &ded[2], &ded[3]);

    // Nesse caso era mais facil literalmente somar tudo,
    // ja que temos poucos elementos.
    int somaDed = (ded[0] + ded[1] + ded[2] + ded[3]);

    // Pegando codigo da letra na tabela ASCII
    int letra = (somaDed > 26) ? ((somaDed%26) + 64) : (somaDed + 64);

    if (letra <= 64)
        puts("Ei! Ninguém colocou nada!");
    else
        printf("Letra: %c\n", letra);
    
    return 0;
}