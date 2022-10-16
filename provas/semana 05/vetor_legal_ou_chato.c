#include <stdio.h>

int* alocArray(int size){
    // O desperdicio de memoria é consciente
    int* vetor = (int*) calloc (size, sizeof(int));

    for(int i = 0; i < size; i++) scanf("%d", &vetor[i]);
    return vetor;
}

void isCool(int* array, int size){
    int count = 0;
    for(int i = 0; i < (size - 1); i++){
        if((array[i + 1] - array[i]) < 0) count++;
    }

    (count > 0) ? puts("Chato") : puts("Legal");
}


int main() {
    int n;
    scanf("%d", &n);
    int* A = alocArray(n);

    isCool(A, n);

    return 0;
}

