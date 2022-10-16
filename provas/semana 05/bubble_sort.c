// Abencoada seja a reutilizacao de codigo

#include <stdio.h>
#include <stdlib.h>

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

void ordenarArray(int* array, int size){ 
    int* vetor = array;
    int aux; 

    printArray(vetor, size); 

    for(int i = size-1; i >= 1; i--){ 
        for(int j = 0; j < i; j++){
            if(vetor[j] > vetor[j+1]){ 
                aux=vetor[j]; 
                vetor[j]=vetor[j+1]; 
                vetor[j+1]=aux; 
            } 
        } 
        printArray(vetor, size); 
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* A = alocArray(n);

    ordenarArray(A, n);

    return 0;
}
