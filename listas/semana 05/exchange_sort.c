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

void ordenarArray(int* array, int size){ 
    int* vetor = array;
    int aux; 

    printArray(vetor, size); 

    for(int i = 0; i < (size - 1); i++){ 
        for(int j = (i + 1); j < size; j++){
            if(vetor[i] > vetor[j]){ 
                aux=vetor[i]; 
                vetor[i]=vetor[j]; 
                vetor[j]=aux; 
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
