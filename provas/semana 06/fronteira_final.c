#include <stdio.h>
#include <stdlib.h>

char** alocMatriz(int sizeR, int sizeC){
    char** matriz = malloc (sizeR * sizeof(char*));
    for(int r = 0; r < sizeR; r++) matriz[r] = malloc (sizeR * sizeof(char));

    for(int i = 0; i < sizeR; i++){
        for(int j = 0; j < sizeC; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }

    return matriz;
}

int contElemento(char** matriz, int sizeR, int sizeC, char element){
    int count = 0;

    for(int i = 0; i < sizeC; i++) {
        for(int j = 0; j < sizeR; j++) if(matriz[i][j] == element) count++;
    }

    return count;
}

void detectarPlaneta(char** matriz, int sizeR, int sizeC){
    float agua =   (contElemento(matriz, sizeR, sizeC, '~') / (float)(sizeR * sizeC)) * 100;
    float hostil = (contElemento(matriz, sizeR, sizeC, 'X') / (float)(sizeR * sizeC)) * 100;
    float desert = (contElemento(matriz, sizeR, sizeC, '^') / (float)(sizeR * sizeC)) * 100;
    float veget =  (contElemento(matriz, sizeR, sizeC, '*') / (float)(sizeR * sizeC)) * 100;
    float infert = (contElemento(matriz, sizeR, sizeC, '.') / (float)(sizeR * sizeC)) * 100;

    if(agua >= 50.0 && veget >= 20.0 && hostil <= 0.0) puts("Planeta Classe M");
    else if(hostil > 0.0) puts("Planeta Hostil");
    else if(agua >= 85.0) puts("Planeta Aquático");
    else if(desert >= 60.0) puts("Planeta Desértico");
    else if(veget >= 65.0) puts("Planeta Selvagem");
    else puts("Planeta Inóspito");

}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    char** matriz = alocMatriz(m,n);

    detectarPlaneta(matriz, m, n);

    return 0;
}

