#include <stdio.h>
#include <stdlib.h>

int menor(int x, int y){ return (x < y) ? x : y; }


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

void criarPiramide(int** matriz, int x, int y){

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            matriz[i][j] = menor(x-1-i, i) + menor(y-1-j, j) + 1;
        }
    }

    printMatriz(matriz, x, y);
}


int main() {
    int n;
    scanf("%d", &n);
    int** matriz = alocMatriz(n,n);

    criarPiramide(matriz, n, n);

    return 0;
}

