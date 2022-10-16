// Abencoada seja a reutilizacao de codigo

#include <stdio.h>

int* alocArray(int size){
    // O desperdicio de memoria é consciente
    int* vetor = (int*) calloc (size, sizeof(int));

    for(int i = 0; i < size; i++) scanf("%d", &vetor[i]);
    return vetor;
}

void printArray(int* array, int size){
    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    puts("");
}

int contido(int n, int* array, int size){
    for (int i = 0; i < size; i++) if(array[i] == n) return 1;
    return 0;
}

void intersecao(int* A, int* B, int sizeA, int sizeB){
    int j = 0;
    int AUB[(sizeA + sizeB)];

    for (int i = 0; i < sizeA; i++){
        if(contido(A[i], B, sizeB)){
            AUB[j] = A[i];
            j++;
        } 
    }

    printArray(AUB, j);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* A = alocArray(n);
    int* B = alocArray(m);

    intersecao(A, B, n, m);

    return 0;
}

