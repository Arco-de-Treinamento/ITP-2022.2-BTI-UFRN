#include <stdio.h>
#include <stdlib.h>

int** alocMatriz(int sizeR, int sizeC){
    int** matriz = malloc (sizeR * sizeof(int*));
    for(int r = 0; r < sizeR; r++) matriz[r] = malloc (sizeR * sizeof(int));

    for(int i = 0; i < sizeR; i++){
        for(int j = 0; j < sizeC; j++){
            matriz[i][j] = 0;
        }
    }

    return matriz;
}

void printMatriz(int** matriz, int sizeR, int sizeC){
    for(int i = 0; i < sizeC; i++) {
        for(int j = 0; j < sizeR; j++) printf("%d ", matriz[i][j]);
        puts("");
    }
}

void criarPiramide(int** matriz, int z, int x, int y){
    // Matriz tridimensional, bro? 

    for(int k = 0; k < z; k++){
        for(int i = 0 + k; i < (x - k); i++){
            for(int j = 0 + k; j < (y - k); j++){
                matriz[i][j] += 1;
            }
        }
    }

    printMatriz(matriz, x, y);
}


int main() {
    int n;
    scanf("%d", &n);
    int** matriz = alocMatriz(n,n);

    criarPiramide(matriz, n, n, n);

    return 0;
}

