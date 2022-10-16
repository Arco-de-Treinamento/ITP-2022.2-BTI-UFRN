// Abencoada seja a reutilizacao de codigo

#include <stdio.h>

int* alocArray(int size){
    // O desperdicio de memoria é consciente
    int* vetor = (int*) calloc (size, sizeof(int));

    for(int i = 0; i < size; i++) scanf("%d", &vetor[i]);
    return vetor;
}

void printArray(char name, int* array, int size){
    printf("%c = [", name);

    for(int i = 0; i < size; i++){
        printf("%d", array[i]);
        if(i < size - 1) printf(", ");
    }

    printf("]");    
    puts("");
}


int main() {
    int* A = alocArray(15);
    int B[15], C[15], D[15];
    int sizeB = 0, sizeC = 0, sizeD = 0;

    for(int i = 0; i < 15; i++){
        if((A[i] % 2) == 0){
            B[sizeB] = A[i];
            sizeB++;
        }

        if((A[i] % 3) == 0){
            C[sizeC] = A[i];
            sizeC++;
        }

        if(!((A[i] % 2) == 0) && !((A[i] % 3) == 0)){
            D[sizeD] = A[i];
            sizeD++;
        }
    }

    printArray('B', B, sizeB);
    printArray('C', C, sizeC);
    printArray('D', D, sizeD);


    return 0;
}
