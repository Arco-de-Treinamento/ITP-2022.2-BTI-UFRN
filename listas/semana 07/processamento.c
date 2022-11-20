#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nrow, ncol;
    char **matriz;
} Matriz;

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
    for(int i = 0; i < matriz->nrow; i++)
        scanf(" %s", matriz->matriz[i]);
}

int menorString(char* stringA, char* stringB){
    int tamA = strlen(stringA);
    int tamB = strlen(stringB);

    return tamA > tamB ? tamB : tamA;
}

int maiorString(char* stringA, char* stringB){
    int tamA = strlen(stringA);
    int tamB = strlen(stringB);

    return tamA > tamB ? tamA : tamB;
}

void compararStrings(Matriz* matriz){
    printf("%*s", 10, "");

    for(int i = 0; i < matriz->nrow; i++) printf("%*s", 10, matriz->matriz[i]);
    puts("");

    for(int i = 0; i < matriz->nrow; i++){
        printf("%*s", -10, matriz->matriz[i]);

        for(int j = 0; j < matriz->nrow; j++){
            char res[11] = {0};
            int sim = 0;

            for(int k = 0; k < menorString(matriz->matriz[i], matriz->matriz[j]); k++){
                if(matriz->matriz[i][k] == matriz->matriz[j][k]) sim++;
            }

            sprintf(res, "%d/%d", sim, maiorString(matriz->matriz[i], matriz->matriz[j]));
            printf("%*s", 10, res);
        }

        puts("");
    }
}

int main(){
    Matriz* palavras;
    int qnt;

    scanf ("%d", &qnt);
    palavras = alocMatriz(qnt, 11);
    readMatriz(palavras);

    compararStrings(palavras);

    destroyMatriz(&palavras);

    return 0;
}
