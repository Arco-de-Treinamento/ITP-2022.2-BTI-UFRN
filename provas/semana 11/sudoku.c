#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nrow, ncol;
    char **matriz;
} Puzzle;

// Converte char em int
int ctoi(char num){ return num - '0';}

// Convete int em char
char itoc(int num){ return num + '0';}

Puzzle* alocPuzzle(int nrow, int ncol){
    static Puzzle puzzle;
    puzzle.nrow = nrow;
    puzzle.ncol = ncol;

    puzzle.matriz = malloc(sizeof(char*) * nrow);
    for(int i = 0; i < nrow; i++) puzzle.matriz[i] = malloc(sizeof(char) * nrow);

    return (&puzzle);
}

void readPuzzle(Puzzle *puzzle){
    for(int i = 0; i < puzzle->nrow; i++){
        for(int j = 0; j < puzzle->ncol; j++) scanf(" %c", &puzzle->matriz[i][j]);
    }
}

void destroyPuzzle(Puzzle **puzzle){ 
    for(int i = 0; i < (*puzzle)->nrow; i++) free((*puzzle)->matriz[i]);
    free((*puzzle)->matriz);
    *puzzle = NULL; 
}

void printPuzzle(Puzzle *puzzle){
    for(int i = 0; i < puzzle->nrow; i++){
        for(int f = 0; f < puzzle->ncol; f++) printf("%c", puzzle->matriz[i][f]);
        puts("");
    }
}

// Encontra valroes vazios
int isEmpty(Puzzle *puzzle, int *rowEmpty, int *colEmpty){
    for(int i = 0; i < puzzle->nrow; i++){
        for(int j = 0; j < puzzle->ncol; j++){
            if(puzzle->matriz[i][j] == '*'){
                *rowEmpty = i;
                *colEmpty = j;

                return 1;
            }
        }
    }

    return 0;
}

// Verifica se o numero é valido
int validNum(Puzzle *puzzle, int rowElement, int colElement, int element){
    int quadRow = (rowElement / 3) * 3;
    int quadCol = (colElement / 3) * 3;

    for(int i = 0; i < 9; i++){
        // Verifica elementos da mesma coluna
        if((ctoi(puzzle->matriz[rowElement][i]) == element) && (i != colElement)) return 0;
        // Verifica elementos da mesma linha
        if((ctoi(puzzle->matriz[i][colElement]) == element) && (i != rowElement)) return 0;
        // Verifica por quadrante
        if(ctoi(puzzle->matriz[quadRow + (i % 3)][quadCol + (i / 3)]) == element) return 0;
    }

    return 1;
}

int solucionar(Puzzle *puzzle){
    int currentRow, currentCol;

    // Verifica se possui celula em branco
    if(!isEmpty(puzzle, &currentRow, &currentCol)) return 1;

    // Testa com numeros de 1 a 9
    for(int num = 1; num < 10; num++){
        if(validNum(puzzle, currentRow, currentCol, num)){
            puzzle->matriz[currentRow][currentCol] = itoc(num);

            if(solucionar(puzzle)) return 1;

            // Caso nao encontre solucao, reseta a celula
            puzzle->matriz[currentRow][currentCol] = '*';
        }
    }

    return 0;
}

int main() {
    Puzzle* puzzle;

    puzzle = alocPuzzle(9, 9);
    readPuzzle(puzzle);

    if(solucionar(puzzle)){
        printPuzzle(puzzle);
    } else puts("Não tem solução!");

    destroyPuzzle(&puzzle);

    return 0;
}

