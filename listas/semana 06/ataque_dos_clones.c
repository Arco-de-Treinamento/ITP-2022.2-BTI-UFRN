#include <stdio.h>
#include <stdlib.h>

#define MINIMO -2147483648

typedef struct {
    int nrow, ncol;
    int **matriz;
} Matriz;

Matriz* alocMatriz(int nrow, int ncol){
    static Matriz matriz;
    matriz.nrow = nrow;
    matriz.ncol = ncol;

    matriz.matriz = malloc(sizeof(int*) * nrow);
    for(int i = 0; i < nrow; i++) matriz.matriz[i] = malloc(sizeof(int) * ncol);

    for(int r = 0; r < matriz.nrow; r++){
        for(int c = 0; c < matriz.ncol; c++) matriz.matriz[r][c] = MINIMO;
    }

    return (&matriz);
}

void destroyMatriz(Matriz **matriz){ 
    for(int i = 0; i < (*matriz)->nrow; i++) free((*matriz)->matriz[i]);
    free((*matriz)->matriz);
    *matriz = NULL; 
}

void readMatriz(Matriz *matriz){
    for(int i = 1; i <= (matriz->nrow - 2); i++){
        for(int j = 1; j <= (matriz->ncol - 2); j++) scanf(" %d", &matriz->matriz[i][j]);
    }
}

int checkBomba(Matriz *planeta, int codX, int codY){
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if((i != 0) || (j != 0)){
                if (planeta->matriz[codX][codY] <= planeta->matriz[codX + i][codY + j]) return 0;
            }
        }
    }
    return 1;
}

void planetScanner(Matriz *planeta, int jediX, int jediY){
    int localList = 1, checkMorreu = 0;
    
    for(int i = 1; i <= (planeta->nrow - 2); i++){
        for(int j = 1; j <= (planeta->ncol - 2); j++){
            if(checkBomba(planeta, i, j)){
                printf("Local %d: %d %d\n", localList, i, j);
                localList++;

                if((i == jediX) && (j == jediY)) checkMorreu = 1;
            }
        }
    }

    if(checkMorreu) puts("Descanse na Força...");
    else puts("Ao resgate!\n");
}

int main(){
    int r, c, jediX, jediY;
    Matriz* planeta;

    scanf("%d %d", &r, &c);
    scanf("%d %d", &jediX, &jediY);

    planeta = alocMatriz((r + 2), (c + 2));
    readMatriz(planeta);

    planetScanner(planeta, jediX, jediY);

    destroyMatriz(&planeta);
    return 0;
}