#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int nrow, ncol;
    char **matriz;
} Matriz;

typedef struct{
    int tamMax, tamMin, proxMedia;
    double media;
} Estatisticas;

Matriz* alocMatriz(int nrow, int ncol){
    static Matriz matriz;
    matriz.nrow = nrow;
    matriz.ncol = ncol;

    matriz.matriz = malloc(sizeof(char*) * nrow);
    for(char i = 0; i < nrow; i++) matriz.matriz[i] = malloc(sizeof(char) * ncol);

    return (&matriz);
}

void destroyMatriz(Matriz **matriz){ 
    for(int i = 0; i < (*matriz)->nrow; i++) free((*matriz)->matriz[i]);
    free((*matriz)->matriz);
    *matriz = NULL; 
}

void readMatriz(Matriz *matriz){
    for(int i = 0; i < matriz->nrow; i++){
        fgets(matriz->matriz[i], 200, stdin);

        if((matriz->matriz[i][strlen(matriz->matriz[i]) - 1]) == '\n')
            matriz->matriz[i][strlen(matriz->matriz[i]) - 1] = '\0';
    }
}

void printMatriz(Matriz *matriz, int target){
    for(int i = 0; i < matriz->nrow; i++){
        if(strlen(matriz->matriz[i]) == target) printf("%s", matriz->matriz[i]);
    }
}

int calcValorProx(Matriz *palavras, double media){
    int prox = round(media);
    int dist = abs(prox - strlen(palavras->matriz[0]));
    int val = strlen(palavras->matriz[0]);

    for(int i = 1; i < palavras->nrow; i++){
        if(abs(strlen(palavras->matriz[i]) - prox) < dist){
            val = strlen(palavras->matriz[i]);
            dist = abs(strlen(palavras->matriz[i]) - prox);
        }
    }

    return val;
}

Estatisticas calcEstatisticas(Matriz *palavras){    
    Estatisticas estatisticas;
    estatisticas.tamMax = strlen(palavras->matriz[0]);
    estatisticas.tamMin = strlen(palavras->matriz[0]);

    double auxMedia = strlen(palavras->matriz[0]);

    for(int i = 1; i < palavras->nrow; i++){
        if(strlen(palavras->matriz[i]) > estatisticas.tamMax) estatisticas.tamMax = strlen(palavras->matriz[i]);
        if(strlen(palavras->matriz[i]) < estatisticas.tamMin) estatisticas.tamMin = strlen(palavras->matriz[i]);
        auxMedia += strlen(palavras->matriz[i]);
    }

    estatisticas.media = auxMedia/(palavras->nrow);
    estatisticas.proxMedia = calcValorProx(palavras, estatisticas.media);

    return estatisticas;
}

void estatisticasParaNerds(Matriz *palavras){
    Estatisticas estatisticas = calcEstatisticas(palavras);

    printf("Tamanho máximo: %d\n", estatisticas.tamMax);
    printf("Tamanho mínimo: %d\n", estatisticas.tamMin);
    printf("Tamanho médio: %.2lf\n", estatisticas.media);
    printf("Tamanho mais próximo da média %d\n", estatisticas.proxMedia);
    puts("Textos");

    printMatriz(palavras, estatisticas.proxMedia);
}

int main(){

    Matriz* palavras;
    int qnt;

    scanf ("%d\n", &qnt);
    palavras = alocMatriz(qnt, 201);

    readMatriz(palavras);
    estatisticasParaNerds(palavras);

    destroyMatriz(&palavras);
    return 0;
}