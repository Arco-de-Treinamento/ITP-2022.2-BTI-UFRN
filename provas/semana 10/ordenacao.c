#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* array, int size){
    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    puts("");
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

int main(){
    char buffer[200];
    char* dado;
    int* array;
    int count;

    array = calloc(1, sizeof(int));

    scanf(" %[^\n]", buffer);
    dado = strtok(buffer, " ");

    for(count = 0; dado != NULL; count++){
        array[count] = atoi(dado);
        dado = strtok(NULL, " ");
        array = realloc(array, sizeof(int) * (count + 2));
    }

    ordenarArray(array, count);
    free(array);

    return 0;
}
