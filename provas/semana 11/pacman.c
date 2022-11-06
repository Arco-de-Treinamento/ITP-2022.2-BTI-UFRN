#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nrow, ncol;
    char **matriz;
} Mapa;

Mapa* alocMapa(int nrow, int ncol){
    static Mapa mapa;
    mapa.ncol = ncol;
    mapa.nrow = nrow;

    mapa.matriz = malloc(sizeof(char*) * nrow);
    for(int i = 0; i < nrow; i++) mapa.matriz[i] = malloc(sizeof(char) * nrow);

    return (&mapa);
}

void readMapa(Mapa *mapa){
    for(int i = 0; i < mapa->nrow; i++){
        for(int j = 0; j < mapa->ncol; j++) scanf(" %c", &mapa->matriz[i][j]);
    }
}

void destroyMapa(Mapa **mapa){ 
    for(int i = 0; i < (*mapa)->nrow; i++) free((*mapa)->matriz[i]);
    free((*mapa)->matriz);
    *mapa = NULL; 
}

void printMapa(Mapa *mapa){
    for(int i = 0; i < mapa->nrow; i++){
        for(int j = 0; j < mapa->ncol; j++) printf("%c", mapa->matriz[i][j]);
        puts("");
    }
}

// Localiza o Pacman
int findPacman(Mapa *mapa, int* rowPacman, int* colPacman){
    for(int i = 0; i < mapa->nrow; i++){
        for(int j = 0; j < mapa->ncol; j++){
            if(mapa->matriz[i][j] == 'C'){
                *rowPacman = i;
                *colPacman = j;

                return 1;
            }
        }
    }
    
    return 0;
}

// Percorre o mapa a partir do xyPacman até encontrar as bolinhas
int findValidBolinha(Mapa *mapa, int row, int col, int *bolinhas){
    // Direita
    if((row >= 0 && row < mapa->nrow) && ((col + 1) >= 0 && (col + 1) < mapa->ncol)){
        if(mapa->matriz[row][col + 1] == '.'){
            mapa->matriz[row][col + 1] = ' ';
            (*bolinhas)++;

            if(findValidBolinha(mapa, row, (col + 1), &(*bolinhas))) return 1;
        }
    }

    // Esquerda
    if((row >= 0 && row < mapa->nrow) && ((col - 1) >= 0 && (col - 1) < mapa->ncol)){     
        if(mapa->matriz[row][col - 1] == '.'){
            mapa->matriz[row][col - 1] = ' ';
            (*bolinhas)++;

            if(findValidBolinha(mapa, row, (col - 1), &(*bolinhas))) return 1;
        }
    }

    // Cima
    if(((row - 1) >= 0 && (row - 1) < mapa->nrow) && (col >= 0 && col < mapa->ncol)){     
        if(mapa->matriz[row - 1][col] == '.'){
            mapa->matriz[row - 1][col] = ' ';
            (*bolinhas)++;

            if(findValidBolinha(mapa, (row - 1), col, &(*bolinhas))) return 1;
        }
    }

    // Baixo
    if(((row + 1) >= 0 && (row + 1) < mapa->nrow) && (col >= 0 && col < mapa->ncol)){     
        if(mapa->matriz[row + 1][col] == '.'){
            mapa->matriz[row + 1][col] = ' ';
            (*bolinhas)++;

            if(findValidBolinha(mapa, (row + 1), col, &(*bolinhas))) return 1;
        }
    }

    return 0;
}

int kirbyMode(Mapa *mapa){
    int rowPacman, colPacman;
    int bolinhas = 0;

    if(findPacman(mapa, &rowPacman, &colPacman)){
        findValidBolinha(mapa, rowPacman, colPacman, &bolinhas);
    }

    return bolinhas;
}

int main() {
    int nrow, ncol, bolinha = 0;
    scanf("%d %d", &nrow, &ncol);
    Mapa* mapa;

    mapa = alocMapa(nrow, ncol);
    readMapa(mapa);

    bolinha = kirbyMode(mapa);

    printf("Total de bolinhas devoradas: %d \n", bolinha);
    puts("Mapa final:");
    printMapa(mapa);

    destroyMapa(&mapa);

    return 0;
}