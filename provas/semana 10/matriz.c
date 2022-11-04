#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nlin, ncol;
    int **mat;
} Matrix;

Matrix* createMatrix(int nlin, int ncol){
    static Matrix matrix;
    matrix.nlin = nlin;
    matrix.ncol = ncol;

    matrix.mat = malloc(sizeof(int*) * nlin);
    for(int i = 0; i < nlin; i++) matrix.mat[i] = malloc(sizeof(int) * ncol);

    return (&matrix); 
}

void readMatrix(Matrix *m){
    for(int i = 0; i < m->nlin; i++){
        for(int f = 0; f < m->ncol; f++) scanf(" %d", &m->mat[i][f]);
    }
}

void printMatrix(Matrix *m){
    for(int i = 0; i < m->nlin; i++){
        for(int f = 0; f < m->ncol; f++) printf("%d ", m->mat[i][f]);
        puts("");
    }
}

void destroyMatrix(Matrix **m){ 
    for(int i = 0; i < (*m)->nlin; i++) free((*m)->mat[i]);
    free((*m)->mat);
    *m = NULL; 
    }

int main() {
    int lin, col;
    Matrix* mat;

    scanf("%i %i", &lin, &col);
    mat = createMatrix(lin, col);
    readMatrix(mat);
    printMatrix(mat);
    destroyMatrix(&mat);
    if(mat == NULL) {
        printf("OK\n");
    }

    return 0;
}