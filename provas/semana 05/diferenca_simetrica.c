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

void ordenarArray(int* array, int size){ 
    int* vetor = array;
    int aux; 
 
    for(int i = size-1; i >= 1; i--){ 
        for(int j = 0; j < i; j++){
            if(vetor[j] > vetor[j+1]){ 
                aux=vetor[j]; 
                vetor[j]=vetor[j+1]; 
                vetor[j+1]=aux; 
            } 
        } 
    }

    printArray(vetor, size); 
}

void difSimetrica(int* A, int* B, int sizeA, int sizeB){
    int j = 0;
    int AUB[(sizeA + sizeB)];

    for (int i = 0; i < sizeA; i++){
        if(!contido(A[i], B, sizeB)){
            AUB[j] = A[i];
            j++;
        } 
    }

    for (int i = 0; i < sizeB; i++){
        if(!contido(B[i], A, sizeA)){
            AUB[j] = B[i];
            j++;
        } 
    }

    ordenarArray(AUB, j);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* A = alocArray(n);
    int* B = alocArray(m);

    difSimetrica(A, B, n, m);

    return 0;
}

